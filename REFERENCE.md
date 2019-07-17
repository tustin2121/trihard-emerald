For future person reference:
* If the game ever crashes in such a way where the screen goes all one color and the music halts, you have triggered an unbounded write of EWRAM, and your memory is now filled with the same value all throughout RAM. Congrats and go check your loop bounds.
* Animated door warps: 
	* The warp tile should be on the door, the metatile should be marked as an MB_ANIMATED_DOOR, and the tile should have collision ON. If the tile does NOT have collision, then it is possible for the player to approach the door from the side and turn quickly into it, and the door will not animate. The door needs to be bumped into for it to animate.
	* Furthermore, events placed on top of doors do not block door warps. To disable a door warp, you will need to change the metatile to a non-warpable tile, ie, one not marked as MB_ANIMATED_DOOR.
* Map Scripts:
	* `ON_LOAD`: Script that runs when the map loads. Do metatile changes here.
	* `ON_TRANSITION`: Script that runs when the map is transitioned into somehow. Do object xy positioning here.
	* `ON_RESUME`: Script that runs when the map is returned to from a menu in addition to when being loaded for the first time. Do virtual object creation here.
	* `ON_FRAME_TABLE`: Table of scripts which run every frame while the player is centered on a tile. Every entry is checked in order if a given variable matches a given constant value, and runs the given script if it does. No other scripts after are checked.
		* Commonly used for scripts that run immediately upon entering a map. Remember to set the variable checked to something other than the constant, or the script will run again immediately upon completion.
	* `ON_WARP_INTO_MAP_TABLE`: Table of scripts checked like the frame table, but only checked on warp in. In the same life cycle stage as OnLoad scripts.
	* `ON_RETURN_TO_FIELD`
	* `ON_DIVE_WARP` is only used for the sealed chamber. idk what it does.
* Event Objects
	* Event Objects that are more than 1 or 2 tiles off screen are entirely despawned and removed from the event object array. Event Objects that come within this range again are recreated from the in-memory template.
		* As such, these objects will need to be explicitly added again if a script wishes to move them from off screen.
		* Note that this behavior means that setting or clearing a hidden flag on the object will take immediate effect as long as where the object's position is is far enough from the camera.
* Scripting
	* Set your editor rulers to column 13 and column 56. As long as your script's text strings are within these two rulers, it will usually be within the limits of the standard field text box.
		* The above assumes a 4 space indent followed by `.string` will precede every string.
	* The `fadeoutbgm` command blocks until the music is faded out. Use `fadedefaultbgm` to not block.
	* Do not `hidemoneybox` without ensuring there is a money box to hide. Doing so will cause the game to softlock in a glitched state.
	* The `warp` commands do not block. You must `waitstate` after them before releasing, otherwise you will release too quickly, nothing will happen, and you might cause an effective softlock depending on what you did.
	* Despite apperances, `waitmovement 0` does not wait for all movement to finish. It waits for the last instance of `applymovement` to end. It might be better to explicitly declare which event you're waiting for.
	* The `applymovement` command does not hide the messagebox.
	* Trick of the trade: If you put a `"\p$"` at the end of a string, you do not have to do `waitbuttonpress` after a `message`, as the `\p` will be considered the button press you wait for, and it will also have an arrow indicator and select sound. The Birch intro uses this trick all the time.
	* The `special FunctionName` syntax is a glorified `callnative FunctionName`. There's in effect no difference between them. The `special` command will be smaller as it uses a u16 index into a table instead of a u32 pointer to a function, but the special table must be maintained as a tradeoff.
	* Pointer tables MUST be aligned 2. You must have an `.align 2` above a pointer table's symbol, otherwise it's 50/50 whether any pointers in the table will work from build to build. This is because of the ARM chip's word boundry requirements (which are u16s, btw).
		* This goes for Pokemart item lists as well.
* Virtual Objects
	* They are sprites which act like event objects.
	* They cannot be moved like event objects. They only stand there and can be turned to look in any cardinal direction. Do not expect to make actors of these objects.
	* They must be given an elevation on creation, or bad things like all the other event objects on screen vanishing will occur.
	* They cannot be removed once created.
	* The player walks through them, as they are not proper event objects.
	* They can be used to bypass the event object limit on a given screen as long as the player isn't able to get near them.
	* They are used in and were made for the contest cutscenes. Check out how they work there.
* Trainers
	* Trainers with line of sight to anything other than 0 must have as their first script command a trainer battle. The engine depends on the data being set up in this manner.
	* Trainers with "no_intro" battle commands must not have line of sight of more than 0. The game will crash. This is a corollary to the above point.
* Default Palette Setup:
	* Object Palettes 2-5 are standard object palettes. All event objects share these palettes.
	* Object palettes 6-9 are standard object reflection palettes. These are so all objects can have a water reflection.
	* 0 is reserved for the player palette, 1 is reserved for the player's reflection palette.
	* 10 and 11 are reserved for special palettes, like the rival's palette and reflection palette.
	* Background palettes 13-16 are reserved for text windows. Usually palette 15 is used for the standard textbox palette. This palette is written to any time the textbox opens.
	* The game has two palette buffers, one for unfaded colors, and a derivative one for faded colors. The faded colors are the ones copied to VRAM, and the fading is used for fading in and out when doing transitions.
* Converting from pokeruby
	* Ruby/Sapphire and Emerald have major differences in text rendering. The text renderer was rewritten from the ground up for FireRed, most likely, and this is backported to Emerald. You cannot expect to copy (non-scripting) code from RS into Emerald without accounting for the fundumental difference in text rendering between the two. Emerald's text renderer is far more sophisticated than RS's.

