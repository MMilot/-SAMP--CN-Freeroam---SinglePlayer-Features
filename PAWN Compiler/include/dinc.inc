//dyq's inc

#if defined _dinc_included
  #endinput
#endif

#define _dinc_included

#define dformat( new str[128];format(str,sizeof(str),
#define df( format(str,sizeof(str),
#define psend( psend_core(playerid,str,
#define prtstr print(str)

stock gname(playerid)
{
	new pn[MAX_PLAYER_NAME];
	GetPlayerName(playerid,pn,sizeof(pn));
	return pn;
}

stock gworld(playerid)
{
	return GetPlayerVirtualWorld(playerid);
}

forward sworld(playerid,worldid);
public sworld(playerid,worldid)
{
	SetPlayerVirtualWorld(playerid,worldid);
	return 1;
}

stock gvehworld(vehid)
{
	new vw;
	GetVehicleVirtualWorld(vehid,vw);
	return vw;
}

stock svehworld(vehid,worldid)
{
	SetVehicleVirtualWorld(vehid,worldid);
}

stock ginterior(playerid)
{
	new interior;
	GetPlayerInterior(playerid,interior);
	return interior;
}

stock IsPlayerDriver(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid)) return false;
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) return true;
	return false;
}

stock ejectplayer(playerid)
{
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	SetPlayerPos(playerid,x,y,z+2);
}

stock getweapname(weapid)
{
	new weapname[32];
	GetWeaponName(weapid,weapname,32);
	return weapname;
}

stock numtostr(number)
{
	dformat("%d",number);
	return str;
}

forward spvehworld(playerid,worldid);
public spvehworld(playerid,worldid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		svehworld(GetPlayerVehicleID(playerid),worldid);
	}
	return 1;
}

forward psend_core(playerid,string[],color);
public psend_core(playerid,string[],color)
{
	SendClientMessage(playerid,color,string);
	return 1;
}