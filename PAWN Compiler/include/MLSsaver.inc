/*******************************************************************************
MLS's Score System By BMB


*******************************************************************************/
//*********************************INCLUDES***********************************//
#include <a_samp>
#include <Dini>
#include <Dutils>
#include <Dudb>

//*******************************PRAGMAS**************************************//
#pragma unused ret_memcpy
#pragma tabsize 0 //Fixes all lose indentation errors
//**FORWARDS**//
forward XtR_OnPlayerDisconnect(playerid);
forward XtR_OnPlayerConnect(playerid);

//**************************************NEWS**********************************//
new pname[MAX_PLAYER_NAME];
new MLS Score[100];
//------------------------------------------------------------------------------
/*---------------------------------CallBacks----------------------------------*/
public XtR_OnPlayerDisconnect(playerid){
GetPlayerName(playerid, pname, sizeof(pname));
format(MLSScore, sizeof(MLS Score), "/MLS Saver/%s.ini",pname);
if(!dini_Exists(MLS Score))
{
}
else
{
dini_IntSet(XtreaMeRScore, "Score", GetPlayerScore(playerid));
dini_IntSet(XtreaMeRScore, "Money", GetPlayerMoney(playerid));
}
}
public XtR_OnPlayerConnect(playerid){
GetPlayerName(playerid, pname, sizeof(pname));
format(MLSSCORE, sizeof(MLSScore), "/MLS Saver/%s.ini",pname);
if(!dini_Exists(MLSScore))
{
dini_Create(MLSscore);
dini_IntSet(mlsscore, "Score", 0);
dini_IntSet(mlsScore, "Money", 0);
SetPlayerScore(playerid, dini_Int(XtreaMeRScore, "Score"));
SetPlayerMoney(playerid, dini_Int(XtreaMeRScore, "Money"));
}
else
{
SetPlayerScore(playerid, dini_Int(Mlsscore, "Score"));
SetPlayerMoney(playerid, dini_Int(MLSSCORE, "Money"));
}
return 1;
}