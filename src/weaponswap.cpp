/* 
	WEAPON SWAP PLUGIN	
	(C) ChairGraveyard 2012		
*/

#include "common\skyscript.h"
#include "common\obscript.h"
#include "common\types.h"
#include "common\enums.h"
#include "common\plugin.h"

#define CONFIG_FILE "weaponswap.ini"
#define SCR_NAME "WeaponSwap"

// unequip - Simple wrapper for Actor::UnequipItem.
void unequip( CActor *player, TESObjectWEAP *weapon )
{
	Actor::UnequipItem( player, (TESForm*)weapon, false, false );
}

// execute_command - Simple wrapper for ExecuteConsoleCommand.
void execute_command( CActor *player, char *command )
{
	ExecuteConsoleCommand( command, player );
}

// Un-equips a single weapon in one hand and re-equips it to the opposite hand.
void swap_one_hand( CActor *player, TESObjectWEAP *weapon, char *command )
{
	// Un-equip so the item is in inventory.
	unequip( player, weapon );
	
	// Execute the equip command on the player.
	execute_command( player, command );
}

// Un-equips both weapons and re-equips to the opposite hands.
void swap_both_hands(	CActor *player, 
						TESObjectWEAP *weapon_one, 
						TESObjectWEAP *weapon_two, 
						char *command_one, 
						char *command_two )
{
	// Un-equip both weapons first.
	unequip( player, weapon_one );
	unequip( player, weapon_two );
	
	// Equip them in the opposite hands.
	execute_command( player, command_one );
	execute_command( player, command_two );
}

void main()
{
   /// Configuration Settings @{
   BYTE key                   =  IniReadInt( CONFIG_FILE, "main", "key", 0 );                   /// Key to bind to weapon swap.
   BYTE print_start_message   =  IniReadInt( CONFIG_FILE, "main", "print_start_message", 1 );   /// Should we print the start message?
   BYTE print_error_messages  =  IniReadInt( CONFIG_FILE, "main", "print_error_messages", 1 );  /// Should we print error messages?
   BYTE wait_time_for_swap    =  IniReadInt( CONFIG_FILE, "main", "wait_time_for_swap", 150 );  /// Delay between being able to swap again.
   /// }@

   if ( print_start_message )
	   PrintNote( "[%s] started, press '%s' to use.", SCR_NAME, GetKeyName( key ).c_str() );
	
   // Command buffers used to build the equip/un-equip commands.
   char left_equip_command[50];
   char right_equip_command[50];

   // This accounts for the case where both hands are equipped.
   bool swap_both = false;
	
	while ( TRUE )
	{
		if ( GetKeyPressed( key ) )
		{
		    // Clear out the command buffers each time.
			memset( left_equip_command, 0, sizeof( left_equip_command ) );
			memset( right_equip_command, 0, sizeof( right_equip_command ) );

            // Get the player.
			CActor *player = Game::GetPlayer(); 
			if ( !player )
			{
            if ( print_error_messages )
				   PrintNote( "Invalid player! Something went wrong." );

				return;
			}

			// If swap_back is set, we want to be able
			// to swap back from the left to the right hand.
			TESObjectWEAP *right_hand_weapon = Actor::GetEquippedWeapon( player, false );
			TESObjectWEAP *left_hand_weapon = Actor::GetEquippedWeapon( player, true );

            // If we can't find a weapon in either hand,
            // notify the user if error printing is enabled.
			if ( !right_hand_weapon && !left_hand_weapon )
			{
				if ( print_error_messages )
					PrintNote( "No weapons found." );
			}

			// Both hands equipped, use the two-hand specific swap.
			if ( right_hand_weapon && left_hand_weapon )
				swap_both = true;

            // Handle building and swapping the 
            // right hand if we don't have 
            // another weapon in the left.
			if ( right_hand_weapon )
			{
				// Build the swap to left command.
				sprintf_s( left_equip_command, "equipitem %x 0 Left", Form::GetFormID( (TESForm*)right_hand_weapon ) );
				
				// If we're not swapping both, do the swap now.
				if ( !swap_both )
                {
					swap_one_hand( player, right_hand_weapon, left_equip_command );
                    Wait( wait_time_for_swap );
                }
			}

            // Handle the left hand.
			if ( left_hand_weapon )
			{
				// Build the swap to right command.
				sprintf_s( right_equip_command, "equipitem %x 0 Right", Form::GetFormID( (TESForm*)left_hand_weapon ) );
				
				// If we're not swapping both, do the swap now.
				if ( !swap_both )
                {
					swap_one_hand( player, left_hand_weapon, right_equip_command );
                    Wait( wait_time_for_swap );
                }
			}
			
			// If we have two weapons equipped, 
			// swap both of them at once.
			// We fill the command buffers above in 
			// the check for each hand's weapon.
			// We use a special swap function for
			// the both weapon case because both 
			// weapons need to be un-equipped before
			// executing the equip commands.
			if ( swap_both )
			{
				swap_both_hands(	player, 
									right_hand_weapon, 
									left_hand_weapon, 
									right_equip_command, 
									left_equip_command );									

                Wait( wait_time_for_swap );

				swap_both = false;
			}
		}

		Wait( 0 );
	}
}

