public TASK_HUD() 
{
	new Players[32], Num;
	get_players(Players, Num, "ch");
	
	for(new index = 0; index <= Num; index++) 
	{
		new id = Players[index]
		
		if(is_user_alive(id) && user_has_team(id)) 
		{
			// Level: 15   Exp: 80%   Bank: xxx $   Rune: None   Ultimate: None  
			new szString[256];
			formatex(szString, 255, "Level: %d  XP: %d/%d  $: %d  Rune: None", get_user_level(id), get_user_xp(id), get_user_levelup_xp(id), get_user_bank(id) );
		
			Create_StatusText( id, 0, szString );
		
			/*
			new Message[128], Powers[64], Ultimate[64];
			#if defined POWERS
			if(get_user_next_level_xp(id))
				formatex(Powers,sizeof(Powers)-1,"^nLevel: %d XP: %d/%d", get_user_level(id), get_user_xp(id), get_user_next_level_xp(id));
			else
				formatex(Powers,sizeof(Powers)-1,"^nLevel: %d XP: %d", get_user_level(id), get_user_xp(id));
			#endif
			
			#if defined ULTIMATES
			formatex(Ultimate,sizeof(Ultimate)-1, "^nUltimate: None");
			if(get_user_ultimate(id) == 1)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Suicide Bomber");
			else if(get_user_ultimate(id) == 2)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Blink");
			else if(get_user_ultimate(id) == 3)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Chain Lightning");
			else if(get_user_ultimate(id) == 4)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Entangling Roots");
			else if(get_user_ultimate(id) == 5)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Immolate");
			else if(get_user_ultimate(id) == 6)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Big Bad Voodoo");
			else if(get_user_ultimate(id) == 7)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Vengeance");
			else if(get_user_ultimate(id) == 8)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Locust Swarm");
			else if(get_user_ultimate(id) == 9)
				formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Ice Lightning");
			#endif
			formatex(Message,sizeof(Message)-1,"Health: %d Armor: %d%s%s", get_user_health(id), get_user_armor(id), Powers, Ultimate);
			HudMessage(id, Message, 200, 100, 0, 0.02, 0.95, _, _, 0.5)
			*/
		}
		
		/*
		new Spectators[32], SpecNum;
		get_players(Players, SpecNum, "bch");
		for(new i = 0; i < SpecNum; i++) 
		{
			new Spectator = Spectators[i];		
			if(!is_user_alive(Spectator) && pev(Spectator, pev_iuser2) == id && is_user_connected(Spectator) && id != Spectator) {
				new Name[32], Message[128], Powers[64], Ultimate[64];
				
				get_user_name(id, Name, 31);
				#if defined POWERS
				if(get_user_next_level_xp(id))
					formatex(Powers,sizeof(Powers)-1,"^nLevel: %d XP: %d/%d", get_user_level(id), get_user_xp(id), get_user_next_level_xp(id));
				else
					formatex(Powers,sizeof(Powers)-1,"^nLevel: %d XP: %d", get_user_level(id), get_user_xp(id));
				#endif
				#if defined ULTIMATES
				formatex(Ultimate,sizeof(Ultimate)-1, "^nUltimate: None");
				if(get_user_ultimate(id) == 1)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Suicide Bomber");
				else if(get_user_ultimate(id) == 2)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Blink");
				else if(get_user_ultimate(id) == 3)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Chain Lightning");
				else if(get_user_ultimate(id) == 4)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Entangling Roots");
				else if(get_user_ultimate(id) == 5)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Immolate");
				else if(get_user_ultimate(id) == 6)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Big Bad Voodoo");
				else if(get_user_ultimate(id) == 7)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Vengeance");
				else if(get_user_ultimate(id) == 8)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Locust Swarm");
				else if(get_user_ultimate(id) == 9)
					formatex(Ultimate,sizeof(Ultimate)-1,"^nUltimate: Ice Lightning");
				#endif
				
				formatex(Message,sizeof(Message)-1,"%s^nHealth: %d Armor: %d%s%s", Name, get_user_health(id), get_user_armor(id), Powers, Ultimate);
				HudMessage(Spectator, Message, 200, 100, 0, 0.02, 0.90, _, _, 0.5)
			}				
		}
		*/ 
		
	}
}	











stock Create_StatusText(id, linenumber, text[]){

	message_begin( MSG_ONE, gmsgStatusText, {0,0,0}, id )
	write_byte( linenumber )			// line number of status bar text
	write_string( text )				// status bar text
	message_end()
}


