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
    format(badname,sizeof(badname),"[������ϵͳ]: ���: {80FF80}%s {FFFFFF}��ϵͳ{FF0000}�Զ���� {FFFFFF}[ԭ��:{FF0000}����ˢ��{FFFFFF}]",kicker);
	SendClientMessageToAll(0xFFFFFFFF,badname);
	CMD_SPAMTIMES[playerid]=0;
	Kick(playerid);
	
	}
	if(CMD_SPAMTIMES[playerid]>=2)
	{
	SendClientMessage(playerid,0xFF0000FF, "**[��С�W��ϵ�y]: ���棡��ˢһ�Ό���Ո���ŷ�����");
	}
	if(g_iCmdTickCount[playerid] + 500 > GetTickCount() && g_iCmdTickCount[playerid] > 0) { // GetTickCount returns the uptime of the actual server in milliseconds. 1 second = 1000 MS.
	SendClientMessage(playerid,0xFF0000FF, "**[��С�W��ϵ�y]: ˢ�������أ�");
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