//===========================public OPCT=============================//

public OnPlayerCommandText(playerid, cmdtext[])
{
	dcmd(dl, 2, cmdtext);
	dcmd(zc, 2, cmdtext);
/*	if(P[playerid][Registed] == false)
	{
	    SendClientMessage(playerid,COLOR_RED,"[��ʾ]ע��ǰ�޷�ʹ��ָ��,��ʹ��/zc [����]��½");
	    return 1;
	}
	if(P[playerid][Registed] == true && P[playerid][Loggedin] == false)
	{
	    SendClientMessage(playerid,COLOR_RED,"[��ʾ]��¼ǰ�޷�ʹ��ָ��,��ʹ��/dl [����]��½");
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
//        SendClientMessage(playerid, COLOR_YELLOW, "/camerapos - �鿴һϵ���ѱ���ľ�ͷ");
	format(s1,sizeof(s1),"GTAIP��Ӱ������[��Ϸָ��]\n \n \n1.��������ָ��\n2.λ�����ָ��\n3.��ͨ�������ָ��\n4.OBJ(object)���ָ��\n5.��������~\n6.���⼼��\n \n=================================================");
	ShowPlayerDialog(playerid,2,DIALOG_STYLE_LIST,"/cmds",s1,"ѡ��","ȡ��");
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
	SendClientMessage(playerid,COLOR_WHITE,"С��~");
	return true;
}

dcmd_osel(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid,COLOR_WHITE,"С��~");
	return true;
}

dcmd_camera(playerid, params[]) {
	new idx; new cString[128];
	
	cString = strtok(params, idx);
	
	if (!strlen(cString)) {
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /camera [RATE/MODE] [RATE/MODEID]");
		
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
		format(cString, 128, "[����]���Ѿ���ʹ��ָ�� \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
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
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /weather(/wea) [����ID]");
		return true;
	}
	
	idx = strval(iString);
	
	if (idx < MIN_WEAT_ID || idx > MAX_WEAT_ID) {
		SendClientMessage(playerid, COLOR_RED, "[����]:��Ч������ID.");
		return true;
	}
	
	if(limit[playerid] >= 5)
	{
		SendClientMessage(playerid, COLOR_RED, "[����]:��ȴ�20���ٳ���.");
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
	
	format(iString, 128, "[����]: %s ��ta��������ΪIDΪ %d ������.", pname, idx);
	SendClientMessageToAll(COLOR_PURPLE, iString);
	
	return true;
}

dcmd_weather(playerid, params[])
return dcmd_wea(playerid, params);

dcmd_t(playerid, params[]) {
	new idx, iString[128];
	iString = strtok(params, idx);
	
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /time(/t) [Сʱ]");
		return true;
	}
	
	idx = strval(iString);
	
	if (idx < MIN_TIME_ID || idx > MAX_TIME_ID) {
		SendClientMessage(playerid, COLOR_RED, "[����]:��Ч��ʱ��");
		return true;
	}
	
	if(limit[playerid] >= 5)
	{
		SendClientMessage(playerid, COLOR_RED, "[����]:��ȴ�20���ٳ���.");
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
	
	format(iString, 128, "[ʱ��]: %s ��ta��ʱ���Ϊ %d ��.", pname, idx);
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
		SendClientMessage( playerid, COLOR_RED, "[�÷�]: /vname [��������]" );
		return true;
	}
	else if(PV[playerid][4][spawned] == true)
	{
		SendClientMessage(playerid,COLOR_RED,"[����]��Ŀ�ˢ�������Ѿ��ﵽ����5,��ʹ��/dcarָ��.");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,COLOR_RED,"[����]����һ����ͨ������,��������.");
		return true;
	}
	else if (P[ playerid ][gPlayerStatus] != 0 )
		{
			format(iString, 128, "[����]: ���Ѿ���ʹ�� \"%s\".", aSelNames[ P[ playerid ][gPlayerStatus] - 1 ] );
			SendClientMessage(playerid, COLOR_RED, iString );
			return true;
		}
	idx = GetVehicleModelIDFromName( params );

	if( idx == -1 )
		{
			idx = strval(params);

			if ( idx < MIN_VEHI_ID || idx > MAX_VEHI_ID )
			{
				SendClientMessage(playerid, COLOR_RED, "[����]:��Ч�ĳ�������.");
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
		format(iString, 128, "[����]: %s �ٻ���һ�� \"%s\" ,��ta�ĵ� %i ����(ģ��ID: %d, ����˳��ID: %d)", pname, aVehicleNames[idx - MIN_VEHI_ID], i+1,idx, curPlayerVehI[playerid]);
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
	ShowPlayerDialog(playerid,100,DIALOG_STYLE_LIST,"/v","ˢ������:\nͨ��IDˢ��,ָ��:/vid [����ID],\n��/vid 411,��ˢ��idΪ411�ĳ���.\n \nͨ������ˢ��,ָ��/vn(vname) [����]\n��/vname sul,��ˢ��һ��Sultan\n \nͨ�������ģ��ˢ��(�ݲ�����)\n \nͨ������ѡ���ٳ�(�ݲ�����)\n \n[��ʾ]ÿ����ˢ5����ͨ����.���ָ��:/dc(/dcar) - ���� || /cc(/ccar) - ����","ȷ��","ȡ��");
    return true;
}

dcmd_vid(playerid, params[])
{
	new idx,i,iString[256];
	if(sscanf(params,"d",idx))
	{
		SendClientMessage(playerid, COLOR_WHITE, "[�÷�]/vid [����ID]");
		return true;
	}
	else if(PV[playerid][4][spawned] == true)
	{
		SendClientMessage(playerid,COLOR_RED,"[����]��Ŀ�ˢ�������Ѿ��ﵽ����5,��ʹ��/dcarָ��.");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,COLOR_RED,"[����]����һ����ͨ������,��������.");
		return true;
	}
	else if (idx > 611 || idx < 400)
	{
		SendClientMessage(playerid, COLOR_RED, "[����]:��Ч�ĳ���ID.");
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
	    format(iString, 128, "[�ɹ�] %s ���³�IDΪ %d,��һ�� %s,��ta�ĵ� %i ����,˳��ID %i .", pname, idx, aVehicleNames[idx - MIN_VEHI_ID],i+1,curPlayerVehI[playerid]);
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
		SendClientMessage(playerid, COLOR_RED,"[����]���Ѿ�ˢ��5����ͨ����,����ʹ��/dcar");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_RED,"[����]����һ����ͨ������,��������");
		return true;
	}
	else if(P[playerid][gPlayerStatus] != 0)
	{
		format(cString, 128, "[����]:���Ѿ���ʹ�� \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
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
		SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]�����Ҽ����,�������ѡȡ.");
		SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]��Ҳ������/vid [ID] ��/vname [����]ѡȡ�ض��ĳ���.");
		P[playerid][gPlayerTimers] = SetTimerEx("VehicleSelect", 200, 2, "i", playerid,i);

		return true;
	}
}

dcmd_dcar(playerid, params[])
{
#pragma unused params
    if(PV[playerid][0][spawned] == false) return SendClientMessage(playerid,COLOR_RED,"[��ʾ]�㻹ûˢ�κγ�,��ʹ��/v�鿴˵��."),true;
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
		SendClientMessage(playerid,COLOR_YELLOW,"[�ɹ�]���г�����λ,���ڿ�����/vˢ����,���5��.");
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
		SendClientMessage(playerid,COLOR_RED,"[��ʾ]�㻹û��ˢ�κγ���,��鿴����ϵͳ˵��/v.");
		return true;
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,COLOR_RED,"[����]����һ����ͨ������,�����뿪.");
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
			format(s,sizeof(s),"1.%s, ģ��ID: %d\n \n2.%s ,ģ��ID: %d\n \n3.%s ,ģ��ID: %d\n \n4.%s ,ģ��ID: %d\n \n5.%s ,ģ��ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid],vn3,PV[playerid][2][mid],vn4,PV[playerid][3][mid],vn5,PV[playerid][4][mid]);
		}
		else if(PV[playerid][3][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(vn3,256,"%s",aVehicleNames[PV[playerid][2][mid] - MIN_VEHI_ID]);
			format(vn4,256,"%s",aVehicleNames[PV[playerid][3][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,ģ��ID: %d\n \n2.%s ,ģ��ID: %d\n \n3.%s ,ģ��ID: %d\n \n4.%s ,ģ��ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid],vn3,PV[playerid][2][mid],vn4,PV[playerid][3][mid]);
		}
		else if(PV[playerid][2][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(vn3,256,"%s",aVehicleNames[PV[playerid][2][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,ģ��ID: %d\n \n2.%s ,ģ��ID: %d\n \n3.%s ,ģ��ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid],vn3,PV[playerid][2][mid]);
		}
		else if(PV[playerid][1][spawned] == true)
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(vn2,256,"%s",aVehicleNames[PV[playerid][1][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,ģ��ID: %d\n \n2.%s ,ģ��ID: %d",vn1,PV[playerid][0][mid],vn2,PV[playerid][1][mid]);
		}
		else
		{
			format(vn1,256,"%s",aVehicleNames[PV[playerid][0][mid] - MIN_VEHI_ID]);
			format(s,sizeof(s),"1.%s ,ģ��ID: %d",vn1,PV[playerid][0][mid]);
		}
		ShowPlayerDialog(playerid,77,DIALOG_STYLE_LIST,"/ccar",s,"�ٻ�","ȡ��");
	}
	return 1;
}
dcmd_qcys(playerid, params[])
{
#pragma unused params
	if(!IsPlayerInAnyVehicle(playerid))
	{
	    SendClientMessage(playerid,COLOR_RED,"[����]�㲻���κν�ͨ������.");
	    return 1;
	}
	else
	{
		new xx = GetPlayerVehicleID(playerid),i=0;
		if(PV[playerid][0][id] == -1)
		{
  			SendClientMessage(playerid,COLOR_RED,"[����]�㻹û���κ�ר����ͨ����.");
			return 1;
		}
		else if(xx != PV[playerid][0][id] && xx != PV[playerid][1][id] && xx != PV[playerid][2][id] && xx != PV[playerid][3][id] && xx != PV[playerid][4][id])
		{
  			SendClientMessage(playerid,COLOR_RED,"[����]�ⲻ�����ר����ͨ����!");
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
			SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]�����Ҽ����,�������ѡȡ.");
			SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]��Ҳ������/carcolor [ID] [ID]ѡȡ�ض��Ľ�ͨ������ɫ.");
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
		format(cString, 128, "[����]:���Ѿ���ʹ�� \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
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
	SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]�����Ҽ����,�������ѡȡ.");
	SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]��Ҳ������/sid [ID] ѡȡ�ض�ID��Ƥ��.");
	P[playerid][gPlayerTimers] = SetTimerEx("SkinSelect", 200, 1, "i", playerid);
	
	return true;
}

dcmd_sid(playerid, params[])
{
	// /s SKINID allows players to directly select a skin using it's ID.
	new idx, iString[128];
	iString = strtok(params, idx);
	
	if (!strlen(iString)) {
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /sid [Ƥ��ID]");
		return true;
	}
	
	idx = strval(iString);
	
	if (IsInvalidSkin(idx) || idx < MIN_SKIN_ID || idx > MAX_SKIN_ID) {
		SendClientMessage(playerid, COLOR_RED, "[����]:��Ч��Ƥ��ID.");
		return true;
	}
	
	SetPlayerSkin(playerid, idx);
	P[playerid][Skin] = idx;
	format(iString, 128, "[�ɹ�]��Ƥ����IDΪ %d", idx);
	SendClientMessage(playerid, COLOR_GREEN, iString);
	
	return true;
}
dcmd_skin(playerid, params[])
{
    #pragma unused params
    ShowPlayerDialog(playerid,102,DIALOG_STYLE_LIST,"/skin","Ƥ����������:(����)\n \n \nͨ������Ƥ��ID����\nָ��:/sid [Ƥ��ID],��Ҫ����ΪIDΪ100��Ƥ��,������/sid 100\n \nͨ�����Ƥ������\nָ��:/ssel,�����Ҽ����,��'����'��ѡ��.","֪����","ȷ��");
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
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /nick [������]");
		return 1;
	}
	if(limit[playerid] >= 2)
	{
		SendClientMessage(playerid, COLOR_RED, "[����]:��ȴ�20���ٳ���.");
		return 1;
	}
	else
	{
	limit[playerid]++;
	SetTimerEx("reset", 20000, 0, "i", playerid);
	GetPlayerName(playerid,pname,sizeof(pname));
	format(string, sizeof(string), "[����]: %s ����Ϊ: %s" ,pname,params);
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
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /setloc X Y Z INTERIOR");
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
		SendClientMessage(playerid, COLOR_RED, "[�÷�]: /weapon(/w2) [����ID������]");
		return true;
	}
	
	new weaponid = GetWeaponModelIDFromName(iString);
	if (weaponid == -1) {
		weaponid = strval(iString);
		if (weaponid < 0 || weaponid > 47) {
			SendClientMessage(playerid, COLOR_RED, "[����]:��Ч������ID������.");
			return true;
		}
	}
	if(limit[playerid] >= 3)
	{
		SendClientMessage(playerid, COLOR_RED, "[����]:��ȴ�20���ٳ���.");
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
		format(iString, 128, "[����]: %s �ٻ��� %s (ID: %d)", pname, aWeaponNames[weaponid], weaponid);
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
	if (!strlen(iString)) return SendClientMessage(playerid,COLOR_RED,"[�÷�]: /wid [ƽ������ID]"),true;
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
	format(s1,sizeof(s1),"[ʱ��]���ѳɹ������� %i ƽ������...",idx);
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
            SendClientMessage(playerid,COLOR_WHITE,"[�л�����]��ص�����.");
            SendClientMessage(playerid,COLOR_WHITE,"[�л�����]ʹ�÷���: /wn [��������]");
    }
    else
        {
        new vwid,str[128];
        for(new i;params[i];i++) vwid += params[i]*(i+i);
        if(vwid >= 0 && vwid < 999999999)
        {
            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) SetVehicleVirtualWorld(GetPlayerVehicleID(playerid),vwid);//�����˾�������ó���virtualworlf
			P[playerid][UsedCmdToChangeVW] = true;
            SetPlayerVirtualWorld(playerid,vwid);
            format(str,sizeof(str),"[�л�����]���л���'%s'����.",params);
            SendClientMessage(playerid,COLOR_WHITE,str);
        }
        else SendClientMessage(playerid,COLOR_WHITE,"[�л�����]����������粻����.");
    }
    return 1;
}
dcmd_w(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,120,DIALOG_STYLE_LIST,"/w","[ƽ�пռ�ʹ��ָ��]\n \nͨ���ռ�����ID����\n�÷�:/wid [����ID],��/wid 3���͵�3��ƽ�пռ�.\n \nͨ���ռ��ַ�ID����\n�÷�:/wn [�����ַ�],��/wn g���͵���Ϊg��ƽ�пռ�.\n \n�ô�:���ڲ�ͬƽ�пռ����ҳ���������������ȫ����Ӵ�.","ȷ��","ȡ��");
    return 1;
}
dcmd_fight(playerid,params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,41,DIALOG_STYLE_LIST,"[Super DM World]�񶷷��","[Super DM World]�񶷷��ѡ��\n \n1.һ����\n2.ȭ�����\n3.������(��)\n4.��ս���1\n5.��ս���2\n6.��ս���3\n \n[��ʾ]ѡ��һ��,˫����ѡ�����л���ť.\n[��ʾ]ʹ�÷���:�ܶ���ֹʱ��ס����Ҽ�+F��س�.","�л�","ȡ��");
	return 1;
}
dcmd_i(playerid, params[])
{
    #pragma unused params
   	ShowPlayerDialog(playerid, INTERIORMENU, DIALOG_STYLE_LIST, "[���ڿռ�]By:Garsino","24/7's(�����г�)\nAirports(�ɻ���)\nAmmunations(������)\nHouses(��)\nHouses 2(��2)\nMissions(��������)\nStadiums��������������\nCasinos(�ĳ�)\nShops(�̵�)\nGarages���ĳ��У�\nGirlfriends(CJŮ����ס��)\nClothing(��װ��)/Barber Store(������)\nResturants(�͹�)/Clubs(���ֲ�)\nNo Category��δ���ࣩ\nBurglary�����ҵ��ԣ�\nBurglary(���ҵ���2��\nGym(ǿ������~������)\nDepartment(��������)\nBack(����)", "ѡ��", "ȡ��");
    return 1;
}
dcmd_drunk(playerid, params[])
{
	new d[256],idx,s[256];
	if(!strlen(params))
	{
	    SendClientMessage(playerid,COLOR_RED,"[�÷�]/drunk [���Ƴ̶�2000~50000]");
		SendClientMessage(playerid,COLOR_YELLOW,"[�ô�]��������ҡ��Ч��.");
		return 1;
	}
	d = strtok(params,idx);
	idx = strval(d);
	if(idx < 0 || idx > 50000) return SendClientMessage(playerid,COLOR_YELLOW,"[����]���Ƴ̶�Ϊ2000~50000�ڲ���Ч."),true;
	SetPlayerDrunkLevel(playerid, idx);
	format(s,sizeof(s),"[��ʾ]������Ƴ̶�����Ϊ %d.",idx);
	SendClientMessage(playerid,COLOR_YELLOW,s);
	return 1;
}
dcmd_skill(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid,88,DIALOG_STYLE_LIST,"/skill","1.��ǹ������\n2.������ǹ������\n3.ɳĮ֮ӥ������\n4.��������������\n5.Sawn-off������\n6.SPAZ����������\n7.UZI������\n8.MP5������\n9.AK47������\n10.M4������\n11.�ѻ�ǹ������\n[�ô�]��������Ч��,��ǹ��ʽ��ͬ.","ѡ��","ȡ��");
	return 1;
}
dcmd_getpos(playerid, params[])
{
	#pragma unused params
	new Float:x,Float:y,Float:z,Float:a,n[256],s[256];
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid,a);
	GetPlayerName(playerid,n,sizeof(n));
	format(s,sizeof(s)," %s ��λ��:\n \n����ƽ������: %d\n \n�������ڿռ�: %d\n \n��������: %f %f %f\n \n�泯�Ƕ�: %f",n,GetPlayerVirtualWorld(playerid),GetPlayerInterior(playerid),x,y,z,a);
	ShowPlayerDialog(playerid,43,DIALOG_STYLE_LIST,"/getpos",s,"ȷ��","ȡ��");
	return 1;
}
dcmd_to(playerid, params[])
{
	new opt;
	if(sscanf(params,"d",opt))
		SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�÷�:/to [1-��������|0-��ֹ����]");
	else if(opt < 0 || opt > 1)
		SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�÷�:/to [1-��������|0-��ֹ����]");
	else
	{
	    if(opt)
	    {
			P[playerid][AllowT] = true;
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]��������������Ҵ��͵����λ��,����/to 0��ֹ.");
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]���������˿���ͨ����\"tab\"��˫���㴫�͵����λ��.");
		}
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]���ѽ�ֹ������Ҵ��͵����λ��,����/to 1����.");
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
	ShowPlayerDialog(playerid,44,DIALOG_STYLE_LIST,"[SDW]�����ٻ�ϵͳ","***���н�ͨ����\n***����ר�ó�\n***���ź����γ�\n***ˮ�Ͻ�ͨ����\n***�˶���\n***�͵��̳�\n***���ֽ�ͨ����\n***������ͨ����\n��������,�����ڴ�.","�ٻ�","ȡ��");
	return 1;
}
dcmd_write(playerid, params[])
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,COLOR_WHITE,"С��~"),true;
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
	format(s1,sizeof(s1),"��־д��!ʱ��:%d/%d/%d/%d/%d/%d",year,month,day,hour,minute,second,year,month,day);
	format(s2,sizeof(s2),"Ҫ��,����/read %d.%d.%d",year,month,day);
	SendClientMessage(playerid,COLOR_WHITE,s1);
	SendClientMessage(playerid,COLOR_WHITE,s2);
	SendClientMessage(playerid,COLOR_WHITE,"һ��ֻ��дһƪ��־,ͬһ�����־���໥����.");
	return true;
}
dcmd_read(playerid, params[])
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid,COLOR_WHITE,"С��~"),true;
	new content[256],s[256];
	format(s,sizeof(s),"dairy/%s.txt",params);
	new File:F_Dairy = fopen(s,io_read);
	if(!F_Dairy)
	    return SendClientMessage(playerid,COLOR_WHITE,"������"),true;
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
		SendClientMessage(playerid,COLOR_RED,"[����]��������:/spawn [set|reset]");
		return 1;
	}
	if(!strcmp(tmp,"set")== true)
	{
	    GetPlayerPos(playerid,P[playerid][Px],P[playerid][Py],P[playerid][Pz]);
	   	P[playerid][SavePos] = true;
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]������������Ϊ��ǰλ��.");
	}
	else if(!strcmp(tmp,"reset") == true)
	{
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]������������Ϊ����������.");
		P[playerid][SavePos] = false;
		P[playerid][Px] = 0.0;
		P[playerid][Py] = 0.0;
		P[playerid][Pz] = 0.0;
 	}
	else SendClientMessage(playerid,COLOR_RED,"[����]��������:/spawn [set|reset]");
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
	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]ʹ�÷���:/pbt [���ID|��������] [1-����|0-���](�����λ�ָ������ҵĴ���)");
	else if(!IsPlayerConnected(pid))
 		SendClientMessage(playerid,COLOR_RED,"[����]��Ч�����ID.");
	else if(pid == playerid)
		SendClientMessage(playerid,COLOR_RED,"[����]�㲻������/���������Լ�!");
	else if(opt)
	{
	    if(pb[playerid][pid][teleport] == true)
			SendClientMessage(playerid,COLOR_WHITE,"[����]������Ѿ���������!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�������θ���ҵĴ���!");
			pb[playerid][pid][teleport] = true;
		}
	}
	else
	{
	    if(pb[playerid][pid][teleport] == false) SendClientMessage(playerid,COLOR_WHITE,"[����]�����δ��������!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]���ѽ�����θ���ҵĴ���!");
			pb[playerid][pid][teleport] = false;
		}
	}
	return 1;
}
dcmd_pbs(playerid, params[])
{
	new opt,pid;
	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]ʹ�÷���:/pbs [���ID|��������] [1-����|0-���](�����λ�ָ������ҵĹ�������)");
	else if(!IsPlayerConnected(pid))
 		SendClientMessage(playerid,COLOR_RED,"[����]��Ч�����ID.");
	else if(pid == playerid)
		SendClientMessage(playerid,COLOR_RED,"[����]�㲻������/���������Լ�!");
	else if(opt)
	{
	    if(pb[playerid][pid][speak] == true)
			SendClientMessage(playerid,COLOR_WHITE,"[����]������Ѿ���������!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�������θ���ҵĹ�������!");
			pb[playerid][pid][speak] = true;
		}
	}
	else
	{
	    if(pb[playerid][pid][speak] == false) SendClientMessage(playerid,COLOR_WHITE,"[����]�����δ��������!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]���ѽ�����θ���ҵĹ�������!");
			pb[playerid][pid][speak] = false;
		}
	}
	return 1;
}
dcmd_pbm(playerid, params[])
{
	new opt,pid;
	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]ʹ�÷���:/pbm [���ID|��������] [1-����|0-���](�����λ�ָ������ҵ�˽��)");
	else if(!IsPlayerConnected(pid))
 		SendClientMessage(playerid,COLOR_RED,"[����]��Ч�����ID.");
	else if(pid == playerid)
		SendClientMessage(playerid,COLOR_RED,"[����]�㲻������/���������Լ�!");
	else if(opt)
	{
	    if(pb[playerid][pid][pm] == true)
			SendClientMessage(playerid,COLOR_WHITE,"[����]������Ѿ���������!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�������θ���ҵ�˽��!");
			pb[playerid][pid][pm] = true;
		}
	}
	else
	{
	    if(pb[playerid][pid][pm] == false) SendClientMessage(playerid,COLOR_WHITE,"[����]�����δ��������!");
		else
		{
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]���ѽ�����θ����˽��!");
			pb[playerid][pid][pm] = false;
		}
	}
	return 1;
}

dcmd_hp(playerid, params[])
{
	if(!strlen(params)) SendClientMessage(playerid,COLOR_RED,"[�÷�]/hp [Ѫ��]");
	else if(strval(params) < 0.0) SendClientMessage(playerid,COLOR_RED,"[����]Ѫ������С��0!");
	else
	{
		SetPlayerHealth(playerid,strval(params));
		new s[256];
		format(s,sizeof(s),"[��ʾ]Ѫ��������Ϊ %d",strval(params));
		SendClientMessage(playerid,COLOR_RED,s);
	}
	return 1;
}
dcmd_spec(playerid, params[])
{
	new pid,opt;

	if(sscanf(params,"ud",pid,opt)) SendClientMessage(playerid,COLOR_RED,"[�÷�]:/spec [���id|����] [1-��ʼ����|0-ֹͣ����]");
	else if(!IsPlayerConnected(pid))
		SendClientMessage(playerid,COLOR_RED,"[����]��Ч�����ID.");
	else if(pid == playerid)
        SendClientMessage(playerid,COLOR_RED,"[����]�㲻�ܹ۲��Լ�.");
	else if(opt)
	{
		TogglePlayerSpectating(playerid,1);
		PlayerSpectatePlayer(playerid,pid);
		P[playerid][specing] = true;
		P[playerid][spectee] = pid;
		SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]����/unspecֹͣ�۲�.");
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
	if(!strlen(params)) SendClientMessage(playerid,COLOR_WHITE,"[�÷�]/gxqm [����ǩ��]");
	else
	{
	    if(P[playerid][gxqm])
	    {
	        Update3DTextLabelText(P[playerid][gxqm],GetPlayerColor(playerid),params);
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]����ǩ���Ѹ���!");
		}
		else
		{
			P[playerid][gxqm] = Create3DTextLabel(params,GetPlayerColor(playerid),x,y,z+1,100.0,0);
			Attach3DTextLabelToPlayer(P[playerid][gxqm],playerid,0.0,0.0,0.5);
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]����ǩ���Ѵ���!");
		}

	}
	return 1;
}
dcmd_wsel(playerid,params[])
{
#pragma unused params
	new cString[128];

	if (P[playerid][gPlayerStatus] != 0) {
		format(cString, 128, "[����]:���Ѿ���ʹ�� \"%s\".", aSelNames[P[playerid][gPlayerStatus] - 1]);
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
	SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]�����Ҽ����ʱ��,�����¼��������,�������ѡȡ.");
	SendClientMessage(playerid,COLOR_CYAN,"[��ʾ]��Ҳ������/wea [ID]��/t [ID]ѡȡ�ض�������ʱ��.");
	P[playerid][gPlayerTimers] = SetTimerEx("WorldSelect", 200, 1, "i", playerid);

	return true;
}
dcmd_saveall(playerid, params[])
{
	if(!strlen(params))
	{
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�÷�:/saveall [auto - �Զ�����|now - ��������]");
	    return true;
 	}
	else if(!strcmp(params,"auto") == true)
	{
		if(P[playerid][Autosave])
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�Զ������ѹر�.");
			P[playerid][Autosave] = false;
		}
		else
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�Զ������ѿ���.");
			P[playerid][Autosave] = true;
		}
	}
	else if(!strcmp(params,"now") == true)
	{
	    SaveAll(playerid);
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�������ñ���.");
 	}
	else
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�÷�:/saveall [auto - �Զ�����|now - ��������]");
	return 1;
}
dcmd_loadall(playerid, params[])
{
	if(!strlen(params))
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�÷�:/loadall [auto - �Զ�����|now - ��������]");
	else if(!strcmp(params,"auto") == true)
	{
		if(P[playerid][Autoload])
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�Զ������ѹر�.");
			P[playerid][Autoload] = false;
		}
		else
		{
		    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�Զ������ѿ���.");
			P[playerid][Autoload] = true;
		}
	}
	else if(!strcmp(params,"now") == true)
	{
	    if(LoadAll(playerid))
			SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]���б�����������.");
 	}
	else
	    SendClientMessage(playerid,COLOR_WHITE,"[��ʾ]�÷�:/loadall [auto - �Զ�����|now - ��������]");
	return 1;
}
dcmd_pm(playerid, params[])
{
	new idp,message[256],Message[256],iName[256],pName[256];
	if(sscanf(params,"us",idp,message))
		SendClientMessage(playerid,COLOR_WHITE,"[�÷�]/pm [���id�򲿷�����] [����]");
	else if(!IsPlayerConnected(idp))
		SendClientMessage(playerid,COLOR_RED,"[����]��Ч�����.");
	else if(pb[idp][playerid][pm] == true)
		SendClientMessage(playerid,COLOR_RED,"[����]������Ѷ�������PM��Ϣ.");
/*		if(playerid == idp)
		{
			SendClientMessage(playerid,COLOR_RED,"[����]�㲻��PM���Լ�.");
			return 1;
		}*/
	else
	{
			GetPlayerName(idp,iName,sizeof(iName));
			GetPlayerName(playerid,pName,sizeof(pName));
			format(Message,sizeof(Message),">> �����ĵض�%s(%d)˵: %s",iName,idp,message);
			SendClientMessage(playerid,COLOR_YELLOW,Message);
//			format(Message,sizeof(Message),"** %s(%d)���ĵض���˵: %s",pName,playerid,gMessage);
//			SendClientMessage(idp,COLOR_GREEN,Message);
			format(Message,sizeof(Message),"***���յ������� %s(%d)��˽����Ϣ **\n%s(%d):\n%s",pName,playerid,pName,playerid,Message);
			ShowPlayerDialog(idp,idp+1000,DIALOG_STYLE_LIST,"PMR",Message,"�ظ�","ȡ��");
			P[idp][LastPMSender] = playerid;
			P[idp][pming] = true;
			PlayerPlaySound(playerid,1058,0,0,0);
			PlayerPlaySound(idp,1058,0,0,0);
//			ShowPlayerDialog(id,77777,DIALOG_STYLE_LIST,"/pm",Message,"ȷ��","����");
//			printf("PM: %s",Message);
	}
	return 1;
}
dcmd_dl(playerid, params[])
{
	if(P[playerid][Loggedin] == true)
	    SendClientMessage(playerid,COLOR_RED,"[����]�Ѿ���½.");
	else if(P[playerid][Registed] == false)
	    SendClientMessage(playerid,COLOR_RED,"[����]��δע��,��ʹ��/zc [����] ע��.");
	else if(!strlen(params))
	    SendClientMessage(playerid,COLOR_WHITE,"[�÷�]/dl [����].");
	else
	{
	    new pn[256],pfile[256],pass[256];
	    GetPlayerName(playerid,pn,sizeof(pn));
	    format(pfile,sizeof(pfile),"spawn/%s.ini",pn);
	    pass = dini_Get(pfile,"password");
	    if(strcmp(params,pass) != 0)
	    {
	    	SendClientMessage(playerid,COLOR_RED,"[��ʾ]�������.");
	    }
	    else
	    {
	    	SendClientMessage(playerid,COLOR_RED,"[��ʾ]�ɹ���½.");
	    	P[playerid][Loggedin] = true;
	    }
	}
	return 1;
}
dcmd_zc(playerid, params[])
{
	if(P[playerid][Loggedin] == true)
	    SendClientMessage(playerid,COLOR_RED,"[����]�Ѿ���½.");
	else if(P[playerid][Registed] == true)
	    SendClientMessage(playerid,COLOR_RED,"[����]�Ѿ�ע��.");
	else if(!strlen(params))
	    SendClientMessage(playerid,COLOR_WHITE,"[�÷�]/dl [����].");
	else
	{
	    new pn[256],pfile[256];
	    GetPlayerName(playerid,pn,sizeof(pn));
	    format(pfile,sizeof(pfile),"spawn/%s.ini",pn);
		dini_Set(pfile,"password",params);
	    SendClientMessage(playerid,COLOR_RED,"[��ʾ]�ɹ�ע��.");
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
		SendClientMessage(playerid,COLOR_RED,"[����]�ο��޷�����.");
	else LaunchCountingDown();
	return 1;
}
dcmd_reset(playerid, params[])
{
#pragma unused params
	RocketReset();
	return 1;
}