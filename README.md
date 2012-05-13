What Is It?
------------
Skyrim currently does not have a way to hotkey an item to be equipped into the left hand. Weapon Swap alleviates this frustration by allowing you to press your left-hand weapon hotkey (equips to right hand), press the (configurable) weapon swap key, then press your right-hand weapon hotkey to equip a weapon into your off-hand via hotkey. 

Weapon Swap has a few INI settings you should know about. First is the key that Weapon Swap will be activated by. There is a list of key-codes below the other settings. Next, there are three settings related to messages that Weapon Swap will print. The first is print_start_message, and is the message that Weapon Swap will print when it's loaded. Next is print_error_messages, and controls whether or not error messages will be printed. The last is wait_time_for_swap which determines how long the script processing will delay before swapping the weapon again.

Requirements
----------------------
http://forums.bethsoft.com/topic/1355668-rel-script-dragon-topic-6/

Installation
-----------------
After installing the files from Script Dragon, copy weaponswap.asi and weaponswap.ini to SkyrimInstall\asi or SkyrimInstall\Data\asi where SkyrimInstall is your main Skyrim install directory (should have TESV.exe).

Usage
------------
With a weapon in either hand, press Home (or your preferred configured key, set in weaponswap.ini) to swap it to the other hand. Works with two weapons equipped as well.


To Compile
-------------
Add the project file to your Script Dragon solution. A rebuild will output the binary .asi file to the bin folder.

Credits
-------------------
Alexander Blade for making Script Dragon and helping me get the functions for Weapon Swap working.