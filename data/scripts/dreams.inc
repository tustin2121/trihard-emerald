@[0100]- Triggered by dad leaving for work
@[0150]- Triggered by first entering Rustboro
@[0200]- Triggered by completing Aqua Fetch Quest
@[0300]- Triggered by completing Museum Heist
@[0400]- Triggered by defeating rival in Route 110
@[    ]- Triggered by beating Magma in Meteor Falls
@[    ]- Triggered by getting Strength (Rusturf Tunnel)
@[    ]- Triggered by defeating the grunt in Meteor Falls
@[0500]- Triggered by defeating Flannery
@[0900]- Triggered by surfing for the first time
@[    ]- Triggered by starting the Weather Institute invasion
@[    ]- Triggered by first entering Route 120
@[    ]- Triggered by completing the Mr. Pyre 
@[    ]- Triggered by first entering Aqua Hideout B1F
@[    ]- Triggered by completing Space Center Rescue
@[1000]- Triggered by the rains cutscene, required location Mossdeep
@[    ]- Triggered by getting defeated by the legendaries
@[    ]- Triggered by defeating Logan

DreamScript_CantSleep::
	delay 30
	message DreamScript_CantSleep_Text1
	waitmessage
	closemessage
	delay 90
	return
DreamScript_CantSleep_Text1:
	.string "You toss and turn all night…\p"
	.string "There's no way to sleep with those\n"
	.string "giant beasts fighting outside…\p$"


@------------------------------------------------------
@ Triggered by dad leaving for work
DreamScript_0100::
	fadenewbgm MUS_B_DOME1
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0100_Text1
	waitmessage
	closemessage
	delay 90
	fadedefaultbgm
	return
	@ Mom and dad arguing with each other
	@ Dad: "How could you let this happen?!"
	@ Mom: "Me?! It's not my fault you're never around!!"
	@ Dad: "Oh yeah, ms spend all my money drinking with friends"
	@ Mom: 
	@ Player wakes up in a cold sweat
DreamScript_0100_Text1:
	.string "{FORCE_SPEED_SLOW}… … …{PAUSE 40}{RESET_SPEED}\p"
	.string "{MAN_SPEAKING}"
	.string "…Pathetic!{PAUSE 20} … …You're the\n"
	.string "poster child of a bad trainer… …!{END}{PAUSE 30}\p"
	.string "{FORCE_SPEED_SLOW}… … …{PAUSE 40}{RESET_SPEED}\p"
	.string "{WOMAN_SPEAKING}"
	.string "Uncle! {PLAYER_Their} {POKEMON}!{PAUSE 20}\n"
	.string "What happened to it?!{PAUSE 30}\p"
	.string "{MAN_SPEAKING}"
	.string "Wha--?! Acerola, some potions, quick!{PAUSE 20}\n"
	.string "What did you do to this poor thing?!\p"
	.string "… … You don't deserve to be a trainer… …{END}{PAUSE 40}\n"
	.string "… … a trainer…{PAUSE 30} {COLOR LIGHT_GREY}… … a trainer…{END}\p"
	.string "{SET_NORM_PAL}{PLAY_BGM MUS_DUMMY}{PLAY_SE SE_MU_PACHI}"
	.string "GASP!{PAUSE 30}\n"
	.string "You sit bolt upright in bed…\p"
	.string "{FORCE_SPEED_SLOW}… … … …{PAUSE 30}{RESET_SPEED}\n"
	.string "It was just a dream… …{PAUSE 30}\l"
	.string "…just a dream…\p"
	.string "$"

@------------------------------------------------------
@ Triggered by first entering Rustboro
DreamScript_0150::
	@ A tale of Skull pulling a prank of some sort on someone
	@ Being all tough and getting money to live on...
	fadenewbgm MUS_TONEKUSA
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0150_Text1
	setyesnotext gYN_Elipsis2, DreamScript_0150_YN_Weep
	waitmessage
	yesnobox 20, 8
	message DreamScript_0150_Text2
	waitmessage
	fadenewbgm MUS_DUMMY
	message DreamScript_0150_Text3
	waitmessage
	closemessage
	delay 90
	fadedefaultbgm
	return
DreamScript_0150_Text1:
	.string "{FORCE_SPEED_MID}"
	.string "The cloudless sky…{PAUSE 50}\n"
	.string "{CLEAR_TO 0x40}The sea-salt breeze…{PAUSE 50}\l"
	.string "Arguing from the house behind you…{PAUSE 20}\p"
	.string "You look down at the empty Pokéball…{PAUSE 50}\n"
	.string "The broken challenge amulet…{PAUSE 20}\p"
	.string "{MAN_SPEAKING}{RESET_SPEED}"
	.string "AND STAY OUT OF MY SHOP!{END}{PAUSE 30}\n"
	.string "This from town ahead.{PAUSE 20}\p"
	.string "Two grunts in black and white…{PAUSE 50}\n"
	.string "They laugh about their petty theft…{PAUSE 30}\p"
	.string "{WOMAN_SPEAKING}"
	.string "Ey yo! He was ticked! Ha ha!{PAUSE 30}\n"
	.string "Toss me some'a dat score, yo!{END}\p"
	.string "The other one looks at you, and pulls\n"
	.string "down {RIVAL_their} bandana.\p"
	.string "{ALEX_SPEAKING}"
	.string "Yo, {PLAYER_dude}… You good?"
	.string "$"
DreamScript_0150_YN_Weep:
	.string "(cry)$"
DreamScript_0150_Text2:
	.string "{RIVAL_They} tosses a bag of chips at you\n"
	.string "and sits next to you.\p"
	.string "{ALEX_SPEAKING}"
	.string "Let it out, {PLAYER_bro}…{PAUSE 50}\n"
	.string "Team Skull's got your back, yo…{PAUSE 20}\p"
	.string "{END}$"
DreamScript_0150_Text3:
	.string "{PAUSE 50}{SET_NORM_PAL}"
	.string "You awaken in bed, crying…{PAUSE 50}\n"
	.string "Good thing no one's around to see…{PAUSE 50}\p"
	.string "$"

@------------------------------------------------------
@ Triggered by completing Aqua Fetch Quest
DreamScript_0200::
	fadenewbgm MUS_DUMMY
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ "At it again..."
	message DreamScript_0200_Text1
	waitmessage
	fadenewbgm MUS_KAKKOII
	@ "Always..."
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0200_Text2
	setyesnotext DreamScript_0200_YN_ShutUp, DreamScript_0200_YN_Stop
	waitmessage
	yesnobox 20, 8
	@ "Escape..."
	fadenewbgm MUS_TONEKUSA
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0200_Text3
	setyesnotext gYN_Elipsis2, gYN_Maybe
	waitmessage
	yesnobox 20, 8
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
	@ The player is getting inducted into Team Skull in Po Town
	@ Player meets Alex for the first time ["Hey..."/"..."]
	@ She waves
	@ {RIVAL_ALOLA} {RIVAL_they}
DreamScript_0200_Text1:
	.string "They're at it again…\p$"
DreamScript_0200_Text2:
	.string "You can hear them through the walls…\p"
	.string "It's about you.{PAUSE 30}\n"
	.string "Of course it is.{PAUSE 20} It always is.\p"
	.string "{MAN_SPEAKING}"
	.string "How could you let this happen?!{PAUSE 30}\p"
	.string "{WOMAN_SPEAKING}"
	.string "Me?! It's not my fault you're never\n"
	.string "around! Always at work!{PAUSE 30}\p"
	.string "{MAN_SPEAKING}"
	.string "Oh, and where are you?!{PAUSE 20} Always out\n"
	.string "with your friends, aren't you?!\p"
	.string "{END}"
	.string "The yelling…{PAUSE 30}\n"
	.string "Always the yelling…{PAUSE 30}"
	.string "$"
DreamScript_0200_YN_ShutUp:
	.string "SHUT UP!$"
DreamScript_0200_YN_Stop:
	.string "STOP!$"
DreamScript_0200_Text3:
	.string "You escape out the window again.\n"
	.string "Just to get away…\p"
	.string "{RIVAL_They}'s there on the corner…\n"
	.string "As always…\p"
	.string "{ALEX_SPEAKING}"
	.string "Guzma's not nearly as bad\n"
	.string "as them, ya know?\p"
	.string "You sure you don't wanna come with?{PAUSE 30}"
	.string "$"

@------------------------------------------------------
@ Triggered by completing Museum Heist
DreamScript_0300::
	fadenewbgm MUS_B_DOME
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0300_Text1
	setyesnotext gYN_YeahStutter, DreamScript_0300_YN_Thanks
	waitmessage
	yesnobox 18, 8
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
	@ Dream of a time with Team Skull and the comraderie had therein
	return
DreamScript_0300_Text1:
	.string "{MAN_SPEAKING}"
	.string "{PAUSE 60}Tch!{END}{PAUSE 60}\n"
	.string "That wicked smile split his face.\p"
	.string "{MAN_SPEAKING}"
	.string "The hated boss who beats you down, and\n"
	.string "beats you down, and never let's up…\l"
	.string "Yeah! Big bad Guzma is here!{END}\p"
	.string "He looks down on you, hands on hips,\n"
	.string "from atop his throne.\p"
	.string "{ALEX_SPEAKING}"
	.string "Yo, boss. We got another here.\p"
	.string "{MAN_SPEAKING}"
	.string "That blowhard kicked you from the\n"
	.string "island challenge?\l"
	.string "Man, it ain't worth nothing.\p"
	.string "Yer 'rents fightin' too? Tch! You'll\n"
	.string "fit right in with the other idiots!\p"
	.string "Yo! Get this kid a hat an' tank!\n"
	.string "{PAUSE 30}{PLAY_SE SE_KOUKA_M}NOW!{PAUSE 20}\p"
	@ .string "{PAUSE 30}{PLAY_SE SE_W233B}NOW!\p"
	.string "{END}Other grunts dash from the room\n"
	.string "at once, scared of Guzma.\p"
	.string "You look over at {RIVAL_them}.\n"
	.string "{RIVAL_They}'s got a self-satisfied grin.\p"
	.string "{ALEX_SPEAKING}"
	.string "Told ya."
	.string "$"
DreamScript_0300_YN_Thanks:
	.string "Thanks {RIVAL_ALOLA}…$"
	
@------------------------------------------------------
@ Triggered by defeating rival in Route 110
DreamScript_0400::
	fadenewbgm MUS_AQA_0
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0400_Text1
	setyesnotext DreamScript_0400_YN_Later, DreamScript_0400_YN_Divorce
	waitmessage
	yesnobox 11, 8
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
	@ Player's battle with Nanu, followed by the death of his starter...
	@ N: "Come on, you can do better than that!"
	@ N: "You're the poster child for bad trainer! You're temper will get you nowhere!"
	@ N: "Pathetic! You called that a battle? You barely--"
	@ A: "Uncle! His pokemon! What happened to it?!"
	@ N: "Wha--?! Acerola, some potions, quick!"
	@ A: "What did you do to this poor thing?! How could you be so mean to take out your anger on this poor thing?!"
	@ ["He started it!"/"Nanu taunted me!"]
	@ N: "You dare blame me for your anger issues?!"
	@ N: "You don't deserve to be a trainer..."
	@ "The sound of the amulet snapping catapults you awake..."
	return
DreamScript_0400_Text1:
	.string "{MAN_SPEAKING}{PAUSE 60}"
	.string "Yo! You go hard on your {POKEMON}!{PAUSE 20}\n"
	.string "That's the 6th battle today you won!{PAUSE 20}\p"
	.string "{WOMAN_SPEAKING}"
	.string "This {PLAYER_dude} be trippin', yo!{PAUSE 20}\n"
	.string "We gotta get {PLAYER_them} on a job!{PAUSE 20}{END}\p"
	.string "{RIVAL_ALOLA} comes over and taps your fist,\n"
	.string "giving you a side eye.{PAUSE 20}\p"
	.string "You've been clenching so hard,\n"
	.string "your nails drew blood again.{PAUSE 40}\p"
	.string "{RIVAL_They} looks at you, concerned…{PAUSE 40}\n"
	.string "{ALEX_SPEAKING}"
	.string "Talk to me…{PAUSE 40}"
	.string "$"
DreamScript_0400_YN_Later:
	.string "I'll tell you later…$"
DreamScript_0400_YN_Divorce:
	.string "They mentioned divorce…$"
	
@------------------------------------------------------
@ Triggered by defeating Flannery
DreamScript_0500::
	fadenewbgm MUS_MABOROSI @TODO
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ "Sure?"
	message DreamScript_0500_Text1
	setyesnotext gYN_Yep_, gYN_Duh
	waitmessage
	yesnobox 20, 8
	@ "Sure?"
	message DreamScript_0500_Text2
	setyesnotext gYN_Yeah, gYN_Elipsis2
	waitmessage
	yesnobox 20, 8
	@ "How do you feel?"
	message DreamScript_0500_Text3
	setyesnotext gYN_Ugh, gYN_Fine1
	waitmessage
	yesnobox 20, 8
	@ "Good to talk"
	message DreamScript_0500_Text3
	setyesnotext gYN_Elipsis2, gYN_No_
	waitmessage
	yesnobox 20, 8
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
	@ Player talks about his parent's divorce with Alex
	@ She gives some insight
	return
DreamScript_0500_Text1:
	.string "{RIVAL_They} throws another rock into the surf.\n"
	.string "You lay in the sand and stare at clouds.\p"
	.string "{ALEX_SPEAKING}"
	.string "You're sure they're getting divorced?$"
DreamScript_0500_Text2:
	.string "{ALEX_SPEAKING}"
	.string "Like you saw the papers? And your\n"
	.string "dad's staying at a hotel now?{END}$"
DreamScript_0500_Text3:
	.string "{RIVAL_ALOLA} comes over and sits beside\n"
	.string "you in the sand, taking your hand.\p"
	.string "{ALEX_SPEAKING}"
	.string "And… how do you feel about that?$"
DreamScript_0500_Text4:
	.string "{ALEX_SPEAKING}"
	.string "I know you don't like talking about\n"
	.string "your feelings and all, but…{END}\p"
	.string "{RIVAL_They} plays with your fingers.\n"
	.string "{ALEX_SPEAKING}"
	.string "Plumeria says it's good to talk.{END}\p"
	.string "{RIVAL_They} looks down at you.\n"
	.string "{ALEX_SPEAKING}"
	.string "You okay?"
	.string "$"
	
@------------------------------------------------------
@ Triggered after helping team Aqua at the volcano
DreamScript_0700::
	@
	return
DreamScript_0700_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered after beating Flannery's gym
DreamScript_0800::
	@ 
	return
DreamScript_0800_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered after having surfed for the first time
DreamScript_0900::
	fadenewbgm MUS_M_BOAT
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_0900_Text1
	waitmessage
	closemessage
	delay 90
	fadedefaultbgm
	return
	@ Player is watching Alex surf a big wave.
	@ Player attempts to do it also and falls in, jumping awake
	return
DreamScript_0900_Text1:
	.string "{FORCE_SPEED_MID}"
	.string "{RIVAL_ALOLA} paddles out to sea\n"
	.string "in front of you.\p"
	.string "The waves{PLAY_SE SE_W057} are big today.\n"
	.string "And you're ready this time…\p"
	.string "{RIVAL_ALOLA} takes{PLAY_SE SE_W057} the wave…\n"
	.string "Stands upright… {RIVAL_They}'s riding high…\p"
	.string "You find a good{PLAY_SE SE_W057} swell…\n"
	.string "It starts to crest…\l"
	.string "You begin to{PLAY_SE SE_W056} stand up, keeping balance…\p"
	.string "You adjust yourself, step forward,{PLAY_SE SE_W250} and\n"
	.string "miss y"
	.string "{SET_NORM_PAL}{PLAY_BGM MUS_DUMMY}{PLAY_SE SE_W291}{RESET_SPEED}"
	.string        "our step and jump awake!\p"
	.string "… … … …{PAUSE 30}\n"
	.string "Hoenn's waves aren't nearly as big…\p"
	.string "$"
	
@------------------------------------------------------
@ Triggered by the rains cutscene, required location Mossdeep
DreamScript_1000::
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_1000_Text1
	waitmessage
	fadenewbgm MUS_OOAME
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_1000_Text2
	waitmessage
	closemessage
	delay 90
	fadedefaultbgm
	return
DreamScript_1000_Text1:
	.string "Between the pounding rain on the roof\n"
	.string "and {AQUA_BOY}'s loud singing outside,\l"
	.string "you're finding it difficult to sleep.\p$"
DreamScript_1000_Text2:
	.string "Eventually, though…"
	.string "{PAUSE 30}{SET_DREAM_PAL}{PAUSE 20}"
	.string                     " You find\n"
	.string "yourself in the pouring rain again…\p"
	.string "{AQUA_BOY} and {AQUA_GIRL} are throwing\n"
	.string "their bandannas to the ground…\p"
	.string "You go to throw yours as well…\n"
	.string "And {RIVAL_ALOLA} is there too…\p"
	.string "{RIVAL_They} throws her bandanna to the\n"
	.string "ground and stomps on it.\p"
	.string "{RIVAL_They} looks at you expectantly…\n"
	.string "You clutch your bandanna tighter…\p"
	.string "You're alone in the rain again…\p"
	.string "{SET_NORM_PAL}{PLAY_BGM MUS_DUMMY}"
	.string "{AQUA_BOY}: Com'on, guys! One more time!\p"
	.string "{AQUA_BOY} launches once more into an\n"
	.string "obnoxious song. You roll over.\p"
	.string "$"
	
@------------------------------------------------------
@ Triggered upon finishing the Weather Institute event
DreamScript_1100::
	@ Alex questioning what the deal is with Luisamine
	@ And how they're always doing her dirty work inexplicably
	@ Possibly Palmera is involved or spoken about
	return
DreamScript_1100_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered after the Mt. Pyre event
DreamScript_1200::
	@ 
	return
DreamScript_1200_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered after entering Aqua hideout BF1 for the first time
DreamScript_1300::
	@ Player is caught in the middle of another argument and
	@ bolts to go see Alex in Po Town, hang out in Po Town
	return
DreamScript_1300_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered 
DreamScript_1400::
	@
	return
DreamScript_1400_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered after the space institute custscene
DreamScript_1500::
	@ Alex has told the player she's leaving Team Skull
	@ Player tries to object
	@ Alex says that if player actually cared, he'd leave too, before things get bad
	return
DreamScript_1500_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered after Team Aqua disbands
DreamScript_1600::
	@ Alex is crying, the player having just told her that he's being forcibly moved to Hoenn
	@ 
	return
DreamScript_1600_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------





@------------------------------------------------------
DreamScript_Dummy:
	.string "Dad's advice…\n"
	.string "{PLAYER}, there's a time and place for\l"
	.string "everything!{PAUSE_UNTIL_PRESS}"
	
	.string "Mom's advice…\n"
	.string "Remember, blood is thicker than water,\l"
	.string "but blood doesn't quench thirst!\l"
	.string "What do we think, ladies? Martinis?{PAUSE_UNTIL_PRESS}"
	
	.string "$"
	