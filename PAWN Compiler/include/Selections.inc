//=============================Selections============================//

#if CCOL_SELECT == true
public ColorSelect(playerid,i)
{
	new keys, updown,leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);
	if(leftright == KEY_RIGHT)
	{
		PV[playerid][i][colour1]++;
		ChangeVehicleColor(i,PV[playerid][i][colour1],PV[playerid][i][colour2]);
	}
	if(leftright == KEY_LEFT)
	{
		PV[playerid][i][colour1]--;
		ChangeVehicleColor(i,PV[playerid][i][colour1],PV[playerid][i][colour2]);
	}
	if(updown == KEY_UP)
	{
		PV[playerid][i][colour2]++;
		ChangeVehicleColor(i,PV[playerid][i][colour1],PV[playerid][i][colour2]);
	}
	if(updown == KEY_DOWN)
	{
		PV[playerid][i][colour2]--;
		ChangeVehicleColor(i,PV[playerid][i][colour1],PV[playerid][i][colour2]);
	}
	if(keys & KEY_FIRE)
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, 1);
		P[playerid][gPlayerStatus] = 0;
		KillTimer(P[playerid][gPlayerTimers]);
	}
}
#endif

#if WORL_SELECT == true
public WorldSelect(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);
	
	new cString[128];
	
	// Right key increases World Time
	if (leftright == KEY_RIGHT) {
		if(P[playerid][time] == MAX_TIME_ID) {
			P[playerid][time] = MIN_TIME_ID;
		}
		else {
			P[playerid][time]++;
		}
		format(cString, 128, "World Time: %d~n~Weather ID: %d", P[playerid][time], P[playerid][wea]);
		GameTextForPlayer(playerid, cString, 1500, 3);
		SetPlayerTime(playerid,P[playerid][time],0);
	}
	
	// Left key decreases World Time
	if (leftright == KEY_LEFT) {
		if(P[playerid][time] == MIN_TIME_ID) {
			P[playerid][time] = MAX_TIME_ID;
		}
		else {
			P[playerid][time]--;
		}
		format(cString, 128, "World Time: %d~n~Weather ID: %d", P[playerid][time], P[playerid][wea]);
		GameTextForPlayer(playerid, cString, 1500, 3);
		SetPlayerTime(playerid,P[playerid][time],0);
	}
	
	// Up key increases Weather ID
	if(updown == KEY_UP) {
		if(P[playerid][wea] == MAX_WEAT_ID) {
			P[playerid][wea] = MIN_WEAT_ID;
		}
		else {
			P[playerid][wea]++;
		}
		format(cString, 128, "World Time: %d~n~Weather ID: %d", P[playerid][time], P[playerid][wea]);
		GameTextForPlayer(playerid, cString, 1500, 3);
		SetPlayerWeather(playerid,P[playerid][wea]);
	}
	
	// Down key decreases Weather ID
	if(updown == KEY_DOWN) {
		if(P[playerid][wea] == MIN_WEAT_ID) {
			P[playerid][wea] = MAX_WEAT_ID;
		}
		else {
			P[playerid][wea]--;
		}
		format(cString, 128, "World Time: %d~n~Weather ID: %d", P[playerid][time], P[playerid][wea]);
		GameTextForPlayer(playerid, cString, 1500, 3);
		SetPlayerWeather(playerid,P[playerid][wea]);
	}
	
	// Action key exits WorldSelection
	if(keys & KEY_FIRE) {
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, 1);
		
		format(cString, 128, "[成功]:时间改变为 %d 点,新天气ID为 %d", P[playerid][time], P[playerid][wea]);
		SendClientMessage(playerid, COLOR_GREEN, cString);
		
		P[playerid][gPlayerStatus] = 0;
		KillTimer(P[playerid][gPlayerTimers]);
		
		return;
	}
}

#endif

#if SKIN_SELECT == true
public SkinSelect(playerid)
{
	new keys, updown, leftright;
	
	GetPlayerKeys(playerid, keys, updown, leftright);
	
	new cString[128];
	
	// Right key increases Skin ID
	if (leftright == KEY_RIGHT) {
		if(P[playerid][Skin] == MAX_SKIN_ID) {
			P[playerid][Skin] = MIN_SKIN_ID;
		}
		else {
			P[playerid][Skin]++;
		}
		while(IsInvalidSkin(P[playerid][Skin])) {
			P[playerid][Skin]++;
		}
		
		format(cString, 128, "Skin ID: %d", P[playerid][Skin]);
		GameTextForPlayer(playerid, cString, 1500, 3);
		SetPlayerSkin(playerid, P[playerid][Skin]);
	}
	
	// Left key decreases Skin ID
	if(leftright == KEY_LEFT) {
		if(P[playerid][Skin] == MIN_SKIN_ID) {
			P[playerid][Skin] = MAX_SKIN_ID;
		}
		else {
			P[playerid][Skin]--;
		}
		while(IsInvalidSkin(P[playerid][Skin])) {
			P[playerid][Skin]--;
		}
		
		format(cString, 128, "Skin ID: %d", P[playerid][Skin]);
		GameTextForPlayer(playerid, cString, 1500, 3);
		SetPlayerSkin(playerid, P[playerid][Skin]);

	}
	
	// Action key exits skin selection
	if(keys & KEY_FIRE)
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, 1);
		
		format(cString, 128, "[成功]:你的新皮肤ID为 %d", P[playerid][Skin]);
		SendClientMessage(playerid, COLOR_GREEN, cString);
		P[playerid][gPlayerStatus] = 0;
		KillTimer(P[playerid][gPlayerTimers]);
	}
}
#endif

#if CAME_SELECT == true
public CameraSelect(playerid)
{
	// CMODE_A 0	Up/Down = IncreaseZ/DecreaseZ; Left/Right = IncreaseX/DecreaseX; Num4/Num6 = IncreaseY/DecreaseY
	// CMODE_B 1	Up/Down = Rotate Up/Down; Left/Right = Rotate Left/Right; Num4/Num6 = Move Left/Right
	
	new keys, updown, leftright;
	
	GetPlayerKeys(playerid, keys, updown, leftright);
	
	printf("Player (%d) keys = %d, updown = %d, leftright = %d", playerid, keys, updown, leftright);
	
	if (curPlayerCamD[playerid][CMODE] == CMODE_A)
	{
		if (leftright == KEY_RIGHT) {
			curPlayerCamD[playerid][CPOS_X] += curPlayerCamD[playerid][RATE];
			curPlayerCamD[playerid][CLOO_X] += curPlayerCamD[playerid][RATE];
			
			SetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
		
		if (leftright == KEY_LEFT) {
			curPlayerCamD[playerid][CPOS_X] -= curPlayerCamD[playerid][RATE];
			curPlayerCamD[playerid][CLOO_X] -= curPlayerCamD[playerid][RATE];
			
			SetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
		
		if (updown == KEY_UP) {
			curPlayerCamD[playerid][CPOS_Z] += curPlayerCamD[playerid][RATE];
			curPlayerCamD[playerid][CLOO_Z] += curPlayerCamD[playerid][RATE];
			
			SetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
		
		if (updown == KEY_DOWN) {
			curPlayerCamD[playerid][CPOS_Z] -= curPlayerCamD[playerid][RATE];
			curPlayerCamD[playerid][CLOO_Z] -= curPlayerCamD[playerid][RATE];
			
			SetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
		
		if (keys & KEY_ANALOG_RIGHT) {
			curPlayerCamD[playerid][CPOS_Y] += curPlayerCamD[playerid][RATE];
			curPlayerCamD[playerid][CLOO_Y] += curPlayerCamD[playerid][RATE];
			
			SetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
		
		
		if (keys & KEY_ANALOG_LEFT) {
			curPlayerCamD[playerid][CPOS_Y] -= curPlayerCamD[playerid][RATE];
			curPlayerCamD[playerid][CLOO_Y] -= curPlayerCamD[playerid][RATE];
			
			SetPlayerPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
	}
	
	
	if(curPlayerCamD[playerid][CMODE] == CMODE_B)
	{
		if (leftright == KEY_RIGHT) {
			// Rotate Y +
		}
		
		if (leftright == KEY_LEFT) {
			// Rotate Y -
		}
		
		if (updown == KEY_UP) {
			// Rotate X +
		}
		
		if (updown == KEY_DOWN) {
			// Rotate X -
		}
		
		if (keys & KEY_ANALOG_RIGHT) {
			// Rotate Z +
		}
		
		if (keys & KEY_ANALOG_LEFT) {
			// Rotate Z -
		}
	}
	
	if (keys & KEY_FIRE)
	{
		SetCameraBehindPlayer(playerid);
		
		new
		File:F_CAMERA = fopen("CAMERA.txt", io_append);
		
		if( F_CAMERA )
		{
			new
			cString[512], h, m, s, Y, M, D;
			
			getdate(Y, M, D);
			gettime(h, m, s);
			
			format(cString, sizeof( cString ), "// %d-%d-%d @ %d:%d:%d\r\nSetPlayerCameraPos(playerid, %f, %f, %f);\r\nSetPlayerCameraLookAt(playerid, %f, %f, %f);\r\n", D, M, Y, h, m, s,curPlayerCamD[playerid][CPOS_X],curPlayerCamD[playerid][CPOS_Y],curPlayerCamD[playerid][CPOS_Z],curPlayerCamD[playerid][CLOO_X],curPlayerCamD[playerid][CLOO_Y],curPlayerCamD[playerid][CLOO_Z]);
			
			fwrite(F_CAMERA, cString);
			fclose(F_CAMERA);
			
			printf("\n%s\n",cString);
			
			SendClientMessage( playerid, COLOR_GREEN, "Current camera data saved to 'CAMERA.txt'" );
		}
		else
		print("Failed to create the file \"CAMERA.txt\".\n");
		
		TogglePlayerControllable(playerid, 1);
		
		KillTimer(P[playerid][gPlayerTimers]);
		
		P[playerid][gPlayerStatus] = 0;
	}
}

#endif

#if VEHI_SELECT == true
public VehicleSelect(playerid,i)
{
	new keys, updown, leftright;

	GetPlayerKeys(playerid, keys, updown, leftright);

	new cString[128],pn[255];
	GetPlayerName(playerid,pn,sizeof(pn));
	// Right key increases Vehicle MODELID
	if (leftright == KEY_RIGHT) {
		if(curPlayerVehM[playerid] == MAX_VEHI_ID) {
			curPlayerVehM[playerid] = MIN_VEHI_ID;
		}
		else {
			curPlayerVehM[playerid]++;
		}

		format(cString, 128, "Model ID: %d~n~Vehicle Name: %s", curPlayerVehM, aVehicleNames[curPlayerVehM[playerid] - MIN_VEHI_ID]);
		GameTextForPlayer(playerid, cString, 1500, 3);

		new Float:x, Float:y, Float:z, Float:a;

		GetPlayerPos(playerid, x, y, z);
		GetXYInFrontOfPlayer(playerid, x, y, VEHI_DIS);
		GetPlayerFacingAngle(playerid, a);

		if(curPlayerVehI[playerid]) DestroyVehicle(curPlayerVehI[playerid]);
		if(curPlayerVehI[playerid] == -1) curPlayerVehI[playerid]++;

//		for(i=0;i<5;i++)
//		    if(PV[playerid][i][id] == -1) break;
		curPlayerVehI[playerid] = CreateVehicle(curPlayerVehM[playerid], x, y, z + 0.5, a + 90.0, -1, -1, 5000);
//		curPlayerVehI[playerid] = PV[playerid][i][id];
		SetVehicleVirtualWorld(PV[playerid][i][id],GetPlayerVirtualWorld(playerid));
//		PV[playerid][i][mid] = curPlayerVehM[playerid];
		LinkVehicleToInterior(curPlayerVehI[playerid], GetPlayerInterior(playerid));
	}

	// Left key decreases Vehicle MODELID
	if(leftright == KEY_LEFT) {
		if(curPlayerVehM[playerid] == MIN_VEHI_ID) {
			curPlayerVehM[playerid] = MAX_VEHI_ID;
		}
		else {
			curPlayerVehM[playerid]--;
		}

		format(cString, 128, "Model ID: %d~n~Vehicle Name: %s", curPlayerVehM, aVehicleNames[curPlayerVehM[playerid] - MIN_VEHI_ID]);
		GameTextForPlayer(playerid, cString, 1500, 3);

		new Float:x, Float:y, Float:z, Float:a;

		GetPlayerPos(playerid, x, y, z);
		GetXYInFrontOfPlayer(playerid, x, y, VEHI_DIS);
		GetPlayerFacingAngle(playerid, a);

		if(curPlayerVehI[playerid]) DestroyVehicle(curPlayerVehI[playerid]);
		if(curPlayerVehI[playerid] == -1) curPlayerVehI[playerid]++;

//		for(i=0;i<5;i++)
//		    if(PV[playerid][i][id] == -1) break;
		curPlayerVehI[playerid] = CreateVehicle(curPlayerVehM[playerid], x, y, z + 0.5, a + 90.0, -1, -1, 5000);
		LinkVehicleToInterior(curPlayerVehI[playerid], GetPlayerInterior(playerid));
//	 	curPlayerVehI[playerid] = PV[playerid][i][id];
		SetVehicleVirtualWorld(PV[playerid][i][id],GetPlayerVirtualWorld(playerid));
//		PV[playerid][i][mid] = curPlayerVehM[playerid];

	}

	// Action key exits vehicle selection
	if(keys & KEY_FIRE)
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, 1);
		PV[playerid][i][id] = curPlayerVehI[playerid];
		PV[playerid][i][mid] = curPlayerVehM[playerid];
		PV[playerid][i][spawned] = true;
		format(cString, 128, "[成功] %s 召唤了一辆 \"%s\" (模型ID: %d, 车辆ID: %d)",pn, aVehicleNames[curPlayerVehM[playerid] - MIN_VEHI_ID], curPlayerVehM[playerid], curPlayerVehI[playerid]+1);
		SendClientMessage(playerid, COLOR_GREEN, cString);
		PutPlayerInVehicle(playerid,curPlayerVehI[playerid],0);
		P[playerid][gPlayerStatus] = 0;
		KillTimer(P[playerid][gPlayerTimers]);
	}
}
#endif

#if OBJE_SELECT == true
public ObjectSelect( playerid )
{
	new keys, updown, leftright;
	
	GetPlayerKeys( playerid, keys, updown, leftright );
	
	new cString[ 128 ];
	
	switch ( curPlayerObjM[ playerid ][ OBJ_MOD ] )
	{
		case O_MODE_SELECTOR:
		{
			if ( updown == KEY_UP)
			{
				curPlayerObjM[ playerid ][ OBJ_MDL ] += 10;
				
				if ( curPlayerObjM[ playerid ][ OBJ_MDL ] >= MAX_OBJE_ID )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ] = MIN_OBJE_ID;
				}
				
				while ( !IsValidModel( curPlayerObjM[ playerid ][ OBJ_MDL ] ) )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ]++;
				}
				
				DestroyObject( curPlayerObjI[ playerid ] );
				curPlayerObjI[ playerid ] = CreateObject( curPlayerObjM[ playerid ][ OBJ_MDL ], curPlayerObjM[ playerid ][ OBJ_X ],
				curPlayerObjM[ playerid ][ OBJ_Y ], curPlayerObjM[ playerid ][ OBJ_Z ],
				curPlayerObjM[ playerid ][ OBJ_RX ], curPlayerObjM[ playerid ][ OBJ_RY ], curPlayerObjM[ playerid ][ OBJ_RZ ]
				);
				
				format( cString, 128, "Model ID: %d", curPlayerObjM[ playerid ][ OBJ_MDL ] );
				GameTextForPlayer(playerid, cString, 1500, 3);
			}
			
			if ( updown == KEY_DOWN)
			{
				curPlayerObjM[ playerid ][ OBJ_MDL ] -= 10;
				
				if ( curPlayerObjM[ playerid ][ OBJ_MDL ] <= MIN_OBJE_ID )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ] = MAX_OBJE_ID;
				}
				
				while ( !IsValidModel( curPlayerObjM[ playerid ][ OBJ_MDL ] ) )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ]--;
				}
				
				DestroyObject( curPlayerObjI[ playerid ] );
				curPlayerObjI[ playerid ] = CreateObject( curPlayerObjM[ playerid ][ OBJ_MDL ], curPlayerObjM[ playerid ][ OBJ_X ],
				curPlayerObjM[ playerid ][ OBJ_Y ], curPlayerObjM[ playerid ][ OBJ_Z ],
				curPlayerObjM[ playerid ][ OBJ_RX ], curPlayerObjM[ playerid ][ OBJ_RY ], curPlayerObjM[ playerid ][ OBJ_RZ ]
				);
				
				format( cString, 128, "Model ID: %d", curPlayerObjM[ playerid ][ OBJ_MDL ] );
				GameTextForPlayer(playerid, cString, 1500, 3);
			}
			
			if ( leftright == KEY_LEFT)
			{
				curPlayerObjM[ playerid ][ OBJ_MDL ]--;
				
				if ( curPlayerObjM[ playerid ][ OBJ_MDL ] <= MIN_OBJE_ID )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ] = MAX_OBJE_ID;
				}
				
				while ( !IsValidModel( curPlayerObjM[ playerid ][ OBJ_MDL ] ) )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ]--;
				}
				
				DestroyObject( curPlayerObjI[ playerid ] );
				curPlayerObjI[ playerid ] = CreateObject( curPlayerObjM[ playerid ][ OBJ_MDL ], curPlayerObjM[ playerid ][ OBJ_X ],
				curPlayerObjM[ playerid ][ OBJ_Y ], curPlayerObjM[ playerid ][ OBJ_Z ],
				curPlayerObjM[ playerid ][ OBJ_RX ], curPlayerObjM[ playerid ][ OBJ_RY ], curPlayerObjM[ playerid ][ OBJ_RZ ]
				);
				
				format( cString, 128, "Model ID: %d", curPlayerObjM[ playerid ][ OBJ_MDL ] );
				GameTextForPlayer(playerid, cString, 1500, 3);
			}
			
			if ( leftright == KEY_RIGHT)
			{
				curPlayerObjM[ playerid ][ OBJ_MDL ]++;
				
				if ( curPlayerObjM[ playerid ][ OBJ_MDL ] >= MAX_OBJE_ID )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ] = MIN_OBJE_ID;
				}
				
				while ( !IsValidModel( curPlayerObjM[ playerid ][ OBJ_MDL ] ) )
				{
					curPlayerObjM[ playerid ][ OBJ_MDL ]++;
				}
				
				DestroyObject( curPlayerObjI[ playerid ] );
				curPlayerObjI[ playerid ] = CreateObject( curPlayerObjM[ playerid ][ OBJ_MDL ], curPlayerObjM[ playerid ][ OBJ_X ],
				curPlayerObjM[ playerid ][ OBJ_Y ], curPlayerObjM[ playerid ][ OBJ_Z ],
				curPlayerObjM[ playerid ][ OBJ_RX ], curPlayerObjM[ playerid ][ OBJ_RY ], curPlayerObjM[ playerid ][ OBJ_RZ ]
				);
				
				format( cString, 128, "Model ID: %d", curPlayerObjM[ playerid ][ OBJ_MDL ] );
				GameTextForPlayer(playerid, cString, 1500, 3);
			}
		}
		
		case O_MODE_MOVER:
		{
			if ( updown == KEY_UP)
			{
				curPlayerObjM[ playerid ][ OBJ_Z ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CPOS_Z ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CLOO_Z ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
			}
			
			if ( updown == KEY_DOWN)
			{
				curPlayerObjM[ playerid ][ OBJ_Z ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CPOS_Z ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CLOO_Z ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
			}
			
			if ( leftright == KEY_LEFT)
			{
				curPlayerObjM[ playerid ][ OBJ_Y ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CPOS_Y ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CLOO_Y ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
			}
			
			if ( leftright == KEY_RIGHT)
			{
				curPlayerObjM[ playerid ][ OBJ_Y ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CPOS_Y ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CLOO_Y ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
			}
			
			if ( keys & KEY_ANALOG_LEFT )
			{
				curPlayerObjM[ playerid ][ OBJ_Y ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CPOS_Y ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CLOO_Y ] -= pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
			}
			
			if ( keys & KEY_ANALOG_LEFT )
			{
				curPlayerObjM[ playerid ][ OBJ_X ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CPOS_X ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
				curPlayerCamD[ playerid ][ CLOO_X ] += pObjectRate[ playerid ][ OBJ_RATE_MOVE ];
			}
			
			SetPlayerPos( playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z] );
			SetObjectPos( curPlayerObjI[ playerid ], curPlayerObjM[ playerid ][ OBJ_X ], curPlayerObjM[ playerid ][ OBJ_Y ], curPlayerObjM[ playerid ][ OBJ_Z ] );
			SetPlayerCameraPos(playerid, curPlayerCamD[playerid][CPOS_X], curPlayerCamD[playerid][CPOS_Y], curPlayerCamD[playerid][CPOS_Z]);
			SetPlayerCameraLookAt(playerid, curPlayerCamD[playerid][CLOO_X], curPlayerCamD[playerid][CLOO_Y], curPlayerCamD[playerid][CLOO_Z]);
		}
		
		case O_MODE_ROTATOR:
		{
			if ( updown == KEY_UP)
			{
				curPlayerObjM[ playerid ][ OBJ_RZ ] += pObjectRate[ playerid ][ OBJ_RATE_ROT ];
			}
			
			if ( updown == KEY_DOWN)
			{
				curPlayerObjM[ playerid ][ OBJ_RZ ] -= pObjectRate[ playerid ][ OBJ_RATE_ROT ];
				
			}
			
			if ( leftright == KEY_LEFT)
			{
				curPlayerObjM[ playerid ][ OBJ_RY ] -= pObjectRate[ playerid ][ OBJ_RATE_ROT ];
			}
			
			if ( leftright == KEY_RIGHT)
			{
				curPlayerObjM[ playerid ][ OBJ_RY ] += pObjectRate[ playerid ][ OBJ_RATE_ROT ];
			}
			
			if ( keys & KEY_ANALOG_LEFT )
			{
				curPlayerObjM[ playerid ][ OBJ_RY ] -= pObjectRate[ playerid ][ OBJ_RATE_ROT ];
			}
			
			if ( keys & KEY_ANALOG_LEFT )
			{
				curPlayerObjM[ playerid ][ OBJ_RX ] += pObjectRate[ playerid ][ OBJ_RATE_ROT ];
			}
			
			SetObjectRot( curPlayerObjI[ playerid ], curPlayerObjM[ playerid ][ OBJ_RX ], curPlayerObjM[ playerid ][ OBJ_RY ], curPlayerObjM[ playerid ][ OBJ_RZ ] );
		}
	}
	
	if ( keys & KEY_FIRE )
	{
		P[ playerid ][gPlayerStatus] = 0;
		TogglePlayerControllable( playerid, 1 );
		SetCameraBehindPlayer( playerid );
		KillTimer( P[playerid][gPlayerTimers] );
	}
	
}
#endif


