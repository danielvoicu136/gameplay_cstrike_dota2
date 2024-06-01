/*======================================================
=== General Configs
=======================================================*/

#define GAME_MENU						"Dota 2 Ultimate"	// main menu header
 
#define GAME_NAME						"!g[DOTA]"		// game name tag

#define PLAYER_SPECIAL_MODEL_CT			"deadct"			// special skin ct 
#define	PLAYER_SPECIAL_MODEL_TE			"deadte"			// special skin te 

/*======================================================
=== Level & XP Configs 
=======================================================*/

#define PLAYER_MAX_LEVEL				100 				// player max level

#define XP_LEVEL_UP						1000				// levelup xp
#define XP_LEVEL_UP_MULIPLIER			1.2					// levelup xp multiplier  

#define XP_HEADSHOT			15			// xp for headshot
#define XP_KILL				10			// xp for kill
#define XP_WIN				20			// xp for win 
#define XP_TIMEPLAYED		10			// xp for minute 
#define XP_BOMB_PLANTED		20			// xp for plant 
#define XP_BOMB_DEFUSED		20			// xp for defuse 
#define XP_LUCK_BONUS		5			// xp bonus + - 

/*======================================================
=== Bank Configs
=======================================================*/

#define	PLAYER_MAX_MONEY		10000	// max money in use 	
#define BANK_MAX_LIMIT			99999	// max money in bank 
#define BANK_WITHDRAW_VALUE		100		// value of withdraw
#define TASK_WITHDRAW_FREQ		2.0		// frequency of withdraw

/*======================================================
=== VIP Configs
=======================================================*/

#define VIP_PLAYER							ADMIN_LEVEL_H		// special flag 
#define VIP_GAME_NAME						"!g[DOTA VIP]"		// special game name tag 
#define VIP_XP_MULTIPLIER 					2.0					// more xp bonus 
#define VIP_BANK_MAX_LIMIT_MULTIPLIER 		2.0					// more bank limit 
#define VIP_BANK_WITHDRAW_MULTIPLIER		2.0					// value of withdraw

/*======================================================
=== Loot Box Configs
=======================================================*/
// soon


/*======================================================
=== Define Skills 
=======================================================*/

enum _:SKILL_MAX  
{

SKILL_NONE,

SKILL_HEALTH,		
SKILL_CRITICAL_GRENADE,			
SKILL_HEALING_KILL,				
SKILL_GRENADE_RECOVERY,				
SKILL_SPEED,						
SKILL_SLOW_STRIKE,				
SKILL_FLASH_RECOVERY,			

SKILL_GRAVITY,			
SKILL_FORCE_STRIKE,			
SKILL_MULTIJUMP,			
SKILL_INVISIBILITY,									
SKILL_HEALING_WAVE,				
SKILL_DAMAGE_WAVE,				

SKILL_MONEY_WAVE,				
SKILL_MONEY_STRIKE,				
SKILL_HEALING_STRIKE,			
SKILL_DAMAGE_STRIKE,			
SKILL_FROZEN_SMOKE,			 	
SKILL_SMOKE_RECOVERY,			
SKILL_GRENADE_EVASION,			

SKILL_ULTIMATE_EVASION,
SKILL_SAVE_WEAPON,
SKILL_STUN
	
}

new const SkillDataBase[][][] = {

	{"Name",				"Description",						"Skill Level",	"Unlock Level"},
	{"Flesh Heap",			"increase health",					"5",			"1"},
	{"Sticky Bomb",			"high damage grenade",				"5",			"2"},
	{"Thirst",				"healing after kill",				"5",			"3"},
	{"Rearm",				"grenade recovery",					"5",			"4"},
	{"Surge",				"increase speed",					"5",			"5"},
	{"Grasp",				"slow enemy",						"5",			"6"},
	{"Blinding",			"flash recovery",					"5",			"7"},
	{"Pounce",				"increase jumps",					"5",			"8"},
	{"Impale",				"push enemy",						"5",			"9"},
	{"Leap",				"add multiple jumps",				"5",			"10"},
	{"Meld",				"invisible using knife",			"5",			"11"},
	{"Restoration",			"heal nearby allies",				"5",			"13"},
	{"Heartstopper",		"damage nearby enemies",			"5",			"14"},
	{"Arcane",				"pay nearby allies",				"5",			"15"},
	{"Jinada",				"steal money",						"5",			"16"},
	{"Feast",				"steal health",						"5",			"17"},
	{"Blessing",			"increase damage",					"5",			"18"},
	{"Crystal Nova",		"increase frozen smoke",			"5",			"19"},
	{"Vortex",				"smoke recovery",					"5",			"20"},
	{"Refraction",			"block some grenades",				"5",			"21"},
	{"Matrix",				"block some ultimates",				"5",			"22"},
	{"Rearm",				"weapons recovery",					"5",			"23"},
	{"Frostbite",			"stun enemy",						"5",			"24"}

};








/*======================================================
=== Define Ultimates
=======================================================*/

enum _:ULTIMATE_MAX  
{

ULTIMATE_NONE,

ULTIMATE_EXPLOSION,				
ULTIMATE_TELEPORT,				
ULTIMATE_LIGHTNING,	
ULTIMATE_PRISON,
ULTIMATE_MEDIC,
ULTIMATE_ESCAPE,
ULTIMATE_VIRUS,

ULTIMATE_ASTRAL,				
ULTIMATE_TIMETRAVEL,			
ULTIMATE_SWAP,
ULTIMATE_WARD			
	
}

new const UltimateDataBase[][][] =
{
	{"Name",				"Description",			"Skill Level",	"Unlock Level"},
	{"Blast Off",		   	"detonate explosion",	"0",			"6"},
	{"Relocate",			"teleport on aim",		"0",			"7"},
	{"Thundergods Wrath",	"damage enemy",			"0",			"8"},
	{"Overgrowth",			"stun enemy",			"0",			"9"},
	{"Hand of God",		  	"over healing",			"0",			"10"},
	{"Fiend Gate",			"relocate in spawn",	"0",			"11"},
	{"Wrath of Nature",		"homing damage",		"0",			"12"},
	{"Astral Form",			"wall passing",			"0",			"13"},
	{"Chronosphere",		"return in time",		"0",			"14"},
	{"Nether Swap",			"take enemy place",		"0",			"15"},
	{"Mass Serpent Ward",	"plant wards",			"0",			"16"}
	
}


/*======================================================
=== Define Items 
=======================================================*/

enum _:ITEM_MAX  
{

ITEM_NONE,

ITEM_ANKH,						
ITEM_RESPAWN,					
ITEM_TOME,						
ITEM_LEARN,						
ITEM_SILENCE,						
ITEM_REFRESH,					
ITEM_IMMUNE,						
		
ITEM_SCANNER,					
ITEM_CHAMELEON,					
ITEM_HELM,						
ITEM_REFORGE							
	
}

new const ItemDataBase[][][] =
{
	{"Name",						"Description",				"Amplifier",				"Cost"					},	
	{"Ankh",						"save weapons",				"0",						"2000"					},	
	{"Respawn",						"instant revive",			"0",						"5000"					},	
	{"Tome",						"instant bonus XP",			"100",						"7000"					},	
	{"Learn",						"always double XP",			"2.0",						"2500"					},	
	{"Silence",						"quiet move",				"0",						"2000"					},
	{"Refresh",						"reduce cooldown",			"10",						"4000"					},	
	{"Block",						"block ultimate",			"0",						"2000"					},	
	{"Scanner",						"seek invisibility",		"2.0",						"3000"					},
	{"Chameleon",					"enemy skin",				"0",						"5000"					},
	{"Helm",						"block headshot",			"0",						"7000"					},
	{"Reforge",						"remaster skills",			"0",						"10000"					}	
	
}



/*======================================================
=== Define Help
=======================================================*/


new const HelpDataBase[][][] =
{
	{"None",						"Unknown"																					},
	{"Game",						"play CS with powers"																		},	
	{"Level",						"earn experience to level up"																},	
	{"Experience",					"earn with kill, headshot, win, events"														},
	{"Skills",						"passive powers, each level is one skill point"												},	
	{"|",							"all skills are auto activated by percent chance"											},	
	//{"Wards",						"if X & Z is not working already, use bind x plant and bind z remove"						},
	//{"Bind Button",					"write in console, bind button command, to use that button in game"							},
	{"Ultimate",					"active powers, you can have only one active"												},	
	{"|",							"all ultimates are manual activated with cooldown"											},
	{"|",							"if F is not working already, use bind f ultimate"											},	
	{"Rune",						"passive benefits, you can have one"														},	
	{"|",							"all runes are auto activated on buy"														},
	{"Save Data",					"experience, money and time played are auto saved"											},
	{"Developer Support",			"DanielV - danielvoicu136@gmail.com"														}
}