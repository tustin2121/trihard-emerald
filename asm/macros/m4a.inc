	.macro song label, music_player, arg
	.4byte \label
	.2byte \music_player
	.2byte \arg
	.endm

	.macro music_player info_struct, track_struct, arg1, arg2
	.4byte \info_struct
	.4byte \track_struct
	.byte \arg1
	.space 1
	.2byte \arg2
	.endm
