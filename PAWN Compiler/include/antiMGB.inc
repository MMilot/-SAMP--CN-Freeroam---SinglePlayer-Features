#include <a_samp>
 
 
forward public OnMGBullDetected(playerid);
 
public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
        new bool:detected;
        detected = false;
        if(weaponid == 0)
        {
            detected = true;
            CallLocalFunction("OnMGBullDetected","i",playerid);
        }
        else if(weaponid != 38)
        {
                new tempTime = gettime();
                SetPVarInt(playerid,"NewShot",tempTime);
                if(GetPVarInt(playerid,"OldShot") == GetPVarInt(playerid,"NewShot"))
                {
                        new warnings = GetPVarInt(playerid,"SusCount");
                        warnings += 1;
                        SetPVarInt(playerid,"SusCount",warnings);
                        if(GetPVarInt(playerid,"SusCount") >= 9)
                        {
                                detected = true;
                                CallLocalFunction("OnMGBullDetected","i",playerid);
                        }
                }
                else
                {
                    if(detected == false)
                    {
                        SetPVarInt(playerid,"SusCount",0);
                    }
                }
                SetPVarInt(playerid,"OldShot",tempTime);
				if(detected) return 0;
        }
        return 1;
}
#if defined _ALS_OnPlayerWeaponShot
    #undef OnPlayerWeaponShot
#else
    #define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot antiMGB_OnPlayerWeaponShot
forward antiMGB_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);