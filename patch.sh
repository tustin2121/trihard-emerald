#!/bin/bash

if [[ $# -lt 2 ]]; then
	echo "usage: $0 output.bsp target.gba [target.gba ...]" >&2
	exit 4
fi

# patch in 32KB-sized fragments. Adjust for better patch compression.
fragsize=0x8000

output="$1"
shift
targets="$@"

function checkfail {
	$@
	local result=$?
	if [[ $result -eq 0 ]]; then
		return 0
	fi
	echo "[$1] exit status $result" >&2
	exit 3
}

function updaterepo {
	# $1: repo, $2: URL
	if [[ ! ( -d $1 ) ]]; then
		checkfail git clone --recursive $2 $1
	fi
	pushd $1
	git pull
	popd
}

function checkhash {
	# $1: file, $2: expected hash
	# returns a Bool: https://thedailywtf.com/articles/What_Is_Truth_0x3f_
	if [[ ! ( -f $1 ) ]]; then
		return 2
	fi
	[ `sha1sum -b $1 | cut -c 1-40` = $2 ]
	if [[ $? -ne 0 ]]; then
		return 1
	fi
	return 0
}

function buildemerald {
	updaterepo agbcc https://github.com/pret/agbcc.git
	updaterepo pokeemerald https://github.com/pret/pokeemerald.git
	pushd agbcc
	checkfail ./build.sh
	checkfail ./install.sh ../pokeemerald
	cd ../pokeemerald
	checkfail make
	checkfail cp pokeemerald.gba ..
	popd
}

# make sure the patch directory exists
if [[ ! ( -d build/patch ) ]]; then
	checkfail mkdir build/patch
fi
pushd build/patch

# make sure we have a copy of bspbuild
if [[ ! ( -x bspbuild ) ]]; then
	updaterepo bspbuildrepo https://github.com/aaaaaa123456789/bspbuild.git
	pushd bspbuildrepo
	checkfail make
	checkfail cp bspbuild ..
	popd
fi

# rebuild the ROM if we don't have a good base
checkhash pokeemerald.gba f3ae088181bf583e55daf962a92bb46f4f1d07b7
if [[ $? -ne 0 ]]; then
	buildemerald
	checkhash pokeemerald.gba f3ae088181bf583e55daf962a92bb46f4f1d07b7
	case $? in
		0)
			;;
		1)
			echo "[check] base ROM hash mismatch" >&2
			exit 1
			;;
		2)
			echo "[check] base ROM not found" >&2
			exit 2
			;;
		*)
			echo "[check] unknown error" >&2
			exit 3
			;;
	esac
fi

# retrieve the target file(s)
popd
checkfail cp -t build/patch/ -- $targets
pushd build/patch

# build the patch
./bspbuild -s pokeemerald.gba -m xor-rle -st $targets -o $output -f $fragsize -pb 0 --check-fragment-swap --titles-from-stdin <<-END
	// base ROM
	pokeemerald.gba=Pokémon Emerald

	// targets
	trihardemerald.gba=TPP TriHard Emerald
END
result=$?
if [[ $result -ne 0 ]]; then
	echo "[bspbuild] exit status $result" >&2
	exit 3
fi

# copy the file to the parent directory and we're done
popd
checkfail cp build/patch/$output .
exit 0
