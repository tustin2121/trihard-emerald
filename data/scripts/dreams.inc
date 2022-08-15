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
@[1200]- Triggered by first entering Mt. Pyre 
@[1300]- Triggered by first entering Aqua Hideout B1F
@[0600]- Triggered by completing Space Center Rescue
@[100X]- Triggered by the rains cutscene, required location Mossdeep
@[    ]- Triggered by getting defeated by the legendaries
@[1600]- Triggered by defeating Logan in victory road

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
	.string "You look down at the empty Poké Ball…{PAUSE 50}\n"
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
	selectyesnoanswer DreamScript_0700_hugged, DreamScript_0700_rejected
	call 0
	@ enable the call from Alex
	setflag FLAG_ENABLE_ALEX_FIRST_CALL
	delay 120
	fadedefaultbgm
	return
DreamScript_0700_hugged:
	message DreamScript_0700_Text9a
	setflag FLAG_HUGGED_ALEX
	waitmessage
	closemessage
	fadenewbgm MUS_DUMMY
	return
DreamScript_0700_rejected:
	message DreamScript_0700_Text9b
	fadenewbgm MUS_DUMMY
	waitmessage
	closemessage
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
@ Triggered by first entering Mt. Pyre
DreamScript_1200::
	fadenewbgm MUS_RG_NAMINORI
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_1200_Text1
	waitmessage
	closemessage
	fadedefaultbgm
	delay 90
	return
DreamScript_1200_Text1:
	.string "You count the candles as tūtū lights\n"
	.string "them: ten in total on the cake.{PAUSE 20}\p"
	.string "{WOMAN_SPEAKING}"
	.string "Now make a wish!{END}{PAUSE 30}\n"
	.string "You blow them out and she claps happily.{PAUSE 20}\p"
	.string "You wished that tūtū would get better.{PAUSE 20}\n"
	.string "That the chemo treatments would work,\l"
	.string "and that you could remain with her…\l"
	.string "Her precious hānai child…{PAUSE 20}\p"
	.string "… … …{PAUSE 50} The wish didn't come true.{PAUSE 20}\p"
	.string "{MAN_SPEAKING}"
	.string "Not now, {PLAYER}, {PLAYER_honey}.\n"
	.string "Daddy's got a work meeting to get to.{PAUSE 20}\p"
	.string "{WOMAN_SPEAKING}"
	.string "Mommy's talking with her friends right\n"
	.string "now, sweetie. Why don't you play outside?{END}{PAUSE 20}\p"
	.string "No one payed attention to you like\n"
	.string "tūtū had.{PAUSE 30} Not until {RIVAL_ALOLA}, at least.{PAUSE 20}\p"
	.string "{ALEX_SPEAKING}"
	.string "Yes, I know I didn't have to get you\n"
	.string "the birthday cake. I still did.{PAUSE 20}\p"
	.string "It's not like I paid for it. Just\n"
	.string "pretend there's sixteen candles on it.{END}{PAUSE 20}\p"
	.string "You blow out the imaginary candles.{PAUSE 20}\n"
	.string "She claps, like tūtū did…{PAUSE 40}\p"
	.string "$"
	
@------------------------------------------------------
@ Triggered after entering Aqua hideout BF1 for the first time
DreamScript_1300::
	fadenewbgm MUS_B_DOME
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_1300_Text1
	waitmessage
	selectpointer_ongender DreamScript_1300_Text2m, DreamScript_1300_Text2f
	message 0
	waitmessage
	message DreamScript_1300_Text3
	waitmessage
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
DreamScript_1300_Text1:
	.string "You lie awake on the mattress, staring\n"
	.string "at the skull symbol tagged on the ceiling.\p"
	.string "This was the first time you opted\n"
	.string "to sleep in the Po Town house.\p"
	.string "The place is run down and tagged up,\n"
	.string "and filled with broken furniture.\p$"
DreamScript_1300_Text2m:
	.string "There are five other guys sleeping\n"
	.string "in this little room, spread across the\n"
	.string "three mattresses and the floor.\p"
	.string "Several of them are half-dressed.\n"
	.string "One had fallen out of bed and is\l"
	.string "sleeping with his legs up on the bed.\p$"
DreamScript_1300_Text2f:
	.string "There are three other girls sleeping\n"
	.string "in this little room, spread across the\l"
	.string "five mattresses shoved together.\p"
	.string "The two girlfriends are sharing one\n"
	.string "bed but the other girl is spread out\l"
	.string "sideways across three beds.\p$"
DreamScript_1300_Text3:
	.string "There's shouting and laughter echoing\n"
	.string "elsewhere in the house, along with\l"
	.string "sounds of breaking glass.\p"
	.string "It's a strange new experience…{PAUSE 20}\n"
	.string "and you haven't stopped smiling yet.{PAUSE 20}\p"
	.string "Earlier in the evening, a bunch of\n"
	.string "grunts were hanging around a campfire,\l"
	.string "all swapping stories and spitting bars.\p"
	.string "At your parents' place, the only thing\n"
	.string "being spit were insults and accusations.\p"
	.string "This place is dirty, run down, and broken,{PAUSE 20}\n"
	.string "but filled with love and opportunity.\p"
	.string "This is practically paradise…{PAUSE 20}\n"
	.string "You never want to leave…{PAUSE 30}\p"
	.string "$"
	
@------------------------------------------------------
@  
DreamScript_1400::
	@
	return
DreamScript_1400_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ 
DreamScript_1500::
	@
	return
DreamScript_1500_Text1:
	.string "{SET_DREAM_PAL}"
	.string "$"
	
@------------------------------------------------------
@ Triggered by defeating Logan in victory road
@ This is the end game. This dream is expected to play upon saving at the E4
@ The additional dreams are for any other times the player explicitly saves at the E4
DreamScript_1600::
	fadenewbgm MUS_RG_POKEYASHI
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	message DreamScript_1600_Text1
	waitmessage
	closemessage
	fadenewbgm MUS_DUMMY
	delay 15
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DESCRIBE
	message DreamScript_1600_Text2
	waitmessage
	closemessage
	@
	setvar VAR_0x8000, 4
	callnative SetPlayerOutfit 
	@ Note: We're not going to reload the map, as this may happen anywhere
	@ The outfit change will just take effect on next map load, 
	@ like the player puts on the hat on the way out the door or something.
	delay 60
	fadedefaultbgm
	return
DreamScript_1600_Text1:
	.string "Guzma stands on the landing, looking\n"
	.string "pensive. Plumeria stands next to him.\p"
	.string "The boss doesn't speak, he simply turns\n"
	.string "around to reveal his jacket's Skull logo.\p"
	.string "There's a big red X over the logo.\n"
	.string "Your stomach drops. Gasps resound.\p"
	.string "Plumeria steps forward, stone-faced.\n"
	.string "{WOMAN_SPEAKING}"
	.string "Team Skull is hereby disbanded.{END}\p"
	.string "Commotion. Uproar. You feel like the\n"
	.string "floor is collapsing under you.\p"
	.string "{WOMAN_SPEAKING}"
	.string "After the Aether incident, the boss\n"
	.string "had some soul searching to do.\p"
	.string "He doesn't want to put y'all in danger\n"
	.string "like that again over his screw ups.\p"
	.string "{MAN_SPEAKING}"
	.string "Y'all can do better than this.{END}\n"
	.string "He speaks over his shoulder, shamefully.\p"
	.string "Bandannas and hats are being discarded\n"
	.string "all around you, thrown to the floor.\p"
	.string "Gang signs are ripped off and tossed aside.\n"
	.string "You clutch your bandanna tightly.\p"
	.string "Everyone's clambering, asking what's next\n"
	.string "asking where they should go, asking why.\p"
	.string "You stay rooted to the spot,\n"
	.string "Skull Bandanna tightly in hand…\p"
	.string "$"
DreamScript_1600_Text2:
	.string "{PLAYER} looks at the Aqua Bandana\n"
	.string "that {PLAYER_they} kept on {PLAYER_them}.\p"
	.string "Some things need to be let go…$" @ Player discards the bandanna


DreamScript_1601::
	fadenewbgm MUS_HIDERI
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ mom speaking
	message DreamScript_1601_Text1
	setyesnotext DreamScript_1601_YN_What, DreamScript_1601_YN_Why
	waitmessage
	yesnobox 20, 8
	@ dad packing
	message DreamScript_1601_Text2
	setyesnotext DreamScript_1601_YN_But, DreamScript_1601_YN_Why2
	waitmessage
	yesnobox 20, 8
	@ run away?
	message DreamScript_1601_Text3
	setyesnotext DreamScript_1601_YN_How, DreamScript_1601_YN_Gone
	waitmessage
	yesnobox 16, 8
	@ fight back?
	message DreamScript_1601_Text4
	setyesnotext DreamScript_1601_YN_Where, DreamScript_1601_YN_WhyBother
	waitmessage
	yesnobox 16, 8
	@ self-harm?
	message DreamScript_1601_Text5
	setyesnotext gYN_Elipsis2, DreamScript_1601_YN_WhyTry
	waitmessage
	yesnobox 16, 8
	@ alex?
	message DreamScript_1601_Text6
	waitmessage
	fadenewbgm MUS_DUMMY
	message DreamScript_1601_Text7
	waitmessage
	closemessage
	delay 60
	fadedefaultbgm
	return
DreamScript_1601_Text1:
	.string "… … Skull's gone… … …\p"
	.string "After several hours wandering the island\n"
	.string "in a daze… you arrive at your parents'.\p"
	.string "The house is quiet for once. Your mom\n"
	.string "smokes out on the front porch.\p"
	.string "{WOMAN_SPEAKING}"
	.string "Go help your Dad pack.\n"
	.string "Pack your things too.$" 
	@ "What?"/"Why?"
DreamScript_1601_YN_What:
	.string "What?$"
DreamScript_1601_YN_Why:
	.string "Why?$"
DreamScript_1601_Text2:
	.string "{WOMAN_SPEAKING}"
	.string "He's got a new job elsewhere. Court\n"
	.string "ordered that custody of… you… is his.\l"
	.string "That means you're going with him.{END}\p"
	.string "First Guzma abandons you. Now this?\p"
	.string "Dad is already half-packed.\n"
	.string "{MAN_SPEAKING}"
	.string "We fly out Friday.\l"
	.string "You've got four days to pack.{END}$"
	@ "But…!"/"Why…?"
DreamScript_1601_YN_But:
	.string "But…!$"
DreamScript_1601_YN_Why2:
	.string "Why…?$"
DreamScript_1601_Text3:
	.string "{MAN_SPEAKING}"
	.string "Don't argue. I didn't want to be\n"
	.string "reassigned away from Alola either.{END}\p"
	.string "Thoughts of running away.$" 
	@ "To where?" / "Skull's gone…"
DreamScript_1601_YN_Where:
	.string "To where?$"
DreamScript_1601_YN_Gone:
	.string "Skull's gone…$"
DreamScript_1601_Text4:
	.string "Thoughts of fighting back.$" 
	@ "But how?" / "Why bother…?"
DreamScript_1601_YN_How:
	.string "But how?$"
DreamScript_1601_YN_WhyBother:
	.string "Why bother…?$"
DreamScript_1601_Text5:
	.string "Thoughts of ending things.$" 
	@ .string "Thoughts… of a darker nature.$" 
	@ "……" / "Why even try…?"
DreamScript_1601_YN_WhyTry:
	.string "Why even try…?$"
DreamScript_1601_Text6:
	.string "Thoughts of {RIVAL_ALOLA}…\p$"
DreamScript_1601_Text7:
	.string "{PAUSE 30}{SET_NORM_PAL}{PAUSE 30}"
	.string "You're in a much better head space now.\n"
	.string "You can do this.\p"
	.string "$"


DreamScript_1602::
	fadenewbgm MUS_HIDERI
	delay 60
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DREAM
	@ mom speaking
	message DreamScript_1602_Text1
	setyesnotext DreamScript_1602_Why, DreamScript_1602_Help
	waitmessage
	yesnobox 20, 8
	message DreamScript_1602_Text2
	waitmessage
	closemessage
	fadenewbgm MUS_DUMMY
	delay 90
	fadedefaultbgm
	return
DreamScript_1602_Text1:
	.string "You must have circled the island\n"
	.string "a hundred times looking for {RIVAL_ALOLA}.\p"
	.string "You're leaving in three days…\p"
	.string "You've run into several former grunts\n"
	.string "all doing community service and crap…\p"
	.string "Apparently Guzma and Plumeria have\n"
	.string "already moved on too. Trainers now.\p"
	.string "… … … …\n"
	.string "As the sun sets, you enter the graveyard.\p"
	.string "You collapse onto tūtū's grave,\n"
	.string "trying to not cry, and failing.$"
DreamScript_1602_Why:
	.string "Tūtū why?$"
DreamScript_1602_Help:
	.string "Help me…$"
DreamScript_1602_Text2:
	.string "The headstone is ever silent.\n"
	.string "The Drifloon peer at you from a distance.\p"
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
	.string "It's me… … {RIVAL_ALOLA}.{PAUSE 60}\p"
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

@------------------------------------------------------

DreamScript_Alex_LegendaryCall::
	lockall
	goto_if_unset FLAG_LEGENDARIES_IN_SOOTOPOLIS, DreamScript_Alex_LegendaryCall_Cleared
	callnative CheckIsWeatherAlternating
	@ Select if we're in the storm or not
	selectyesnoanswer gText_Alex_Pokenav_LegendaryCall_Rain, gText_Alex_Pokenav_LegendaryCall_Normal
	pokenavcall 0
	waitmessage
	closemessage
	goto DreamScript_Alex_LegendaryCall_END
	end
DreamScript_Alex_LegendaryCall_Cleared:
	setvar VAR_0x800B, 0
	addvar_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, VAR_0x800B, 1
	@ select response
	selectpointer_from VAR_0x800B, gText_Alex_Pokenav_LegendaryCall_Cleared, gText_Alex_Pokenav_LegendaryCall_ClearedHero
	pokenavcall 0
	waitmessage
	closemessage
	goto DreamScript_Alex_LegendaryCall_END
	end
DreamScript_Alex_LegendaryCall_END:
	setflag FLAG_ALEX_TOLD_SKY_PILLAR
	clearflag FLAG_ALEX_CALL_LEGENDARIES
	releaseall
	end
	
gText_Alex_Pokenav_LegendaryCall_Rain:
	@ .string "… … … … … …\n"
	@ .string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "{RIVAL_ALOLA}: {PLAYER}! Are you there?!\p"
	.string "Wow, the signal is somehow worse!\n"
	.string "Are you IN the storm?!\p"
	.string "I found some info you might want\n"
	.string "about the legendary beasts!\p"
	.string "Like, literally, there's legends\n"
	.string "about them! I have one here!\p"
	.string "Groudon and Kyogre fought in the\n"
	.string "distant past and nearly ended\l"
	.string "the world, so the story goes!\p"
	.string "But they were stopped by some\n"
	.string "sort of greater serpent dragon?\p"
	.string "The legend says it lives atop\n"
	.string "Sky Pillar! Have you heard of that?\p"
	.string "{PLAYER}? Hello?! Did I get dis--\n"
	.string "… … Click! (CALL FAILED).$"
gText_Alex_Pokenav_LegendaryCall_Normal:
	@ .string "… … … … … …\n"
	@ .string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey!\n"
	.string "The signal got better since\l"
	.string "I last called. That's good!\p"
	.string "So, I found some info you might\n"
	.string "want about those rampaging beasts!\p"
	.string "There's an old legend about Groudon\n"
	.string "and Kyogre fighting in the past.\p"
	.string "Legend says it nearly ended the\n"
	.string "world! But they were stopped.\p"
	.string "There's some sort of greater\n"
	.string "serpent dragon, which is said to\l"
	.string "live atop Sky Pillar?\p"
	.string "Is there some place called\n"
	.string "Sky Pillar in Hoenn?\p"
	.string "I'll try and keep researching for\n"
	.string "more stuff that might help.\l"
	.string "Stay safe, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
gText_Alex_Pokenav_LegendaryCall_Cleared:
	@ .string "… … … … … …\n"
	@ .string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey!\n"
	.string "The signal got better since\l"
	.string "I last called. That's good!\p"
	.string "So, I found some info you might\n"
	.string "want about those rampaging beasts!\p"
	.string "… … … Wait, what? You took care\n"
	.string "of it already?! What?! How?!\p"
	.string "Was it going and finding the\n"
	.string "greater serpent dragon I was\l"
	.string "literally about to tell you about?\p"
	.string "Well, heh. I'm glad you managed\n"
	.string "to figure it out!\l"
	.string "I was worried about you.\p"
	.string "Well, stay safe, {PLAYER}!\n"
	.string "Talk to you later, I guess!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
gText_Alex_Pokenav_LegendaryCall_ClearedHero:
	@ .string "… … … … … …\n"
	@ .string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey!\n"
	.string "The signal got better since\l"
	.string "I last called. That's good!\p"
	.string "So, I found some info you might\n"
	.string "want about those rampaging beasts!\p"
	.string "… … … Wait, what? You took care\n"
	.string "of it already?! What?! How?!\p"
	.string "You FOUGHT OFF THE BEASTS?!?!\p"
	.string "… … … … … …\n"
	.string "WHAT?!?!\p"
	.string "{PLAYER}, you could have been\n"
	.string "KILLED!! What were you THINKING?!\p"
	.string "I gotta lie down. I'll… I'll…\n"
	.string "Tapu Bulu give me strength…\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
	
	
@------------------------------------------------------

DreamScript_Alex_LeagueCall::
	lockall
	goto_if_set FLAG_ALEX_KNOWS_LEGENDARY_OUTCOME, DreamScript_Alex_LeagueCall_CaughtUp
	@ Buffer part one of the call: did Alex know?
	setvar VAR_0x800A, 0
	addvar_if_set FLAG_ALEX_KNOWS_LEGENDARIES, VAR_0x800A, 1
	addvar_if_set FLAG_ALEX_TOLD_SKY_PILLAR, VAR_0x800A, 1
	selectpointer gText_Alex_Pokenav_LeagueCallTableA, VAR_0x800A
	bufferstring 0, 0
	@ buffer part two of the call: reaction
	setvar VAR_0x800B, 0
	addvar_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, VAR_0x800B, 1
	selectpointer gText_Alex_Pokenav_LeagueCallTableB, VAR_0x800B
	bufferstring 1, 0
	@ display message
	pokenavcall gText_Alex_Pokenav_LeagueCall
	waitmessage
	goto DreamScript_Alex_LeagueCall_END
DreamScript_Alex_LeagueCall_END:
	closemessage
	clearflag FLAG_ENABLE_ALEX_LEAGUE_CALL
	setflag FLAG_ALEX_KNOWS_E4
	releaseall
	end
gText_Alex_Pokenav_LeagueCall:
	@ .string "… … … … … …\n"
	@ .string "… … … … … Beep!\p"
	@ .string "{ALEX_SPEAKING}"
	.string "{STR_VAR_1}\p"
	.string "{STR_VAR_2}\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
.align 2
gText_Alex_Pokenav_LeagueCallTableA:
	.4byte gText_Alex_Pokenav_LeagueCallA_Base
	.4byte gText_Alex_Pokenav_LeagueCallA_Called
	.4byte gText_Alex_Pokenav_LeagueCallA_FollowedUp
	.4byte 0
gText_Alex_Pokenav_LeagueCallTableB:
	.4byte gText_Alex_Pokenav_LeagueCallB_Base
	.4byte gText_Alex_Pokenav_LeagueCallB_Hero
	.4byte 0
gText_Alex_Pokenav_LeagueCallA_Base:
	.string "{RIVAL_ALOLA}: {PLAYER}! You're alright!\n"
	.string "I just heard the news about the\l"
	.string "rampaging beasts over there!\p"
	.string "Are you okay?! Are they still\n"
	.string "causing terrible weather?!\p"
	.string "Oh, they're gone now? Oh, thank\n"
	.string "the deities. What happened?$"
gText_Alex_Pokenav_LeagueCallA_Called:
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey!\n"
	.string "The signal got better since\l"
	.string "I last called. That's good!\p"
	.string "So, I found some info you might\n"
	.string "want about those rampaging beasts!\p"
	.string "… … … Wait, what? You took care\n"
	.string "of it already?! What?! How?!\p"
	.string "Was it going and finding the\n"
	.string "greater serpent dragon I was\l"
	.string "literally about to tell you about?$"
gText_Alex_Pokenav_LeagueCallA_FollowedUp:
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey!\n"
	.string "Did you find the Sky Pillar yet?\p"
	.string "Oh, it's all over and done with?\n"
	.string "And you didn't update me?\p"
	.string "I'm glad you're okay.\n"
	.string "What ended up happening?$"
gText_Alex_Pokenav_LeagueCallB_Base:
	.string "What was that name? Rayquaza?\n"
	.string "That's so cool!\p"
	.string "I'm glad that all got sorted out\n"
	.string "and everyone's okay.\p"
	.string "Oh? You're going to the\n"
	.string "{POKEMON} League Championship?!\p"
	.string "That's starting so soon!\p"
	.string "Do you mind if I tell your mom?\n"
	.string "I think we'd BOTH want to watch!\p"
	.string "Good luck at the league,\n{PLAYER}!$"
gText_Alex_Pokenav_LeagueCallB_Hero:
	.string "… … … … … …\n"
	.string "WHAT?!?!\p"
	.string "You FOUGHT OFF THE BEASTS?!?!\p"
	.string "{PLAYER}, you could have been\n"
	.string "KILLED!! What were you THINKING?!\p"
	.string "I gotta lie down. I'll… I'll…\n"
	.string "Tapu Bulu give me strength…$"
DreamScript_Alex_LeagueCall_CaughtUp:
	@ display message
	pokenavcall gText_Alex_LeagueCall_CaughtUp
	waitmessage
	goto DreamScript_Alex_LeagueCall_END
	end
gText_Alex_LeagueCall_CaughtUp:
	.string "{RIVAL_ALOLA}: {PLAYER}! Finally!\n"
	.string "I've been trying to call you, but\l"
	.string "the call wouldn't go through!\p"
	.string "You're where? Victory Road?\p"
	.string "Oh? You're going to the\n"
	.string "{POKEMON} League Championship?!\p"
	.string "Oh, right, that's starting so soon!\p"
	.string "Do you mind if I tell your mom?\n"
	.string "I think we'd BOTH want to watch!\p"
	.string "Good luck at the league,\n{PLAYER}!$"
	

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

gText_Alex_Pokenav_CatchUp::
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey! You wanna\n"
	.string "chat? Yeah, I've got time.\p"
	.string "So, what's Hoenn like?\n"
	.string "What have you been up to?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Wow, your're doing the gym challenge?\n"
	.string "Good to see you back at--\p"
	.string "You, what? You joined a new team?!\p"
	.string "…{PAUSE 30}Oh…{PAUSE 20}! That's…{PAUSE 30} cool…!\p"
	.string "Well, what do you want me to say?!\n"
	.string "Being on Team Skull is kind of…\l"
	.string "I'm not proud of it, {PLAYER}…\p"
	.string "Alright! No need to yell!\n"
	.string "Having friends is good, but…\p"
	.string "Just… be aware of if they're maybe…\n"
	.string "Doing something extreme…\p"
	.string "Let's talk more later, okay?\n"
	.string "Bye…$"

gText_Alex_Pokenav_GymChallenge::
	.string "{RIVAL_ALOLA}: Hey, {PLAYER}.\n"
	.string "You doing okay?\p"
	.string "I wanted to ask you about the gym\n"
	.string "challenge? What's it been like?\p"
	.string "They're trying to implement some\n"
	.string "gym stuff here. A lot of the locals\l"
	.string "are really mad about it.\p"
	.string "How many badges do you have now?\p"
	.string "Yes, I am avoiding talking about\n"
	.string "your new team. Team Aqua, whatever.\p"
	.string "I've been researching Hoenn news\n"
	.string "about them, and it's not pretty.\p"
	.string "I'll talk to you later.$"

gText_Alex_Pokenav_TeamAqua::
	.string "{RIVAL_ALOLA}: Hey, {PLAYER}.\n"
	.string "How are you?\p"
	.string "Alright, so Team Aqua…\n"
	.string "I've been doing research.\p"
	.string "There's some manifesto in the\n"
	.string "news about them loving the seas?\p"
	.string "Since when did you love the seas\n"
	.string "so much? Or is it just comradery?\p"
	.string "Yeah, I figured it would be.\n"
	.string "Team Skull was quite close knit.\p"
	.string "Is Aqua as close knit as Skull was?\n"
	.string "Yeah, you've got two friends, but…\p"
	.string "Yeah, most of Skull were idiots.\n"
	.string "Some of the stupid things we did…\p"
	.string "Anyway, gotta go.\n"
	.string "Stay safe, {PLAYER}.$"

gText_Alex_Pokenav_Grandma::
	.string "{RIVAL_ALOLA}: Hey {PLAYER}!\n"
	.string "You doing okay?\p"
	.string "Mt. Pyre?{PAUSE 30} A graveyard, huh?{PAUSE 30}\n"
	.string "Are you gonna--{PAUSE 20}yep.{PAUSE 30} Let it out.\p"
	.string "Don't apologize, {PLAYER}.\n"
	.string "You're allowed to cry sometimes.\p"
	.string "Your tūtū meant a lot to you.\n"
	.string "You're allowed to cry.\p"
	.string "Feel a little better? I'm glad.\n"
	.string "Call me if you wanna cry some more.$"

gText_Alex_Pokenav_Magma::
	.string "{RIVAL_ALOLA}: {PLAYER}! H--!\n"
	.string "Woah, you alright?\p"
	.string "Wh-What about a volcano and…?\n"
	.string "A rampaging beast…?!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "So a massive red beast got awoken\n"
	.string "by a rival team and… Are you hurt?!\p"
	.string "Okay, good, you're not hurt.\n"
	.string "Do you know where it went?!\p"
	.string "What's it called, maybe I can\n"
	.string "try and find something…?\p"
	.string "Alright, breathe, {PLAYER}\n"
	.string "you're gonna be alright… … …\p"
	.string "I'll see what I can find.\n"
	.string "Call me with any developments.$"

gText_Alex_Pokenav_Stern::
	.string "{RIVAL_ALOLA}: {PLAYER}!\n"
	.string "Great timing!\p"
	.string "Are you aware that your Team Aqua\n"
	.string "people are on the news RIGHT NOW?!\p"
	.string "They're in… Slateport?! They're\n"
	.string "stealing some submarine?!\p"
	.string "Are you not there with them?!$"
gText_Alex_Pokenav_SternAfter::
	.string "{RIVAL_ALOLA}: {PLAYER}!\n"
	.string "Care to explain?!\p"
	.string "We saw your new friends in some\n"
	.string "Slateport? Stealing a submarine?!\l"
	.string "Do you know anything about this?\p"
	.string "Really? You don't know anything?\n"
	.string "Is that usually what happens?\p"
	.string "And you're okay with that?\n"
	.string "If you say so…$"

gText_Alex_Pokenav_Logan_Base::
	.string "{RIVAL_ALOLA}: Hey, {PLAYER}.\n"
	.string "How's it going over there?\p"
	.string "Oh, time for venting?\n"
	.string "Okay, hit me with it.\p"
	.string "… … … … …\n"
	.string "Wait wait, who's {RIVAL_HERO}? You've never\l"
	.string "mentioned this guy before.\p"
	.string "{STR_VAR_1}" @ insert below string if relevant
	.string "… … … … …\n"
	.string "Okay, let me get this straight:\p"
	.string "He's an annoying fashion disaster.\n"
	.string "He thinks he owns the place.\l"
	.string "He regularly beats down team grunts…\p"
	.string "Honestly, he sounds like that guy from\n"
	.string "the Aether Incident. Remember?\p"
	.string "The one Gladion teamed up with?\n"
	.string "Weirdly never stopped smiling?\l"
	.string "He had a massive hero complex, that guy.\p"
	.string "Anyway, I gotta go. You can tell me\n"
	.string "more about this {RIVAL_HERO} guy later.$"
gText_Alex_Pokenav_Logan_Deaths::
	.string "… … … … …\n"
	.string "He took out HOW MANY of your {POKEMON}?!\l"
	.string "{STR_VAR_2} of them?!\p$"

gText_Alex_Pokenav_SpaceCenter::
	.string "{RIVAL_ALOLA}: {PLAYER}! H--!\n"
	.string "Oh no, what's wrong now?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Okay, so… I hate to tell you that\n"
	.string "“I told you so”, but…\p"
	.string "What?! I'm not gonna sugarcoat it!\n"
	.string "I knew Team Aqua were bad news from\l"
	.string "the moment you tried to justify them!\p"
	.string "Look, maybe it's not too late.\n"
	.string "Maybe things can be salvaged.\p"
	.string "You made friends, right? I'm sure they\n"
	.string "will still like you, just like I do!\p"
	.string "You can set things right, {PLAYER}.\n"
	.string "I believe in you.$"

@ During legendaries event
gText_Alex_Pokenav_RainsBegan::
	.string "{RIVAL_ALOLA}: {PLAYER}? What's going on?\n"
	.string "I can barely hear you!\p"
	.string "… … … … … …\n"
	.string "Woah, okay, slow down!\l"
	.string "Start again from the beginning.\p"
	.string "… … … … … …\n"
	.string "Your team did what?! An ancient\l"
	.string "super-powerful {POKEMON}?!\p"
	.string "Okay, that's got Team Skull beat…\p"
	.string "Listen, I can barely hear you.\n"
	.string "I think our connection is bad!\p"
	.string "But I can see if I can find any\n"
	.string "info on… what were the names?\l"
	.string "Kyogre and Grupon-- Groudon, okay.\p"
	.string "I'll call you back if I find anything!\n"
	.string "Stay safe, please!$"
gText_Alex_Pokenav_MidResearch::
	.string "{RIVAL_ALOLA}: {PLAYER}? Are you alright?\n"
	.string "Okay, that's good.\p"
	.string "Listen, I can't talk much.\n"
	.string "I think I found a lead for you\l"
	.string "but I'm still tracing it down.\p"
	.string "I'll give you a call if it might\n"
	.string "be something useful to you.\p"
	.string "Stay safe, please!$"
gText_Alex_Pokenav_PostResearch::
	.string "{RIVAL_ALOLA}: {PLAYER}? Hey!\n"
	.string "Have you found anything yet?\p"
	.string "Remember, you're looking for\n"
	.string "some place called Sky Pillar?\p"
	.string "Maybe ask around? Or surf around?\n"
	.string "I imagine it'd be hard to miss!\p"
	.string "Good luck! And stay safe!$"

@ TODO: Post legendaries pokenav calls
gText_Alex_Pokenav_PostReport_BaseUnknown::
	.string "{RIVAL_ALOLA}: {PLAYER}! You're alright!\n"
	.string "I just heard the news about the\l"
	.string "rampaging beasts over there!\p"
	.string "Are you okay?! Are they still\n"
	.string "causing terrible weather?!\p"
	.string "Oh, they're gone now? Oh, thank\n"
	.string "the deities. What happened?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "{STR_VAR_1}$"
gText_Alex_Pokenav_PostReport_BaseKnown::
	.string "{RIVAL_ALOLA}: {PLAYER}? Are you alright?\n"
	.string "I'm still researching for you.\p"
	.string "What? It's over?! You did it?!\n"
	.string "Tell me what happened!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "{STR_VAR_1}$"
gText_Alex_Pokenav_PostReport_BaseHelped::
	.string "{RIVAL_ALOLA}: {PLAYER}? Hey!\n"
	.string "Have you found anything yet?\p"
	.string "Oh, you found the Sky Pillar!?\n"
	.string "Tell me what happened!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "{STR_VAR_1}$"
gText_Alex_Pokenav_PostReport_OutcomeNormal::
	.string "Oh, thank the deities, you're alright!\n"
	.string "I'm so glad the great dragon didn't\l"
	.string "just eat you or something!\p"
	.string "I wonder if the news has any footage\n"
	.string "of the dragon flying down like that!\p"
	.string "I'm gonna go see!\n"
	.string "Talk to you later, {PLAYER}!$"
gText_Alex_Pokenav_PostReport_OutcomeHero::
	.string "You FOUGHT OFF THE BEASTS?!?!\p"
	.string "… … … … … …\n"
	.string "WHAT?!?!\p"
	.string "{PLAYER}, you could have been\n"
	.string "KILLED!! What were you THINKING?!\p"
	.string "I gotta lie down. I'll… I'll…\n"
	.string "Tapu Bulu give me strength…$"
	
@ One reacting to it finishing
@ One reacting to the player being a hero
@ 1-2 just talking afterwards.


gText_Alex_Pokenav_E4Day1::
	.string "{RIVAL_ALOLA}: {PLAYER}! Hey!\n"
	.string "It's starting!\p"
	.string "The {POKEMON} League Conference!\n"
	.string "It's starting today!\p"
	.string "Are you participating?!\n"
	.string "I haven't seen you yet!\p"
	.string "You are parti--You're NEXT?!\p"
	.string "Don't let me hold you up! You can\n"
	.string "do this! Good luck!!$"
gText_Alex_Pokenav_E4Day2::
	.string "{RIVAL_ALOLA}: {PLAYER}!\n"
	.string "You did so well yesterday!\p"
	.string "I can't beleive how good you've\n"
	.string "gotten at handling {POKEMON}!\p"
	.string "Like, you've always been the best\n"
	.string "of us at it, but going against the\l"
	.string "Elites of the region is no joke!\p"
	.string "Oh, they just said on the TV that\n"
	.string "you're going next! Good luck!!$"
gText_Alex_Pokenav_E4Day3::
	.string "{RIVAL_ALOLA}: {PLAYER}! They're talking about\n"
	.string "you being in Team Aqua.\p"
	.string "Did you hear the news casters?\n"
	.string "Is there a TV nearby you can watch?\p"
	.string "Oh, I hope this doesn't disqualify\n"
	.string "you or something! I'd be so mad!\p"
	.string "Don't let it get you down!\n"
	.string "You can do this! Good luck!$"
gText_Alex_Pokenav_E4Day3_Hero::
	.string "{RIVAL_ALOLA}: {PLAYER}! They're talking about\n"
	.string "you beating those rampaging beasts!\p"
	.string "Did you hear the news casters?\n"
	.string "Is there a TV nearby you can watch?\p"
	.string "The images they dug up of you fighting\n"
	.string "them! It makes me scared all over again!\p"
	.string "You've set some big expectations\n"
	.string "for yourself…\p"
	.string "Oh! Uh, but don't let it get to you!\n"
	.string "Y-You can do this! Good luck!$"
gText_Alex_Pokenav_E4Day4::
	.string "{RIVAL_ALOLA}: {PLAYER}…\n"
	.string "Can you believe it…?\p"
	.string "It's down to the final five,\n"
	.string "and YOU'RE ONE OF THEM!\p"
	.string "I'm sure you're so nervous, so let\n"
	.string "me tell you what's happening here.\p"
	.string "Your mom has thrown a big lū'au\n"
	.string "with a big TV high on the house wall.\p"
	.string "All of her friends have come, as well\n"
	.string "as all of your dad's friends.\p"
	.string "Team Skull is basically having\n"
	.string "a reunion here, just to watch you!\p"
	.string "No one knows where Guzma is,\n"
	.string "but Plumeria showed up!\p"
	.string "She's pretending she doesn't care,\n"
	.string "but I think she likes seeing one of\l"
	.string "“her kids” accomplish so much.\p"
	.string "Oh, they just announced you're\n"
	.string "up next! I better go!\p"
	.string "We're all rooting for you,\n"
	.string "{PLAYER}! Good luck!$"
gText_Alex_Pokenav_E4Day5::
	.string "{RIVAL_ALOLA}: {PLAYER}…!\n"
	.string "You're calling me now…?\p"
	.string "You're the star challenger, {PLAYER_dude}!\n"
	.string "You're due on stage!\p"
	.string "Don't be nervous.\n"
	.string "You can do this.\l"
	.string "You've done so much already.\p"
	.string "This champion guy? He's gonna be\n"
	.string "a push over. You just watch and see.\p"
	.string "Yeah, the lū'au is still going.\n"
	.string "The whole the island is here, I swear!\p"
	.string "I think I did actually see Guzma\n"
	.string "hiding moodily somewhere in the back.\p"
	.string "You can do this. I know you can.\n"
	.string "Good luck, {PLAYER}… We love you…$"

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
