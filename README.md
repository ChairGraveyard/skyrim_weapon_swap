What Is It?
------------
Skyrim currently does not have a way to hotkey an item to be equipped into the left hand. Weapon Swap alleviates this frustration by allowing you to press your left-hand weapon hotkey (equips to right hand), press the (configurable) weapon swap key, then press your right-hand weapon hotkey to equip a weapon into your off-hand via hotkey. 

Weapon Swap has a few INI settings you should know about. First is the key that Weapon Swap will be activated by. There is a list of key-codes below the other settings. Next, there are three settings related to messages that Weapon Swap will print. The first is print_start_message, and is the message that Weapon Swap will print when it's loaded. Next is print_error_messages, and controls whether or not error messages will be printed. The last is wait_time_for_swap which determines how long the script processing will delay before swapping the weapon again.

Requirements
----------------------
http://forums.bethsoft.com/topic/1355668-rel-script-dragon-topic-6/

Installation
-----------------
After installing the files from Script Dragon, copy weaponswap.asi and weaponswap.ini (located in the \bin file of this archive) to SkyrimInstall\asi or SkyrimInstall\Data\asi where SkyrimInstall is your main Skyrim install directory (should have TESV.exe).

Usage
------------
With a weapon in either hand, press Home (or your preferred configured key, set in weaponswap.ini) to swap it to the other hand. Works with two weapons equipped as well.

To Compile/For Developers
-------------
Add the project file to your Script Dragon solution (or view weaponswap.cpp). A rebuild will output the binary .asi file to the bin folder after adding the project. Since the project is just one file, I am not going to include project files for various versions of Visual Studio as it is easy enough to copy one of the existing example projects and add weaponswap.cpp.

Credits
-------------------
Alexander Blade for making Script Dragon and helping me get the functions for Weapon Swap working.

License
--------------
WeaponSwap and it's source code are licensed under a Creative Commons Attribution 3.0 Unported (CC BY 3.0) license. This means you are free to share and remix the work (even commercially) under the following conditions:

 - Attribution — You must attribute the work in the manner specified by the author or licensor (but not in any way that suggests that they endorse you or your use of the work).

A "Thanks to ChairGraveyard for creating WeaponSwap" is fine.

<a rel="license" href="http://creativecommons.org/licenses/by/3.0/"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by/3.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/3.0/">Creative Commons Attribution 3.0 Unported License</a>.