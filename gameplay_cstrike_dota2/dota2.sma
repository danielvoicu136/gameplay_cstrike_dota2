/*======================================================
=== Library 
=======================================================*/

#include <amxmodx>
#include <amxmisc>
#include <cstrike>
#include <nvault_array>

/*======================================================
=== Files
=======================================================*/
#include "dota2/config.inl"
#include "dota2/var.inl"	
#include "dota2/share.inl"	
#include "dota2/menu.inl"
#include "dota2/bank.inl"	
#include "dota2/xp.inl"	
#include "dota2/hud.inl"
#include "dota2/skills/skills.inl"
#include "dota2/ultimate/ultimate.inl"


/*======================================================
=== Plugin 
=======================================================*/


#define	PLUGIN_NAME			"Dota2" 
#define PLUGIN_VERSION		"1.0"
#define PLUGIN_DEVELOPER	"Daniel"



public plugin_init() {

register_plugin(PLUGIN_NAME, PLUGIN_VERSION, PLUGIN_DEVELOPER)


	NVHandle = nvault_open( "dota2data" );
	gmsgStatusText = get_user_msgid("StatusText");
	
	register_concmd("amx_give_xp", "CMD_GiveExperience", ADMIN_CVAR, "Name/@All -> Amount");
	register_concmd("amx_reset_xp", "CMD_ResetExperience", ADMIN_CVAR, "Name/@All -> Amount");
	register_concmd("amx_give_bank", "CMD_GiveBank", ADMIN_CVAR, "Name/@All -> Amount");
	register_concmd("amx_reset_bank", "CMD_ResetBank", ADMIN_CVAR, "Name/@All -> Amount");

	register_clcmd("chooseteam", "ChooseTeam");
	register_clcmd("gamemenu", "GameMenu");
	register_clcmd("menu", "GameMenu");
	register_clcmd("say gamemenu", "GameMenu");
	register_clcmd("say menu", "GameMenu");	
	register_clcmd("say /gamemenu", "GameMenu");
	register_clcmd("say /menu", "GameMenu");
	register_clcmd("say_team gamemenu", "GameMenu");
	register_clcmd("say_team menu", "GameMenu");
	register_clcmd("say_team /gamemenu", "GameMenu");
	register_clcmd("say_team /menu", "GameMenu");
	
	set_task(120.0, "GameMenuMessage", _,_,_,"b");
	
	set_task(TASK_HUD_FREQ, "TASK_HUD", _, _, _, "b")
	set_task(TASK_BANK_FREQ, "TASK_BANK", _, _, _, "b")
}




public client_connect(id)
{
    LoadData(id);
}

public client_putinserver(id) 
{ 
	ChooseTeamOverrideActive[id] = true;
	//LoadData(id);
}


public client_disconnect(id)
{
    SaveData(id);
}

public plugin_end()
{
    nvault_close( NVHandle );
}












stock ColorChat(const id, const input[], any:...) {
	new count = 1, players[32];
	static msg[191];
	vformat(msg, 190, input, 3);
	
	replace_all(msg, 190, "!g", "^4");
	replace_all(msg, 190, "!y", "^1");
	replace_all(msg, 190, "!t", "^3");
	
	if(id) players[0] = id;
	else get_players(players, count, "ch"); {
		for(new i = 0; i < count; i++) {
			if(is_user_connected(players[i])) {
				message_begin(MSG_ONE_UNRELIABLE, get_user_msgid("SayText"), _, players[i]);
				write_byte(players[i]);
				write_string(msg);
				message_end();
			}
		}
	} 
}