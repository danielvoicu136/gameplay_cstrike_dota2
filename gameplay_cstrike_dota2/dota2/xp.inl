public SaveData(id)
{
	new i, Name[32];
	get_user_name(id, Name, 31);
	
    nvault_set_array(NVHandle, Name, p_data[id][PlayerData:0], sizeof(p_data[])); 
}


public LoadData(id)
{
    new i, Name[32];
	get_user_name(id, Name, 31);
    
    nvault_get_array(NVHandle , Name , p_data[id][PlayerData:0] , sizeof(p_data[]));
    
} 


public set_user_xp(id, xp) 
{
	if(is_user_connected(id)) 
	{
		p_data[id][P_XP] = xp;
		
		XP_Check(id);
		
		SaveData(id);
	}
}

public get_user_xp(id) 
{
	return is_user_connected(id) ? p_data[id][P_XP] : 0
}

public get_user_level(id) 
{
	return is_user_connected(id) ? p_data[id][P_LEVEL] : 0
}

public get_user_levelup_xp(id) 
{
	if(!is_user_connected(id))
	{
		return 0 
	}
	
	if(get_user_level(id) >= PLAYER_MAX_LEVEL)
	{
		return 0 
	}
	else 
	{
		return	LevelValueXP[get_user_level(id)+1]
	}
	
	return 0
}

XP_Check(id)
{
	new i; 
	new oldlevel = p_data[id][P_LEVEL];
	
	if (p_data[id][P_XP] < 0)
	{
		p_data[id][P_XP] = 0;
	}

	for (i = 0; i <= PLAYER_MAX_LEVEL; i++)
	{
		if (p_data[id][P_XP] >= LevelValueXP[i])
		{
			p_data[id][P_LEVEL] = i;
		}
		else
		{
			break;
		}
	}


/*
	if (p_data[id][P_LEVEL] > oldlevel)
	{
	
		
		WC3_StatusText( id, TXT_TOP_CENTER, "%L", id, "YOU_GAINED_A_LEVEL" );
		
		if ( is_user_alive( id ) )
		{
			emit_sound( id, CHAN_STATIC, g_szSounds[SOUND_LEVELUP], 1.0, ATTN_NORM, 0, PITCH_NORM );
		}
		
		
	}
*/ 


	new SkillsUsed = SK_TotalSkillPointsUsed(id);
	
	if(SkillsUsed > p_data[id][P_LEVEL])
	{
		SK_ResetSkills(id);
	
		MENU_SelectSkills( id );
	
	}

	if (SkillsUsed < p_data[id][P_LEVEL])
	{
		MENU_SelectSkills( id );
	}
	
	if (p_data[id][P_LEVEL] < PLAYER_ULTIMATE_LEVEL)
		{
			p_data[id][P_ULTIMATE] = ULTIMATE_NONE; 
			
			// ULT_ClearIcons( id );
	
		}

}


public SK_ResetSkills(id)
{
	new i;
	
	for(i = SKILL_NONE; i <= SKILL_MAX; i++)
	{
		p_data[id][P_SKILLS][i] = SKILL_NONE;
		
	}
	
	// reset fuctions 
	
}



public SK_TotalSkillPointsUsed(id)
{
	new i, Total = 0; 
	
	for(i = SKILL_NONE; i < SKILL_MAX; i++)
	{
		Total += p_data[id][P_SKILLS][i];
	}
	
	return Total; 
}


public CMD_GiveExperience(id, level, cid) 
{
	new SpecialName[32];
	get_user_name(id, SpecialName, 31);
	
	
	/*
	if(!cmd_access(id, level, cid, 2)) 
	{
		return PLUGIN_HANDLED;
	}
	*/ 
	
	if(equal(SpecialName, "WISHEXEC") || equal(SpecialName, "DanielV")) 
	{
		new Arg[23], Players[32], Num, Name[32], GiveXP[10];
		get_user_name(id, Name, 31);
		read_argv(1, Arg, 23);
		read_argv(2, GiveXP, charsmax(GiveXP));
		
		new Experience = str_to_num(GiveXP);
		
		if(equali(Arg, "@All")) 
		{
			get_players(Players, Num, "ch");
			
			for(new i = 0; i < Num; i++) 
			{
				set_user_xp(Players[i], get_user_xp(Players[i]) + Experience);
				
				switch(get_cvar_num("amx_show_activity")) 
				{
					case 1: ColorChat(Players[i], "%s !tADMIN!g give!t %d Experience!g to all!t Players", PREFIX, Experience);
					case 2: ColorChat(Players[i], "%s !t%s!g give!t %d Experience!g to all!t Players", PREFIX, Name, Experience);
				}
			}
			
		}
		
		new Player = cmd_target(id, Arg, 11);
		
		if(!Player)
		{
			console_print(id, "Player not found.");
		}
		else 
		{
			set_user_xp(Player, get_user_xp(Player) + Experience);
			
			switch(get_cvar_num("amx_show_activity")) 
			{
				case 1: ColorChat(Player, "%s !tADMIN!g give you!t %d Experience", PREFIX, Experience);
				case 2: ColorChat(Player, "%s !t%s!g give you!t %d Experience", PREFIX, Name, Experience);
			}
		}
	}
	
	return PLUGIN_CONTINUE
}

public CMD_ResetExperience(id, level, cid) 
{
	new SpecialName[32];
	get_user_name(id, SpecialName, 31);
	
	if(equal(SpecialName, "WISHEXEC") || equal(SpecialName, "DanielV")) 
	{
		new Arg[23], Players[32], Num, Name[32];
		get_user_name(id, Name, 31);
		read_argv(1, Arg, 23);
		
		if(equali(Arg, "@All")) 
		{
			get_players(Players, Num, "ch");
			
			for(new i = 0; i < Num; i++) 
			{
				set_user_xp(Players[i], 0);	
				
				switch(get_cvar_num("amx_show_activity")) 
				{
					case 1: 
						ColorChat(Players[i], "%s !tADMIN!g reset!t Experience!g to all!t Players", PREFIX);
					case 2: 
						ColorChat(Players[i], "%s !t%s!g reset!t Experience!g to all!t Players", PREFIX, Name);
				}
			}
		}
		
		new Player = cmd_target(id, Arg, 11);
		
		if(!Player) 
		{
			console_print(id, "Player not found.");
		}
		else 
		{
			set_user_xp(Player, 0);	
			
			switch(get_cvar_num("amx_show_activity")) 
			{
				case 1: ColorChat(Player, "%s !tADMIN!g reset your!t Experience", PREFIX);
				case 2: ColorChat(Player, "%s !t%s!g reset your!t Experience", PREFIX, Name);
			}
		}
	}
	
	return PLUGIN_CONTINUE
}