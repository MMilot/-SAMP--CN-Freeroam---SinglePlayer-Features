/*
EPISODES ANTI COMMAND SPAM INC
(C) JAVA SPARROW PROJECT 2013
*/

new g_iCmdTickCount[MAX_PLAYERS];
new CMD_SPAMTIMES[MAX_PLAYERS];
forward AntiCommandSpam(playerid);


public AntiCommandSpam(playerid)
{
	
	if(CMD_SPAMTIMES[playerid]>=3)
	{
    new badname[156],kicker[65];
    GetPlayerName(playerid,kicker,sizeof(kicker));
    format(badname,sizeof(badname),"[反垃圾系统]: 玩家: {80FF80}%s {FFFFFF}被系统{FF0000}自动请出 {FFFFFF}[原因:{FF0000}命令刷屏{FFFFFF}]",kicker);
	SendClientMessageToAll(0xFFFFFFFF,badname);
	CMD_SPAMTIMES[playerid]=0;
	Kick(playerid);
	
	}
	if(CMD_SPAMTIMES[playerid]>=2)
	{
	SendClientMessage(playerid,0xFF0000FF, "**[反小學生系統]: 警告！再刷一次將被請出伺服器！");
	}
	if(g_iCmdTickCount[playerid] + 500 > GetTickCount() && g_iCmdTickCount[playerid] > 0) { // GetTickCount returns the uptime of the actual server in milliseconds. 1 second = 1000 MS.
	SendClientMessage(playerid,0xFF0000FF, "**[反小學生系統]: 刷命令自重！");
	CMD_SPAMTIMES[playerid]++;
	return 1;
	}
	g_iCmdTickCount[playerid] = GetTickCount();
	return 0;
}
public OnPlayerDisconnect(playerid, reason)
{
	CMD_SPAMTIMES[playerid]=0;
	print("[DEBUG] Clearn Players CMD SPAM TIME");
	return 0;
}
#if defined _ALS_OnPlayerDisconnect
        #undef OnPlayerDisconnect
#else
        #define _ALS_OnPlayerDisconnect
#endif
 
#define OnPlayerDisconnect Spam_OnPlayerDisconnect
forward Spam_OnPlayerDisconnect( playerid, reason );