//=========================declarations==============================/

new Text3D:Help;
new Helper;

new limit[200];
forward reset(playerid);

new curPlayerVehM[MAX_PLAYERS]				= {MIN_VEHI_ID, ...}; // Current Player Vehicle ID
new curPlayerVehI[MAX_PLAYERS]				= {-1, ...};
enum CURVEHICLE {
	bool:spawn,
	vmodel,
	vInt
};

/*============Vehicle===========*/
enum V{id,mid,colour1,colour2,bool:spawned}
new PV[MAX_PLAYERS][5][V];

/*============Player============*/
enum PConfigs
{
	/*Account*/
	bool:Loggedin,
	bool:Registed,
	bool:Autosave,
	bool:Autoload,
	/*PM*/
	LastPMSender,
	bool:pming,
	/*Status*/
	gPlayerStatus,
	gPlayerTimers,
	wea,
	time,
	Skin,
	clicked,
	bool:AllowT,
	bool:FirstSpawn,
	/*Location*/
	bool:UsedCmdToChangeVW,
	iCurVW,
	iCurrentVW,
	VW,
	IN,
	Float:Px,
	Float:Py,
	Float:Pz,
	bool:SavePos,
	/*Fun*/
	bool:pk,
	Text3D:gxqm,
	bool:specing,
	spectee,
}
new P[MAX_PLAYERS][PConfigs];

/*============Weapons============*/
enum Weapons{weap,ammo}
new PW[MAX_PLAYERS][12][Weapons];

/*=========Ignoration============*/
enum Ex
{
	bool:pm,
	bool:teleport,
	bool:speak
	
}
new pb[MAX_PLAYERS][MAX_PLAYERS][Ex];

/*============Server=============*/
new HighestID;

//To discover

enum E_OBJECT
{
	OBJ_MOD,
	OBJ_MDL,
	Float:OBJ_X,
	Float:OBJ_Y,
	Float:OBJ_Z,
	Float:OBJ_RX,
	Float:OBJ_RY,
	Float:OBJ_RZ
}

enum E_OBJ_RATE
{
	Float:OBJ_RATE_ROT,
	Float:OBJ_RATE_MOVE
}

new pObjectRate[ MAX_PLAYERS ][ E_OBJ_RATE ];
new curPlayerObjM[ MAX_PLAYERS ][ E_OBJECT ];
new curPlayerObjI[ MAX_PLAYERS ]				= {-1, ...};

enum P_CAMERA_D {
	CMODE,
	Float:RATE,
	Float:CPOS_X,
	Float:CPOS_Y,
	Float:CPOS_Z,
	Float:CLOO_X,
	Float:CLOO_Y,
	Float:CLOO_Z
};

new curPlayerCamD[MAX_PLAYERS][P_CAMERA_D];

//===========================forwards================================//

forward SkinSelect(playerid);
forward VehicleSelect(playerid,i);
forward WorldSelect(playerid);
forward CameraSelect(playerid);
forward ObjectSelect(playerid);
forward ColorSelect(playerid,i);
forward GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance);
forward AntiTrackTest(playerid);