new Timers[MAX_PLAYERS];//AutoNos
AutoNos(playerid, newstate)
{
    if(!IsPlayerInInvalidNosVehicle(playerid,GetPlayerVehicleID(playerid)))
	{
		if(newstate == 2)
		{
			new vid = GetPlayerVehicleID(playerid);
			AddVehicleComponent(vid, 1010);
			KillTimer(Timers[playerid]);
			Timers[playerid] = SetTimerEx("Update", 20000, true, "i", playerid);
		}
	}
}
IsPlayerInInvalidNosVehicle(playerid,vehicleid){
	#define MAX_INVALID_NOS_VEHICLES 38

	new InvalidNosVehicles[MAX_INVALID_NOS_VEHICLES] =
	{
		581,523,462,521,463,522,461,448,468,586,
		509,481,510,472,473,493,595,484,430,453,
		452,446,454,590,569,537,538,570,449,513,
		520,519,487,417,406,556,444,557

	};

	vehicleid = GetPlayerVehicleID(playerid);

	if(IsPlayerInVehicle(playerid,vehicleid))
	{
		for(new i = 0; i < MAX_INVALID_NOS_VEHICLES; i++)
		{
			if(GetVehicleModel(vehicleid) == InvalidNosVehicles[i])
			{
				return true;
			}
		}
	}
	return false;
}

forward Update(playerid);
public Update(playerid){
	if(!IsPlayerConnected(playerid) || !IsPlayerInAnyVehicle(playerid))
		return KillTimer(Timers[playerid]);
	if(!IsPlayerInInvalidNosVehicle(playerid,GetPlayerVehicleID(playerid)))
	{
		new vid = GetPlayerVehicleID(playerid);
		AddVehicleComponent(vid, 1010);
	}
	return 1;
}