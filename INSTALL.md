## Prerequisites

| Linux | macOS | Windows 10 (build 18917+) | Windows 10 (1709+) | Windows Vista, 7, 8, 8.1, and 10 (1507, 1511, 1607, 1703)
| ----- | ----- | ------------------------- | ------------------ | ---------------------------------------------------------
| none | [Xcode Command Line Tools package][xcode] | [Windows Subsystem for Linux 2][wsl2] | [Windows Subsystem for Linux][wsl] | [Cygwin][cygwin]

[xcode]: https://developer.apple.com/library/archive/technotes/tn2339/_index.html#//apple_ref/doc/uid/DTS40014588-CH1-DOWNLOADING_COMMAND_LINE_TOOLS_IS_NOT_AVAILABLE_IN_XCODE_FOR_MACOS_10_9__HOW_CAN_I_INSTALL_THEM_ON_MY_MACHINE_
[wsl2]: https://docs.microsoft.com/windows/wsl/wsl2-install
[wsl]: https://docs.microsoft.com/windows/wsl/install-win10
[cygwin]: https://cygwin.com/install.html

The [prerelease version of the Linux subsystem](https://docs.microsoft.com/windows/wsl/install-legacy) available in the 1607 and 1703 releases of Windows 10 is obsolete so consider uninstalling it.

Make sure that the `build-essential`, `git`, and `libpng-dev` packages are installed. The `build-essential` package includes the `make`, `gcc-core`, and `g++` packages so they do not have to be obtained separately.

In the case of Cygwin, [include](https://cygwin.com/cygwin-ug-net/setup-net.html#setup-packages) the `make`, `git`, `gcc-core`, `gcc-g++`, and `libpng-devel` packages.


## Installation

To set up the repository:

	git clone https://github.com/tustin2121/trihard-emerald
	git clone https://github.com/luckytyphlosion/agbcc -b new_layout_with_libs

	cd ./agbcc
	make
	make install prefix=../trihard-emerald

	cd ../trihard-emerald

To build **trihard-emerald.gba**:

	make

It's common for a first-time build to take 30-60 minutes, so go grab a snack. Subsequent builds only have to build what's been changed.

To force a rebuild when make says there's nothing to do, use `make tidy` before using `make` again. To rebuild all of the map scripts (sometimes needed when something fundamental about the overworld engine changes), use `make cleanmaps` before running `make` (you will have to reload the map you're on after loading your save to see the proper changes).
