#include <YSI\y_hooks>

forward OnPlayerPaused(playerid);
forward OnPlayerUnpaused(playerid);
forward CheckPausedPlayer(playerid);
forward Pause_OnPlayerUpdate(playerid);
enum e_Player
{
	Timer,
	Count,
	bool:Paused
}

static PlayerPauseInfo[MAX_PLAYERS][e_Player];

Hook:P_OnPlayerConnect(playerid)
{
   	PlayerPauseInfo[playerid][Paused] = false;
	PlayerPauseInfo[playerid][Timer] = SetTimerEx("CheckPausedPlayer", 500, 1, "i",playerid);
	return 0;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Pause_OnPlayerConnect
forward Pause_OnPlayerConnect(playerid);

Hook:P_OnPlayerDisconnect(playerid)
{
	KillTimer(PlayerPauseInfo[playerid][Timer]);
	return 0;
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Pause_OnPlayerDisconnect
forward Pause_OnPlayerDisconnect(playerid, reason);

Hook:P_OnPlayerUpdate(playerid)
{
	PlayerPauseInfo[playerid][Count] = 0;
	return 0;
}

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate Pause_OnPlayerUpdate
forward Pause_OnPlayerConnect(playerid);

stock pause_IsPlayerSpawned(playerid) { // By Goldkiller
	new
		PlayerState;
	PlayerState=GetPlayerState(playerid);
	return ( PlayerState != PLAYER_STATE_NONE && PlayerState != PLAYER_STATE_WASTED && PlayerState != PLAYER_STATE_SPECTATING);
}

public CheckPausedPlayer(playerid)
{
	if(pause_IsPlayerSpawned(playerid))
	{
		PlayerPauseInfo[playerid][Count]++;
		if(PlayerPauseInfo[playerid][Count] > 2)
		{
		    if(!PlayerPauseInfo[playerid][Paused])
		    {
			    CallLocalFunction("OnPlayerPaused","i",playerid);
			    PlayerPauseInfo[playerid][Paused] = true;
			}
		} else if(PlayerPauseInfo[playerid][Paused])
		{
		    CallLocalFunction("OnPlayerUnpaused","i",playerid);
	 		PlayerPauseInfo[playerid][Paused] = false;
		}
	}
	return 1;
}

stock IsPlayerPaused(playerid) return PlayerPauseInfo[playerid][Paused];


