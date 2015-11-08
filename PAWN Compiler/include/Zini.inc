#define Max_Players 50
#define Invalid_Player (0xFFFF)
#define Invalid_Vehicle (0xFFFF)

#define Normal 0xACCBF1FF
#define Red 0xFF0000FF
#define Cyan 0x00FFFFFF
#define Green 0x008000FF
#define LightYellow 0xFFFFC1FF
#define LightGreen 0x00FF00FF
#define Yellow 0xFFFF00FF
#define Orange 0xFFA500FF

forward SaveToFile(filename[],text[]);
public SaveToFile(filename[],text[])
{
	new File:LAdminfile,filepath[256],string[256],year,month,day,hour,minute,second;
	getdate(year,month,day); gettime(hour,minute,second);
	format(filepath,256,"/%s.txt",filename);
	LAdminfile = fopen(filepath,io_append);
	format(string,256,"[%d/%d/%d %d:%d:%d] %s\r\n",year,month,day,hour,minute,second,text);
	fwrite(LAdminfile,string);
	fclose(LAdminfile);
	return 1;
}

stock name(playerid)
{
	new pname[256];
	GetPlayerName(playerid,pname,256);
	return pname;
}

stock IsPlayerInWater(playerid)
{
	new anim = GetPlayerAnimationIndex(playerid);
 	if(((anim >=  1538) && (anim <= 1542)) || (anim == 1544) || (anim == 1250) || (anim == 1062)) return 1;
  	return 0;
}

stock IsPlayerAiming(playerid)
{
	new anim = GetPlayerAnimationIndex(playerid);
	if(((anim >= 1160) && (anim <= 1163)) || (anim == 1167) || (anim == 1365) || (anim == 1643) || (anim == 1453) || (anim == 220)) return 1;
 	return 0;
}

forward LaserUpdate(playerid);
public LaserUpdate(playerid)
{
	if(GetPVarInt(playerid,"laser") == 1)
		{
			RemovePlayerAttachedObject(playerid,0);
     		if((IsPlayerInAnyVehicle(playerid)) || (IsPlayerInWater(playerid))) return 1;
       		switch (GetPlayerWeapon(playerid))
			{
   				case 23:
		    	{
       				if (IsPlayerAiming(playerid))
			    	{
        				if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
		 				{
       						SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SP standing aiming
             				0.108249, 0.030232, 0.118051, 1.468254, 350.512573, 364.284240);
              			}
					  	else
					   	{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SP crouched aiming
              				0.108249, 0.030232, 0.118051, 1.468254, 349.862579, 364.784240);
                  		}
                    }
					else
				 	{
      					if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
			   			{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SP standing not aiming
              				0.078248, 0.027239, 0.113051, -11.131746, 350.602722, 362.384216);
                  		}
	  					else
					   	{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SP crouched not aiming
         					0.078248, 0.027239, 0.113051, -11.131746, 350.602722, 362.384216);
                        }
      				}
			  	}
				case 27:
			 	{
     				if (IsPlayerAiming(playerid))
  					{
       					if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
			    		{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SPAS standing aiming
              				0.588246, -0.022766, 0.138052, -11.531745, 347.712585, 352.784271);
                  		}
					  	else
					   	{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SPAS crouched aiming
              				0.588246, -0.022766, 0.138052, 1.468254, 350.712585, 352.784271);
                  		}
           			}
				   	else
				    {
        				if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
				 		{
       						SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SPAS standing not aiming
             				0.563249, -0.01976, 0.134051, -11.131746, 351.602722, 351.384216);
                 		}
				 		else
					  	{
        					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // SPAS crouched not aiming
        					0.563249, -0.01976, 0.134051, -11.131746, 351.602722, 351.384216);
                        }
					}
				}
				case 30:
			 	{
     				if (IsPlayerAiming(playerid))
				 	{
      					if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
				  		{
        					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // AK standing aiming
             				0.628249, -0.027766, 0.078052, -6.621746, 352.552642, 355.084289);
                 		}
					 	else
					  	{
        					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // AK crouched aiming
             				0.628249, -0.027766, 0.078052, -1.621746, 356.202667, 355.084289);
                 		}
                   	}
				   	else
			    	{
        				if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
					 	{
       						SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // AK standing not aiming
             				0.663249, -0.02976, 0.080051, -11.131746, 358.302734, 353.384216);
                 		}
					 	else
					  	{
        					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // AK crouched not aiming
             				0.663249, -0.02976, 0.080051, -11.131746, 358.302734, 353.384216);
                        }
					}
				}
				case 31:
			 	{
     				if (IsPlayerAiming(playerid))
			  		{
       					if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
				   		{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // M4 standing aiming
              				0.528249, -0.020266, 0.068052, -6.621746, 352.552642, 355.084289);
          				}
					  	else
					   	{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // M4 crouched aiming
              				0.528249, -0.020266, 0.068052, -1.621746, 356.202667, 355.084289);
               			}
                  	}
			  		else
				   	{
        				if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
				 		{
       						SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // M4 standing not aiming
             				0.503249, -0.02376, 0.065051, -11.131746, 357.302734, 354.484222);
                 		}
				 		else
					  	{
        					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // M4 crouched not aiming
             				0.503249, -0.02376, 0.065051, -11.131746, 357.302734, 354.484222);
                        }
					}
				}
    			case 29:
			 	{
     				if (IsPlayerAiming(playerid))
			  		{
       					if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
			    		{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // MP5 standing aiming
   							0.298249, -0.02776, 0.158052, -11.631746, 359.302673, 357.584259);
          				}
					  	else
					   	{
         					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // MP5 crouched aiming
              				0.298249, -0.02776, 0.158052, 8.368253, 358.302673, 352.584259);
                  		}
                    }
					else
					{
    					if (GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
				 		{
       						SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // MP5 standing not aiming
             				0.293249, -0.027759, 0.195051, -12.131746, 354.302734, 352.484222);
                 		}
				 		else
					  	{
        					SetPlayerAttachedObject(playerid, 0, GetPVarInt(playerid, "color"), 6, // MP5 crouched not aiming
             				0.293249, -0.027759, 0.195051, -12.131746, 354.302734, 352.484222);
                        }
					}
				}
			}
		}
	return 1;
}

stock File_Exists(filename[]) return fexist(filename);
stock File_Remove(filename[]) return fremove(filename);

stock File_Create(filename[])
{
	if(fexist(filename)) return 0;
	new File:fhnd;
	fhnd = fopen(filename,io_write);
	if(fhnd)
	{
		fclose(fhnd);
		return 1;
	}
	return 0;
}

stock File_Set(filename[],key[],value[])
{
	new key_length = strlen(key);
	new value_length = strlen(value);
	if(key_length == 0 || key_length + value_length + 2 > 255) return 0;
	new File:fohnd,File:fwhnd;
	new tmpres[255];
	new bool:wasset = false;
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fremove(tmpres);
	fohnd = fopen(filename,io_read);
	if(!fohnd) return 0;
	fwhnd = fopen(tmpres,io_write);
	if(!fwhnd)
	{
		fclose(fohnd);
		return 0;
	}
	while(fread(fohnd,tmpres))
	{
		if(!wasset && tmpres[key_length] == '=' && !strcmp(tmpres,key,true,key_length))
		{
			format(tmpres,sizeof(tmpres),"%s=%s",key,value);
			wasset = true;
		}
		else
		{
			StripNewLine(tmpres);
		}
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}
	if(!wasset)
	{
		format(tmpres,sizeof(tmpres),"%s=%s",key,value);
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}
	fclose(fohnd);
	fclose(fwhnd);
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if(fcopytextfile(tmpres,filename)) return fremove(tmpres);
	return 0;
}

stock File_IntSet(filename[],key[],value)
{
   new valuestring[255];
   format(valuestring,255,"%d",value);
   return File_Set(filename,key,valuestring);
}

stock File_Int(filename[],key[]) return strval(File_Get(filename,key));

stock File_FloatSet(filename[],key[],Float:value)
{
   new valuestring[255];
   format(valuestring,255,"%f",value);
   return File_Set(filename,key,valuestring);
}

stock Float:File_Float(filename[],key[]) return floatstr(File_Get(filename,key));

stock File_Bool(filename[],key[]) return strval(File_Get(filename,key));

stock File_BoolSet(filename[],key[],value)
{
	if(value) return File_Set(filename,key,"1");
	return File_Set(filename,key,"0");
}

stock File_Unset(filename[],key[])
{
	new key_length = strlen(key);
	if(key_length == 0 || key_length + 2 > 255) return 0;
	new File:fohnd,File:fwhnd;
	new tmpres[255];
	format(tmpres,255,"%s.part",filename);
	fremove(tmpres);
	fohnd = fopen(filename,io_read);
	if(!fohnd) return 0;
	fwhnd = fopen(tmpres,io_write);
	if(!fwhnd)
	{
		fclose(fohnd);
		return 0;
	}
	while(fread(fohnd,tmpres))
	{
		if(tmpres[key_length] == '=' && !strcmp(tmpres,key,true,key_length))
		{
		}
		else
		{
			StripNewLine(tmpres);
			fwrite(fwhnd,tmpres);
			fwrite(fwhnd,"\r\n");
		}
	}
	fclose(fohnd);
	fclose(fwhnd);
	format(tmpres,255,"%s.part",filename);
	if(fcopytextfile(tmpres,filename)) return fremove(tmpres);
	return 0;
}

stock File_Get(filename[],key[])
{
	new tmpres[255];
	new key_length = strlen(key);
	if(key_length == 0 || key_length + 2 > 255) return tmpres;
	new File:fohnd;
	fohnd = fopen(filename,io_read);
	if(!fohnd) return tmpres;
	while(fread(fohnd,tmpres))
	{
		if(tmpres[key_length] == '=' && !strcmp(tmpres,key,true,key_length))
		{
			StripNewLine(tmpres);
			strmid(tmpres,tmpres,key_length + 1,strlen(tmpres),255);
			fclose(fohnd);
			return tmpres;
		}
	}
	fclose(fohnd);
	return tmpres;
}


stock File_Isset(filename[],key[])
{
	new key_length = strlen(key);
	if(key_length == 0 || key_length + 2 > 255) return 0;
	new File:fohnd;
	fohnd = fopen(filename,io_read);
	if (!fohnd) return 0;
	new tmpres[255];
	while(fread(fohnd,tmpres))
	{
		if(tmpres[key_length] == '='&& !strcmp(tmpres,key,true,key_length))
		{
			fclose(fohnd);
			return 1;
		}
	}
	fclose(fohnd);
	return 0;
}

stock StripNewLine(string[])
{
	new len = strlen(string);
	if(string[0] == 0) return ;
	if((string[len - 1] == '\n') || (string[len - 1] == '\r'))
	{
		string[len - 1] = 0;
		if(string[0] == 0) return ;
		if((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

stock fcopytextfile(oldname[],newname[])
{
	new File:ohnd,File:nhnd;
	if(!fexist(oldname)) return 0;
	ohnd = fopen(oldname,io_read);
	if(!ohnd) return 0;
	nhnd = fopen(newname,io_write);
	if(!nhnd)
	{
		fclose(ohnd);
		return 0;
	}
	new tmpres[255];
	while(fread(ohnd,tmpres))
	{
		StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		fwrite(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return 1;
}

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

//------------------------------------------------

stock strrest(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

//----------------------------------------------------------
// Tokenise by a delimiter
// Return string and index of the end determined by the
// provided delimiter in delim

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

stock isNumeric(const string[])
{
  new length=strlen(string);
  if (length==0) return false;
  for (new i = 0; i < length; i++)
    {
      if (
            (string[i] > '9' || string[i] < '0' && string[i]!='-' && string[i]!='+') // Not a number,'+' or '-'
             || (string[i]=='-' && i!=0)                                             // A '-' but not at first.
             || (string[i]=='+' && i!=0)                                             // A '+' but not at first.
         ) return false;
    }
  if (length==1 && (string[0]=='-' || string[0]=='+')) return false;
  return true;
}

//----------------------------------------------------------

stock IsKeyJustDown(key, newkeys, oldkeys)
{
	if((newkeys & key) && !(oldkeys & key)) return 1;
	return 0;
}