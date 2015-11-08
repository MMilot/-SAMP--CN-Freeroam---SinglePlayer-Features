// This is an Include File
// Do not use this file as a GameMode/Filterscript
// Copyright (C) 2011 Joe Zhao Corporation. All rights reserved.

#include <a_samp>

new Float:PreX, Float:PreY, Float:PreZ;

stock PlayControlSoundForPlayer(playerid)    // Play Control Complete Sound For Specify Player
	PlayerPlaySound(playerid, 1057, 0, 0, 0);
	
stock PlayControlSoundForAll() {    // Play Control Complete Sound For All Players
	for(new Players = 0; Players < GetMaxPlayers(); Players++)
		PlayerPlaySound(Players, 1057, 0, 0, 0);
}

stock IsPlayerNearPlayer(playerid, targetid) {    // Check Is Player Stand Near Specify Player
	GetPlayerPos(targetid, PreX, PreY, PreZ);
	if(IsPlayerInRangeOfPoint(playerid, 6.0, PreX, PreY, PreZ) return 1;
	else return 0;
}

stock MovePlayerToPlayer(playerid, targetid) {    // Move Player To Specify Player
	GetPlayerPos(targetid, PreX, PreY, PreZ);
	SetPlayerPos(playerid, PreX + 0.7, PreY + 0.7, PreZ);
}