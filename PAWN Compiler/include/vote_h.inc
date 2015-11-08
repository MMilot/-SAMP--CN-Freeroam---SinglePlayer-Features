//BY:GTAYY

#include <a_samp>
#include <zcmd>
#include <sscanf2>
#define vote: vote_
new votebannum[MAX_PLAYERS];
new votekicknum[MAX_PLAYERS];
new bool:votekflag[MAX_PLAYERS][MAX_PLAYERS];
new bool:votebflag[MAX_PLAYERS][MAX_PLAYERS];
new allvote = 2;

vote:OnGameModeInit();
vote:OnGameModeExit();
vote:OnPlayerConnect(playerid);
vote:OnPlayerDisconnect(playerid);
