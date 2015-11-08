// 投票模块 投票 决定一件事
// v 1.0 功能 /voteban /votekick
// BY: GTAYY

#if defined _vote_inc
#endinput
#endif
#define _vote_inc

#include "vote_h"


stock vote:OnGameModeInit()
{
	print("[组件] 投票ban,kick成功加载!");
	SendClientMessageToAll(0xFF0000AA,"[组件] 投票ban,kick成功加载!");
}

stock vote:OnGameModeExit()
{
	print("[组件] 投票ban,kick成功卸载!");
	SendClientMessageToAll(0xFF0000AA,"[组件] 投票ban,kick成功卸载!");
}

stock vote:OnPlayerConnect(playerid)
{
    votebannum[playerid] = 0;
    votekicknum[playerid] = 0;
	allvote++;
}

stock vote:OnPlayerDisconnect(playerid)
{

    for(new i = 0; i < MAX_PLAYERS;i++)
    {
    	votekflag[playerid][i] = false;
     	votebflag[playerid][i] = false;
      	if(votebannum[i] != 0) votebannum[i]--;
        if(votekicknum[i] != 0) votekicknum[i]--;
    }
	allvote--;
}

//投票
COMMAND:votekick(playerid,params[])
{
	new id;
	new sreason[64];
	new pname[MAX_PLAYER_NAME],gname[MAX_PLAYER_NAME];
	new string[128];
	if(sscanf(params,"us[64]",id,sreason))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "用法: \"/votekick <玩家名称/编号> <原因>\"");
	}else if(id == INVALID_PLAYER_ID)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "无效的玩家ID!");
	}else if(id == playerid)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "你不可以对自己使用!");
	}else if(IsPlayerNPC(id))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "你不可以对NPC使用!");
	}else
	{
		GetPlayerName(id,gname,sizeof(gname));
		GetPlayerName(playerid,pname,sizeof(pname));
		if(!votekflag[playerid][id])
		{
			votekicknum[id]++;
			votekflag[playerid][id] = true;
	  		if(votekicknum[id] == (allvote/2))
	    	{
				format(string,sizeof(string),"由于大部分人的决定 %s 被踢出服务器",gname);
				SendClientMessageToAll(0xFF0000AA,string);
	  			Kick(id);
		    }else
		    {
				format(string,sizeof(string),"%s 发起投票踢出 %s 当前还需 %d 票 原因:%s",pname,gname,(allvote/2)-votekicknum[id],sreason);
				SendClientMessageToAll(0xFF0000AA,string);
	   		}
		}else
		{
		    SendClientMessage(playerid, 0xFF0000AA, "你不能重复投票哦!");
			format(string,sizeof(string),"%s 发起投票踢出 %s 当前还需 %d 票 原因:%s",pname,gname,(allvote/2)-votekicknum[id],sreason);
			SendClientMessageToAll(0xFF0000AA,string);
		}
	}
	return 1;
}

COMMAND:voteban(playerid,params[])
{
	new id;
	new sreason[64];
	new pname[MAX_PLAYER_NAME],gname[MAX_PLAYER_NAME];
	new string[128];
	if(sscanf(params,"us[64]",id,sreason))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "用法: \"/voteban <玩家名称/编号> <原因>\"");
	}else if(id == INVALID_PLAYER_ID)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "无效的玩家ID!");
	}else if(id == playerid)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "你不可以对自己使用!");
	}else if(IsPlayerNPC(id))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "你不可以对NPC使用!");
	}else
	{
		GetPlayerName(id,gname,sizeof(gname));
		GetPlayerName(playerid,pname,sizeof(pname));
		if(!votebflag[playerid][id])
		{
	 	    votebannum[id]++;
	 	    votebflag[playerid][id] = true;
	 	    if(votebannum[id] == (allvote/2))
	 	    {
				format(string,sizeof(string),"由于大部分人的决定 %s 被禁止进入服务器",gname);
				SendClientMessageToAll(0xFF0000AA,string);
		    	Ban(id);
	 	    }else
	 	    {
				format(string,sizeof(string),"%s 发起投票封号 %s 当前还需 %d 票 原因:%s",pname,gname,(allvote/2)-votebannum[id],sreason);
				SendClientMessageToAll(0xFF0000AA,string);
			}
		}else
		{
		    SendClientMessage(playerid, 0xFF0000AA, "你不能重复投票哦!");
			format(string,sizeof(string),"%s 发起投票封号 %s 当前还需 %d 票 原因:%s",pname,gname,(allvote/2)-votebannum[id],sreason);
			SendClientMessageToAll(0xFF0000AA,string);
		}
	}
	return 1;
}
