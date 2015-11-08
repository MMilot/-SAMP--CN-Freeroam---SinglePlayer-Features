/*L-Bug report v1.0
By Lordz?.
********************Copyright (c) 2012 L-Bug report System.****************************/

#include <a_samp>
#include <zcmd>
#include <streamer>
#define red 0xFF0000FF
#define orange 0xFF9900AA
#define green 0x33FF33AA
#define Bug_input 600
#define Bug_ERR Bug_input+1
#define MESSAGE_PLAYERS true
//Change true to false to prevent messaging the bug report to all players.

new File:bugs;
new SQ[MAX_PLAYERS];
new Float:BUG_POS[1][3] = {
{1815.3750,-1286.9117,13.6300}
};

/*
public OnPlayerConnect(playerid)
{
	SQ[playerid] = 0;
	return 1;
}
*/
public OnFilterScriptInit()
{
for(new B = 0; B < sizeof(BUG_POS); B++)
{
CreateDynamicCP(BUG_POS[B][0],BUG_POS[B][1],BUG_POS[B][2], 1.5, 0, 0, -1, 5.0);
Create3DTextLabel("{FF0000}==BUG{FFFFFF}Report/{FFE600}Suggestions==\n{FFFFFF}[Shortcut]\n{FF0000}/rbug",0xFFFFFFFF,BUG_POS[B][0], BUG_POS[B][1], BUG_POS[B][2],20.0,0,1);
}
return 1;
}

CMD:rbug(playerid,params[])
{
	if(SQ[playerid] == 0)
	{
		SendClientMessage(playerid, red, "Sequirty Question:Please make sure that you're at the point where bug occurs and use the cmd again.");
		SQ[playerid] = 1;
		return 1;
	}
	if(SQ[playerid] >= 2)
	{
		SendClientMessage(playerid, red, "Please use /csq and then try.");
		return 1;
	}

	/*if (isnull(params))
	{
		SendClientMessage(playerid, red, "Usage: /rbug [bug]");
		SendClientMessage(playerid, orange, "Function: Will send the bug report to owners.");
		return 1;
	}*/
	ShowPlayerDialog(playerid,Bug_input,DIALOG_STYLE_INPUT,"Bug/Suggestion","{FF0000}Liberty_Episodes:\n{00FF00}If u find any buy pls wrote it down\nI'll take care of 'em\nThank You!","Sent","Cancel");
	return 1;
}

CMD:csq(playerid,params[])
{
	SQ[playerid] = 0;
	SendClientMessage(playerid, orange, "You are now safe to use /rbug.");
	return 1;
}
public OnDialogResponse( playerid, dialogid, response, listitem, inputtext[] )
{
if (dialogid == Bug_input && response)
{
new
string[192],
ip[16],
Lname[MAX_PLAYER_NAME],
Float:xpos,
Float:ypos,
Float:zpos,
interior = GetPlayerInterior(playerid),
skin = GetPlayerSkin(playerid),
ping = GetPlayerPing(playerid);
		
if (isnull(inputtext))
{
ShowPlayerDialog(playerid,Bug_ERR,DIALOG_STYLE_MSGBOX,"Bug/Suggestion","{FF0000}Empty??\n{00FF00}If u don't like to tell us\nPls don't write something meaningless to us\nThank You!","Rewrite","Close");
return 1;
}
	
GetPlayerName(playerid, Lname, sizeof(Lname));
GetPlayerPos(playerid, xpos, ypos, zpos);
GetPlayerIp(playerid, ip, sizeof(ip));
bugs = fopen("Reported_Bugs.txt", io_append);
format(string,sizeof(string),"***Reporter:%s|IP:%i|Skin:%d|X:%f|Y:%f|Z:%f|Int:%i|Ping:%d|Bug:%s|Bug reported using L-Bug Report\r\n", Lname, ip, skin, xpos, ypos, zpos, interior, ping, inputtext);
fwrite_cn(bugs, string);
fclose(bugs);
#if defined MESSAGE_PLAYERS == true
format(string, sizeof(string), "[Bug Report] %s(ID:%d):%s", Lname, playerid, inputtext);
SendClientMessageToAll(red, string);
#endif
ShowPlayerDialog(playerid,13,DIALOG_STYLE_MSGBOX,"Bug/Suggestion","{00FF00}Your bug report has been sent. Thank you.","Close","");
}
if (dialogid == Bug_ERR && response)
{
ShowPlayerDialog(playerid,Bug_input,DIALOG_STYLE_INPUT,"Bug/Suggestion","{FF0000}Liberty_Episodes:\n{00FF00}If u find any buy pls wrote it down\nI'll take care of 'em\nThank You!","Sent","Cancel");
}
return 0;
}

public OnPlayerEnterCheckpoint(playerid)
{
    for(new i = 0; i < sizeof(BUG_POS); i++)
    {
    	if(IsPlayerInRangeOfPoint(playerid,3.0,BUG_POS[i][0],BUG_POS[i][1],BUG_POS[i][2]))
    	{
        ShowPlayerDialog(playerid,Bug_input,DIALOG_STYLE_INPUT,"Bug/Suggestion","{FF0000}Liberty_Episodes:\n{00FF00}If u find any buy pls wrote it down\nI'll take care of 'em\nThank You!","Sent","Cancel");
		}
	}
	return 1;
}