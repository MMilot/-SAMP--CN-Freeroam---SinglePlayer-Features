/*
	SINGLE PLAYER POOL SCRIPTS

*/



#define SINGLE_POOL (1)

#define MAX_POOL_AREAS 1 //最大台球地方
#define PoolRadius 1.3081 // 球桿轉動的半徑

#define CAM_NORMAL 0
#define CAM_POOL_VIEW 1
#define CAM_POOL_READY 2
#define CAM_SHOOT 3
//Animations 
#define POOL_CHALK 0	
#define POOL_LOG_SHOT 1
#define TD_X 556.666809 //Textdraw Corridinate
#define TD_Y 348.029541

#define CAM_NORMAL 0
#define CAM_POOL_VIEW 1
#define CAM_POOL_READY 2
#define CAM_SHOOT 3



new Float:PoolAreaInfo[][] = 
{
	{510.11218261719, -84.40771484375, 998.86785888672, 3.0}

};
new PoolAreas[MAX_POOL_AREAS];

enum PoolBallInfo
{
	Handle,//句柄
	ObjectID,
	Float:x,
	Float:y,
	Float:z,
	IsMoving

}
new PoolBall[16][PoolBallInfo];
enum PoolTemObjectInfo
{
	PoolCue,
	Float:PoolRot,
	Float:CuePos[3]

}

new PoolTemObject[MAX_PLAYERS][PoolTemObjectInfo];


enum PoolGameInfo
{	
	InUsed,

}
new POOL[MAX_POOL_AREAS];

enum PoolTextDrawInfo
{
	PlayerText:PoolWhite,
	PlayerText:PoolHit,
	Float:TD_COR[2]
}
new PoolTextDraw[MAX_PLAYERS][PoolTextDrawInfo];

enum PoolCameraInfo
{
	CameraStatus,
	CameraAngle
	
}
new PoolCamera[MAX_PLAYERS][PoolCameraInfo];

enum PoolTimerInfo
{
	KeyUpdate
}

new PoolTimer[MAX_PLAYERS][PoolTimerInfo];
stock CreatePoolAreas()
{
	new counter;
	for (new i = 0 ; i < MAX_POOL_AREAS; i++)
	{
		PoolAreas[i] = CreateDynamicSphere(PoolAreaInfo[i][0],PoolAreaInfo[i][1],PoolAreaInfo[i][2], PoolAreaInfo[i][3],0, -1,-1);
		counter++;
	}
	printf("[小游戏]: Created Pool Areas: %d",counter);

}

forward OnEnterPoolArea(playerid, areaid);
public OnEnterPoolArea(playerid, areaid)
{
	for (new i = 0 ; i < MAX_POOL_AREAS; i++)
	{
		if(areaid == PoolAreas[i]) SG_Textbox(playerid,"RETURN play the pool.",3000);
	}
	
	
	//Player[playerid][PlayerStatus] = SINGLE_POOL;
}

forward POOL_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

public POOL_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PRESSED(KEY_FIRE))
	{
		if(Player[playerid][PlayerStatus] == SINGLE_POOL)
		{
			//TogglePlayerControllable(playerid,0);//冻结玩家控制
			SetPlayerPoolAnimation(playerid,POOL_CHALK); 
		}
		
	}
	/*
	if (PRESSED(KEY_SECONDARY_ATTACK))//Key F
	{
		if(POOL_PINFO[playerid][IsPlayerInGame])
		{
			ExitViewMode(playerid);
		}
	}
	*/
	
	if (PRESSED(KEY_SECONDARY_ATTACK))//Key Space
	{
		if(Player[playerid][PlayerStatus] == SINGLE_POOL)
		{
			//当母亲停止后才能击球
			if(PHY_IsObjectMoving(PoolBall[0][Handle]))
			{
				SendClientMessage(playerid,-1,"[台球]:请等待母球停下来在击球!");
				return 1;
			}
			if(PoolCamera[playerid][CameraStatus] == CAM_POOL_VIEW)
			{
			//	
				ApplyAnimation(playerid, "POOL", "POOL_Long_Start", 4.1, 0, 1, 1, 1, 1, 1);
				//ExitViewMode(playerid);
				//POOL_PINFO[playerid][PlayerCamStatus] = CAM_POOL_READY;
				POOL_InitTextDrawHit(playerid);//开启TextDraw
				
				
			}
			else
			{
				if(PoolCamera[playerid][CameraStatus] == CAM_POOL_READY) 
				{
					
					POOL_SHOOT(playerid,2);
					return 1;
				}
				if(PoolCamera[playerid][CameraStatus] == CAM_NORMAL) POOL_InitViewMode(playerid);
				
			}
			
			
		}
	
	}

	return 1;
}


forward SetPlayerPoolAnimation(playerid,type);
public SetPlayerPoolAnimation(playerid,type)
{
	switch(type)
	{
		case POOL_CHALK:
		{
			//設置物體偏移
			PlayerPlaySound(playerid,31807, 0.0, 0.0, 0.0);
			SetPlayerArmedWeapon(playerid,0);
			SetPlayerAttachedObject(playerid,9,338,6,0.000000,0.059999,-0.885000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
			//偏移值
			ApplyAnimation(playerid, "POOL", "POOL_ChalkCue", 4.0, 0, 0, 0, 0, 0);
			SetTimerEx("ClearnPoolAnimation",4000, false, "i", playerid);
		
		}
		case POOL_LOG_SHOT:
		{
			ApplyAnimation(playerid, "POOL", "POOL_Long_Shot", 4.1, 0, 1, 1, 1, 1, 1);
		
		}
	
	
	}

}


forward POOL_SHOOT(playerid,power);
public POOL_SHOOT(playerid,power)
{

	//Set Camera Above
	//获取母球坐标
	new Float:pos[3];
	GetObjectPos(PoolBall[0][Handle],pos[0],pos[1],pos[2]);
	SetPlayerCameraPos(playerid, pos[0]+2,pos[1]+2,pos[2]+2);
	SetPlayerCameraLookAt(playerid, pos[0],pos[1],pos[2]);
	
	POOL_DestoryPoolCue(playerid);
//	PHY_SetObjectVelocity(PoolBall[0], power * floatcos(pos[2], degrees), power * floatsin(pos[2], degrees));
	
	//new Float:rotation[3];
	//GetObjectRot(POOL_PINFO[playerid][PoolCue],rotation[0],rotation[1],rotation[2]);
	PHY_SetObjectVelocity(PoolBall[0][Handle], power * floatsin(-PoolCamera[playerid][CameraAngle]-90, degrees), power * floatcos(-PoolCamera[playerid][CameraAngle]-90, degrees));

	//ExitViewMode(playerid);
	PoolCamera[playerid][CameraStatus]= CAM_SHOOT;
	POOL_ExitTextDrawHit(playerid);
	
	//BallStopCheckTimer = SetTimerEx("WaitAllBallStop",500, true, "i", playerid);
	//SetTimerEx("ViewExitDelay",2000, false, "i", playerid);
	POOL_ViewExitDelay(playerid);
	print("SetTimerEx");
	//动作
	SetPlayerPoolAnimation(playerid,POOL_LOG_SHOT);

}
forward POOL_ViewExitDelay(playerid);
public POOL_ViewExitDelay(playerid)
{

	POOL_ExitViewMode(playerid);
	PoolCamera[playerid][CameraStatus] = CAM_NORMAL;


}
POOL_ExitViewMode(playerid)
{
	PoolCamera[playerid][CameraStatus] = CAM_NORMAL;
	POOL_DestoryPoolCue(playerid);
	POOL_ResetCamera(playerid);
	KillTimer(PoolTimer[playerid][KeyUpdate]);
	TogglePlayerControllable(playerid,1);

}

POOL_ResetCamera(playerid)
{
	SetCameraBehindPlayer(playerid);
}
POOL_ExitTextDrawHit(playerid)
{
	PlayerTextDrawDestroy(playerid,PoolTextDraw[playerid][PoolWhite]);
	PlayerTextDrawDestroy(playerid,PoolTextDraw[playerid][PoolHit]);
	return 1;
}
POOL_InitTextDrawHit(playerid)
{
	PoolTextDraw[playerid][PoolWhite] = CreatePlayerTextDraw(playerid, 518.000549, 311.525695, "ld_pool:ball");
	//PoolHit[playerid] = CreatePlayerTextDraw(playerid,TD_X,TD_Y, "ld_pool:nib");
	PlayerTextDrawTextSize(playerid, PoolTextDraw[playerid][PoolWhite], 93, 93);
	PlayerTextDrawAlignment(playerid, PoolTextDraw[playerid][PoolWhite], 1);
	PlayerTextDrawColor(playerid, PoolTextDraw[playerid][PoolWhite], -1);
	PlayerTextDrawSetShadow(playerid, PoolTextDraw[playerid][PoolWhite], 0);
	PlayerTextDrawSetOutline(playerid, PoolTextDraw[playerid][PoolWhite], 0);
	PlayerTextDrawFont(playerid, PoolTextDraw[playerid][PoolWhite], 4);
	
	PoolTextDraw[playerid][PoolHit] = CreatePlayerTextDraw(playerid,TD_X,TD_Y, "ld_pool:nib");
	
	PlayerTextDrawLetterSize(playerid, PoolTextDraw[playerid][PoolHit], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, PoolTextDraw[playerid][PoolHit], 15, 15);
	PlayerTextDrawAlignment(playerid, PoolTextDraw[playerid][PoolHit], 1);
	PlayerTextDrawColor(playerid,PoolTextDraw[playerid][PoolHit], -1);
	PlayerTextDrawSetShadow(playerid,PoolTextDraw[playerid][PoolHit], 0);
	PlayerTextDrawSetOutline(playerid,PoolTextDraw[playerid][PoolHit], 0);
	PlayerTextDrawFont(playerid,PoolTextDraw[playerid][PoolHit], 4);
		
	PlayerTextDrawShow(playerid,PoolTextDraw[playerid][PoolHit]);
	
	
	PoolCamera[playerid][CameraStatus] = CAM_POOL_READY;
	
	new Float:rcue[3];
	GetObjectRot(PoolTemObject[playerid][PoolCue],rcue[0],rcue[1],PoolTemObject[playerid][PoolRot]);

	GetObjectPos(PoolTemObject[playerid][PoolCue],PoolTemObject[playerid][CuePos][0],PoolTemObject[playerid][CuePos][1],PoolTemObject[playerid][CuePos][2]);
	PlayerTextDrawShow(playerid,PoolTextDraw[playerid][PoolHit]);
	PlayerTextDrawShow(playerid,PoolTextDraw[playerid][PoolWhite]);
	//POOL_PINFO[playerid][IsPlayerInGame]=true;
	PoolTextDraw[playerid][TD_COR][0] = TD_X;
	PoolTextDraw[playerid][TD_COR][1] = TD_Y;
	//POOL_PINFO[playerid][PoolKeyCKTimer] = SetTimerEx("CamKeyCheck",1, true, "i", playerid);
	
	//UpdateHitTextDraw();
	

	return 1;
}


POOL_InitViewMode(playerid)
{

	
	PoolCamera[playerid][CameraStatus] = CAM_POOL_VIEW;
	new Float:ang;
	GetPlayerFacingAngle(playerid,ang);
	TogglePlayerControllable(playerid,0);
	POOL_CreatePoolCue(playerid,ang);
	POOL_UpdateCamera(playerid,ang);
	//開啟視角按鍵檢測
	PoolTimer[playerid][KeyUpdate] = SetTimerEx("CamKeyCheck",1, true, "i", playerid);

}

POOL_UpdateCamera(playerid,Float:angle)
{

	/*
		Episodes Formula
		Supported by Tom
	*/
	//Get Wihte ball Pos -獲取母球坐標
	new Float:temx,Float:temy,Float:temz,Float:camX,Float:camY,Float:camZ;
	GetObjectPos(PoolBall[0][Handle],temx,temy,temz);
	//Calculater Camrea position 計算視角位置
	camX = temx + PoolRadius*0.5 * floatcos(angle, degrees);
	camY = temy + PoolRadius*0.5 * floatsin(angle, degrees);
	
	camZ = 0.3;
	SetPlayerCameraPos(playerid, camX, camY, temz + camZ);
	SetPlayerCameraLookAt(playerid, temx, temy, temz);
	printf("View Ang:X: %f Y:%f,Z:%f",camX,camY,temz + camZ);
	POOL_UpdatePoolCue(playerid,temx,temy,temz,angle);
	POOL_LimitAngle(playerid,camX,camY);
}

POOL_LimitAngle(playerid,Float:cx,Float:cy)
{
	/*
		By Tom
	*/
	new Float:hole1[2];
	hole1[0]=1129.4600;
	hole1[1]=-1440.9500;
	new Float:hole2[2];
	hole2[0]= 1129.4600;
	hole2[1]= -1439.0500;
	new Float:hole3[3];
	hole3[0] = 1130.5000;
	hole3[1]= -1439.0500;
	new Float:hole4[3];
	hole4[0] = 1130.5000;
	hole4[1] = -1440.9500;
	
	
	//new Float:L = floatsqroot(  floatpower(wx-playerpos[0],2)+ floatpower(wy-playerpos[1],2));
	if(1129.4600<= cx<=1130.5000 && -1440.9500<=cy<= -1439.0500)
	{
		SendClientMessage(playerid,-1,"计算出死角");
	}


}

POOL_UpdatePoolCue(playerid,Float:wx,Float:wy,Float:wz,Float:angle)
{
	new Float:CircleX,Float:CircleY;
	//Calculater Camrea position 計算球杆位置
	CircleX = wx + PoolRadius *0.05* floatcos(angle, degrees);
	CircleY = wy + PoolRadius *0.05* floatsin(angle, degrees);
	
	
	SetObjectRot(PoolTemObject[playerid][PoolCue],0,45,angle-90);
	SetObjectPos(PoolTemObject[playerid][PoolCue],CircleX,CircleY,wz);
	printf("rx=%f,ry=%f,rz=%f",0,45,angle);
	/*new Float:x,Float:y,Float:z,Float:camX,Float:camY,Float:camZ;
	GetObjectPos(PoolBall[playerid][0],x,y,z);
	
	//Calculater Camrea position 計算球杆
	camX = x + PoolRadius * floatcos(PlayerPool[playerid][angle], degrees);
	camY = y + PoolRadius * floatsin(PlayerPool[playerid][angle], degrees);
	camZ = 0.5;	*/


}

POOL_CreatePoolCue(playerid,Float:ang)
{
	new Float:px,Float:py,Float:pz;
	GetObjectPos(PoolBall[0][Handle],px,py,pz);
	PoolTemObject[playerid][PoolCue]=CreateObject(3004,px-1,py-1,pz+0.01,0,45,ang-90);
	new string[125];
	format(string,sizeof(string),"Cue Created At; %f,%f,%f",px,py,pz);
	SendClientMessage(playerid,-1,string);
}

POOL_DestoryPoolCue(playerid)
{
	DestroyObject(PoolTemObject[playerid][PoolCue]);

}