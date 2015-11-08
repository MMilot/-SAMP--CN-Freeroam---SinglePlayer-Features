//-------------------------------------------------
//
//  NPC initialisation for Grand Larceny
//
//-------------------------------------------------

#pragma tabsize 0
#include <a_samp>
#include <YSI\y_hooks>

new NPCBlueBus;
new NPCBlackBus;
new NPCTrain[3];
new Plane[4];
/*
new Limo1;
new Limo2;
new Tug;
new LVTaxi;
new Dodo;
new Elegy;

new Bus1;
new Bus2;
new PoliceHeli;
new Van;
new Bulldozer;
*/
//-------------------------------------------------

hook OnFilterScriptInit()
{
	print("Load NPCS");
	ConnectNPC("TrainDriverLV","train_lv");
	ConnectNPC("TrainDriverLS","train_ls");
	ConnectNPC("TrainDriverSF","train_sf");
	ConnectNPC("PilotLV","at400_lv");
	ConnectNPC("PilotSF","at400_sf");
	ConnectNPC("PilotLS","at400_ls");
	
	
	ConnectNPC("BlueBusDriver","Bus");
	ConnectNPC("BlackBusDriver","Bus2");
	// Testing
	//ConnectNPC("OnfootTest","onfoot_test");
	//ConnectNPC("DriverTest","mat_test2");
	//ConnectNPC("DriverTest2","driver_test2");
	//Vehicles
	/*
	ConnectNPC("Bus1","bus1");
	ConnectNPC("Bus2","bus2");
	ConnectNPC("PoliceHeli","policeheli");
	ConnectNPC("Van","van");
	ConnectNPC("Bulldozer","bulldozer");
	
	ConnectNPC("Limo1","limo1");
	ConnectNPC("Limo2","limo2");
	ConnectNPC("Tug","tug");
	ConnectNPC("LVTaxi","lvtaxi");
	ConnectNPC("Dodo","dodo");
	ConnectNPC("Elegy","elegy");
	
 	Limo1 =	AddStaticVehicle(409,2125.1548,1045.6689,10.6029,125.6300,1,1); // limo1
	Limo2 =	AddStaticVehicle(409,2039.3546,989.0201,10.4719,179.9125,0,0); // limo2
	Tug =	AddStaticVehicle(583,1633.1984,1648.5555,10.3607,177.7618,1,1); // tug
	LVTaxi =	AddStaticVehicle(420,1710.0829,1452.1614,10.5395,343.1176,6,1); // taxi
	Dodo =	AddStaticVehicle(593,1327.7201,1581.3104,11.2769,271.5139,51,1); // dodo
	Elegy =  AddStaticVehicle(562,2085.3762,863.2629,6.4877,89.4885,33,33); // elegy
	
 	Bus1 =	AddStaticVehicle(431,-1988.0057,116.6116,27.6411,0.6686,75,59); // bus1
	Bus2 =	AddStaticVehicle(431,-1987.3301,163.1342,27.7086,177.6835,75,59); // bus2
	PoliceHeli =	AddStaticVehicle(497,-1679.7006,705.9991,30.7217,89.8752,0,1); // heli
	Van =	AddStaticVehicle(482,-2139.1716,221.6213,35.4811,180.1554,102,65); // van
	Bulldozer =	AddStaticVehicle(486,-2087.0195,135.7291,35.3750,58.4615,1,1); // bulldozer
	*/
	NPCBlueBus = CreateVehicle(431, 0.0, 0.0, 0.0, 0.0, 125, 125, 1);
	NPCBlackBus = CreateVehicle(431, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
	Plane[0] = CreateVehicle(577, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
	Plane[1] = CreateVehicle(577, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
	Plane[2] = CreateVehicle(577, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
	NPCTrain[0] =  AddStaticVehicle(537, 1462.0745,2630.8787,10.8203,200.0,-1,-1);
	NPCTrain[1] =  AddStaticVehicle(538, -1942.7950,168.4164,27.0006,200.0,-1,-1);
	NPCTrain[2] =  AddStaticVehicle(538, 1700.7551,-1953.6531,14.8756,200.0,-1,-1);
	return 1;
}

//-------------------------------------------------
// IMPORTANT: This restricts NPCs connecting from
// an IP address outside this server. If you need
// to connect NPCs externally you will need to modify
// the code in this callback.

hook OnPlayerConnect(playerid)
{
	if(IsPlayerNPC(playerid)) {
	    new ip_addr_npc[64+1];
	    new ip_addr_server[64+1];
	    GetServerVarAsString("bind",ip_addr_server,64);
	    GetPlayerIp(playerid,ip_addr_npc,64);
	    
		if(!strlen(ip_addr_server)) {
		    ip_addr_server = "127.0.0.1";
		}
		
		if(strcmp(ip_addr_npc,ip_addr_server,true) != 0) {
		    // this bot is remote connecting
		    printf("NPC: Got a remote NPC connecting from %s and I'm kicking it.",ip_addr_npc);
		    Kick(playerid);
		    return 0;
		}
        printf("NPC: Connection from %s is allowed.",ip_addr_npc);
	}
	
	return 1;
}

//-------------------------------------------------

hook OnPlayerRequestClass(playerid, classid)
{
	if(!IsPlayerNPC(playerid)) return 0; // We only deal with NPC players in this script
	
	new playername[64];
	GetPlayerName(playerid,playername,64);

 	if(!strcmp(playername,"TrainDriverLV",true)) {
        SetSpawnInfo(playerid,69,255,1462.0745,2630.8787,10.8203,0.0,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"TrainDriverSF",true)) {
	    SetSpawnInfo(playerid,69,255,-1942.7950,168.4164,27.0006,0.0,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"TrainDriverLS",true)) {
	    SetSpawnInfo(playerid,69,255,1700.7551,-1953.6531,14.8756,0.0,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"PilotLV",true)) {
	    SetSpawnInfo(playerid,69,61,0.0,0.0,0.0,0.0,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"PilotSF",true)) {
	    SetSpawnInfo(playerid,69,61,0.0,0.0,0.0,0.0,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"PilotLS",true)) {
	    SetSpawnInfo(playerid,69,61,0.0,0.0,0.0,0.0,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"OnfootTest",true)) {
	    SetSpawnInfo(playerid,69,61,2388.1003,-1279.8933,25.1291,94.3321,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"DriverTest",true)) {
	    SetSpawnInfo(playerid,69,61,2388.1003,-1279.8933,25.1291,94.3321,-1,-1,-1,-1,-1,-1);
	}
	else if(!strcmp(playername,"DriverTest2",true)) {
	    SetSpawnInfo(playerid,69,61,2388.1003,-1279.8933,25.1291,94.3321,-1,-1,-1,-1,-1,-1);
	}

/*
	if(!strcmp(playername,"Bus1",true)) {
        PutPlayerInVehicle(playerid, Bus1, 0);
        SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
        ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Bus2",true)) {
	    SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, Bus2, 0);
		ShowPlayerMarkers(0);
	}
	*/
	/*
	else if(!strcmp(playername,"PoliceHeli",true)) {
        SetSpawnInfo( playerid, 0, 285, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
	    PutPlayerInVehicle(playerid, PoliceHeli, 0);
	    ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Van",true)) {
	    SetSpawnInfo( playerid, 0, 153, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, Van, 0);
		ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Bulldozer",true)) {
	    SetSpawnInfo( playerid, 0, 260, 1958.33, 1343.12, 15.36, 269.15, 31, 1000, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, Bulldozer, 0);
		ShowPlayerMarkers(0);
	}
	
	 	if(!strcmp(playername,"Limo1",true)) {
        PutPlayerInVehicle(playerid, Limo1, 0);
        SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
        ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Limo2",true)) {
	    SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, Limo2, 0);
		ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Tug",true)) {
        SetSpawnInfo( playerid, 0, 16, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
	    PutPlayerInVehicle(playerid, Tug, 0);
 		ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"LVTaxi",true)) {
	    SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, LVTaxi, 0);
		ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Dodo",true)) {
	    SetSpawnInfo( playerid, 0, 187, 1958.33, 1343.12, 15.36, 269.15, 31, 1000, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, Dodo, 0);
		ShowPlayerMarkers(0);
	}
	else if(!strcmp(playername,"Elegy",true)) {
	    SetSpawnInfo( playerid, 0, 217, 1958.33, 1343.12, 15.36, 269.15, 31, 1000, 0, 0, 0, 0 );
		PutPlayerInVehicle(playerid, Elegy, 0);
		ShowPlayerMarkers(0);
	}
	*/
	
	return 0;
}

//-------------------------------------------------

stock SetVehicleTireStatus(vehicleid, tirestatus)
{
    new panels, doors, lights, tires;
    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tirestatus);
}

//-------------------------------------------------

hook OnPlayerSpawn(playerid)
{
	if(!IsPlayerNPC(playerid)) return 1; // We only deal with NPC players in this script

	new playername[64];
	GetPlayerName(playerid,playername,64);

	if(!strcmp(playername,"TrainDriverLV",true)) {
        PutPlayerInVehicle(playerid,NPCTrain[0],0);
        SetPlayerColor(playerid,0xFFFFFFFF);
 	}
	else if(!strcmp(playername,"TrainDriverSF",true)) {
	    PutPlayerInVehicle(playerid,NPCTrain[1],0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	else if(!strcmp(playername,"TrainDriverLS",true)) {
	    PutPlayerInVehicle(playerid,NPCTrain[2],0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	else if(!strcmp(playername,"PilotLV",true)) {
	    PutPlayerInVehicle(playerid,Plane[0],0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	else if(!strcmp(playername,"PilotSF",true)) {
	    PutPlayerInVehicle(playerid,Plane[1],0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	else if(!strcmp(playername,"PilotLS",true)) {
	    PutPlayerInVehicle(playerid,Plane[2],0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	/*
	else if(!strcmp(playername,"OnfootTest",true)) {
	    //PutPlayerInVehicle(playerid,876,0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	else if(!strcmp(playername,"DriverTest",true)) {
	    PutPlayerInVehicle(playerid,376,0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}
	else if(!strcmp(playername,"DriverTest2",true)) {
		//SetVehicleTireStatus(876,0xFF);
	    PutPlayerInVehicle(playerid,875,0);
	    SetPlayerColor(playerid,0xFFFFFFFF);
	}*/

	else if(!strcmp(playername, "BlueBusDriver", true))
	{
        SetPlayerColor(playerid, 0xFFFFFF00);
		PutPlayerInVehicle(playerid, NPCBlueBus, 0);
        SetPlayerSkin(playerid, 255);
        ResetPlayerWeapons(playerid);
        //Attach3DTextLabelToVehicle(NPCTextBlue, NPCBlueBus, 0.0, 0.0, 0.0);
    }
    else if(!strcmp(playername, "BlackBusDriver", true))
    {
        SetPlayerColor(playerid, 0xFFFFFF00);
		PutPlayerInVehicle(playerid, NPCBlackBus, 0);
        SetPlayerSkin(playerid, 255);
        ResetPlayerWeapons(playerid);
       // Attach3DTextLabelToVehicle(NPCTextBlack, NPCBlackBus, 0.0, 0.0, 0.0);
    }


	return 1;
}

//-------------------------------------------------
// EOF


