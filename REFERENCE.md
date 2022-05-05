For future person reference:
* Misc
    * Never ever ever ever ever use VBA for testing. It cuts corners in emulation to get things to work in vanilla, and so those cut corners will make it so that your ROM will not work with other more accurate emulators. For best results, use [mGBA](https://mgba.io/), one of the most accurate emulators on the web.
    * If the game ever crashes in such a way where the screen goes all one color and the music halts, you have triggered an unbounded write of EWRAM, and your memory is now filled with the same value all throughout RAM. Congrats and go check your loop bounds.
    * Many emulators use the Game Code (defined in the Makefile) to determine what game is being played and adjust emulation settings accordingly (properly match what the game's cartridge usually gave it for memory, save chip, etc). If you change the game code, all of these assumptions go away, and the compiled ROM may not even run (Pokemon gen 3 specifically has a check in `AgbMain` which doesn't allow the game to boot if it doesn't have Flash memory). Some emulators have the ability to manually set these emulation options, but that's something you'll have to tell your users to do if you change the game code.
* VRAM
    * VRAM is not just another part of memory. It has special write access limitations. For one thing, it doesn't like you trying to write u8s to it. When you do, it tends to duplicate the u8's bits into a u16.
        * This limitation is the reason there's a LZ77UnCompWRAM and a LZ77UnCompVRAM.
        * Consider using the gDecompressionBuffer to decompress things before pushing them straight to VRAM via a DMA transfer request.
        * no$GBA does not seem to emulate the VRAM write restrictions, so what looks perfectly fine on no$GBA might cause problems on another emulator or real hardware.
    * Backgrounds have Tile data and Tilemap data. The latter references the former. Tile data is the actual pixels that make up a graphic. Tilemap data is which blocks of Tile data make up the background map.
        * BG_CHAR_ADDR() resolves a pointer to the Tile data.
        * BG_SCREEN_ADDR() resolves a pointer to the Tilemap data.
* Animated door warps: 
    * The warp tile should be on the door, the metatile should be marked as an MB_ANIMATED_DOOR, and the tile should have collision ON. If the tile does NOT have collision, then it is possible for the player to approach the door from the side and turn quickly into it, and the door will not animate. The door needs to be bumped into for it to animate.
    * Furthermore, events placed on top of doors do not block door warps. To disable a door warp, you will need to change the metatile to a non-warpable tile, ie, one not marked as MB_ANIMATED_DOOR.
    * Which door animation to use is determined by the lower tile's metatile id. This id is used as an "index" into the array named `gDoorAnimGraphicsTable`. This use as an index is global across the game, so if you put a new MB_ANIMATED_DOOR tile on an already existing id, the game will use the existing animation already.
    * In vanilla emerald, these door animations must not rely on two layers of tiles like the map does already. However individual tiles can have different palettes.
        * It's possible to mod it so that they can support multi-layered door animations, see TriHard Emerald's `fortree` door animation, and `gfx->size == 3`.
* Caves
    * The southern warps do not work the way you think. The glowing cave exit tiles are not special. It's the nondescript floor tile underfoot that is the warp tile. No, you cannot tell them apart by sight in the editor, which leads to a lot of hacks putting down the warp tiles as normal tiles. You can tell the difference in-game by if the game shows an arrow under the player when the player is standing on the tile facing downward. Check the Metatile Behavior.
* Map Scripts:
    * `ON_LOAD`: Script that runs when the map loads. Do metatile changes here.
    * `ON_TRANSITION`: Script that runs when the map is transitioned into somehow. Do object xy positioning here.
    * `ON_RESUME`: Script that runs when the map is returned to from a menu in addition to when being loaded for the first time. Do virtual object creation here.
    * `ON_FRAME_TABLE`: Table of scripts which run every frame while the player is centered on a tile. Every entry is checked in order if a given variable matches a given constant value, and runs the given script if it does. No other scripts after are checked.
        * Commonly used for scripts that run immediately upon entering a map. Remember to set the variable checked to something other than the constant, or the script will run again immediately upon completion.
    * `ON_WARP_INTO_MAP_TABLE`: Table of scripts checked like the frame table, but only checked on warp in. In the same life cycle stage as OnLoad scripts.
    * `ON_RETURN_TO_FIELD`: Run when returning from a battle to the field. This is usually used for when battling Voltorbs, to remove the pokemon's overworld sprite after battle.
    * `ON_DIVE_WARP` is only used for the sealed chamber. idk what it does offhand.
    * For an example of how the map script headers can be expanded upon or used to store arbitrary pointers to data about a map, see my other hack, the Trick-or-Treat-House: [A](https://github.com/TwitchPlaysPokemon/trick-or-treat-house/blob/master/include/constants/map_scripts.h), [B](https://github.com/TwitchPlaysPokemon/trick-or-treat-house/blob/master/data/maps/Puzzle_LedgeMountain/scripts.pory), [C](https://github.com/TwitchPlaysPokemon/trick-or-treat-house/blob/master/asm/macros/puzzle.inc), [D](https://github.com/TwitchPlaysPokemon/trick-or-treat-house/blob/master/src/trickhouse.c#L72).
* Event Objects (aka Object Events in new code)
    * Event Objects that are more than 1 or 2 tiles off screen are entirely despawned and removed from the event object array. Event Objects that come within this range again are recreated from the in-memory event object template list.
        * As such, these objects will need to be explicitly added again if a script wishes to move them from off screen.
        * Note that this behavior means that setting or clearing a hidden flag on the object will take immediate effect as long as where the object's position is is far enough from the camera.
    * Event object templates cannot be placed off the map above or to the left; coordinates are stored unsigned. They can however be placed off the map to the right or below with no problem.
    * Event objects are able to walk off the edges of their maps with no problem.
    * A map's event objects do not get instantiated until the player enters the map. Connected maps will not have events on them until the player steps onto the map itself. This is why there's often a buffer space of at least 7 squares (the radius of the camera view area) between routes and towns in the map design.
* Elevation
    * Part of a tilemap's collision data.
    * The term "Elevation" is a misnomer. An event object at a higher "elevation" does not necessarily mean it will be in front of objects and tiles at a lower elevation. Each "elevation" level means something different.
    * Objects at two different elevations cannot interact with one another. Objects cannot pass from one elevation directly to another.
        * This means that players that are surfing cannot interact with event objects on a land elevation, and visa versa.
        * Similarly, a trigger at an elevation that does not match the player's elevation will not trigger. This limitation is in place so that triggers placed on a bridge can't get triggered by going under the bridge.
            * Remember to place water triggers at elevation 1, surfing level. Default placement in porymap (elevation 3) means they won't trigger while surfing.
    * The player "bumps" into an elevation difference; as such, a door warp placed at a different elevation from the floor in front of it can still be entered.
    * Elevation of an event object is tied to the tile the event object is currently standing on. Attempting to set the elevation of an event object does nothing because it is always immediately overridden by the tilemap on the next frame.
        * The exception is elevations 0 and 15. These do not overwrite an event object's elevation.
    * Tilemaps default to elevation 3. This is the standard elevation where high-tiles (bg layer 1) will go over objects while low tiles (bg layers 2, 3) will go under. (bg layer 0 is reserved for text windows)
    * Elevation 4 is the standard elevation for going over high-tiles.
    * Elevation 1 is the surfing elevation. The actual prompt to surf is handled by the metatile behavior, and exiting surf is handled by bumping into an elevation 3 tile while surfing.
        * Note: Only elevation 3 is allowed to initiate surfing, and surfing can only exit onto elevation 3.
    * Elevation 0 is the transition elevation. You do not need it for doors, but you will need it for bridges. Objects on this elevation will keep their previous elevation, and can step off onto any other elevation. 
    * Elevation 15 is the bridge elevation. Objects on this elevation will keep their previous elevation, and cannot step off onto any elevation other than their previous elevation.
    * The remaining elevations are repeats of elevations 3, and 4 (repeating in order, but not past 12), so that one can have up to five separate areas of distinct elevations separate from each other, where the player cannot cross from one to the other without first passing through a 0 elevation tile. (In theory, in practice you'll never use more than 2 or 3, simply due to tileset aesthetics).
        * For an example: these separate elevations are used for the higher ground areas on Route 120, and a large chunk of Mossdeep City.
    * The cheat code for vanilla emerald that allows players to walk through walls only nullifies the check for the collision bit, and not the check for elevation, which is why it's impossible to walk from land to water in the vanilla game when using it. Note that you can pass from land to water via rocks and other things that are normally collision because the 0 elevation collision is always what's used for collision in vanilla, and most of the rest of the game uses elevation 3 only.
        * Corollary: if you want to block cheaters, use collision with a different elevation. Second corollary: [vanilla cheats don't work for source hacks anyway](https://github.com/tustin2121/trihard-emerald/wiki/Cheat-Codes), so it doesn't much matter.
* Scripting
    * Set your editor rulers to column 13 and column 56. As long as your script's text strings are within these two rulers, it will usually be within the limits of the standard field text box.
        * The above assumes a 4 space indent followed by `.string` will precede every string.
    * The `fadeoutbgm` command blocks until the music is faded out. Use `fadedefaultbgm` to not block.
    * Do not `hidemoneybox` without ensuring there is a money box to hide. Doing so will cause the game to softlock in a glitched state.
    * The `warp` commands do not block. You must `waitstate` after them before releasing, otherwise you will release too quickly, nothing will happen, and you might cause an effective softlock depending on what you did.
    * Despite appearances, `waitmovement 0` does not wait for all movement to finish. It waits for the last instance of `applymovement` to end. It might be better to explicitly declare which event you're waiting for.
    * The `applymovement` command does not hide the messagebox.
    * Trick of the trade: If you put a `"\p$"` at the end of a string, you do not have to do `waitbuttonpress` after a `message`, as the `\p` will be considered the button press you wait for, and it will also have an arrow indicator and select sound. The Birch intro uses this trick all the time.
    * The `special FunctionName` syntax is a glorified `callnative FunctionName`. There's in effect no difference between them. The `special` command will be smaller as it uses a u16 index into a table instead of a u32 pointer to a function, but the special table must be maintained as a tradeoff.
    * Pointer tables MUST be aligned 2. You must have an `.align 2` above a pointer table's symbol, otherwise it's 50/50 whether any pointers in the table will work from build to build. This is because of the ARM chip's word boundary requirements (which are u16s, btw).
        * This goes for Pokemart item lists as well.
    * `setobjectxyperm` changes an event object template's x/y position. These only affect objects before they are instantiated (ie, not on screen). `setobjectxy` changes an event object's x/y position. These only affect objects after they are instantiated (ie, on screen).
        * When changing object positions in an OnLoad script, use `setobjectxyperm`, as the objects aren't yet instantiated.
* Virtual Objects
    * They are sprites which look like event objects, but do not act like event objects.
    * They are used in and were made for the contest cutscenes (ie, the overworld bit before and after the judging "battle" screen). Check out how they work there.
        * Their purpose is to be be used to bypass the visible overworld object limit on a given screen (~15 + the player).
        * Normally when you bypass this limit, you will notice event objects failing to appear and/or flickering into existence the moment another event object is removed from the screen.
    * Virtual objects cannot be moved like event objects. They only stand there and can be turned to look in any cardinal direction. Do not expect to make actors of these objects.
    * They cannot be removed via scripting once created. They will be removed when the map is unloaded (this includes both going into a new map and going into a menu screen).
    * The player walks through Virtual Objects; they do not provide collision inherently. If you intend the player to get close, ensure collision is set on the tile.
    * Virtual objects should be created ON_RESUME, as placing them on load will cause them to be misplaced sometimes. 
    * [See here for an example use outside of constests](https://github.com/tustin2121/trihard-emerald/blob/master/data/maps/EverGrandeCity_WaitingRoom1/scripts.inc#L43).
    * Virtual objects must be given an elevation on creation, or bad things (like all the other event objects on screen vanishing) will occur.
* Triggers
    * If the player is warped onto a trigger, it will not trigger. This includes warping onto a door warp and stepping down from it onto a trigger.
        * Use a frame table script to run a script upon entering from a warp instead.
* Trainers
    * The code that makes the trainers spot you and walk up to you is notoriously flimsy, relying on the map designers and scripters to adhere to a certain set of assumptions in order for things to work.
        * Trainers with their line of sight set to anything other than 0 *MUST* have a trainer battle command as the *very first* command in their script.
        * Corollary: Trainers with a "no_intro" battle command must not have line of sight set to more than 0. The game *WILL* crash.
        * The engine depends on the data being set up in this specific manner, as it sets up the impending battle using unchecked pointers to this script data and interpreting as battle data.
        * Trainers will walk through walls if they spot the player; no checking of collision or metatile data will occur as the game marches them up to the player.
        * You cannot easily harness the line-of-sight system for anything else, and attempting to preface a standard line-of-sight-triggered battle with anything other than a standard dialog box is impossible without significant changes to the game engine.
            * The line-of-sight system is actually pretty badly coded, with basically a brute-force approach to checking every frame if the player is in sight of an instantiated object event.
    * There's a reason that every time the game wants to do a double battle, it checks to make sure the player has more than one pokemon alive. The game was not programmed to handle setting up a battle with only one pokemon alive. Don't force it to.
        * The most noticeable glitch to this effect is a duplication of the singular pokemon into both party slots.
        * The game has programmed into it the ability to do a double wild battle that is never used in the vanilla game. It functions, but it's not polished.
    * There's a reason the battle goes to black when starting a trainer battle: instantiating pokemon teams is a taxing operation. If you attempt to generate a pokemon as part of an overworld script, expect the game to lag for a few frames, worse if you're generating more than one. *Definitely* don't try to do it after an `applymovement` to the player in an attempt to mitigate the lag spike at either end of the movement, as that only makes the lag ten times more noticable. Totally not speaking from experience or anything...
    * DON'T TOUCH THE BATTLE SYSTEM UNLESS YOU KNOW WHAT YOU'RE DOING. That way madness lies... It's a miracle the gen 3 battle system isn't *more* broken...
* Default Palette Setup:
    * Object Palettes 2-5 are standard object palettes. All event objects share these palettes.
    * Object palettes 6-9 are standard object reflection palettes. These are so all objects can have a water reflection.
    * 0 is reserved for the player palette, 1 is reserved for the player's reflection palette.
    * 10 and 11 are reserved for special palettes, like the rival's palette and reflection palette.
    * Background palettes 13-16 are reserved for text windows. Usually palette 15 is used for the standard textbox palette. This palette is written to any time the textbox opens.
    * The game has two palette buffers, one for unfaded colors, and a derivative one for faded colors. The faded colors are the ones copied to VRAM, and the fading is used for fading in and out when doing transitions.
* Converting from pokeruby
    * Ruby/Sapphire and Emerald have major differences in text rendering. The text renderer was rewritten from the ground up for FireRed, most likely, and this is backported to Emerald. You cannot expect to copy (non-scripting) code from RS into Emerald without accounting for the fundamental difference in text rendering between the two. Emerald's text renderer is far more sophisticated than RS's.

