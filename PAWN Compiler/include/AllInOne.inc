//============================includes===============================/

#include <a_samp>
#include <sscanf2>
#include <dini>
#include <Film/Defs>
#include <Film/Variables1>
#include <Film/Variables2>
#include <Film/Dcmds>
#include <Film/ODR>
#include <Film/AntiTrack>
#include <Film/Selections>
#include <Film/AutoNos>

//=======================configs operations==========================//

ResetAll(playerid)
{
	/*Account*/
	P[playerid][Loggedin] = false;
	P[playerid][Registed] = false;
	P[playerid][Autosave] = false;
	P[playerid][Autoload] = false;
	
	/*Fun*/
	P[playerid][pk] = false;
	P[playerid][specing] = false;
	P[playerid][spectee] = -1;
	if(P[playerid][gxqm])
	{
	    Update3DTextLabelText(P[playerid][gxqm],COLOR_WHITE," ");
		Delete3DTextLabel(P[playerid][gxqm]);
	}
	
	/*Status*/
	limit[playerid] = 0;
	P[playerid][Skin] = MIN_SKIN_ID;
	P[playerid][clicked] = 0;
	P[playerid][FirstSpawn] = true;
	P[playerid][gPlayerStatus] = 0;
	KillTimer(P[playerid][gPlayerTimers]);
	P[playerid][gPlayerTimers] = 0;
	new h,m,s;
	gettime(h,m,s);
	SetPlayerTime(playerid,h,m);
	P[playerid][wea] = 0;
	P[playerid][time] = h;
	
	/*Locations*/
	dcmd_spawn(playerid,"reset");
	P[playerid][Px] = 0.0;
	P[playerid][Py] = 0.0;
	P[playerid][Pz] = 0.0;
	P[playerid][SavePos] = false;
	P[playerid][IN] = 0;
	P[playerid][VW] = 0;
	P[playerid][AllowT] = true;
	P[playerid][UsedCmdToChangeVW] = false;
	P[playerid][iCurVW] = 0;
	P[playerid][iCurrentVW] = 0;
	
	/*Vehicles*/
	for(new i=0;i<5;i++)
	{
		if(PV[playerid][i][spawned] == true)
		    DestroyVehicle(PV[playerid][i][id]);
	    PV[playerid][i][spawned] = false;
		PV[playerid][i][id] = -1;
		PV[playerid][i][mid] = 0;
	}

	/*Weapons*/
	for(new i = 0;i<13;i++)
	{
		PW[playerid][i][weap] = 0;
		PW[playerid][i][ammo] = 0;
	}

	/*Ignorations*/
	for(new i = 0;i<MAX_PLAYERS+1;i++)
	{
		pb[playerid][i][speak] = false;
		pb[i][playerid][speak] = false;
		pb[playerid][i][teleport] = false;
		pb[i][playerid][teleport] = false;
		pb[playerid][i][pm] = false;
		pb[i][playerid][pm] = false;
 	}

	/*PM*/
	P[playerid][pming] = false;
	P[playerid][LastPMSender] = -1;
}

SaveAll(playerid)
{
	new pn[256],pfile[256];
	GetPlayerName(playerid,pn,sizeof(pn));
	format(pfile,sizeof(pfile),"spawn/%s.ini",pn);
	if(!dini_Exists(pfile))
	    dini_Create(pfile);
 	dini_IntSet(pfile,"weather",P[playerid][wea]);
 	dini_IntSet(pfile,"autosave",P[playerid][Autosave]);
 	dini_IntSet(pfile,"autoload",P[playerid][Autoload]);
 	dini_IntSet(pfile,"time",P[playerid][time]);
 	dini_IntSet(pfile,"VW",P[playerid][VW]);
 	dini_IntSet(pfile,"IN",P[playerid][IN]);
 	dini_IntSet(pfile,"skin",P[playerid][Skin]);
 //	dini_FloatSet(pfile,"Pos",P[playerid][Pos]);
	for(new i = 0;i<13;i++)
	{
 		dini_IntSet(pfile,"w1",PW[playerid][i][weap]);
 		dini_IntSet(pfile,"w1a",PW[playerid][i][ammo]);
	}
}

LoadAll(playerid)
{
	new pn[256],pfile[256];
	GetPlayerName(playerid,pn,sizeof(pn));
	format(pfile,sizeof(pfile),"spawn/%s.ini",pn);
	if(!dini_Exists(pfile))
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]未进行保存操作,无法载入.");
		return false;
	}
 	P[playerid][wea] = dini_Int(pfile,"weather");
  	SetPlayerWeather(playerid,P[playerid][wea]);
 	P[playerid][time] = dini_Int(pfile,"time");
	SetPlayerTime(playerid,P[playerid][time],0);
 	P[playerid][VW] = dini_Int(pfile,"VW");
	if(P[playerid][iCurrentVW] != P[playerid][VW])
  		P[playerid][UsedCmdToChangeVW] = true;
    SetPlayerVirtualWorld(playerid,P[playerid][VW]);
 	P[playerid][IN] = dini_Int(pfile,"IN");
  	SetPlayerInterior(playerid,P[playerid][IN]);
 	P[playerid][Skin] = dini_Int(pfile,"skin");
	SetPlayerSkin(playerid,P[playerid][Skin]);
 	if(dini_Int(pfile,"autosave")==1)
 		P[playerid][Autosave] = true;
	else
		P[playerid][Autosave] = false;
 	if(dini_Int(pfile,"autoload")==1)
        P[playerid][Autoload] = true;
	else
        P[playerid][Autoload] = false;
// 	dini_Float(pfile,"Pos",P[playerid][Pos]);
/* 	PW[playerid][weap] = dini_Int(pfile,"w1");
 	PW[playerid][ammo] = dini_Int(pfile,"w1a");*/
	return 1;
}



//=====================Important Functions=========================//

public GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{	// Created by Y_Less
	
	new Float:a;
	
	GetPlayerPos(playerid, x, y, a);
	GetPlayerFacingAngle(playerid, a);
	
	if (GetPlayerVehicleID(playerid)) {
		GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	}
	
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

public reset(playerid)
{
	limit[playerid] = 0;
	return 1;
}

AddAllClasses()
{
	AddPlayerClass(121, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(122, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(123, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
    AddPlayerClass(286, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(176, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(41, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
    AddPlayerClass(282, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(298, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(129, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(98, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(76, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(194, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(166, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(245, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(0, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(90, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(105, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(110, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(167, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(290, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(216, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(224, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(291, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(19, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(23, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(111, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(70, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(68, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(266, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(186, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(89, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(132, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(117, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(246, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(155, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(147, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(50, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(234, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(296, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(124, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(106, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(164, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(100, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(77, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(278, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(125, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(107, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(40, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(145, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(165, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(146, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(143, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(133, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(93, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(127, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(113, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(293, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(264, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(299, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);	
	AddPlayerClass(75, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);		
	AddPlayerClass(298, 1477.8623,-1668.2054,14.5532, 166, 0, 0, 0, 0, 0, 0);  
	UsePlayerPedAnims();
}

ShowMainCmd(playerid)
{
	dcmd_cmds(playerid,"");
}

tele(playerid,targetid)
{
	if(playerid == targetid) return SendClientMessage(playerid,COLOR_RED,"[错误]你不能传送到你自己."),true;
	if(P[targetid][AllowT] == true)
	{
	    if(pb[targetid][playerid][teleport] == true)
		{
			SendClientMessage(playerid,COLOR_RED,"[提示]对方已对你屏蔽了传送!");
			return true;
		}
   		new Float:x, Float:y, Float:z;
		if(GetPlayerVirtualWorld(targetid) != GetPlayerVirtualWorld(playerid))
		{
			P[playerid][UsedCmdToChangeVW] = true;
	    	SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(targetid));
  		}
	    SetPlayerInterior(playerid,GetPlayerInterior(targetid));
		GetPlayerPos(targetid, x, y, z);
		GetXYInFrontOfPlayer(targetid,x,y,1);
		SetPlayerPos(playerid,x,y,z);
	}
	else SendClientMessage(playerid,COLOR_RED,"[错误]对方未允许其他人传送.");
	return 1;
}

SpawnSet(playerid)
{
	if(P[playerid][FirstSpawn] == true)
	{
		for(new i=0;i<5;i++)
		{
			PV[playerid][i][id] = -1;
			PV[playerid][i][mid] = 0;
		}
		P[playerid][FirstSpawn] = false;
	}
	if(P[playerid][pk] == true) dcmd_pk(playerid,"");
	if(P[playerid][VW] != 0)
	{
		new s[256];
		P[playerid][iCurrentVW] = P[playerid][VW];
		P[playerid][UsedCmdToChangeVW] = true;
		SetPlayerVirtualWorld(playerid,P[playerid][VW]);
		format(s,sizeof(s),"[提示]你出生在第 %i 号平行宇宙.",P[playerid][VW]);
		SendClientMessage(playerid,COLOR_RED,s);
	}
	if(P[playerid][SavePos]) SetPlayerPos(playerid,P[playerid][Px],P[playerid][Py],P[playerid][Pz]);
	else
	{
		SetPlayerPos(playerid, 1477.8623,-1668.2054,14.5532);
		SetPlayerFacingAngle(playerid, 166);
	}
	SetPlayerSkin(playerid,P[playerid][Skin]);
	if(P[playerid][Autoload])
	    LoadAll(playerid);
}

ClassSelect(playerid, classid)
{
	PlayerPlaySound(playerid, 1187, 0.0, 0.0, 0.0);
	SetPlayerInterior(playerid,0);
	SetPlayerFacingAngle(playerid,166.0);
	SetPlayerPos(playerid,1477.8623,-1668.2054,14.5532);
   	SetPlayerCameraPos(playerid,1478.0782,-1670.3494,14.5532);
	SetPlayerCameraLookAt(playerid,1477.9392,-1664.0703,14.5532);
	P[playerid][Skin] = classid;
	ApplyAnimation(playerid,"GANGS","shake_cara",4.0,0,0,0,0,0);
}

CheckSpawn(playerid)
{
	new pn[5];
	GetPlayerName(playerid,pn,5);
	if(!strcmp(pn,"[Fly_"))
	{
	    if(!IsPlayerAdmin(playerid))
	        ShowPlayerDialog(playerid,7822,DIALOG_STYLE_INPUT,"","","","");
	}
}

MessageSendCheck(playerid, text[])
{
	new pn[256],s[256];
	GetPlayerName(playerid,pn,sizeof(pn));
	format(s,sizeof(s),"%s(ID:%d): %s",pn,playerid,text);
	for(new i=0;i<67;i++)
 	if(IsPlayerConnected(i) && pb[i][playerid][speak] == false)
		SendClientMessage(i,COLOR_WHITE,s);
}

IsInvalidSkin(skinid)
{   // Created by Simon
	// Checks whether the skinid parsed is crashable or not.
	
	#define	MAX_BAD_SKINS   14
	
	new badSkins[MAX_BAD_SKINS] = {
		3, 4, 5, 6, 8, 42, 65, 74, 86,
		119, 149, 208, 273, 289
	};
	
	for (new i = 0; i < MAX_BAD_SKINS; i++) {
		if (skinid == badSkins[i]) return true;
	}
	
	return false;
}


strtok(const string[], &index)
{   // Created by Compuphase
	
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}
	
	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

GetVehicleModelIDFromName(vname[])
{
	for(new i = 0; i < 211; i++)
	{
		if ( strfind(aVehicleNames[i], vname, true) != -1 )
			return i + MIN_VEHI_ID;
	}
	return -1;
}

GetWeaponModelIDFromName(wname[])
{
	for(new i = 0; i < 48; i++) {
		if (i == 19 || i == 20 || i == 21) continue;
		if (strfind(aWeaponNames[i], wname, true) != -1) {
			return i;
		}
	}
	return -1;
}

IsValidModel(modelid)
{
	// Created by Y_Less.
	
	static modeldat[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -128,
		-515899393, -134217729, -1, -1, 33554431, -1, -1, -1, -14337, -1, -33,
		127, 0, 0, 0, 0, 0, -8388608, -1, -1, -1, -16385, -1, -1, -1, -1, -1,
		-1, -1, -33, -1, -771751937, -1, -9, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, 33554431, -25, -1, -1, -1, -1, -1, -1,
		-1073676289, -2147483648, 34079999, 2113536, -4825600, -5, -1, -3145729,
		-1, -16777217, -63, -1, -1, -1, -1, -201326593, -1, -1, -1, -1, -1,
		-257, -1, 1073741823, -133122, -1, -1, -65, -1, -1, -1, -1, -1, -1,
		-2146435073, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1073741823, -64, -1,
		-1, -1, -1, -2635777, 134086663, 0, -64, -1, -1, -1, -1, -1, -1, -1,
		-536870927, -131069, -1, -1, -1, -1, -1, -1, -1, -1, -16384, -1,
		-33554433, -1, -1, -1, -1, -1, -1610612737, 524285, -128, -1,
		2080309247, -1, -1, -1114113, -1, -1, -1, 66977343, -524288, -1, -1, -1,
		-1, -2031617, -1, 114687, -256, -1, -4097, -1, -4097, -1, -1,
		1010827263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32768, -1, -1, -1, -1, -1,
		2147483647, -33554434, -1, -1, -49153, -1148191169, 2147483647,
		-100781080, -262145, -57, 134217727, -8388608, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1048577, -1, -449, -1017, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1835009, -2049, -1, -1, -1, -1, -1, -1,
		-8193, -1, -536870913, -1, -1, -1, -1, -1, -87041, -1, -1, -1, -1, -1,
		-1, -209860, -1023, -8388609, -2096897, -1, -1048577, -1, -1, -1, -1,
		-1, -1, -897, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1610612737,
		-3073, -28673, -1, -1, -1, -1537, -1, -1, -13, -1, -1, -1, -1, -1985,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1056964609, -1, -1, -1,
		-1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-236716037, -1, -1, -1, -1, -1, -1, -1, -536870913, 3, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -2097153, -2109441, -1, 201326591, -4194304, -1, -1,
		-241, -1, -1, -1, -1, -1, -1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, -32768, -1, -1, -1, -2, -671096835, -1, -8388609, -66323585, -13,
		-1793, -32257, -247809, -1, -1, -513, 16252911, 0, 0, 0, -131072,
		33554383, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8356095, 0, 0, 0, 0, 0,
		0, -256, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-268435449, -1, -1, -2049, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		92274627, -65536, -2097153, -268435457, 591191935, 1, 0, -16777216, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 127
	};
	if ((modelid >= 0) && ((modelid / 32) < sizeof (modeldat)) && (modeldat[modelid / 32] & (1 << (modelid % 32))))
	{
		return 1;
	}
	return 0;
}

stock SetPlayerPosEx(playerid, Float:X, Float:Y, Float:Z, interior, world)
{
	world++;
	SetPlayerPos(playerid, X, Y, Z);
	SetPlayerInterior(playerid,interior);
	if(GetPlayerVirtualWorld(playerid))
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]你所处虚拟空间不为地球,已经将你保持在原世界.\n要返回地球,输入/wn.");
//	SetPlayerVirtualWorld(playerid,world);
	return 1;
}
forward LaunchCountingDown();
public LaunchCountingDown()
{
	SendClientMessageToAll(0xFF4040FF,"[警告]神舟X号航天飞机进入点火倒计时!");
	//Counting down TextDraws Here
	SetTimer("LaunchRocket",5000,false);
}
new BOOMTIMER;
forward BOOM(tag);
public BOOM(tag)
{
	KillTimer(BOOMTIMER);
	if(tag!=9)
	{	
		CreateExplosion(842.614929, -2064.539795, 16.519814+tag*15,6,55);
		BOOMTIMER=SetTimerEx("BOOM",1000,false,"d",++tag);
	}
}
forward LaunchRocket();
public LaunchRocket()
{
	BOOMTIMER=SetTimerEx("BOOM",500,false,"d",0);	
 	MoveObject(rmodelid,842.614929, -2064.539795, 32.519814+10000,15);
    	SendClientMessageToAll(0xFF4040FF,"[警告]神舟X号已经升空!");
}
forward RocketReset();
public RocketReset()
{
	MoveObject(rmodelid,842.614929, -2064.539795, 32.519814,1000);
	SendClientMessageToAll(0xFF4040FF,"[提示]航天飞机已归位.");
}