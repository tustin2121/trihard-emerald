@[0100]- Triggered by dad leaving for work
@[0150]- Triggered by first entering Rustboro
@[0200]- Triggered by completing Aqua Fetch Quest
@[0300]- Triggered by completing Museum Heist
@[0400]- Triggered by defeating rival in Route 110
@[    ]- Triggered by beating Magma in Meteor Falls
@[080X]- Triggered by getting Strength (Rusturf Tunnel)
@[0500]- Triggered by defeating Flannery
@[0900]- Triggered by surfing for the first time
@[    ]- Triggered by starting the Weather Institute invasion
@[0700]- Triggered by first entering Route 120
@[    ]- Triggered by completing the Mt. Pyre event
@[    ]- Triggered by first entering Aqua Hideout B1F
@[0600]- Triggered by completing Space Center Rescue
@[100X]- Triggered by the rains cutscene, required location Mossdeep
@[    ]- Triggered by getting defeated by the legendaries
@[    ]- Triggered by defeating Logan

DreamScript_CantSleep:: @done
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
DreamScript_0100::  @done
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
DreamScript_0150:: @done
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
	.string "The arguing from the house behind you…{PAUSE 20}\p"
	.string "You look down at the empty Pokéball…{PAUSE 50}\n"
	.string "The broken challenge amulet…{PAUSE 20}\p"
	.string "{MAN_SPEAKING}{RESET_SPEED}"
	.string "AND STAY OUT OF MY SHOP!{END}{PAUSE 30}\n"
	.string "Someone shouted from the town ahead.{PAUSE 20}\p"
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
	.string "{FORCE_SPEED_MID}"
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
DreamScript_0200:: @done
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
DreamScript_0300::  @done
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
	.string "beats you down, and never lets up…\l"
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
DreamScript_0400::  @done
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
DreamScript_0500:: @done
	fadenewbgm MUS_RG_SANTOAN @TODO
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
	message DreamScript_0500_Text4
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
	.string "{PAUSE 30}{RIVAL_They} throws another rock into the surf.\n"
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
@ Triggered by completing Space Center Rescue
DreamScript_0600:: @done
	fadenewbgm MUS_KAKKOII @TODO
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ "Something is happening!"
	message DreamScript_0600_Text1
	setyesnotext DreamScript_0600_YN_Crazy, DreamScript_0600_YN_Refusal
	waitmessage
	yesnobox 18, 8
	@ "Kidnapping!!"
	message DreamScript_0600_Text2
	setyesnotext DreamScript_0600_YN_Fine, DreamScript_0600_YN_Refusal
	waitmessage
	yesnobox 17, 8
	@ "You're fine with this?!"
	message DreamScript_0600_Text3
	setyesnotext DreamScript_0600_YN_Guzma, DreamScript_0600_YN_Why
	waitmessage
	yesnobox 18, 8
	@ stomp, stalk off
	message DreamScript_0600_Text4
	setyesnotext DreamScript_0600_YN_Alex, DreamScript_0600_YN_Guzma
	waitmessage
	yesnobox 18, 8
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
DreamScript_0600_Text1:
	.string "{ALEX_SPEAKING}"
	.string "{PAUSE 30}{PLAYER}!{PAUSE 30} Can't you see?!{PAUSE 30}\n"
	.string "Something is happening to Team Skull!{PAUSE 20}$"
DreamScript_0600_YN_Crazy:
	.string "You're crazy!$"
DreamScript_0600_YN_Refusal:
	.string "No it's not!$"
DreamScript_0600_Text2:
	.string "{ALEX_SPEAKING}"
	.string "Kidnapping, {PLAYER}!{PAUSE 20} Kidnapping!{PAUSE 20}\n"
	.string "They want us to kidnap a girl!\p"
	.string "Guzma has never asked us to do\n"
	.string "something like this before!{END}\p"
	.string "{RIVAL_They} was pacing agitatedly. {RIVAL_They}'s\n"
	.string "never seemed this stressed before.\p"
	.string "{ALEX_SPEAKING}"
	.string "Graffiti, sure.{PAUSE 20} Petty theft, fine.{PAUSE 20}\n"
	.string "Property damage, of course.{PAUSE 20}\l"
	.string "Those are all just being a nuisance!\p"
	.string "But this?! Kidnapping!?\n"
	.string "It's too dangerous!\p"
	.string "Someone could get hurt, {PLAYER}!\n"
	.string "We don't want to hurt nobody!$"
	.string "$"
DreamScript_0600_YN_Fine:  @ no. it's not /
	.string "It'll be fine!$"
DreamScript_0600_Text3:
	.string "{RIVAL_ALOLA} looks at you with wide eyes.\p"
	.string "{ALEX_SPEAKING}"
	.string "{P_PLAYER}…{PAUSE 20} Wha-?{PAUSE 20}\n"
	.string "Y-You're actually…{PAUSE 20} FINE with this?!$"
DreamScript_0600_YN_Guzma:
	.string "Guzma said…$"
DreamScript_0600_YN_Why:
	.string "Why not?$"
DreamScript_0600_Text4:
	.string "{RIVAL_ALOLA} looks away as you speak.{PAUSE 30}\n"
	.string "{ALEX_SPEAKING}"
	.string "And I thought I knew you…{END}\p"
	.string "{RIVAL_They} takes off her Skull bandanna and\n"
	.string "tosses it on the ground!{PAUSE 30} And stomps it!\p"
	.string "You stare in shock,\n"
	.string "as {RIVAL_they} stalks away…$"
DreamScript_0600_YN_Alex:
	.string "{RIVAL_ALOLA}…$" @ "Guzma said…"
	.string "$"
	
@------------------------------------------------------
@ Triggered by first entering Route 120
DreamScript_0700::
	@ I would have just the sound of the surf here, if that were possible
	fadenewbgm MUS_BIJYUTU @TODO
	delay 60
	setvar VAR_0x800B, 0
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ Arrive, skull broke up
	message DreamScript_0700_Text1
	waitmessage
DreamScript_0700_loop1:
	setyesnotext DreamScript_0700_YN1, gYN_Elipsis3
	yesnobox 12, 8
	compare VAR_RESULT, YES
	goto_if_eq DreamScript_0700_next2
	@ if no, loop
	selectpointer_clamp DreamScript_0700_AltTable, VAR_0x800B
	message 0
	waitmessage
	addvar VAR_0x800B, 1
	goto DreamScript_0700_loop1
	
DreamScript_0700_next2:
	@ disbanded
	message DreamScript_0700_Text2
	waitmessage
DreamScript_0700_loop2:
	setyesnotext DreamScript_0700_YN2, gYN_Elipsis3
	yesnobox 12, 8
	compare VAR_RESULT, YES
	goto_if_eq DreamScript_0700_next3
	@ if no, loop
	selectpointer_clamp DreamScript_0700_AltTable, VAR_0x800B
	message 0
	waitmessage
	addvar VAR_0x800B, 1
	goto DreamScript_0700_loop2
	
DreamScript_0700_next3:
	@ divorce
	message DreamScript_0700_Text3
	waitmessage
DreamScript_0700_loop3:
	setyesnotext DreamScript_0700_YN3, gYN_Elipsis3
	yesnobox 12, 8
	compare VAR_RESULT, YES
	goto_if_eq DreamScript_0700_next4
	@ if no, loop
	selectpointer_clamp DreamScript_0700_AltTable, VAR_0x800B
	message 0
	waitmessage
	addvar VAR_0x800B, 1
	goto DreamScript_0700_loop3
	
DreamScript_0700_next4:
	@ moving away
	message DreamScript_0700_Text4
	waitmessage
DreamScript_0700_loop4:
	setyesnotext DreamScript_0700_YN4, gYN_Elipsis3
	yesnobox 11, 8
	compare VAR_RESULT, YES
	goto_if_eq DreamScript_0700_next5
	@ if no, loop
	selectpointer_clamp DreamScript_0700_AltTable, VAR_0x800B
	message 0
	waitmessage
	addvar VAR_0x800B, 1
	goto DreamScript_0700_loop4
	
DreamScript_0700_next5:
	@ taking me
	message DreamScript_0700_Text5
	waitmessage
DreamScript_0700_loop5:
	setyesnotext DreamScript_0700_YN5, gYN_Elipsis3
	yesnobox 11, 8
	compare VAR_RESULT, YES
	goto_if_eq DreamScript_0700_next6
	@ if no, loop
	selectpointer_clamp DreamScript_0700_AltTable, VAR_0x800B
	message 0
	waitmessage
	addvar VAR_0x800B, 1
	goto DreamScript_0700_loop5
	
DreamScript_0700_next6:
	@ leaving tomorrow
	message DreamScript_0700_Text6
	waitmessage
DreamScript_0700_loop6:
	setyesnotext DreamScript_0700_YN6, gYN_Elipsis2
	yesnobox 12, 8
	compare VAR_RESULT, YES
	goto_if_eq DreamScript_0700_next7
	@ if no, loop
	selectpointer_clamp DreamScript_0700_AltTable, VAR_0x800B
	message 0
	waitmessage
	addvar VAR_0x800B, 1
	goto DreamScript_0700_loop6
	
DreamScript_0700_next7:
	@ "Do you want to go?"
	message DreamScript_0700_Text7
	waitmessage
	setyesnotext gYN_No_, gYN_Elipsis3
	yesnobox 20, 8
	@ Hug?
	message DreamScript_0700_Text8
	waitmessage
	setyesnotext DreamScript_0700_YN7a, DreamScript_0700_YN7b
	yesnobox 20, 8
	@ Split on answer
	selectyesnoanswer DreamScript_0700_Text9a, DreamScript_0700_Text9b
	message 0
	fadenewbgm MUS_DUMMY
	waitmessage
	closemessage
	@ enable the call from Alex
	setflag FLAG_ENABLE_ALEX_FIRST_CALL
	delay 120
	fadedefaultbgm
	return
DreamScript_0700_Text1:
	.string "{PAUSE 30}You finally find {RIVAL_ALOLA} on the beach.{PAUSE 20}\n"
	.string "It's been weeks since you last saw {RIVAL_them}.{PAUSE 20}\p"
	.string "{RIVAL_They} doesn't look up as you approach…{PAUSE 20}\n"
	.string "just stares over the darkening ocean.{PAUSE 20}$"
DreamScript_0700_YN1:
	.string "Team Skull broke up.$"
DreamScript_0700_Text2:
	.string "{RIVAL_Their} eyebrows raise slightly at the news.\n"
	.string "{RIVAL_They} doesn't seem surprised.{PAUSE 30}$"
DreamScript_0700_YN2:
	.string "Guzma disbanded us.$"
DreamScript_0700_Text3:
	.string "{RIVAL_They} huffs a tiny laugh, like it was\n"
	.string "some sort of unfunny joke.{PAUSE 30}$"
DreamScript_0700_YN3:
	.string "The divorce finalized.$"
DreamScript_0700_Text4:
	.string "{RIVAL_They} sighs, {RIVAL_their} eyes ever on the horizon.{PAUSE 30}$"
DreamScript_0700_YN4:
	.string "My dad's moving away.$"
DreamScript_0700_Text5:
	.string "{RIVAL_They} scratches {RIVAL_their} nose.{PAUSE 20}\n"
	.string "Biggest reaction out of {RIVAL_them} yet.{PAUSE 30}$"
DreamScript_0700_YN5:
	.string "He's taking me with him.$"
DreamScript_0700_Text6:
	.string "{RIVAL_Their} head finally turns halfway towards\n"
	.string "you, {RIVAL_their} eyebrows hinting at fear.\p"
	.string "{ALEX_SPEAKING}"
	.string "Oh.{END}{PAUSE 30}$"
DreamScript_0700_YN6:
	.string "We leave tomorrow.$"
DreamScript_0700_Text7:
	.string "{ALEX_SPEAKING}"
	.string "… … …{PAUSE 30} Is he…{PAUSE 40}\n"
	.string "Do you…{PAUSE 30} want to go?{PAUSE 20}$" @ "No"/"..."
DreamScript_0700_Text8:
	.string "{RIVAL_ALOLA} stands up, brushing sand off\n"
	.string "{RIVAL_their}self, and turns to you.\p"
	.string "{ALEX_SPEAKING}"
	.string "Then, I guess…{PAUSE 30} This is…{PAUSE 30}\n"
	.string "Goodbye…?{END}\p"
	.string "{RIVAL_They} sheepishly holds {RIVAL_their} hands out\n"
	.string "expectantly…{PAUSE 20}$"
DreamScript_0700_YN7a:
	.string "(hug)$"
DreamScript_0700_YN7b:
	.string "(don't)$"
DreamScript_0700_Text9a:
	.string "You stand there, hands in pockets.\n"
	.string "You nod slightly.\p"
	.string "{RIVAL_They} wraps {RIVAL_their} arms around you tightly.\n"
	.string "A warm feeling washes over you.\p"
	.string "You break away, hoping {RIVAL_they} doesn't see\n"
	.string "you wipe tears away as you leave.{PAUSE 20}\p$"
DreamScript_0700_Text9b:
	.string "You turn away from {RIVAL_them}. Too much has\n"
	.string "transpired to just forgive so easily.\p"
	.string "{ALEX_SPEAKING}"
	.string "{PLAYER}…!{END}\p"
	.string "You sulk away, not even looking back.\p"
	.string "You regret it for the rest of the night…{PAUSE 20}\n"
	.string "and the whole plane ride out of Alola…{PAUSE 20}\p$"
	.string "$"

.align 2
DreamScript_0700_AltTable:
	.4byte DreamScript_0700_TextAlt1
	.4byte DreamScript_0700_TextAlt2
	.4byte DreamScript_0700_TextAlt3
	.4byte DreamScript_0700_TextAlt4
	.4byte DreamScript_0700_TextAlt5
	.4byte DreamScript_0700_TextAlt6
	.4byte DreamScript_0700_TextAlt7
	.4byte 0
DreamScript_0700_TextAlt1:
	.string "You wish {RIVAL_they} would turn to look at you.{PAUSE 20}\n"
	.string "{RIVAL_Their} eyes stay on the horizon.{PAUSE 30}$"
DreamScript_0700_TextAlt2:
	.string "You sigh at the heavens in frustration.{PAUSE 20}\n"
	.string "The stars get brighter overhead.{PAUSE 30}$"
DreamScript_0700_TextAlt3:
	.string "{RIVAL_ALOLA} shoves around the sand a bit.{PAUSE 20}\n"
	.string "You gotta get this off your chest…{PAUSE 30}$"
DreamScript_0700_TextAlt4:
	.string "The last remnants of sunlight finally\n"
	.string "vanish from the mountaintop.{PAUSE 30}$"
DreamScript_0700_TextAlt5:
	.string "You sigh, and wish {RIVAL_they} would do\n"
	.string "the talking here…{PAUSE 30}$"
DreamScript_0700_TextAlt6:
	.string "Why doesn't {RIVAL_they} apologize?{PAUSE 20} {RIVAL_They}'s the\n"
	.string "one that abandoned you, after all…{PAUSE 30}$"
DreamScript_0700_TextAlt7:
	.string "You plead to the guardian deities of\n"
	.string "Alola to give you strength…{PAUSE 30}$"
	

@------------------------------------------------------
@ Triggered by getting Strength (Rusturf Tunnel)
DreamScript_0800:: @done
	fadenewbgm MUS_RUNECITY @TODO
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ "Making out!"
	message DreamScript_0800_Text1
	setyesnotext DreamScript_0800_YN_Really, DreamScript_0800_YN_Again
	waitmessage
	yesnobox 20, 8
	@ mouthing
	message DreamScript_0800_Text2
	setyesnotext DreamScript_0800_YN_What, DreamScript_0800_YN_Huh
	waitmessage
	yesnobox 20, 8
	@ more mumbling
	message DreamScript_0800_Text3
	setyesnotext DreamScript_0800_YN_Huh, DreamScript_0800_YN_What
	waitmessage
	yesnobox 20, 8
	@ continues story
	message DreamScript_0800_Text4
	waitmessage
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
DreamScript_0800_Text1:
	.string "… … …\p"
	.string "{ALEX_SPEAKING}"
	.string "…and Guzma asked me to go get her, so\n"
	.string "I started searching through bedrooms.{END}\p"
	.string "{RIVAL_ALOLA} looked back to the sun setting\n"
	.string "over the ocean, Malie City glowing below.\p"
	.string "{ALEX_SPEAKING}"
	.string "Third door I walked in, and she's there\n"
	.string "making out with her girlfriend!$"
DreamScript_0800_YN_Really:
	.string "Really?!$"
DreamScript_0800_YN_Again:
	.string "Again?!$"
DreamScript_0800_Text2:
	.string "{ALEX_SPEAKING}"
	.string "Right? And I'm like “Guzma's on his way,\n"
	.string "you two!” And they curse up a storm!{END}\p"
	.string "You both laugh raucously.{PAUSE 20}\n"
	.string "{RIVAL_They} shares a smile with you.{PAUSE 20}\p"
	.string "{RIVAL_They} then mouths something at you.{PAUSE 30}\n"
	.string "You never could read lips well.$"
DreamScript_0800_YN_What:
	.string "What?$"
DreamScript_0800_YN_Huh:
	.string "Huh?$"
DreamScript_0800_Text3:
	.string "{RIVAL_They} mumbles it again.{PAUSE 30}\n"
	.string "Why can't {RIVAL_they} just say it?{PAUSE 20}$" @Huh?/What?
DreamScript_0800_Text4:
	.string "{RIVAL_They} turns to look back at the\n"
	.string "sunset, {RIVAL_their} smile faltering.\p"
	.string "{ALEX_SPEAKING}"
	.string "So then, I'm playing defense for them\n"
	.string "as Guzma is striding towards the door…{END}\p"
	.string "… … …\p"
	.string "$"

DreamScript_0801::
	@ Do nothing in this script, just set the flag
	return
	
DreamScript_0802::
	fadenewbgm MUS_RUNECITY @TODO (same music as above)
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ mumbles
	message DreamScript_0802_Text1
	setyesnotext DreamScript_0800_YN_Huh, DreamScript_0800_YN_What
	waitmessage
	yesnobox 20, 8
	@ "Fuck!!" -- note to self, DO NOT use hashtags randomly. It causes weird EOFs when parsing
	message DreamScript_0802_Text2
	waitmessage
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
DreamScript_0802_Text1:
	.string "… … …\p"
	.string "{ALEX_SPEAKING}"
	.string "Right? And I'm like “Guzma's on his way,\n"
	.string "you two!” And they curse up a storm!{END}\p"
	.string "You both laugh raucously.{PAUSE 20}\n"
	.string "{RIVAL_They} shares a smile with you.\p"
	.string "{RIVAL_They} then mouths something at you.{PAUSE 30}\n"
	.string "Why can't {RIVAL_they} just speak up??$" @Huh?/What?
DreamScript_0802_Text2:
	.string "{RIVAL_They} mouths it again.{PAUSE 40}\n"
	.string "And again.{PAUSE 40} And again…{PAUSE 40}\p"
	.string "{SET_NORM_PAL}{PLAY_BGM MUS_DUMMY}{PLAY_SE SE_W153}"
	@ .string "{SET_NORM_PAL}{PLAY_BGM MUS_RG_SEIBETU}"
	.string "Like a bolt of lightning, it suddenly\n"
	.string "hits you what {RIVAL_they} was saying!\p"
	.string "{RIVAL_They} was too afraid of losing what\n"
	.string "{RIVAL_they} had with you, but had to try!\p"
	.string "How could you have been so stupid?!{PAUSE 30}\n"
	.string "How did you not realize before?!{PAUSE 30}\p"
	.string "{RIVAL_They} was saying…{PAUSE 60}\n"
	.string "{CENTER}“I love you”{PAUSE 60}\p"
	.string "… … … … … … …{PAUSE 40}\n"
	.string "… … … … …{PAUSE 60} F&¥%!!{PAUSE 20}\p"
	.string "$"
	
	
@------------------------------------------------------
@ Triggered after having surfed for the first time
DreamScript_0900:: @done
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
	.string "… … … …{PAUSE 30}After Alolan waves,\n"
	.string "Hoenn's waves are nothing…\p"
	.string "$"
	
@------------------------------------------------------
@ Triggered by the rains cutscene, required location Mossdeep
DreamScript_1000:: 
	delay 60
	message DreamScript_1000_Text1
	waitmessage
	fadenewbgm MUS_OOAME
	@ setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
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
	.string "You go to throw yours as well…{PAUSE 30}\n"
	.string "And {RIVAL_ALOLA} is there too…\p"
	.string "{RIVAL_They} throws {RIVAL_their} bandanna to the\n"
	.string "ground and stomps on it.\p"
	.string "{RIVAL_They} looks at you expectantly…{PAUSE 30}\n"
	.string "You clutch your bandanna tighter…{PAUSE 20}\p"
	.string "{RIVAL_They} rolls {RIVAL_their} eyes and turns away…{PAUSE 30}\n"
	.string "You're alone in the rain again…\p"
	.string "{SET_NORM_PAL}{PLAY_BGM MUS_DUMMY}{PLAY_SE SE_W153}"
	.string "{AQUA_BOY}: Com'on, guys! One more time!\p"
	.string "{AQUA_BOY} {PLAY_SE SE_W195}launches once more into an\n"
	.string "obnoxious song.{PAUSE 30} You roll over.{PAUSE 20}\p"
	.string "$"

DreamScript_1001:: @ Alt version for not-Mossdeep
	fadenewbgm MUS_OOAME
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_1001_Text1
	waitmessage
	closemessage
	delay 90
	fadedefaultbgm
	return
DreamScript_1001_Text1:
	.string "You find yourself in the pouring\n"
	.string "rain again…\p"
	.string "{AQUA_BOY} and {AQUA_GIRL} are throwing\n"
	.string "their bandannas to the ground…\p"
	.string "You go to throw yours as well…{PAUSE 30}\n"
	.string "And {RIVAL_ALOLA} is there too…\p"
	.string "{RIVAL_They} throws {RIVAL_their} bandanna to the\n"
	.string "ground and stomps on it.\p"
	.string "{RIVAL_They} looks at you expectantly…{PAUSE 30}\n"
	.string "You clutch your bandanna tighter…{PAUSE 20}\p"
	.string "{RIVAL_They} rolls {RIVAL_their} eyes and turns away…{PAUSE 30}\n"
	.string "You're alone in the rain again…\p"
	.string "{ALEX_SPEAKING}"
	.string "I won't be part of something so vile…{END}{PAUSE 40}\n"
	.string "{SET_NORM_PAL}{PLAY_BGM MUS_DUMMY}{PLAY_SE SE_W153}"
	.string "{RIVAL_Their} words echo as you bolt awake.\p"
	.string "$"
	
@------------------------------------------------------
@ Triggered upon finishing the Weather Institute event
DreamScript_1100::
	@ Alex questioning what the deal is with Luisamine
	@ And how they're always doing her dirty work inexplicably
	@ Possibly Palmera is involved or spoken about
	return
DreamScript_1100_Text1:
	.string "{ALEX_SPEAKING}"
	.string "I don't like Lusamine.{END}\p"
	.string "You look over at {RIVAL_ALOLA}, eating {RIVAL_their}\n"
	.string "Malasada pensively.\p$"
DreamScript_1100_YN_Why:
	.string "Why?$"
DreamScript_1100_YN_Okay:
	.string "Okay…?$"
DreamScript_1100_Text2:
	.string "{ALEX_SPEAKING}"
	.string "There's just something off about her,\n"
	.string "ya know? I know Guzma loves her, but…\p"
	@ TODO
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


DreamScript_Alex_FirstCall::
	lockall
	pokenavcall gText_Alex_Pokenav_FirstCall1
	waitmessage
	delay 30
	@ "Registered!"
	playfanfare MUS_ME_TORE_EYE
	msgbox gText_Alex_Pokenav_Registered, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ALEX_MATCH_CALL
	clearflag FLAG_ENABLE_ALEX_FIRST_CALL
	releaseall
	end
gText_Alex_Pokenav_FirstCall1:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "… …{PAUSE 30} {P_PLAYER}?{PAUSE 40} Is that you?{PAUSE 30}\n"
	@ TODO: Test how choices work with pokenav: choice here "Alex?!" / "Wha?!"
	.string "It's me… … {RIVAL_ALOLA}.\p"
	.string "I, uh…{PAUSE 20} got your new number from\n"
	.string "your mom. I hope that's alright.\p"
	.string "I wasn't sure if you wanted to hear\n"
	.string "from me again after…{PAUSE 30} you know…\p"
	.string "It's good to hear your voice again…\p"
	.string "I can't talk long right now but…\n"
	.string "call me if you need to talk.\p"
	.string "I know it's long distance.\n"
	.string "But for you, I don't mind…{END}\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
gText_Alex_Pokenav_Registered: @ 8213C01
	.string "Registered your friend {RIVAL_ALOLA}\n"
	.string "in the PokéNav.$"


DreamScript_Alex_LeagueCall::
	lockall
	pokenavcall gText_Alex_Pokenav_LeagueCall1
	waitmessage
	closemessage
	clearflag FLAG_ENABLE_ALEX_LEAGUE_CALL
	releaseall
	end
gText_Alex_Pokenav_LeagueCall1:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "{RIVAL_ALOLA}: {PLAYER}! You're alright!\n"
	.string "I just heard the news about the\l"
	.string "legendary beasts!\p"
	.string "I was so worried!\n"
	.string "I'm glad you're okay!\p"
	.string "What? You're going to the\n"
	.string "{POKEMON} League Championship?!\p"
	.string "That's starting so soon!\p"
	.string "Do you mind if I tell your mom?\n"
	.string "I think we'd BOTH want to watch!\p"
	.string "Good luck at the league,\n{PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

@------------------------------------------------------

gText_Alex_Pokenav_Unavailable::
	.string "… … … … … …\n"
	.string "beee-Deee-DEEEEP!\p"
	.string "We're sorry, we are unable to\n"
	.string "connect your call at this time.\p"
	.string "Your long distance minutes for\n"
	.string "the day have been expended.\p"
	.string "Please try again tomorrow.\p"
	.string "… … … … … …\n"
	.string "BEEP BEEP BEEP BEEP BEEP BEEP\l"
	.string "BEEP BEEP BEEP BEEP BEEP BEEP$"



@------------------------------------------------------
DreamScript_Dummy:
	.string "{RIVAL_ALOLA}'s advice…\n"
	.string "We got plenty of beds in Po Town.\p"
	.string "Nothing says you have to sleep near\n"
	.string "your crazy mom and dad all the time."
	
	.string "Grip with your toes. Feel the waves\l"
	.string "under the board. You feel them?"
	
	.string "Someone could get hurt, {PLAYER}!\n"
	.string "We don't want to hurt nobody!$"
	
	
	.string "You already failed at {POKEMON},\l"
	.string "don't you fail at math too! Homework!{PAUSE_UNTIL_PRESS}"
	
	.string "I don't like you hanging out with those\l"
	.string "hoodlums, {PLAYER}.\p"
	.string "What have they ever done for you\n"
	.string "besides get you in trouble?{PAUSE_UNTIL_PRESS}"
	
	.string "Mom's advice…\n"
	.string "Remember, blood is thicker than water,\l"
	.string "but blood doesn't quench thirst!\l"
	.string "What do we think, ladies? Martinis?{PAUSE_UNTIL_PRESS}"
	
	.string "$"
