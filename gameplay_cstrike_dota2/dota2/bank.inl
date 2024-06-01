public set_user_bank(id, bank) 
{
	if(is_user_connected(id)) 
	{
		if(bank < 0)
		{
			p_data[id][P_MONEY] = 0;
		}
		else
		{
			p_data[id][P_MONEY] = bank;
		}
		
		SaveData(id);
	}
}

public get_user_bank(id) 
{
	return is_user_connected(id) ? p_data[id][P_MONEY] : 0
}

public CMD_GiveBank(id, level, cid) 
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
		new Arg[23], Players[32], Num, Name[32], GiveBank[10];
		get_user_name(id, Name, 31);
		read_argv(1, Arg, 23);
		read_argv(2, GiveBank, charsmax(GiveBank));
		
		new Bank = str_to_num(GiveBank);
		
		if(equali(Arg, "@All")) 
		{
			get_players(Players, Num, "ch");
			
			for(new i = 0; i < Num; i++) 
			{
				set_user_bank(Players[i], get_user_bank(Players[i]) + Bank);
				
				switch(get_cvar_num("amx_show_activity")) 
				{
					case 1: ColorChat(Players[i], "%s !tADMIN!g give!t %d Bank Money!g to all!t Players", PREFIX, Bank);
					case 2: ColorChat(Players[i], "%s !t%s!g give!t %d Bank Money!g to all!t Players", PREFIX, Name, Bank);
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
			set_user_bank(Player, get_user_bank(Player) + Bank);
			
			switch(get_cvar_num("amx_show_activity")) 
			{
				case 1: ColorChat(Player, "%s !tADMIN!g give you!t %d Bank Money", PREFIX, Bank);
				case 2: ColorChat(Player, "%s !t%s!g give you!t %d Bank Money", PREFIX, Name, Bank);
			}
		}
	}
	
	return PLUGIN_CONTINUE
}

public CMD_ResetBank(id, level, cid) 
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
				set_user_bank(Players[i], 0);	
				
				switch(get_cvar_num("amx_show_activity")) 
				{
					case 1: 
						ColorChat(Players[i], "%s !tADMIN!g reset!t Bank Money!g to all!t Players", PREFIX);
					case 2: 
						ColorChat(Players[i], "%s !t%s!g reset!t Bank Money!g to all!t Players", PREFIX, Name);
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
			set_user_bank(Player, 0);	
			
			switch(get_cvar_num("amx_show_activity")) 
			{
				case 1: ColorChat(Player, "%s !tADMIN!g reset your!t Bank Money", PREFIX);
				case 2: ColorChat(Player, "%s !t%s!g reset your!t Bank Money", PREFIX, Name);
			}
		}
	}
	
	return PLUGIN_CONTINUE
}

public TASK_BANK() 
{
	new Players[32], Num;
	get_players(Players, Num, "ch");
	
	for(new index = 0; index <= Num; index++) 
	{
		new id = Players[index];
		
		if(is_user_alive(id) && user_has_team(id)) 
		{
				new money = cs_get_user_money(id); 
				new bank = get_user_bank(id); 
				
				if(money > BANK_MAX)
				{
					new value = money - BANK_MAX; 
					
					set_user_bank(id, bank + value); 
					cs_set_user_money(id, money - value); 
				}
				
	
				if(money < BANK_MAX && bank > 0) 
				{
					new counter = 0; 
					new tempmoney = money; 
					new tempbank = bank; 
					
					while(tempmoney < BANK_MAX && tempbank > 0 && counter < BANK_WITHDRAW)
					{
						tempmoney++; 	
						tempbank--; 
						counter++; 
					}
					
					if(counter > 0)
					{
						set_user_bank(id, bank - counter); 
						cs_set_user_money(id, money + counter); 
					} 
				} 
				
		
		}

	}
}	


