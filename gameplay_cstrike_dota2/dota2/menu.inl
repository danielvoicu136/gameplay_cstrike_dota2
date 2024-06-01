public GameMenuMessage(id) 
{
	ColorChat(id, "%s !yYou can press!g M!y to open the menu.",PREFIX);	
}
	

public ChooseTeam(id) 
{
	if (ChooseTeamOverrideActive[id]) 
	{
		GameMenu(id)
		return PLUGIN_HANDLED;
	}
	
	ChooseTeamOverrideActive[id] = true
	return PLUGIN_CONTINUE;
}


public GameMenu(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\yHero XP Mode 2020 \d(in work)");
		
		Menu = menu_create(Title, "_GameMenu");
		
		new szItem1[256];
		formatex(szItem1,sizeof(szItem1)-1,"Select \ySkills");
		menu_additem(Menu, szItem1, "1", 0); 
		
		new szItem2[256];
		formatex(szItem2,sizeof(szItem2)-1,"Select \yUltimate^n");
		menu_additem(Menu, szItem2, "2", 0); 
		
		new szItem3[256];
		formatex(szItem3,sizeof(szItem3)-1,"Shop \yRune^n");
		menu_additem(Menu, szItem3, "3", 0); 
		
		new szItem4[256];
		formatex(szItem4,sizeof(szItem4)-1,"Account");
		menu_additem(Menu, szItem4, "4", 0); 
		
		new szItem5[256];
		formatex(szItem5,sizeof(szItem5)-1,"Who is ...^n");
		menu_additem(Menu, szItem5, "5", 0); 
		
		
		new szItem6[256];
		formatex(szItem6,sizeof(szItem6)-1,"\yChange Team^n");
		menu_additem(Menu, szItem6, "6", 0); 
		
		new szItem7[256];
		formatex(szItem7,sizeof(szItem7)-1,"Information");
		menu_additem(Menu, szItem7, "7", 0); 
				
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);
	}
}

public _GameMenu(id, menu, item) 
{
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	
	new Data[6], Name[64];
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	
	switch(Key)
	{
		case 1: MENU_SelectSkills(id);
	
		case 2: MENU_SelectUltimate(id);
		
		case 3: MENU_Shop(id);
		
		case 4: client_print( id, print_chat, "%s Ai apasat pe 4.", PREFIX );
		
		case 5:	client_print( id, print_chat, "%s Ai apasat pe 5.", PREFIX );
		
		case 6: {
		
			ChooseTeamOverrideActive[id] = false;
			client_cmd(id, "chooseteam");
		
		}
		
		case 7: MENU_Info(id);
			
		default: return PLUGIN_HANDLED;
	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}



public MENU_SelectSkills(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\ySelect Skills");
		
		Menu = menu_create(Title, "_MENU_SelectSkills");
		
		new i, szItem[256], szKey[256];
		
		for (i = SKILL_NONE + 1; i < SKILL_MAX; i++) 
		{ 
				
			formatex(szItem,sizeof(szItem)-1,"%s \d(%s)",mySkillInfo[i][LANG_NAME],mySkillInfo[i][LANG_DESCRIPTION]);

			num_to_str(i,szKey,255);
			menu_additem(Menu, szItem, szKey, 0); 
		}
  
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);
	}
}

public _MENU_SelectSkills(id, menu, item) 
{
	
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	
	new Data[6], Name[64], i;
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	
	for (i = SKILL_NONE + 1; i < SKILL_MAX; i++) 
	{ 
		if(Key == i)
		{
				client_print( id, print_chat, "%s Ai apasat pe %d.", PREFIX, i );
				break;
		}

	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}


public MENU_SelectUltimate(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\ySelect Ultimate ");
		
		Menu = menu_create(Title, "_MENU_SelectUltimate");
		
		new i, szItem[256], szKey[256];
		
		for (i = ULTIMATE_NONE + 1; i < ULTIMATE_MAX; i++) 
		{ 
				
			formatex(szItem,sizeof(szItem)-1,"%s \d(%s)",myUltimateInfo[i][LANG_NAME],myUltimateInfo[i][LANG_DESCRIPTION]);

			num_to_str(i,szKey,255);
			menu_additem(Menu, szItem, szKey, 0); 
		}
  
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);
	}
}

public _MENU_SelectUltimate(id, menu, item) 
{
	
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	
	new Data[6], Name[64], i;
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	
	for (i = ULTIMATE_NONE + 1; i < ULTIMATE_MAX; i++) 
	{ 
		if(Key == i)
		{
				client_print( id, print_chat, "%s Ai apasat pe %d.", PREFIX, i );
				break;
		}

	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}




public MENU_Shop(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\yShop ");
		
		Menu = menu_create(Title, "_MENU_Shop");
		
		new i, szItem[256], szKey[256];
		
		for (i = ITEM_NONE + 1; i < ITEM_MAX; i++) 
		{ 
				
			formatex(szItem,sizeof(szItem)-1,"%s \d(%s) \R\y%s $",myItemInfo[i][LANG_NAME],myItemInfo[i][LANG_DESCRIPTION],myItemInfo[i][LANG_COST]);

			num_to_str(i,szKey,255);
			menu_additem(Menu, szItem, szKey, 0); 
		}
  
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);
	}
}

public _MENU_Shop(id, menu, item) 
{
	
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	
	new Data[6], Name[64], i;
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	
	for (i = ITEM_NONE + 1; i < ITEM_MAX; i++) 
	{ 
		if(Key == i)
		{
				client_print( id, print_chat, "%s Ai apasat pe %d.", PREFIX, i );
				break;
		}

	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}



public MENU_Info(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\yInformation");
		
		Menu = menu_create(Title, "_MENU_Info");
		
		new i, szItem[256], szKey[256];
		
		for (i = 1; i < sizeof(myInfo); i++) 
		{ 
				
			formatex(szItem,sizeof(szItem)-1,"%s \d(%s)",myInfo[i][LANG_NAME],myInfo[i][LANG_DESCRIPTION]);

			num_to_str(i,szKey,255);
			menu_additem(Menu, szItem, szKey, 0); 
		}
  
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);
	}
}

public _MENU_Info(id, menu, item) 
{
	
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	
	new Data[6], Name[64], i;
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	
	for (i = 1; i < sizeof(myInfo); i++) 
	{ 
		if(Key == i)
		{
				client_print( id, print_chat, "%s Ai apasat pe %d.", PREFIX, i );
				break;
		}

	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}