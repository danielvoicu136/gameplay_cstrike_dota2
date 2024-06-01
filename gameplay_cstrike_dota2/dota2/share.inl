public user_has_team(id)
{
	new team = get_user_team(id);

	if (team == 1 || team == 2)
	{
		return true;
	}
	
	return false;
}


