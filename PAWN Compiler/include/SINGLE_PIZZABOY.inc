/*
	Single Pizza Boy Sub Missions Port To SAMP
    by Episodes

*/


//==================================================
//		    -------	[全局宏定义] -------
//==================================================
#define SINGLE_PIZZA 2 //任务ID (重要)

#define COLANDREAS
#include <physicsBAK>

//#include <streamer>
#include <YSI\y_hooks>
//#include "../include/gl_spawns.inc"//作为送货地点 :)
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define VECTOR_LEFT 0
#define VECTOR_RIGHT 1




#define MAX_PIZZA 6

//Locations 
new Float:gRandomSpawns_LosSantos[][4] = {
{1751.1097,-2106.4529,13.5469,183.1979}, // El-Corona - Outside random house
{2652.6418,-1989.9175,13.9988,182.7107}, // Random house in willowfield - near playa de seville and stadium
{2489.5225,-1957.9258,13.5881,2.3440}, // Hotel in willowfield - near cluckin bell
{2689.5203,-1695.9354,10.0517,39.5312}, // Outside stadium - lots of cars
{2770.5393,-1628.3069,12.1775,4.9637}, // South in east beach - north of stadium - carparks nearby
{2807.9282,-1176.8883,25.3805,173.6018}, // North in east beach - near apartments
{2552.5417,-958.0850,82.6345,280.2542}, // Random house north of Las Colinas
{2232.1309,-1159.5679,25.8906,103.2939}, // Jefferson motel
{2388.1003,-1279.8933,25.1291,94.3321}, // House south of pig pen
{2481.1885,-1536.7186,24.1467,273.4944}, // East LS - near clucking bell and car wash
{2495.0720,-1687.5278,13.5150,359.6696}, // Outside CJ's house - lots of cars nearby
{2306.8252,-1675.4340,13.9221,2.6271}, // House in ganton - lots of cars nearby
{2191.8403,-1455.8251,25.5391,267.9925}, // House in south jefferson - lots of cars nearby
{1830.1359,-1092.1849,23.8656,94.0113}, // Mulholland intersection carpark
{2015.3630,-1717.2535,13.5547,93.3655}, // Idlewood house
{1654.7091,-1656.8516,22.5156,177.9729}, // Right next to PD
{1219.0851,-1812.8058,16.5938,190.0045}, // Conference Center
{1508.6849,-1059.0846,25.0625,1.8058}, // Across the street of BANK - lots of cars in intersection carpark
{1421.0819,-885.3383,50.6531,3.6516}, // Outside house in vinewood
{1133.8237,-1272.1558,13.5469,192.4113}, // Near hospital
{1235.2196,-1608.6111,13.5469,181.2655}, // Backalley west of mainstreet
{590.4648,-1252.2269,18.2116,25.0473}, // Outside "BAnk of San Andreas"
{842.5260,-1007.7679,28.4185,213.9953}, // North of Graveyard
{911.9332,-1232.6490,16.9766,5.2999}, // LS Film Studio
{477.6021,-1496.6207,20.4345,266.9252}, // Rodeo Place
{255.4621,-1366.3256,53.1094,312.0852}, // Outside propery in richman
{281.5446,-1261.4562,73.9319,305.0017}, // Another richman property
{790.1918,-839.8533,60.6328,191.9514}, // Mulholland house
{1299.1859,-801.4249,84.1406,269.5274}, // Maddoggs
{1240.3170,-2036.6886,59.9575,276.4659}, // Verdant Bluffs
{2215.5181,-2627.8174,13.5469,273.7786}, // Ocean docks 1
{2509.4346,-2637.6543,13.6453,358.3565} // Ocean Docks spawn 2
};


enum PizzaInfo
{
	Handle,
	Taken
	
}
new Float:CPPos[MAX_PLAYERS][3];
new Pizza[MAX_PLAYERS][MAX_PIZZA][PizzaInfo];
new PizzaCP[MAX_PLAYERS];
new Pizza_CPTemObject[MAX_PLAYERS];//储存零时OBJ HANDLE

public PHY_OnObjectUpdate(objectid)
{
	PIZZA_OnObjectUpdate(objectid);//处理OBJ运动过程
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER) 
    {
        new vehicleid = GetPlayerVehicleID(playerid);
		if(GetVehicleModel(vehicleid) == 448) 
		{
			if(Player[playerid][PlayerStatus] != SINGLE_PIZZA) SG_Textbox(playerid,"Press 2 to start Pizza Boy Missions.",3000);//SG_Textbox(playerid,"Press 2 to start Pizza Boy Missions.",3000);
		}
    }
    return 1;
}

hook OnPlayerDisconnect(playerid,reason)
{
	//重设玩家的属性状态
	Player[playerid][PlayerStatus] = STATUS_NORMAL;
	//SendClientMessage(playerid,-1,"[小任务]:离开Pizza Boy小任务.");
	PIZZA_Fill(playerid);
	PIZZA_DestoryPlayerCheckPoints(playerid);
	//SG_Sub(playerid,"~r~You have left the Pizza Boy Missions.",5000);
	Pizza_CPTemObject[playerid] = -1;

	return 1;
}

PIZZA_CreatePlayerCheckPoints(playerid)
{
	#define CONS (0.5)
	new randSpawn = 0;
	randSpawn = random(sizeof(gRandomSpawns_LosSantos));
	
	
	//CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_RACE_CP_SD);
	CPPos[playerid][0] = gRandomSpawns_LosSantos[randSpawn][0];
	CPPos[playerid][1] = gRandomSpawns_LosSantos[randSpawn][1];
	CPPos[playerid][2] = gRandomSpawns_LosSantos[randSpawn][2]+1;
	
	PizzaCP[playerid] = CreateDynamicRaceCP(4,
	CPPos[playerid][0],
	CPPos[playerid][1],
	CPPos[playerid][2],
    CPPos[playerid][0]+ CONS * floatsin(gRandomSpawns_LosSantos[randSpawn][3], degrees),
	CPPos[playerid][1] + CONS *  floatcos(gRandomSpawns_LosSantos[randSpawn][3], degrees),
	CPPos[playerid][2],2,-1,-1,-1,-1);
	
	/*
	
	PizzaCP[playerid] = SetPlayerRaceCheckpoint(playerid,3,
	CPPos[playerid][0],
	CPPos[playerid][1],
	CPPos[playerid][2],
    CPPos[playerid][0]+ CONS * floatsin(gRandomSpawns_LosSantos[randSpawn][3], degrees),
	CPPos[playerid][1] + CONS *  floatcos(gRandomSpawns_LosSantos[randSpawn][3], degrees),
	CPPos[playerid][2],2);
	*/

/*
	CreateDynamicMapIcon(gRandomSpawns_LosSantos[randSpawn][0],
	gRandomSpawns_LosSantos[randSpawn][1],
	gRandomSpawns_LosSantos[randSpawn][2], 0, 0x80FFFFFF, -1,-1,playerid,STREAMER_MAP_ICON_SD,MAPICON_GLOBAL);
*/
	/*
	SetPlayerMapIcon(playerid, 54,gRandomSpawns_LosSantos[randSpawn][0],
	gRandomSpawns_LosSantos[randSpawn][1],
	gRandomSpawns_LosSantos[randSpawn][2], 0, 0x80FFFFFF, MAPICON_LOCAL);
	*/
	
	SendClientMessage(playerid,-1,"[小任务]:CP Created");

}
PIZZA_DestoryPlayerCheckPoints(playerid)
{
	DestroyDynamicRaceCP(PizzaCP[playerid]);
}
PIZZA_InitMissionForPlayer(playerid,type)
{
	switch(type)
	{
		case true:
		{
			Player[playerid][PlayerStatus] = SINGLE_PIZZA;
			SendClientMessage(playerid,-1,"[小任务]:进入Pizza Boy小任务.");
			SG_Sub(playerid,"Throw the pizza through ~r~checkpoint ~w~in the Temple area.",5000);
			SG_Textbox(playerid,"Hold Q or E and press ~n~LMB to throw a pizza ~n~to the left or right.",5000);
			PIZZA_CreatePlayerCheckPoints(playerid);
		}
		case false:
		{
			Player[playerid][PlayerStatus] = STATUS_NORMAL;
			SendClientMessage(playerid,-1,"[小任务]:离开Pizza Boy小任务.");
			PIZZA_Fill(playerid);
			PIZZA_DestoryPlayerCheckPoints(playerid);
			SG_Sub(playerid,"~r~You have left the Pizza Boy Missions.",5000);
			Pizza_CPTemObject[playerid] = -1;
		}
	
	}
	
	
	return 1;

}

PIZZA_OnPizzaHitMarker(playerid)
{
	//当玩家丢中了
	PIZZA_DestoryPlayerCheckPoints(playerid);
	PIZZA_CreatePlayerCheckPoints(playerid);

}
forward PIZZA_OnObjectUpdate(objectid);
public PIZZA_OnObjectUpdate(objectid)
{
	//printf("PHY_OnObjectUpdate(%d)",objectid);
	
	//Loop All Players
	for(new i = 0;i<MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i))
		{
			//如果OBJ是我们要的
			if(PIZZA_IsAVaildObject(i,objectid) && objectid != Pizza_CPTemObject[i])
			{
			
				//SendClientMessage(i,-1,"[小任务]:OBJ IS VAILD.");
				new Float:Tem[3];
				GetObjectPos(objectid,Tem[0],Tem[1],Tem[2]);
				//判断物体是否丢中
				
				if(IsPointInRangeOfPoint(Tem[0],Tem[1],Tem[2],CPPos[i][0],CPPos[i][1],CPPos[i][2],3))
				{
					
					Pizza_CPTemObject[i] = objectid;
					PIZZA_OnPizzaHitMarker(i);
					GivenPlayerMoneyByRange(i,900,1000);
					
				}

			}
		
		}
	
	}


}

stock IsPointInRangeOfPoint(Float:x, Float:y, Float:z, Float:x2, Float:y2, Float:z2, Float:range)
{
	x2 -= x;
	y2 -= y;
	z2 -= z;
	return ((x2 * x2) + (y2 * y2) + (z2 * z2)) < (range * range);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{

	new vehicleid = GetPlayerVehicleID(playerid);
	if(GetVehicleModel(vehicleid) != 448) return 1;
	//if(Player[playerid][PlayerStatus] != STATUS_NORMAL) return 1;
	if (HOLDING( KEY_SUBMISSION))
	{
		
		if(Player[playerid][PlayerStatus] == SINGLE_PIZZA)
		{
			PIZZA_InitMissionForPlayer(playerid,false);
			return 1;
		}		
		if(Player[playerid][PlayerStatus] == STATUS_NORMAL)
		{
			PIZZA_InitMissionForPlayer(playerid,true);
			return 1;
		}
	}
	
	if(Player[playerid][PlayerStatus] != SINGLE_PIZZA) return 1;//判断玩家是否在做任务
	
	
	if (HOLDING( KEY_LOOK_LEFT))
	{
		//printf("KEY_LOOK_LEFT");
		if (PRESSED( KEY_FIRE ))
		{
			LunchPizzaObject(playerid,VECTOR_LEFT);
			//printf("KEY_ACTION");
		}
	
	}
	if(HOLDING( KEY_LOOK_RIGHT))
	{
		//printf("KEY_LOOK_RIGHT");
		if (PRESSED( KEY_FIRE ))
		{
			LunchPizzaObject(playerid,VECTOR_RIGHT);
			//printf("KEY_ACTION");
		}
	}
	return 1;
}
stock PIZZA_IsAVaildObject(playerid,objectid)
{
	for(new i =0;i<MAX_PIZZA;i++)
	{
		if(Pizza[playerid][i][Handle] == objectid ) return true;
	
	}
	return false;
}
PIZZA_GetFreeSlot(playerid)
{
	for(new i =0;i<MAX_PIZZA;i++)
	{
		if(!Pizza[playerid][i][Taken]) return i;
	
	}
	return -1;
}
PIZZA_Fill(playerid)
{
	//清空创建的Pizza
	for(new i = 0; i <MAX_PIZZA;i++)
	{
		DestroyObject(Pizza[playerid][i][Handle]);
		Pizza[playerid][i][Taken] = false;
	}
	

}
//停止OBJ滑动当落地的时候.
public PHY_OnObjectCollideWithZBound(objectid, lowhigh)
{
	for(new i = 0;i<MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i))
		{
			//如果OBJ是我们要的
			if(PIZZA_IsAVaildObject(i,objectid))
			{
				PHY_SetObjectVelocity(objectid, 0.0, 0.0, 0.0);
			}
			
		}
	}
	return 1;
}
/*
public PHY_OnObjectCollideWithSAWorld(objectid)
{
	print("PHY_OnObjectCollideWithSAWorld");
	for(new i = 0;i<MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i))
		{
			//如果OBJ是我们要的
			if(PIZZA_IsAVaildObject(i,objectid))
			{
				PHY_SetObjectVelocity(objectid, 0.0, 0.0, 0.0);
			}
			
		}
	}
	
	return 1;
}*/

LunchPizzaObject(playerid,type)
{
	#define SPEED (5.0)
	#define CONS (0.5)
	#define Z_SPEED (4.0)
	
	#define mass (5.0)
    new modelid = 19571 ; // Deagle Model ID
	new Float:x, Float:y, Float:z, Float:ang;
	GetPlayerPos(playerid, x, y, z);
	new currentveh;
	currentveh = GetPlayerVehicleID(playerid);

	GetVehicleZAngle(currentveh,ang);
	new Sot = PIZZA_GetFreeSlot(playerid);
	if(Sot == -1)
	{
		SendClientMessage(playerid,-1,"[小任务]: 没Pizza了,请回到餐厅去在拿一些~.");
		SG_Sub(playerid,"Return to the ~r~restaurant ~w~for more pizzas.",5000);
	}	
	
	
	switch (type)
	{
		case VECTOR_LEFT:
		{
			Pizza[playerid][Sot][Handle] = CreateObject(modelid, x- CONS * floatcos(ang, degrees), y- CONS *  floatsin(ang, degrees) , z+1, 90, 0, 0);
			Pizza[playerid][Sot][Taken] = true;
			//PHY_InitObject(Pizza[playerid][Sot][Taken], modelid, mass, _, PHY_MODE_3D);
			PHY_InitObject(Pizza[playerid][Sot][Handle], modelid, 2.0, 0.3);
			PHY_SetObjectVelocity(Pizza[playerid][Sot][Handle], -SPEED * floatcos(ang, degrees), -SPEED * floatsin(ang, degrees), Z_SPEED);
			print("VECTOR_LEFT");
		}
		case VECTOR_RIGHT:
		{
			Pizza[playerid][Sot][Handle]  = CreateObject(modelid, x+ CONS * floatcos(ang, degrees), y+ CONS *  floatsin(ang, degrees) , z+1, 90, 0, 0);
			Pizza[playerid][Sot][Taken] = true;
			//PHY_InitObject(Pizza[playerid][Sot][Taken], modelid, mass, _, PHY_MODE_3D);
			PHY_InitObject(Pizza[playerid][Sot][Handle], modelid, 2.0, 0.3);
			PHY_SetObjectVelocity(Pizza[playerid][Sot][Handle] , SPEED * floatcos(ang, degrees), SPEED * floatsin(ang, degrees), Z_SPEED);
			print("VECTOR_RIGHT");
		}
		
		
	}
	
	PHY_SetObjectFriction(Pizza[playerid][Sot][Handle], 10.0);
	PHY_SetObjectAirResistance(Pizza[playerid][Sot][Handle], 0.1);
	PHY_SetObjectGravity(Pizza[playerid][Sot][Handle], 10.0);
	PHY_SetObjectZBound(Pizza[playerid][Sot][Handle], _, _, 0.1);
	PHY_UseColAndreas(Pizza[playerid][Sot][Handle],3);
	

	return 1;
}
