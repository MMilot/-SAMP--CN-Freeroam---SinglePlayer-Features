#if defined Y_INC
  #endinput
#endif
#define Y_INC

#include <a_samp>
/*
native GetPlayerName_(playerid)//获取玩家名称
*/
stock GetPlayerName_(playerid)//获取玩家名称
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,sizeof(name));
	return name;
}

/*
native Float:GetPlayerFacingAngle_(playerid)
*/
stock Float:GetPlayerFacingAngle_(playerid)
{
	new Float:ang;
	GetPlayerFacingAngle(playerid,ang);
	return ang;
}


//----------------------------------------------------------
// Tokenise by a delimiter
// Return string and index of the end determined by the
// provided delimiter in delim
/*
native token_by_delim(const string[], return_str[], delim, start_index)
*/
stock token_by_delim(const string[], return_str[], delim, start_index)
{
	new x=0;
	while(string[start_index] != EOS && string[start_index] != delim) {
	    return_str[x] = string[start_index];
	    x++;
	    start_index++;
	}
	return_str[x] = EOS;
	if(string[start_index] == EOS) start_index = (-1);
	return start_index;
}

//----------------------------------------------------------

/*

native strtok(const string[], &index)

stock strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

*/