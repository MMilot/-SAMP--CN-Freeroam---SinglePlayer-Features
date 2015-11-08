

new OldScore[MAX_PLAYERS];
new NewScore[MAX_PLAYERS];

forward SetPlayerScoreEx(playerid,ammount);//Forward - this is how you call a new public
public SetPlayerScoreEx(playerid,ammount)
{
      //First the gonna have to set the OldScore of the player , just in case .
      OldScore[playerid] = GetPlayerScore(playerid);//Get the Score ( GetPlayerScore ) they put it in the OldScore var...
      //Now we gotta define the new ammount of Score the player holds , we gotta do it before we give him the Score , so he wont get banned / kicked .
      NewScore[playerid] = OldScore[playerid];//Putting the ammount in the NewScore var
      //Now we gotta give the player some sweet cash
      SetPlayerScore(playerid,NewScore[playerid]);//default function : )

      return 1;
}

forward CheckScore();
public CheckScore()
{
      for(new i = 0; i < MAX_PLAYERS; i++)//This loop will check all players at one time
      {
               if(IsPlayerConnected(i))//Player is gotta be connected right
               {
                        if(GetPlayerScore(i) > NewScore[i])//Getting player's Score , checking if its more then his NewScore(means he is hacking)
                        {
                                //  ResetPlayerScore(i);//We gonna reset his Score
printf("NOWSCORE = %d NEWSCORE=%d",GetPlayerScore(i),NewScore[i]);
								new string[125],pname[MAX_PLAYER_NAME];
								GetPlayerName(i,pname,sizeof(pname));
								format(string,sizeof(string),"[反垃圾系统]:玩家 {00B9FF}%s {FFFFFF}被系统{FF0000}T出服务器{FFFFFF} 原因{FF0000}[刷积分]",pname);
	    						SendClientMessageToAll(0xFFFFFFFF, string);
                                SetPlayerScore(i,OldScore[i]);//Give him his old Score , as a punishment !
                                Kick(i);//Kick/Ban the poor kid

                        }
               }
      }
      return 1;
}

