AquaHideout_1F_MapScripts:: @ 8233493
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, AquaHideout_1F_OnLoad
	.byte 0

@ -----------------------------------------------------

AquaHideout_1F_OnLoad:
	call_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_OnLoad_MoveDoorGuard
	end

AquaHideout_1F_OnLoad_MoveDoorGuard:
	setobjectxyperm 2, 24, 3
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return

@ -----------------------------------------------------

AquaHideout_1F_OnTransition:
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	end

@ -----------------------------------------------------
@ Bailey

AquaHideout_1F_EventScript_Bailey:: @ 8233494
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_1F_EventScript_Bailey_PostEscape1
	goto_if_set FLAG_TEAM_AQUA_STOLE_SUBMARINE, AquaHideout_1F_EventScript_Bailey_PostHijack1
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_Bailey_PostMagma1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_Bailey_PostPyre1
	goto AquaHideout_1F_EventScript_Bailey_Initial1
	end

@ Before Mt. Pyre
AquaHideout_1F_EventScript_Bailey_Initial1:
	goto_if_set FLAG_SCENE_0, AquaHideout_1F_EventScript_Bailey_Initial2
	msgbox AquaHideout_1F_Text_Bailey_Initial1
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	release
	end
AquaHideout_1F_Text_Bailey_Initial1:
	.string "{AQUA_BOY}: Hey, {PLAYER}!\n"
	.string "Good to see you found the place.\p"
	.string "If you're looking for some action,\n"
	.string "the boss said he was heading to nab\l"
	.string "something from Mt. Pyre's summit.\p"
	.string "He could always use the backup.$"
AquaHideout_1F_EventScript_Bailey_Initial2:
	msgbox AquaHideout_1F_Text_Bailey_Initial2
	release
	end
AquaHideout_1F_Text_Bailey_Initial2:
	.string "{AQUA_BOY}: I don't know what it is\n"
	.string "that the boss might want from Mt. Pyre.\p"
	.string "But it's not unusual for him to keep\n"
	.string "us in the dark about his bigger plans.$"

@ After Mt. Pyre, go to Magma
AquaHideout_1F_EventScript_Bailey_PostPyre1:
	goto_if_set FLAG_SCENE_0, AquaHideout_1F_EventScript_Bailey_PostPyre2
	msgbox AquaHideout_1F_Text_Bailey_PostPyre1
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	release
	end
AquaHideout_1F_Text_Bailey_PostPyre1:
	.string "{AQUA_BOY}: Hey, {PLAYER}.\n"
	.string "… … … … … … …\p"
	.string "Woah, slow down, slow down!\p"
	.string "You and {AQUA_GIRL} got personally\n"
	.string "assigned a mission by the boss?!\p"
	.string "That's sweet! I think I saw {AQUA_GIRL}\n"
	.string "head downstairs a while ago.\p"
	.string "Head down there if you wanna find her.\n"
	.string "But, eh heh… A word of caution.\p"
	.string "There's a lot of guys itching for a\n"
	.string "scrap downstairs.\p"
	.string "Don't worry, no one's aiming to kill\n"
	.string "your Pokémon, but you know, don't\l"
	.string "get complacent.$"
AquaHideout_1F_EventScript_Bailey_PostPyre2:
	msgbox AquaHideout_1F_Text_Bailey_PostPyre2
	release
	end
AquaHideout_1F_Text_Bailey_PostPyre2:
	.string "{AQUA_BOY}: {AQUA_GIRL} should be\n"
	.string "downstairs.\p"
	.string "Watch our for guys looking for a\n"
	.string "friendly battle, a “scrap” fight.$"

@ After Magma, Before Slateport Hijacking
AquaHideout_1F_EventScript_Bailey_PostMagma1:
	goto_if_set FLAG_SCENE_0, AquaHideout_1F_EventScript_Bailey_PostMagma2
	msgbox AquaHideout_1F_Text_Bailey_PostMagma1
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	release
	end
AquaHideout_1F_Text_Bailey_PostMagma1:
	.string "{AQUA_BOY}: Woah, {PLAYER}!\n"
	.string "You alright? You look a bit pale.\p"
	.string "… … … … … … …\n"
	.string "Magma did WHAT?!\l"
	.string "What's a Groudon?!\p"
	.string "No, I never heard of it either!\p"
	.string "Don't worry. Just tell the boss if you\n"
	.string "see him next. I will too.\p"
	.string "Last I heard, he was off to Slateport.\p"
	.string "But you might also wanna just leave a\n"
	.string "note on his desk downstairs.\p"
	.string "If you can find his office downstairs…\n"
	.string "It's a literal maze down there.$"
AquaHideout_1F_EventScript_Bailey_PostMagma2:
	msgbox AquaHideout_1F_Text_Bailey_PostMagma2
	release
	end
AquaHideout_1F_Text_Bailey_PostMagma2:
	.string "{AQUA_BOY}: Don't worry, {PLAYER}.\n"
	.string "I'm sure things are going to plan.\p"
	.string "The boss is off in Slateport, but\n"
	.string "he should be back soon.$"

@ After Slateport Hijacking
AquaHideout_1F_EventScript_Bailey_PostHijack1:
	goto_if_set FLAG_SCENE_0, AquaHideout_1F_EventScript_Bailey_PostHijack2
	msgbox AquaHideout_1F_Text_Bailey_PostHijack1
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	release
	end
AquaHideout_1F_Text_Bailey_PostHijack1:
	.string "{AQUA_BOY}: The boss is back, {PLAYER}.\p"
	.string "He should be downstairs in the underwater\n"
	.string "docks area. You should go tell him\l"
	.string "about that Groudon Pokémon.$"
AquaHideout_1F_EventScript_Bailey_PostHijack2:
	msgbox AquaHideout_1F_Text_Bailey_PostHijack2
	release
	end
AquaHideout_1F_Text_Bailey_PostHijack2:
	.string "{AQUA_BOY}: Still didn't find him?\p"
	.string "Did you check the docks? They're on\n"
	.string "the bottommost level.$"


@ After Sub Escape
AquaHideout_1F_EventScript_Bailey_PostEscape1:
	goto_if_set FLAG_SCENE_0, AquaHideout_1F_EventScript_Bailey_PostEscape2
	msgbox AquaHideout_1F_Text_Bailey_PostEscape1
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	release
	end
AquaHideout_1F_Text_Bailey_PostEscape1:
	.string "{AQUA_BOY}: Hey, {PLAYER}.\p"
	.string "I just saw that visor kid run out of\n"
	.string "here really fast. Did you do that?\p"
	.string "Good job. You held him off long enough\n"
	.string "for the boss to get the preperations\l"
	.string "done and head out to sea.\p"
	.string "You… didn't get the chance to tell him\n"
	.string "about Groudon, did you?\p"
	.string "It's probably alright.\n"
	.string "He likely knows already anyway.\p"
	.string "Next stop is Mossdeep. You might be able\n"
	.string "to contact the boss from there.\p"
	.string "We've got a radio relay to him there.$"
AquaHideout_1F_EventScript_Bailey_PostEscape2:
	@ Check if the player has a surfer
	checkpartycapability CAPABILITY_SURF
	compare VAR_RESULT, 6
	goto_if_eq AquaHideout_1F_EventScript_Bailey_PostEscape3
	@ Normal message
	msgbox AquaHideout_1F_Text_Bailey_PostEscape2
	release
	end
AquaHideout_1F_Text_Bailey_PostEscape2:
	.string "{AQUA_BOY}: It's alright, {PLAYER}.\p"
	.string "You should head to Mossdeep. The boss\n"
	.string "directed us there to be part of his\l"
	.string "radio relay.$"
AquaHideout_1F_EventScript_Bailey_PostEscape3:
	@ Soft lock prevention
	msgbox AquaHideout_1F_Text_Bailey_PostEscape3
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq AquaHideout_1F_EventScript_Bailey_PostEscape4
	@ Give surf mon
	setvar VAR_TEMP_1, SPECIES_CARVANHA
	bufferspeciesname 0, VAR_TEMP_1
	givemon VAR_TEMP_1, 30, ITEM_NONE
	@
	playfanfare MUS_FANFA4
	message AquaHideout_1F_Text_Bailey_PostEscape3a, MSGTYPE_DESCRIBE
	waitmessage
	waitfanfare
	@ Nickname?
	.if !TPP_MODE
		msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
		compare VAR_RESULT, 0
		goto_if_eq Common_EventScript_ReleaseEnd
	.endif
	getpartysize
	copyvar VAR_0x8004, VAR_RESULT
	subvar VAR_0x8004, 1
	call Common_EventScript_NameReceivedPokemon
	release
	end
AquaHideout_1F_Text_Bailey_PostEscape3:
	.string "{AQUA_BOY}: What's up, {PLAYER}?\p"
	.string "Oh, that visor kid took out your only\n"
	.string "surfing Pokémon, huh?\p"
	.string "Well, um… I can give you one of mine.\n"
	.string "Just caught this little guy myself.\p"
	.string "Here, take good care of it.$"
AquaHideout_1F_Text_Bailey_PostEscape3a:
	.string "{PLAYER} scored a free {STR_VAR_1}!$"
AquaHideout_1F_EventScript_Bailey_PostEscape4:
	msgbox AquaHideout_1F_Text_Bailey_PostEscape3b
	release
	end
AquaHideout_1F_Text_Bailey_PostEscape3b:
	.string "How do you have no room??$"


@ -----------------------------------------------------
@ Grunts

AquaHideout_1F_EventScript_DoorGuard:: @ 82334C6
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334EE
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334E4
	msgbox AquaHideout_1F_Text_233739
	release
	end
AquaHideout_1F_Text_233739: @ 8233739
	.string "Sup, {PLAYER_dude}. Everyone kinda went\n"
	.string "down to help the boss at Mt. Pyre.\p"
	.string "Since no one's here, they're remodelling\n"
	.string "some things downstairs.\p"
	.string "Something about installing teleporters\n"
	.string "so it's easier to get around?\p"
	.string "It is kinda a maze down there,\n"
	.string "so this should help, maybe.$"
AquaHideout_1F_EventScript_2334E4:: @ 82334E4
	msgbox AquaHideout_1F_Text_2337FA
	release
	end
AquaHideout_1F_Text_2337FA: @ 82337FA
	.string "I hear that Team Magma is after\n"
	.string "some powerful Pokémon at Mt. Chimney.\p"
	.string "I wonder what kind of Pokémon it is.$"
AquaHideout_1F_EventScript_2334EE:: @ 82334EE
	msgbox AquaHideout_1F_Text_233884
	release
	end
AquaHideout_1F_Text_233884: @ 8233884
	.string "There's a bunch of other guys downstairs\n"
	.string "who will want to scrap fight with you.\p"
	.string "Why don't you head down and say hi?$"



AquaHideout_1F_EventScript_Scrappy1:: @ 82334F8
	lock
	faceplayer
	markasdialog
	checktrainerflag TRAINER_GRUNT_1
	goto_if_eq AquaHideout_1F_EventScript_Scrappy1_Lost
	setyesnotext gYN_Sure, gYN_Later
	msgbox AquaHideout_1F_Text_23393D, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq AquaHideout_1F_EventScript_Scrappy1_Fight
	msgbox AquaHideout_1F_Text_23393G
	release
	end
AquaHideout_1F_Text_23393D:
	.string "Ayi! Dude! I'm itching for a fight!\p"
	.string "You wanna scrap? I'll go easy on\n"
	.string "yer 'mon, promise!$"
AquaHideout_1F_Text_23393G:
	.string "Awwww, com'on!\n"
	.string "I gotta scratch this itch!$"
AquaHideout_1F_EventScript_Scrappy1_Fight:
	msgbox AquaHideout_1F_Text_23393E
	setflag FLAG_DEATH_PREVENT
	setflag FLAG_DEATH_PREVENT_1HP
	trainerbattle_no_intro TRAINER_GRUNT_1, AquaHideout_1F_Text_233964
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	release
	end
AquaHideout_1F_Text_23393E:
	.string "Yiah! Let's gooooooo!$"
AquaHideout_1F_Text_233964: @ 8233964
	.string "Yoooo…\n"
	.string "I lost it!$"
AquaHideout_1F_EventScript_Scrappy1_Lost:
	msgbox AquaHideout_1F_Text_233977
	release
	end
AquaHideout_1F_Text_233977:
	.string "Well, I'm all out of fight now.\n"
	.string "Thanks.$"

