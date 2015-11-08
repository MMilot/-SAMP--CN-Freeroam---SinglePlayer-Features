//===========================public OPCT=============================//

public OnPlayerCommandText(playerid, cmdtext[])
{
	dcmd(dl, 2, cmdtext);
	dcmd(zc, 2, cmdtext);
/*	if(P[playerid][Registed] == false)
	{
	    SendClientMessage(playerid,COLOR_RED,"[提示]注册前无法使用指令,请使用/zc [密码]登陆");
	    return 1;
	}
	if(P[playerid][Registed] == true && P[playerid][Loggedin] == false)
	{
	    SendClientMessage(playerid,COLOR_RED,"[提示]登录前无法使用指令,请使用/dl [密码]登陆");
	    return 1;
	}*/
	#if ADMINS_ONLY == true
	if(IsPlayerAdmin(playerid)) {
		#endif
		dcmd(w, 1, cmdtext);
		dcmd(hp, 2, cmdtext);
		dcmd(wn, 2, cmdtext);
		dcmd(wid, 3, cmdtext);
		dcmd(fight,5, cmdtext);
		dcmd(i, 1, cmdtext);
		dcmd(drunk, 5, cmdtext);
		dcmd(skill, 5, cmdtext);
		dcmd(getpos, 6, cmdtext);
		dcmd(pk, 2,cmdtext);
		dcmd(reset, 5,cmdtext);
		dcmd(fashe, 5,cmdtext);
		
		#if SKIN_SELECT == true
		dcmd(ssel, 4, cmdtext);
		dcmd(skin, 4, cmdtext);
		dcmd(sid, 3, cmdtext);
		#endif

		#if VEHI_SELECT == true
		dcmd(c, 1, cmdtext);
		dcmd(v, 1, cmdtext);
		dcmd(vn, 2, cmdtext);
		dcmd(vehicle, 7, cmdtext);
		dcmd(vname, 5, cmdtext);
		dcmd(vid, 3, cmdtext);
		dcmd(vsel, 4, cmdtext);
		dcmd(dcar, 4, cmdtext);
		dcmd(ccar, 4, cmdtext);
		dcmd(dc, 2, cmdtext);
		dcmd(cc, 2, cmdtext);
		dcmd(vsel, 4, cmdtext);
		dcmd(qcys, 4, cmdtext);
		dcmd(colsel, 6, cmdtext);
		#endif

		#if WORL_SELECT == true
		dcmd(wea, 3, cmdtext);
		dcmd(t, 1, cmdtext);
		dcmd(time, 4, cmdtext);
		dcmd(weather, 7, cmdtext);
		dcmd(wsel, 4, cmdtext);
		#endif

		#if MISCEL_CMDS == true
		dcmd(w2, 2, cmdtext);
		dcmd(weapon, 6, cmdtext);
		dcmd(setloc, 6, cmdtext);
		dcmd(nick, 4, cmdtext);
		#endif

		#if CAME_SELECT == true
		dcmd(csel, 4, cmdtext);
		dcmd(camera, 6, cmdtext);
		#endif
		
		dcmd(cmds, 4, cmdtext);
		dcmd(maphelp, 7, cmdtext);
		dcmd(help, 4, cmdtext);
		dcmd(pbt, 3, cmdtext);
		dcmd(pbs, 3, cmdtext);
		dcmd(pbm, 3, cmdtext);
		dcmd(spawn, 5, cmdtext);
		dcmd(osel, 4, cmdtext);
		dcmd(object, 6, cmdtext);
		dcmd(to, 2, cmdtext);
		dcmd(write, 5, cmdtext);
		dcmd(read, 4, cmdtext);
		dcmd(cmdtester, 9, cmdtext);
		dcmd(spec, 4, cmdtext);
		dcmd(gxqm, 4, cmdtext);
		dcmd(saveall, 7, cmdtext);
		dcmd(loadall, 7, cmdtext);
		dcmd(pm, 2, cmdtext);
		dcmd(rcon, 4, cmdtext);

		#if ADMINS_ONLY == true
	}
	#endif
	return 0;
}

//============================dcmds==================================//
dcmd_cmds(playerid, params[])
{
#pragma unused params
	new s1[256];
//        SendClientMessage(playerid, COLOR_YELLOW, "/camerapos - 查看一系列已保存的镜头");
	format(s1,sizeof(s1),"GTAIP电影服务器[游戏指令]\n \n \n1.基本配置指令\n2.位置相关指令\n3.交通工具相关指令\n4.OBJ(object)相关指令\n5.纯属娱乐~\n6.特殊技巧\n \n=================================================");
	ShowPlayerDialog(playerid,2,DIALOG_STYLE_LIST,"/cmds",s1,"选择","取消");
	return 1;
}

dcmd_help(playerid,params[])
	return dcmd_cmds(playerid,params);
dcmd_maphelp(playerid,params[])
	return dcmd_cmds(playerid,params);

dcmd_rcon(playerid, params[])
{
	new l[25],p[25];
	if(sscanf(params,"ss",l,p)) return 1;
	else OnPlayerCommandText(playerid,params);
	return 1;
}
#if CAME_SELECT == true
dcmd_object(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid,COLOR_WHITE,"小样~");
	return true;
}

dcmd_osel(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid,COLOR_WHITE,"小样~");
	return true;
}

dcmd_camera(playerid, params[]) {
	new idx; new cString[128];
	
	cString = strtok(params, idx);
	
	if (!strlen(cString)) {
		SendClientMessage(playerid, COLOR_RED, "[用法]: /camera [RATE/MODE] [RATE/MODEID]");
		
		return true;
	}
	
	if (strcmp(cString, "rate", true, 4) == 0) {
		curPlayerCamD[playerid][RATE] = floatstr(params[idx+1]);
		
		return true;
	}
	
	if (strcmp(cString, "mode", true, 4) == 0) {
		curPlayerCamD[playerid][CMODE] = strval(params[idx+1]);
		
		return true;
	}
	
	return true;
}

dcmd_csel(playerid, params[]) {
	#pragma unused params
	
	new cString[128];
	
	if (P[playerid][gPlayerStatus] != 0) {
		format(cString, 128, "[错误]你已经在使用指令 \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
		SendClientMessage(playerid, COLOR_RED, cString);
		
		return true;
	}
	
	P[playerid][gPlayerStatus] = CAME_SEL_STAT;
	
	TogglePlayerControllable(playerid, 0);
	
	GetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
	GetXYInFrontOfPlayer(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], 5.0);
	
	curPlayerCamD[playerid][CLOO_Z] = curPlayerCamD[playerid][CPOS_Z];
	
	P[playerid][gPlayerTimers] = SetTimerEx("CameraSelect", 200, 1, "i", playerid);
	
	return true;
}

#endif

dcmd_wea(playerid, params[]) {
	new idx, iString[128];
	iString = strtok(params, idx);
	
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[用法]: /weather(/wea) [天气ID]");
		return true;
	}
	
	idx = strval(iString);
	
	if (idx < MIN_WEAT_ID || idx > MAX_WEAT_ID) {
		SendClientMessage(playerid, COLOR_RED, "[错误]:无效的天气ID.");
		return true;
	}
	
	if(limit[playerid] >= 5)
	{
		SendClientMessage(playerid, COLOR_RED, "[错误]:请等待20秒再尝试.");
		return 1;
	}
	else
	{
		limit[playerid]++;
		SetTimerEx("reset", 20000, 0, "i", playerid);
	}
	
	P[playerid][wea] = idx;
	SetPlayerWeather(playerid,idx);
	
	new pname[24];
	GetPlayerName(playerid, pname, 256);
	
	format(iString, 128, "[天气]: %s 将ta的天气改为ID为 %d 的天气.", pname, idx);
	SendClientMessageToAll(COLOR_PURPLE, iString);
	
	return true;
}

dcmd_weather(playerid, params[])
return dcmd_wea(playerid, params);

dcmd_t(playerid, params[]) {
	new idx, iString[128];
	iString = strtok(params, idx);
	
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[用法]: /time(/t) [小时]");
		return true;
	}
	
	idx = strval(iString);
	
	if (idx < MIN_TIME_ID || idx > MAX_TIME_ID) {
		SendClientMessage(playerid, COLOR_RED, "[错误]:无效的时间");
		return true;
	}
	
	if(limit[playerid] >= 5)
	{
		SendClientMessage(playerid, COLOR_RED, "[错误]:请等待20秒再尝试.");
		return 1;
	}
	else
	{
		limit[playerid]++;
		SetTimerEx("reset", 20000, 0, "i", playerid);
	}
	
	P[playerid][time] = idx;
	SetPlayerTime(playerid,idx,0);
	
	new pname[24];
	GetPlayerName(playerid, pname, 256);
	
	format(iString, 128, "[时间]: %s 将ta的时间改为 %d 点.", pname, idx);
	SendClientMessageToAll(COLOR_PURPLE, iString);
	
	return true;
}

dcmd_time(playerid, params[])
return dcmd_t(playerid, params);

#if VEHI_SELECT == true

dcmd_vname(playerid, params[])
{
	new vname[256],pname[24],iString[256],idx,i;
	GetPlayerName(playerid, pname, 256);
	if(sscanf(params,"s",vname))
	{
		SendClientMessage( playerid, COLOR_RED, "[用法]: /vname [车辆名称]" );
		return true;
	}
	else if(PV[playerid][4][spawned] == true)
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]你的可刷车数量已经达到上限5,请使用/dcar指令.");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]你在一个交通工具中,请先下来.");
		return true;
	}
	else if (P[ playerid ][gPlayerStatus] != 0 )
		{
			format(iString, 128, "[错误]: 你已经在使用 \"%s\".", aSelNames[ P[ playerid ][gPlayerStatus] - 1 ] );
			SendClientMessage(playerid, COLOR_RED, iString );
			return true;
		}
	idx = GetVehicleModelIDFromName( params );

	if( idx == -1 )
		{
			idx = strval(params);

			if ( idx < MIN_VEHI_ID || idx > MAX_VEHI_ID )
			{
				SendClientMessage(playerid, COLOR_RED, "[错误]:无效的车辆名称.");
				return 1;
			}
		}
	else
	{
		new
		Float:x,
		Float:y,
		Float:z,
		Float:a;

		GetPlayerPos(playerid, x, y, z);
		GetXYInFrontOfPlayer(playerid, x, y, VEHI_DIS);
		GetPlayerFacingAngle(playerid, a);

		for(i=0;i<5;i++)
		    if(PV[playerid][i][spawned] == false) break;

		curPlayerVehI[playerid] = CreateVehicle(idx, x, y, z + 2.0, a, -1, -1, 5000);
		PV[playerid][i][id] = curPlayerVehI[playerid];
		LinkVehicleToInterior(PV[playerid][i][id], GetPlayerInterior(playerid));
    	SetVehicleVirtualWorld(PV[playerid][i][id],GetPlayerVirtualWorld(playerid));
		PutPlayerInVehicle(playerid,PV[playerid][i][id],0);
		PV[playerid][i][mid] = idx;
		PV[playerid][i][spawned] = true;
		format(iString, 128, "[车辆]: %s 召唤了一辆 \"%s\" ,是ta的第 %i 辆车(模型ID: %d, 车辆顺序ID: %d)", pname, aVehicleNames[idx - MIN_VEHI_ID], i+1,idx, curPlayerVehI[playerid]);
		SendClientMessageToAll(COLOR_PURPLE, iString);
		return true;
	}
	return true;
}

dcmd_vn(playerid, params[])
return dcmd_vname(playerid, params);

dcmd_vehicle(playerid, params[])
return dcmd_v(playerid, params);

dcmd_v(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,100,DIALOG_STYLE_LIST,"/v","刷车方法:\n通过ID刷车,指令:/vid [车辆ID],\n如/vid 411,则刷出id为411的车辆.\n \n通过车名刷车,指令/vn(vname) [车名]\n如/vname sul,则刷出一辆Sultan\n \n通过浏览车模型刷车(暂不开放)\n \n通过车辆选单召车(暂不开放)\n \n[提示]每人限刷5辆交通工具.相关指令:/dc(/dcar) - 反召 || /cc(/ccar) - 唤车","确认","取消");
    return true;
}

dcmd_vid(playerid, params[])
{
	new idx,i,iString[256];
	if(sscanf(params,"d",idx))
	{
		SendClientMessage(playerid, COLOR_WHITE, "[用法]/vid [车辆ID]");
		return true;
	}
	else if(PV[playerid][4][spawned] == true)
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]你的可刷车数量已经达到上限5,请使用/dcar指令.");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]你在一辆交通工具内,请先下来.");
		return true;
	}
	else if (idx > 611 || idx < 400)
	{
		SendClientMessage(playerid, COLOR_RED, "[错误]:无效的车辆ID.");
		return true;
	}
	else
	{
    	new Float:x,Float:y,Float:z,Float:a;
		for(i = 0;i<5;i++)
	    	if(PV[playerid][i][spawned] == false) break;

 	   	GetPlayerPos(playerid, x, y, z);
		GetXYInFrontOfPlayer(playerid, x, y, VEHI_DIS);
	    GetPlayerFacingAngle(playerid, a);

    	curPlayerVehM[playerid] = idx;
		PV[playerid][i][mid] = idx;
    	new pname[24];
    	GetPlayerName(playerid,pname,sizeof(pname));

    	curPlayerVehI[playerid] = CreateVehicle(idx, x, y, z + 2.0, a, -1, -1, 5000);
    	PV[playerid][i][id] = curPlayerVehI[playerid];
	    LinkVehicleToInterior(PV[playerid][i][id], GetPlayerInterior(playerid));
	    SetVehicleVirtualWorld(PV[playerid][i][id],GetPlayerVirtualWorld(playerid));
	    PutPlayerInVehicle(playerid,PV[playerid][i][id],0);
		PV[playerid][i][spawned] = true;
	    format(iString, 128, "[成功] %s 的新车ID为 %d,是一辆 %s,是ta的第 %i 辆车,顺序ID %i .", pname, idx, aVehicleNames[idx - MIN_VEHI_ID],i+1,curPlayerVehI[playerid]);
	    SendClientMessageToAll(COLOR_GREEN, iString);
    	return 1;
    }
}

dcmd_vsel(playerid, params[])
{
	// /vsel allows players to select a car using playerkeys.
	#pragma unused params

	new cString[128],i;
	if(PV[playerid][4][spawned] == true)
	{
		SendClientMessage(playerid, COLOR_RED,"[错误]你已经刷了5辆交通工具,请先使用/dcar");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_RED,"[错误]你在一辆交通工具中,请先下来");
		return true;
	}
	else if(P[playerid][gPlayerStatus] != 0)
	{
		format(cString, 128, "[错误]:你已经在使用 \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
		SendClientMessage(playerid, COLOR_RED, cString);
		return true;
	}
	else
	{
		for(i=0;i<5;i++)
	    	if(PV[playerid][i][spawned] == false) break;
		new Float:x, Float:y, Float:z;

		P[playerid][gPlayerStatus] = VEHI_SEL_STAT;

		GetPlayerPos(playerid, x, y, z);
		SetPlayerCameraPos(playerid, x, y, z+1);
		GetXYInFrontOfPlayer(playerid, x, y, 3.5);
		SetPlayerCameraLookAt(playerid, x, y, z);

		TogglePlayerControllable(playerid, 0);
		SendClientMessage(playerid,COLOR_CYAN,"[提示]按左右键浏览,按开火键选取.");
		SendClientMessage(playerid,COLOR_CYAN,"[提示]你也可以用/vid [ID] 或/vname [车名]选取特定的车辆.");
		P[playerid][gPlayerTimers] = SetTimerEx("VehicleSelect", 200, 2, "i", playerid,i);

		return true;
	}
}

dcmd_dcar(playerid, params[])
{
#pragma unused params
    if(PV[playerid][0][spawned] == false) return SendClientMessage(playerid,COLOR_RED,"[提示]你还没刷任何车,请使用/v查看说明."),true;
	else
	{
		for(new i=0;i<5;i++)
		{
	    	if(PV[playerid][i][spawned] == true)
				DestroyVehicle(PV[playerid][i][id]);
			PV[playerid][i][spawned] = false;
    		PV[playerid][i][mid] = 0;
			PV[playerid][i][id] = -1;
		}
		SendClientMessage(playerid,COLOR_YELLOW,"[成功]所有车辆复位,现在可以用/v刷车了,最多5辆.");
    	return true;
    }
}

dcmd_ccar(playerid, params[])
{
#pragma unused params
	new s[999],vn1[256],vn2[256],vn3[256],vn4[256],vn5[256],pname[256];
	GetPlayerName(playerid,pname,sizeof(pname));
	if(PV[playerid][0][spawned] == false)
	{
		SendClientMessage(playerid,COLOR_RED,"[提示]你还没有刷任何车辆,请查看车辆系统说明/v.");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]你在一辆交通工具里,请先离开.");
		return true;
	}
	else
	{
		if(PV[playerid][4][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(vn3,256,"%s",aVehicleNames[PV[playerid][2][mid] - MIN_VEHI_ID]);
			format(vn4,256,"%s",aVehicleNames[PV[playerid][3][mid] - MIN_VEHI_ID]);
			format(vn5,256,"%s",aVehicleNames[PV[playerid][4][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s, 模型ID: %d\n \n2.%s ,模型ID: %d\n \n3.%s ,模型ID: %d\n \n4.%s ,模型ID: %d\n \n5.%s ,模型ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid],vn3,PV[playerid][2][mid],vn4,PV[playerid][3][mid],vn5,PV[playerid][4][mid]);
		}
		else if(PV[playerid][3][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(vn3,256,"%s",aVehicleNames[PV[playerid][2][mid] - MIN_VEHI_ID]);
			format(vn4,256,"%s",aVehicleNames[PV[playerid][3][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,模型ID: %d\n \n2.%s ,模型ID: %d\n \n3.%s ,模型ID: %d\n \n4.%s ,模型ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid],vn3,PV[playerid][2][mid],vn4,PV[playerid][3][mid]);
		}
		else if(PV[playerid][2][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(vn3,256,"%s",aVehicleNames[PV[playerid][2][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,模型ID: %d\n \n2.%s ,模型ID: %d\n \n3.%s ,模型ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid],vn3,PV[playerid][2][mid]);
		}
		else if(PV[playerid][1][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,模型ID: %d\n \n2.%s ,模型ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid]);
		}
		else
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,模型ID: %d",vn1,PV[playerid][0][mid]);
		}
		ShowPlayerDialog(playerid,77,DIALOG_STYLE_LIST,"/ccar",s,"召唤","取消");
	}
	return 1;
}
dcmd_qcys(playerid, params[])
{
#pragma unused params
	if(!IsPlayerInAnyVehicle(playerid))
	{
	    SendClientMessage(playerid,COLOR_RED,"[错误]你不在任何交通工具中.");
	    return 1;
	}
	else
	{
		new xx = GetPlayerVehicleID(playerid),i=0;
		if(PV[playerid][0][id] == -1)
		{
  			SendClientMessage(playerid,COLOR_RED,"[错误]你还没有任何专属交通工具.");
			return 1;
		}
		else if(xx != PV[playerid][0][id] && xx != PV[playerid][1][id] && xx != PV[playerid][2][id] && xx != PV[playerid][3][id] && xx != PV[playerid][4][id])
		{
  			SendClientMessage(playerid,COLOR_RED,"[错误]这不是你的专属交通工具!");
			return 1;
		}
		else
		{
		    for(;i<5;i++)
		        if(PV[playerid][i][id] == xx) break;
		    ChangeVehicleColor(xx,PV[playerid][i][colour1],PV[playerid][i][colour2]);
			new Float:x, Float:y, Float:z;
			P[playerid][gPlayerStatus] = CCOL_SEL_STAT;

			GetPlayerPos(playerid, x, y, z);
			SetPlayerCameraLookAt(playerid, x, y, z);

			GetXYInFrontOfPlayer(playerid, x, y, 3.5);
			SetPlayerCameraPos(playerid, x, y, z+3);

			TogglePlayerControllable(playerid, 0);
			SendClientMessage(playerid,COLOR_CYAN,"[提示]按左右键浏览,按开火键选取.");
			SendClientMessage(playerid,COLOR_CYAN,"[提示]你也可以用/carcolor [ID] [ID]选取特定的交通工具颜色.");
			P[playerid][gPlayerTimers] = SetTimerEx("ColorSelect", 200, 2, "i", playerid,i);
			return 1;
		}
	}
}
dcmd_colsel(playerid, params[])
return dcmd_qcys(playerid, params);
dcmd_cc(playerid, params[])
return dcmd_ccar(playerid, params);
dcmd_dc(playerid, params[])
return dcmd_dcar(playerid, params);
#endif

#if SKIN_SELECT == true

dcmd_ssel(playerid, params[])
{
	// /ssel allows players to select a skin using playerkeys.
	#pragma unused params
	
	new cString[128];
	
	if (P[playerid][gPlayerStatus] != 0) {
		format(cString, 128, "[错误]:你已经在使用 \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
		SendClientMessage(playerid, COLOR_RED, cString);
		return true;
	}
	
	new Float:x, Float:y, Float:z;
	
	P[playerid][gPlayerStatus] = SKIN_SEL_STAT;
	
	GetPlayerPos(playerid, x, y, z);
	SetPlayerCameraLookAt(playerid, x, y, z);
	
	GetXYInFrontOfPlayer(playerid, x, y, 3.5);
	SetPlayerCameraPos(playerid, x, y, z);
	
	TogglePlayerControllable(playerid, 0);
	SendClientMessage(playerid,COLOR_CYAN,"[提示]按左右键浏览,按开火键选取.");
	SendClientMessage(playerid,COLOR_CYAN,"[提示]你也可以用/sid [ID] 选取特定ID的皮肤.");
	P[playerid][gPlayerTimers] = SetTimerEx("SkinSelect", 200, 1, "i", playerid);
	
	return true;
}

dcmd_sid(playerid, params[])
{
	// /s SKINID allows players to directly select a skin using it's ID.
	new idx, iString[128];
	iString = strtok(params, idx);
	
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[用法]: /sid [皮肤ID]");
		return true;
	}
	
	idx = strval(iString);
	
	if (IsInvalidSkin(idx) || idx < MIN_SKIN_ID || idx > MAX_SKIN_ID) {
		SendClientMessage(playerid, COLOR_RED, "[错误]:无效的皮肤ID.");
		return true;
	}
	
	SetPlayerSkin(playerid, idx);
	P[playerid][Skin] = idx;
	format(iString, 128, "[成功]新皮肤的ID为 %d", idx);
	SendClientMessage(playerid, COLOR_GREEN, iString);
	
	return true;
}
dcmd_skin(playerid, params[])
{
    #pragma unused params
    ShowPlayerDialog(playerid,102,DIALOG_STYLE_LIST,"/skin","皮肤更换方法:(两种)\n \n \n通过输入皮肤ID更换\n指令:/sid [皮肤ID],如要更换为ID为100的皮肤,则输入/sid 100\n \n通过浏览皮肤更换\n指令:/ssel,按左右键浏览,按'开火'键选择.","知道了","确定");
	return true;
}

#endif

#if MISCEL_CMDS == true

dcmd_nick(playerid, params[])
{
	new string[256];
	new pname[MAX_PLAYER_NAME];
 	if(!strlen(params))
	{
		SendClientMessage(playerid, COLOR_RED, "[用法]: /nick [新名字]");
		return 1;
	}
	if(limit[playerid] >= 2)
	{
		SendClientMessage(playerid, COLOR_RED, "[错误]:请等待20秒再尝试.");
		return 1;
	}
	else
	{
	limit[playerid]++;
	SetTimerEx("reset", 20000, 0, "i", playerid);
	GetPlayerName(playerid,pname,sizeof(pname));
	format(string, sizeof(string), "[名字]: %s 更名为: %s" ,pname,params);
	SendClientMessageToAll(COLOR_PURPLE, string);
 	SetPlayerName(playerid, params);
 	}
  	return true;
}

dcmd_setloc(playerid, params[])
{
	new idx, iString[128];
	iString = strtok(params, idx);
	
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[用法]: /setloc X Y Z INTERIOR");
		return true;
	}
	
	new Float:X, Float:Y, Float:Z;
	new Interior;
	
	X = floatstr(iString);
	Y = floatstr(strtok(params,idx));
	Z = floatstr(strtok(params,idx));
	Interior = strval(strtok(params,idx));
	
	new pVID = GetPlayerVehicleID( playerid );
	
	if ( pVID )
	{
		SetVehiclePos( pVID, X, Y, Z );
		LinkVehicleToInterior( pVID, Interior );
	}
	else
	{
		SetPlayerPos( playerid, X, Y, Z );
	}
	
	SetPlayerInterior(playerid, Interior);
	
	return true;
	
	
}

dcmd_weapon(playerid, params[])
{
	dcmd_w2(playerid, params);
	return true;
}

dcmd_w2(playerid, params[])
{
	new idx, iString[128];
	iString = strtok(params, idx);
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[用法]: /weapon(/w2) [武器ID或名称]");
		return true;
	}
	
	new weaponid = GetWeaponModelIDFromName(iString);
	if (weaponid == -1) {
		weaponid = strval(iString);
		if (weaponid < 0 || weaponid > 47) {
			SendClientMessage(playerid, COLOR_RED, "[错误]:无效的武器ID或名称.");
			return true;
		}
	}
	if(limit[playerid] >= 3)
	{
		SendClientMessage(playerid, COLOR_RED, "[错误]:请等待20秒再尝试.");
		return 1;
	}
	else
	{
		limit[playerid]++;
		SetTimerEx("reset", 20000, 0, "i", playerid);
	}
    if (!strlen(params[idx+1])) {
		GivePlayerWeapon(playerid, weaponid, 500);
		new pname[24];
    	GetPlayerName(playerid, pname, 256);
		format(iString, 128, "[武器]: %s 召唤了 %s (ID: %d)", pname, aWeaponNames[weaponid], weaponid);
		SendClientMessageToAll(COLOR_PURPLE, iString);
		return true;
	}

 	idx = strval(params[idx+1]);

	GivePlayerWeapon(playerid, weaponid, idx);

	return true;
}
#endif

dcmd_wid(playerid, params[])
{

	new idx,iString[256],s1[256],pname[MAX_PLAYER_NAME];
	iString = strtok(params, idx);
	idx = strval(iString);
	GetPlayerName(playerid,pname,sizeof(pname));
	if (!strlen(iString)) return SendClientMessage(playerid,COLOR_RED,"[用法]: /wid [平行世界ID]"),true;
	P[playerid][UsedCmdToChangeVW] = true;
	if(curPlayerVehI[playerid] > 0 && IsPlayerInVehicle(playerid,curPlayerVehI[playerid]))
	{
		P[playerid][UsedCmdToChangeVW] = true;
	    SetVehicleVirtualWorld(curPlayerVehI[playerid],idx);
		SetPlayerVirtualWorld(playerid,idx);
		PutPlayerInVehicle(playerid,curPlayerVehI[playerid],0);
	}

	else
	{
		P[playerid][UsedCmdToChangeVW] = true;
		SetPlayerVirtualWorld(playerid,idx);
	}
	format(s1,sizeof(s1),"[时空]你已成功来到第 %i 平行世界...",idx);
	SendClientMessage(playerid,COLOR_GREEN,s1);
	P[playerid][VW] = idx;
    return 1;
}
dcmd_wn(playerid,params[])
{
    if(!strlen(params))
        {
			P[playerid][UsedCmdToChangeVW] = true;
        	SetPlayerVirtualWorld(playerid,0);
            SendClientMessage(playerid,COLOR_WHITE,"[切换世界]你回到地球.");
            SendClientMessage(playerid,COLOR_WHITE,"[切换世界]使用发法: /wn [世界名称]");
    }
    else
        {
        new vwid,str[128];
        for(new i;params[i];i++) vwid += params[i]*(i+i);
        if(vwid >= 0 && vwid < 999999999)
        {
            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) SetVehicleVirtualWorld(GetPlayerVehicleID(playerid),vwid);//玩家是司机就设置车辆virtualworlf
			P[playerid][UsedCmdToChangeVW] = true;
            SetPlayerVirtualWorld(playerid,vwid);
            format(str,sizeof(str),"[切换世界]你切换到'%s'世界.",params);
            SendClientMessage(playerid,COLOR_WHITE,str);
        }
        else SendClientMessage(playerid,COLOR_WHITE,"[切换世界]你输入的世界不存在.");
    }
    return 1;
}
dcmd_w(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,120,DIALOG_STYLE_LIST,"/w","[平行空间使用指南]\n \n通过空间数字ID传送\n用法:/wid [数字ID],如/wid 3则传送到3号平行空间.\n \n通过空间字符ID传送\n用法:/wn [任意字符],如/wn g则传送到名为g的平行空间.\n \n用处:处在不同平行空间的玩家除了聊天内容外完全避免接触.","确定","取消");
    return 1;
}
dcmd_fight(playerid,params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,41,DIALOG_STYLE_LIST,"[Super DM World]格斗风格","[Super DM World]格斗风格选择\n \n1.一般风格\n2.拳击风格\n3.功夫风格(荐)\n4.帮战风格1\n5.帮战风格2\n6.帮战风格3\n \n[提示]选择一项,双击或选定后按切换按钮.\n[提示]使用方法:跑动或静止时按住鼠标右键+F或回车.","切换","取消");
	return 1;
}
dcmd_i(playerid, params[])
{
    #pragma unused params
   	ShowPlayerDialog(playerid, INTERIORMENU, DIALOG_STYLE_LIST, "[室内空间]By:Garsino","24/7's(超级市场)\nAirports(飞机场)\nAmmunations(武器店)\nHouses(民房)\nHouses 2(民房2)\nMissions(单机任务房)\nStadiums（室内赛车场）\nCasinos(赌场)\nShops(商店)\nGarages（改车行）\nGirlfriends(CJ女朋友住处)\nClothing(服装店)/Barber Store(理发店)\nResturants(餐馆)/Clubs(俱乐部)\nNo Category（未分类）\nBurglary（入室盗窃）\nBurglary(入室盗窃2）\nGym(强身健体~锻炼房)\nDepartment(政府部门)\nBack(返回)", "选择", "取消");
    return 1;
}
dcmd_drunk(playerid, params[])
{
	new d[256],idx,s[256];
	if(!strlen(params))
	{
	    SendClientMessage(playerid,COLOR_RED,"[用法]/drunk [醉酒程度2000~50000]");
		SendClientMessage(playerid,COLOR_YELLOW,"[用处]拍摄特殊摇晃效果.");
		return 1;
	}
	d = strtok(params,idx);
	idx = strval(d);
	if(idx < 0 || idx > 50000) return SendClientMessage(playerid,COLOR_YELLOW,"[错误]醉酒程度为2000~50000内才有效."),true;
	SetPlayerDrunkLevel(playerid, idx);
	format(s,sizeof(s),"[提示]你的醉酒程度设置为 %d.",idx);
	SendClientMessage(playerid,COLOR_YELLOW,s);
	return 1;
}
dcmd_skill(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,88,DIALOG_STYLE_LIST,"/skill","1.手枪熟练度\n2.消音手枪熟练度\n3.沙漠之鹰熟练度\n4.警用霰弹熟练度\n5.Sawn-off熟练度\n6.SPAZ霰弹熟练度\n7.UZI熟练度\n8.MP5熟练度\n9.AK47熟练度\n10.M4熟练度\n11.狙击枪熟练度\n[用处]增加拍摄效果,持枪方式不同.","选择","取消");
	return 1;
}
dcmd_getpos(playerid, params[])
{
	#pragma unused params
	new Float:x,Float:y,Float:z,Float:a,n[256],s[256];
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid,a);
	GetPlayerName(playerid,n,sizeof(n));
	format(s,sizeof(s)," %s 的位置:\n \n所处平行宇宙: %d\n \n所处室内空间: %d\n \n所处坐标: %f %f %f\n \n面朝角度: %f",n,GetPlayerVirtualWorld(playerid),GetPlayerInterior(playerid),x,y,z,a);
	ShowPlayerDialog(playerid,43,DIALOG_STYLE_LIST,"/getpos",s,"确定","取消");
	return 1;
}
dcmd_to(playerid, params[])
{
	new opt;
	if(sscanf(params,"d",opt))
		SendClientMessage(playerid,COLOR_WHITE,"[提示]用法:/to [1-允许传送|0-禁止传送]");
	else if(opt < 0 || opt > 1)
		SendClientMessage(playerid,COLOR_WHITE,"[提示]用法:/to [1-允许传送|0-禁止传送]");
	else
	{
	    if(opt)
	    {
			P[playerid][AllowT] = true;
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已允许其他玩家传送到你的位置,输入/to 0禁止.");
			SendClientMessage(playerid,COLOR_WHITE,"[提示]现在其他人可以通过按\"tab\"后双击你传送到你的位置.");
		}
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已禁止其他玩家传送到你的位置,输入/to 1允许.");
			P[playerid][AllowT] = false;
		}
	}
	return 1;
}
dcmd_pk(playerid, params[])
{
	#pragma unused params
	GivePlayerWeapon(playerid,24,1000);
	P[playerid][UsedCmdToChangeVW] = true;
	SetPlayerVirtualWorld(playerid,99);
	SetPlayerPos(playerid,-2334.0029,-1632.4867,483.6996);
	P[playerid][pk] = true;
	return true;
}
dcmd_c(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,44,DIALOG_STYLE_LIST,"[SDW]车辆召唤系统","***空中交通工具\n***四门专用车\n***四门豪华轿车\n***水上交通工具\n***运动车\n***低底盘车\n***二轮交通工具\n***其他交通工具\n即将出现,敬请期待.","召唤","取消");
	return 1;
}
dcmd_write(playerid, params[])
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,COLOR_WHITE,"小样~"),true;
	new year,month,day,hour,minute,second,s[256];
	getdate(year, month, day);
	gettime(hour,minute,second);
	format(s,sizeof(s),"dairy/%d.%d.%d.txt",year,month,day);
	new File:F_Dairy = fopen(s,io_write);
	new content[256];
	format(content,256,"%s",params);
	fwrite(F_Dairy,content);
	fclose(F_Dairy);
	new s1[256],s2[256];
	format(s1,sizeof(s1),"日志写就!时间:%d/%d/%d/%d/%d/%d",year,month,day,hour,minute,second,year,month,day);
	format(s2,sizeof(s2),"要打开,输入/read %d.%d.%d",year,month,day);
	SendClientMessage(playerid,COLOR_WHITE,s1);
	SendClientMessage(playerid,COLOR_WHITE,s2);
	SendClientMessage(playerid,COLOR_WHITE,"一天只能写一篇日志,同一天的日志会相互覆盖.");
	return true;
}
dcmd_read(playerid, params[])
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,COLOR_WHITE,"小样~"),true;
	new content[256],s[256];
	format(s,sizeof(s),"dairy/%s.txt",params);
	new File:F_Dairy = fopen(s,io_read);
	if(!F_Dairy)
	    return SendClientMessage(playerid,COLOR_WHITE,"不存在"),true;
	fread(F_Dairy,content);
	fclose(F_Dairy);
	SendClientMessage(playerid,COLOR_WHITE,content);
	return 1;
}
dcmd_spawn(playerid, params[])
{
	new tmp[256],idx;
	tmp = strtok(params, idx);
	if(!strlen(tmp))
	{
		SendClientMessage(playerid,COLOR_RED,"[错误]可用内容:/spawn [set|reset]");
		return 1;
	}
	if(!strcmp(tmp,"set")== true)
	{
	    GetPlayerPos(playerid,P[playerid][Px],P[playerid][Py],P[playerid][Pz]);
	   	P[playerid][SavePos] = true;
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]出生点已设置为当前位置.");
	}
	else if(!strcmp(tmp,"reset") == true)
	{
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]出生点已重置为公共出生点.");
		P[playerid][SavePos] = false;
		P[playerid][Px] = 0.0;
		P[playerid][Py] = 0.0;
		P[playerid][Pz] = 0.0;
 	}
	else SendClientMessage(playerid,COLOR_RED,"[错误]可用内容:/spawn [set|reset]");
	return 1;
}
dcmd_cmdtester(playerid, params[])
{
	#pragma unused params
	new s[255];
	format(s,sizeof(s),"%d",P[playerid][LastPMSender]);
	SendClientMessage(playerid,COLOR_WHITE,s);
	return 1;
}

dcmd_pbt(playerid, params[])
{
	new opt,pid;
	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_WHITE,"[提示]使用方法:/pbt [玩家ID|部分名字] [1-屏蔽|0-解除](将屏蔽或恢复与该玩家的传送)");
	else if(!IsPlayerConnected(pid))
 		SendClientMessage(playerid,COLOR_RED,"[错误]无效的玩家ID.");
	else if(pid == playerid)
		SendClientMessage(playerid,COLOR_RED,"[错误]你不能屏蔽/反屏蔽你自己!");
	else if(opt)
	{
	    if(pb[playerid][pid][teleport] == true)
			SendClientMessage(playerid,COLOR_WHITE,"[错误]该玩家已经被你屏蔽!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已屏蔽该玩家的传送!");
			pb[playerid][pid][teleport] = true;
		}
	}
	else
	{
	    if(pb[playerid][pid][teleport] == false) SendClientMessage(playerid,COLOR_WHITE,"[错误]该玩家未被你屏蔽!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已解除屏蔽该玩家的传送!");
			pb[playerid][pid][teleport] = false;
		}
	}
	return 1;
}
dcmd_pbs(playerid, params[])
{
	new opt,pid;
	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_WHITE,"[提示]使用方法:/pbs [玩家ID|部分名字] [1-屏蔽|0-解除](将屏蔽或恢复与该玩家的公共聊天)");
	else if(!IsPlayerConnected(pid))
 		SendClientMessage(playerid,COLOR_RED,"[错误]无效的玩家ID.");
	else if(pid == playerid)
		SendClientMessage(playerid,COLOR_RED,"[错误]你不能屏蔽/反屏蔽你自己!");
	else if(opt)
	{
	    if(pb[playerid][pid][speak] == true)
			SendClientMessage(playerid,COLOR_WHITE,"[错误]该玩家已经被你屏蔽!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已屏蔽该玩家的公共聊天!");
			pb[playerid][pid][speak] = true;
		}
	}
	else
	{
	    if(pb[playerid][pid][speak] == false) SendClientMessage(playerid,COLOR_WHITE,"[错误]该玩家未被你屏蔽!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已解除屏蔽该玩家的公共聊天!");
			pb[playerid][pid][speak] = false;
		}
	}
	return 1;
}
dcmd_pbm(playerid, params[])
{
	new opt,pid;
	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_WHITE,"[提示]使用方法:/pbm [玩家ID|部分名字] [1-屏蔽|0-解除](将屏蔽或恢复与该玩家的私聊)");
	else if(!IsPlayerConnected(pid))
 		SendClientMessage(playerid,COLOR_RED,"[错误]无效的玩家ID.");
	else if(pid == playerid)
		SendClientMessage(playerid,COLOR_RED,"[错误]你不能屏蔽/反屏蔽你自己!");
	else if(opt)
	{
	    if(pb[playerid][pid][pm] == true)
			SendClientMessage(playerid,COLOR_WHITE,"[错误]该玩家已经被你屏蔽!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已屏蔽该玩家的私聊!");
			pb[playerid][pid][pm] = true;
		}
	}
	else
	{
	    if(pb[playerid][pid][pm] == false) SendClientMessage(playerid,COLOR_WHITE,"[错误]该玩家未被你屏蔽!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[提示]你已解除屏蔽该玩家私聊!");
			pb[playerid][pid][pm] = false;
		}
	}
	return 1;
}

dcmd_hp(playerid, params[])
{
	if(!strlen(params)) SendClientMessage(playerid,COLOR_RED,"[用法]/hp [血量]");
	else if(strval(params) < 0.0) SendClientMessage(playerid,COLOR_RED,"[错误]血量不能小于0!");
	else
	{
		SetPlayerHealth(playerid,strval(params));
		new s[256];
		format(s,sizeof(s),"[提示]血量已设置为 %d",strval(params));
		SendClientMessage(playerid,COLOR_RED,s);
	}
	return 1;
}
dcmd_spec(playerid, params[])
{
	new pid,opt;

	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_RED,"[用法]:/spec [玩家id|名字] [1-开始监视|0-停止监视]");
	else if(!IsPlayerConnected(pid))
		SendClientMessage(playerid,COLOR_RED,"[错误]无效的玩家ID.");
	else if(pid == playerid)
        SendClientMessage(playerid,COLOR_RED,"[错误]你不能观察自己.");
	else if(opt)
	{
		TogglePlayerSpectating(playerid,1);
		PlayerSpectatePlayer(playerid,pid);
		P[playerid][specing] = true;
		P[playerid][spectee] = pid;
		SendClientMessage(playerid,COLOR_WHITE,"[提示]输入/unspec停止观察.");
  	}
  	else
  	{
  		if(P[playerid][specing])
		{
			P[playerid][spectee] = -1;
			P[playerid][specing] = false;
			TogglePlayerSpectating(playerid,0);
			SetCameraBehindPlayer(playerid);
		}
		else return true;
  	}
  	return 1;
}
dcmd_gxqm(playerid, params[])
{
#pragma unused params
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(!strlen(params)) SendClientMessage(playerid,COLOR_WHITE,"[用法]/gxqm [个性签名]");
	else
	{
	    if(P[playerid][gxqm])
	    {
	        Update3DTextLabelText(P[playerid][gxqm],GetPlayerColor(playerid),params);
			SendClientMessage(playerid,COLOR_WHITE,"[提示]个性签名已更新!");
		}
		else
		{
			P[playerid][gxqm] = Create3DTextLabel(params,GetPlayerColor(playerid),x,y,z+1,100.0,0);
			Attach3DTextLabelToPlayer(P[playerid][gxqm],playerid,0.0,0.0,0.5);
			SendClientMessage(playerid,COLOR_WHITE,"[提示]个性签名已创建!");
		}

	}
	return 1;
}
dcmd_wsel(playerid,params[])
{
#pragma unused params
	new cString[128];

	if (P[playerid][gPlayerStatus] != 0) {
		format(cString, 128, "[错误]:你已经在使用 \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
		SendClientMessage(playerid, COLOR_RED, cString);
		return true;
	}

	new Float:x, Float:y, Float:z;

	P[playerid][gPlayerStatus] = WORL_SEL_STAT;

	GetPlayerPos(playerid, x, y, z);
	SetPlayerCameraLookAt(playerid, x, y, z+2);

	GetXYInFrontOfPlayer(playerid, x, y, 3.5);
	SetPlayerCameraPos(playerid, x, y, z);

	TogglePlayerControllable(playerid, 0);
	SendClientMessage(playerid,COLOR_CYAN,"[提示]按左右键浏览时间,按上下键浏览天气,按开火键选取.");
	SendClientMessage(playerid,COLOR_CYAN,"[提示]你也可以用/wea [ID]和/t [ID]选取特定天气和时间.");
	P[playerid][gPlayerTimers] = SetTimerEx("WorldSelect", 200, 1, "i", playerid);

	return true;
}
dcmd_saveall(playerid, params[])
{
	if(!strlen(params))
	{
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]用法:/saveall [auto - 自动保存|now - 立即保存]");
	    return true;
 	}
	else if(!strcmp(params,"auto") == true)
	{
		if(P[playerid][Autosave])
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[提示]自动保存已关闭.");
			P[playerid][Autosave] = false;
		}
		else
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[提示]自动保存已开启.");
			P[playerid][Autosave] = true;
		}
	}
	else if(!strcmp(params,"now") == true)
	{
	    SaveAll(playerid);
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]所有设置保存.");
 	}
	else
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]用法:/saveall [auto - 自动保存|now - 立即保存]");
	return 1;
}
dcmd_loadall(playerid, params[])
{
	if(!strlen(params))
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]用法:/loadall [auto - 自动载入|now - 立即载入]");
	else if(!strcmp(params,"auto") == true)
	{
		if(P[playerid][Autoload])
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[提示]自动载入已关闭.");
			P[playerid][Autoload] = false;
		}
		else
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[提示]自动载入已开启.");
			P[playerid][Autoload] = true;
		}
	}
	else if(!strcmp(params,"now") == true)
	{
	    if(LoadAll(playerid))
			SendClientMessage(playerid,COLOR_WHITE,"[提示]所有保存设置载入.");
 	}
	else
	    SendClientMessage(playerid,COLOR_WHITE,"[提示]用法:/loadall [auto - 自动载入|now - 立即载入]");
	return 1;
}
dcmd_pm(playerid, params[])
{
	new idp,message[256],Message[256],iName[256],pName[256];
	if(sscanf(params,"us",idp,message))
		SendClientMessage(playerid,COLOR_WHITE,"[用法]/pm [玩家id或部分名字] [内容]");
	else if(!IsPlayerConnected(idp))
		SendClientMessage(playerid,COLOR_RED,"[错误]无效的玩家.");
	else if(pb[idp][playerid][pm] == true)
		SendClientMessage(playerid,COLOR_RED,"[错误]该玩家已对你屏蔽PM信息.");
/*		if(playerid == idp)
		{
			SendClientMessage(playerid,COLOR_RED,"[错误]你不能PM你自己.");
			return 1;
		}*/
	else
	{
			GetPlayerName(idp,iName,sizeof(iName));
			GetPlayerName(playerid,pName,sizeof(pName));
			format(Message,sizeof(Message),">> 你悄悄地对%s(%d)说: %s",iName,idp,message);
			SendClientMessage(playerid,COLOR_YELLOW,Message);
//			format(Message,sizeof(Message),"** %s(%d)悄悄地对你说: %s",pName,playerid,gMessage);
//			SendClientMessage(idp,COLOR_GREEN,Message);
			format(Message,sizeof(Message),"***你收到了来自 %s(%d)的私人信息 **\n%s(%d):\n%s",pName,playerid,pName,playerid,Message);
			ShowPlayerDialog(idp,idp+1000,DIALOG_STYLE_LIST,"PMR",Message,"回复","取消");
			P[idp][LastPMSender] = playerid;
			P[idp][pming] = true;
			PlayerPlaySound(playerid,1058,0,0,0);
			PlayerPlaySound(idp,1058,0,0,0);
//			ShowPlayerDialog(id,77777,DIALOG_STYLE_LIST,"/pm",Message,"确认","明白");
//			printf("PM: %s",Message);
	}
	return 1;
}
dcmd_dl(playerid, params[])
{
	if(P[playerid][Loggedin] == true)
	    SendClientMessage(playerid,COLOR_RED,"[错误]已经登陆.");
	else if(P[playerid][Registed] == false)
	    SendClientMessage(playerid,COLOR_RED,"[错误]尚未注册,请使用/zc [密码] 注册.");
	else if(!strlen(params))
	    SendClientMessage(playerid,COLOR_WHITE,"[用法]/dl [密码].");
	else
	{
	    new pn[256],pfile[256],pass[256];
	    GetPlayerName(playerid,pn,sizeof(pn));
	    format(pfile,sizeof(pfile),"spawn/%s.ini",pn);
	    pass = dini_Get(pfile,"password");
	    if(strcmp(params,pass) != 0)
	    {
	    	SendClientMessage(playerid,COLOR_RED,"[提示]密码错误.");
	    }
	    else
	    {
	    	SendClientMessage(playerid,COLOR_RED,"[提示]成功登陆.");
	    	P[playerid][Loggedin] = true;
	    }
	}
	return 1;
}
dcmd_zc(playerid, params[])
{
	if(P[playerid][Loggedin] == true)
	    SendClientMessage(playerid,COLOR_RED,"[错误]已经登陆.");
	else if(P[playerid][Registed] == true)
	    SendClientMessage(playerid,COLOR_RED,"[错误]已经注册.");
	else if(!strlen(params))
	    SendClientMessage(playerid,COLOR_WHITE,"[用法]/dl [密码].");
	else
	{
	    new pn[256],pfile[256];
	    GetPlayerName(playerid,pn,sizeof(pn));
	    format(pfile,sizeof(pfile),"spawn/%s.ini",pn);
		dini_Set(pfile,"password",params);
	    SendClientMessage(playerid,COLOR_RED,"[提示]成功注册.");
	    P[playerid][Registed] = true;
	}
	return 1;
}
dcmd_fashe(playerid, params[])
{
#pragma unused params
	new name[5];
	GetPlayerName(playerid,name);
	if(!IsPlayerAdmin(playerid))
		SendClientMessage(playerid,COLOR_RED,"[错误]游客无法发射.");
	else LaunchCountingDown();
	return 1;
}
dcmd_reset(playerid, params[])
{
#pragma unused params
	RocketReset();
	return 1;
}