//==========================public OPU===============================//

public AntiTrackTest(playerid)
{
	P[playerid][iCurVW] = GetPlayerVirtualWorld(playerid);
	if(P[playerid][iCurrentVW] != P[playerid][iCurVW])
	    if(P[playerid][UsedCmdToChangeVW] == false)
	    {
	        new i[256],pn[256];
	        GetPlayerName(playerid,pn,sizeof(pn));
	        format(i,sizeof(i),"[祝贺]玩家 %s 因为使用作弊器追踪其他玩家而得到了奖励!Ta趴下了!",pn);
	        SetPlayerHealth(playerid,0.0);
	        SendClientMessageToAll(COLOR_RED,i);
	    	P[playerid][iCurrentVW] = P[playerid][iCurVW];
		}
		else
		{
	        SendClientMessage(playerid,COLOR_RED,"切换正常");
			P[playerid][UsedCmdToChangeVW] = false;
	    	P[playerid][iCurrentVW] = P[playerid][iCurVW];
  		}
	return 1;
}