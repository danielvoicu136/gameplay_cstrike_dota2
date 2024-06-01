/*======================================================
=== Utils Default
=======================================================*/

#define	PLAYER_DEFAULT_HEALTH			100					// default health
#define PLAYER_DEFAULT_SPEED			260					// default speed

#define	PLAYER_MAX_HEALTH				250					// max health
#define PLAYER_MAX_ARMOR				250					// max armor

#define PLAYER_DEFAULT_MODEL_CT			"skin"				// default skin ct 
#define	PLAYER_DEFAULT_MODEL_TE			"skin"				// default skin te 




/*======================================================
=== Utils Language 
=======================================================*/

#define	LANG_NAME					0
#define	LANG_DESCRIPTION			1
#define	LANG_COST					2


/*======================================================
=== Utils Global 
=======================================================*/

#define MAX_PLAYERS    32


/*======================================================
=== Utils Menu 
=======================================================*/

new ChooseTeamOverrideActive[MAX_PLAYERS+1];
new Menu; 

/*======================================================
=== Utils Storage
=======================================================*/

new NVHandle;

enum PlayerData
{
    P_NAME[32],
    P_TIME,
    P_MONEY,
    P_LEVEL,
    P_XP,
    P_ULTIMATE,
	P_SKILLS[SKILL_MAX] 
}

new p_data[MAX_PLAYERS + 1][PlayerData];



/*======================================================
=== Utils HUD
=======================================================*/

#define TASK_HUD_FREQ			0.5

//#define TASKID_HUDINFO			552

new gmsgStatusText;









