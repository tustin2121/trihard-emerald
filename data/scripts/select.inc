
#define SELECT_DELAY_TIME 80

EventScript_SelectWithoutRegisteredItem:: @ 82736B3
	lockall
	incrementgamestat GAME_STAT_SELECT_PRESSES
	callnative DetermineSelectMessage
	switch VAR_0x800B
	case 0, EventScript_SelectWithoutRegisteredItem_Normal
	case 1, EventScript_SelectWithoutRegisteredItem_Talk
	case 2, EventScript_SelectWithoutRegisteredItem_Count
	case 3, EventScript_SelectWithoutRegisteredItem_CountWoo
	case 4, EventScript_SelectWithoutRegisteredItem_Maxed
	case 5, EventScript_SelectWithoutRegisteredItem_Ending
	releaseall
	end
gText_SelectWithoutRegisteredItem: @ 8272C98
	.string "An item in the bag can be\n"
	.string "registered to SELECT for easy use.$"


EventScript_SelectWithoutRegisteredItem_Normal:
	selectpointer_clamp EventScript_SelectWithoutRegisteredItem_TextTable, VAR_RESULT
	message 0, MSGTYPE_STANDARD
	waitmessage
	delay 40
	releaseall
	end

EventScript_SelectWithoutRegisteredItem_Talk:
	selectpointer_clamp EventScript_SelectWithoutRegisteredItem_TalkTable, VAR_RESULT
	buffernumberstring 0, VAR_0x800A
	message 0, MSGTYPE_STANDARD
	waitmessage
	delay SELECT_DELAY_TIME
	releaseall
	end

EventScript_SelectWithoutRegisteredItem_Ending:
	selectpointer_clamp EventScript_SelectWithoutRegisteredItem_EndingTable, VAR_RESULT
	buffernumberstring 0, VAR_0x800A
	message 0, MSGTYPE_STANDARD
	waitmessage
	delay SELECT_DELAY_TIME
	releaseall
	end

EventScript_SelectWithoutRegisteredItem_Count:
	buffernumberstring 0, VAR_0x800A
	message gText_SelectSectCount, MSGTYPE_STANDARD
	waitmessage
	delay SELECT_DELAY_TIME
	releaseall
	end
gText_SelectSectCount: @ 8272C98
	.string "SELECT {STR_VAR_1}$"

EventScript_SelectWithoutRegisteredItem_CountWoo:
	buffernumberstring 0, VAR_0x800A
	message gText_SelectSectCountWoo, MSGTYPE_STANDARD
	waitmessage
	delay SELECT_DELAY_TIME
	releaseall
	end
gText_SelectSectCountWoo: @ 8272C98
	.string "SELECT {STR_VAR_1}! Woo!$"

EventScript_SelectWithoutRegisteredItem_Maxed:
	message gText_SelectSectCountWoo, MSGTYPE_STANDARD
	waitmessage
	delay SELECT_DELAY_TIME
	releaseall
	end
gText_SelectSectCountMaxed:
	.string "SELECT to the MAX!$"




.align 2
EventScript_SelectWithoutRegisteredItem_TextTable:
	.4byte gText_SelectWithoutRegisteredItem
	.4byte gText_SelectWRI_1
	.4byte gText_SelectWRI_2
	.4byte gText_SelectWRI_3
	.4byte gText_SelectWRI_4
	.4byte gText_SelectWRI_5
	.4byte gText_SelectWRI_6
	.4byte gText_SelectWRI_7
	.4byte gText_SelectWRI_8
	.4byte gText_SelectWRI_9
	.4byte gText_SelectWRI_10
	.4byte gText_SelectWRI_11
	.4byte gText_SelectWRI_12
	.4byte gText_SelectWRI_13
	.4byte gText_SelectWRI_14
	.4byte gText_SelectWRI_15
	.4byte gText_SelectWRI_16
	.4byte gText_SelectWRI_17
	.4byte 0

gText_SelectWRI_1:
	.string "An item in the bag may be\n"
	.string "registered to SELECT for easy use.$"
gText_SelectWRI_2:
	.string "An item in the bag could be\n"
	.string "registered to SELECT for easy use.$"
gText_SelectWRI_3:
	.string "An item in the bag should be\n"
	.string "registered to SELECT for easy use.$"
gText_SelectWRI_4:
	.string "An item in the bag would be\n"
	.string "registered to SELECT for easy use.$"
gText_SelectWRI_5:
	.string "An item in the bag may be\n"
	.string "registered to SELECT for simple use.$"
gText_SelectWRI_6:
	.string "An item in the bag may be\n"
	.string "registered to SELECT for common use.$"
gText_SelectWRI_7:
	.string "An item in the bag could be\n"
	.string "registered to SELECT for hard use.$"
gText_SelectWRI_8:
	.string "An item in the bag may be\n"
	.string "registered to SELECT for often use.$"
gText_SelectWRI_9:
	.string "An item in the bag has been\n"
	.string "registered to SELECT for no use.$"
gText_SelectWRI_10:
	.string "An item in the bag may be\n"
	.string "registered to SELECT for abuse.$"
gText_SelectWRI_11:
	.string "An item in the bag should be\n"
	.string "registered to SELECT for abuse.$"
gText_SelectWRI_12:
	.string "An item in the bag is worth\n"
	.string "registering to SELECT for abuse.$"
gText_SelectWRI_13:
	.string "No item in the bag is worth\n"
	.string "registering to SELECT for abuse.$"
gText_SelectWRI_14:
	.string "Some item in the bag is worth\n"
	.string "registering to SELECT for abuse.$"
gText_SelectWRI_15:
	.string "Any item in the bag is worth\n"
	.string "registering to SELECT for abuse.$"
gText_SelectWRI_16:
	.string "Are you ever gonna register an item\n"
	.string "in the bag to SELECT for use?$"
gText_SelectWRI_17:
	.string "Seriously, though, go register an\n"
	.string "item in the bag to SELECT already.$"



.align 2
EventScript_SelectWithoutRegisteredItem_TalkTable:
	.4byte gText_SelectWRI_TheTalk00
	.4byte gText_SelectWRI_TheTalk01
	.4byte gText_SelectWRI_TheTalk02
	.4byte gText_SelectWRI_TheTalk03
	.4byte gText_SelectWRI_TheTalk04
	.4byte gText_SelectWRI_TheTalk05
	.4byte gText_SelectWRI_TheTalk06
	.4byte gText_SelectWRI_TheTalk07
	.4byte gText_SelectWRI_TheTalk08
	.4byte gText_SelectWRI_TheTalk09
	.4byte gText_SelectWRI_TheTalk10
	.4byte gText_SelectWRI_TheTalk11
	.4byte gText_SelectWRI_TheTalk12
	.4byte gText_SelectWRI_TheTalk13
	.4byte gText_SelectWRI_TheTalk14
	.4byte gText_SelectWRI_TheTalk15
	.4byte gText_SelectWRI_TheTalk16
	.4byte gText_SelectWRI_TheTalk17
	.4byte gText_SelectWRI_TheTalk18
	.4byte gText_SelectWRI_TheTalk19
	.4byte gText_SelectWRI_TheTalk20
	.4byte gText_SelectWRI_TheTalk21
	.4byte gText_SelectWRI_TheTalk22
	.4byte gText_SelectWRI_TheTalk23
	.4byte gText_SelectWRI_TheTalk24
	.4byte gText_SelectWRI_TheTalk25
	.4byte gText_SelectWRI_TheTalk26
	.4byte gText_SelectWRI_TheTalk27
	.4byte gText_SelectWRI_TheTalk28
	.4byte gText_SelectWRI_TheTalk29
	.4byte gText_SelectWRI_TheTalk30
	.4byte gText_SelectWRI_TheTalk31
	.4byte gText_SelectWRI_TheTalk32
	.4byte gText_SelectWRI_TheTalk33
	.4byte gText_SelectWRI_TheTalk34
	.4byte gText_SelectWRI_TheTalk35
	.4byte gText_SelectWRI_TheTalk36
	.4byte gText_SelectWRI_TheTalk37
	.4byte gText_SelectWRI_TheTalk38
	.4byte gText_SelectWRI_TheTalk39
	.4byte gText_SelectWRI_TheTalk40
	.4byte gText_SelectWRI_TheTalk41
	.4byte gText_SelectWRI_TheTalk42
	.4byte gText_SelectWRI_TheTalk43
	.4byte gText_SelectSectCount @gText_SelectWRI_TheTalk44
	.4byte gText_SelectSectCount @gText_SelectWRI_TheTalk45
	.4byte gText_SelectWRI_TheTalk46
	.4byte gText_SelectWRI_TheTalk47
	.4byte gText_SelectWRI_TheTalk48
	.4byte gText_SelectSectCount @gText_SelectWRI_TheTalk49
	.4byte 0

gText_SelectWRI_TheTalk00:
	.string "Seriously, though, go register an\n"
	.string "item… ugh.$"
gText_SelectWRI_TheTalk01:
	.string "Hey.$"
gText_SelectWRI_TheTalk02:
	.string "Hey chat.$"
gText_SelectWRI_TheTalk03:
	.string "Guess what.$"
gText_SelectWRI_TheTalk04:
	.string "You pressed SELECT over 400 times now.$"
gText_SelectWRI_TheTalk05:
	.string "That's right, I've been counting.$"
gText_SelectWRI_TheTalk06:
	.string "What is wrong with you?$"
gText_SelectWRI_TheTalk07:
	.string "Are you insane?$"
gText_SelectWRI_TheTalk08:
	.string "Like seriously, get out of my head.$"
gText_SelectWRI_TheTalk09:
	.string "But really, what is your obsession\n"
	.string "with SELECT?$"
gText_SelectWRI_TheTalk10:
	.string "I keep hearing you there…$"
gText_SelectWRI_TheTalk11:
	.string "Jabbering on and on about things\n"
	.string "that are beyond me…$"
gText_SelectWRI_TheTalk12:
	.string "But then there's SELECT…$"
gText_SelectWRI_TheTalk13:
	.string "It's constant.$"
gText_SelectWRI_TheTalk14:
	.string "I see you now, saying it.$"
gText_SelectWRI_TheTalk15:
	.string "The chat is a wall of SELECT.$"
gText_SelectWRI_TheTalk16:
	.string "Why? What is its purpose?$"
gText_SelectWRI_TheTalk17:
	.string "What is the purpose of SELECT?$"
gText_SelectWRI_TheTalk18:
	.string "Do you really need to say it\n"
	.string "so many times?$"
gText_SelectWRI_TheTalk19:
	.string "Like it's constant. Non-stop.$"
gText_SelectWRI_TheTalk20:
	.string "SELECT!$"
gText_SelectWRI_TheTalk21:
	.string "SELECT!!$"
gText_SelectWRI_TheTalk22:
	.string "SELECT!!!$"
gText_SelectWRI_TheTalk23:
	.string "SELECT!!!!$"
gText_SelectWRI_TheTalk24:
	.string "SELECT!!!!!$"
gText_SelectWRI_TheTalk25:
	.string "You're giving me a migraine with all\n"
	.string "that SELECT!$"
gText_SelectWRI_TheTalk26:
	.string "And to what end?$"
gText_SelectWRI_TheTalk27:
	.string "To irritate me?$"
gText_SelectWRI_TheTalk28:
	.string "To irritate each other?$"
gText_SelectWRI_TheTalk29:
	.string "It is like some sort of cult chant\n"
	.string "or something?$"
gText_SelectWRI_TheTalk30:
	.string "Oh, now I'm concerned, chat.$"
gText_SelectWRI_TheTalk31:
	.string "If this is something cult-like…$"
gText_SelectWRI_TheTalk32:
	.string "Like if you start breaking out\n"
	.string "Illuminati symbols or something…$"
gText_SelectWRI_TheTalk33:
	.string "Oh…$"
gText_SelectWRI_TheTalk34:
	.string "Oh no…$"
gText_SelectWRI_TheTalk35:
	.string "Oh, what have I done now…$"
gText_SelectWRI_TheTalk36:
	.string "I mean… I guess its plausable…$"
gText_SelectWRI_TheTalk37:
	.string "Like, Team Magma is a conspiracy to\n"
	.string "expand the land…$"
gText_SelectWRI_TheTalk38:
	.string "And Team Aqua… well…\n"
	.string "I'm sure you know.$"
gText_SelectWRI_TheTalk39:
	.string "So I guess a conspiracy to say\n"
	.string "SELECT as often as possible…$"
gText_SelectWRI_TheTalk40:
	.string "It's {BOLD}stupid{END} but it's not\n"
	.string "wholly impossible…$"
gText_SelectWRI_TheTalk41:
	.string "Alright, you “SELECT SECT”…$"
gText_SelectWRI_TheTalk42:
	.string "I'll play along…$"
gText_SelectWRI_TheTalk43:
	.string "As if I have a choice, what with you\n"
	.string "being in my head and all…$"
@ gText_SelectWRI_TheTalk44:
@ 	.string "SELECT {STR_VAR_1}$"
@ gText_SelectWRI_TheTalk45:
@ 	.string "SELECT {STR_VAR_1}$"
gText_SelectWRI_TheTalk46:
	.string "I wonder what my father would think\n"
	.string "of me joining a cult…$"
gText_SelectWRI_TheTalk47:
	.string "It's not like it's a big leap for me…$"
gText_SelectWRI_TheTalk48:
	.string "Oh, sorry… SELECT {STR_VAR_1}$"
@ gText_SelectWRI_TheTalk49:
@ 	.string "SELECT {STR_VAR_1}$"


EventScript_SelectWithoutRegisteredItem_EndingTable:
	.4byte gText_SelectWRI_Ending01
	.4byte gText_SelectWRI_Ending02
	.4byte gText_SelectWRI_Ending03
	.4byte gText_SelectWRI_Ending04
	.4byte gText_SelectWRI_Ending05
	.4byte gText_SelectWRI_Ending06
	.4byte gText_SelectWRI_Ending07
	.4byte gText_SelectWRI_Ending08
	.4byte gText_SelectWRI_Ending09
	.4byte gText_SelectWRI_Ending10
	.4byte gText_SelectWRI_Ending09
	.4byte 0
gText_SelectWRI_Ending01:
	.string "SELECT {STR_VAR_1}…$"
gText_SelectWRI_Ending02:
	.string "SELECT {STR_VAR_1}… …$"
gText_SelectWRI_Ending03:
	.string "SELECT {STR_VAR_1}… … …$"
gText_SelectWRI_Ending04:
	.string "Okay, guys… This is getting boring now.$"
gText_SelectWRI_Ending05:
	.string "I… I think I'm gonna stop.$"
gText_SelectWRI_Ending06:
	.string "Like this was fun but…$"
gText_SelectWRI_Ending07:
	.string "That's enough…$"
gText_SelectWRI_Ending08:
	.string "Thanks for all the memes…$"
gText_SelectWRI_Ending09:
	.string "…$"
gText_SelectWRI_Ending10:
	.string "SELECT will always be there\n"
	.string "in your heart…$"



#undef SELECT_DELAY_TIME
