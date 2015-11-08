/*
	=========== General Libaray For Add on Features =========
	
*/
#include <YSI\y_hooks>
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define STATUS_NORMAL 0

enum PlayerInfo
{
	PlayerText:NotifyTextDraw,
	PlayerStatus
}

new Player[MAX_PLAYERS][PlayerInfo];


hook OnPlayerConnect(playerid)
{
	Player[playerid][PlayerStatus] = STATUS_NORMAL;

	return 1;
}

stock GivenPlayerMoneyByRange(playerid,low,high)
{
	new rand = randomEx(low,high);
	GivePlayerMoney(playerid,rand);
	new string[125];
	format(string,sizeof(string),"[系统]:你获得了$%d.",rand);
	SendClientMessage(playerid,-1,string);
	format(string,sizeof(string),"~y~payout~n~~w~$%d",rand);
	GameTextForPlayer(playerid,string, 2000, 6);
	PlayerPlaySound(playerid ,1056,0.0, 0.0,0.0);
}

stock randomEx(min, max)
{    
    //Credits to y_less    
    new rand = random(max-min)+min;    
    return rand;
}