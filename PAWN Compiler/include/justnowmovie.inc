#define COLOR_GRAD1 0xB4B5B7FF
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_GRAD3 0xCBCCCEFF
#define COLOR_GRAD4 0xD8D8D8FF
#define COLOR_GRAD5 0xE3E3E3FF
#define COLOR_GRAD6 0xF0F0F0FF
#define COLOR_GREY 0xAFAFAFAA
#define COLOR_GREEN 0x33AA33AA
#define COLOR_RED 0xAA3333AA
#define COLOR_LIGHTRED 0xFF6347AA
#define COLOR_LIGHTBLUE 0x01FCFFC8
#define COLOR_LIGHTGREEN 0x9ACD32AA
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_YELLOW2 0xF5DEB3AA
#define COLOR_WHITE 0xFFFFFFAA
#define COLOR_FADE1 0xE6E6E6E6
#define COLOR_FADE2 0xC8C8C8C8
#define COLOR_FADE3 0xAAAAAAAA
#define COLOR_FADE4 0x8C8C8C8C
#define COLOR_FADE5 0x6E6E6E6E
#define COLOR_PURPLE 0xC2A2DAAA
#define COLOR_INVIS 0xAFAFAF00
#define COLOR_SPEC 0xBFC0C200
#define COLOR_GREY 0xAFAFAFAA
#define COLOR_RED 0xAA3333AA
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_PINK 0xFF66FFAA
#define COLOR_BLUE 0x0000BBAA
#define COLOR_WHITE 0xFFFFFFAA
#define COLOR_DARKRED 0x660000AA
#define COLOR_ORANGE 0xFF9900AA
#define COLOR_BRIGHTRED 0xFF0000AA
#define COLOR_INDIGO 0x4B00B0AA
#define COLOR_VIOLET 0x9955DEEE
#define COLOR_LIGHTRED 0xFF6347AA
#define COLOR_SEAGREEN 0x00EEADDF
#define COLOR_GRAYWHITE 0xEEEEFFC4
#define COLOR_LIGHTNEUTRALBLUE 0xabcdef66
#define COLOR_GREENISHGOLD 0xCCFFDD56
#define COLOR_LIGHTBLUEGREEN 0x0FFDD349
#define COLOR_NEUTRALBLUE 0xABCDEF01
#define COLOR_LIGHTCYAN 0xAAFFCC33
#define COLOR_LEMON 0xDDDD2357
#define COLOR_MEDIUMBLUE 0x63AFF00A
#define COLOR_NEUTRAL 0xABCDEF97
#define COLOR_BLACK 0x00000000
#define COLOR_NEUTRALGREEN 0x81CFAB00
#define COLOR_DARKGREEN 0x12900BBF
#define COLOR_DARKBLUE 0x300FFAAB
#define COLOR_BLUEGREEN 0x46BBAA00
#define COLOR_PINK 0xFF66FFAA
#define COLOR_DARKRED 0x660000AA
#define COLOR_ORANGE 0xFF9900AA
#define COLOR_PURPLE 0xC2A2DAAA
#define COLOR_GRAD1 0xB4B5B7FF
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_RED1 0xFF0000AA
#define COLOR_GREY 0xAFAFAFAA
#define COLOR_GREEN 0x33AA33AA
#define COLOR_RED 0xAA3333AA
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_WHITE 0xFFFFFFAA
#define COLOR_BROWN 0x993300AA
#define COLOR_CYAN 0x99FFFFAA
#define COLOR_TAN 0xFFFFCCAA
#define COLOR_PINK 0xFF66FFAA
#define COLOR_KHAKI 0x999900AA
#define COLOR_LIME 0x99FF00AA
#define COLOR_SYSTEM 0xEFEFF7AA
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_GRAD4 0xD8D8D8FF
#define COLOR_GRAD6 0xF0F0F0FF
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_GRAD3 0xCBCCCEFF
#define COLOR_GRAD5 0xE3E3E3FF
#define COLOR_GRAD1 0xB4B5B7FF
#define COLOR_AQUA 0x33CCFFAA
#define COLOR_GRAD1 0xB4B5B7FF
#define COLOR_GRAD2 0xBFC0C2FF
#define COLOR_GRAD3 0xCBCCCEFF
#define COLOR_GRAD4 0xD8D8D8FF
#define COLOR_GRAD5 0xE3E3E3FF
#define COLOR_GRAD6 0xF0F0F0FF



#define TOTAL_ITEMS         207
#define SELECTION_ITEMS 	21
#define ITEMS_PER_LINE  	7

#define HEADER_TEXT "Vehicles"
#define NEXT_TEXT   "Next"
#define PREV_TEXT   "Prev"

#define DIALOG_BASE_X   	75.0
#define DIALOG_BASE_Y   	130.0
#define DIALOG_WIDTH    	550.0
#define DIALOG_HEIGHT   	180.0
#define SPRITE_DIM_X    	60.0
#define SPRITE_DIM_Y    	70.0



#define forEx(%0,%1) for(new %1=0;%1<%0;%1++)
 
//______________________________________________________________________________
#pragma unused TuneVehicleRandomly


//0HIDE

	
#define Loop:<%0,%1>    \
		for( new %0; %0 < %1; %0++)

/*
	With this definition you cannot be bugged while hiding.
	Keeping it uncommented will remove the object each time
	you are not crouching using OnPlayerUpdate
	
	Comment this if you are experiencing any lag from the script.
*/
	#define PERFECTION
/*

*/
new
	bool:Activated[MAX_PLAYERS char],
	Hidden[MAX_PLAYERS char],
	CurrentObject[MAX_PLAYERS char]
;
enum
	e_objects
	{
		o_id,		o_n[15],	o_b,
		Float:o_x,	Float:o_y,	Float:o_z,
		Float:o_rx,	Float:o_ry,	Float:o_rz,
		Float:o_sx,	Float:o_sy,	Float:o_sz
	}

enum
	e_dialogs
	{
	    Empty = 5555,
	    List = 5556
	}

new
	ObjectInfo[33][e_objects] =
	{
	    {1221, "箱子 1", 11, 0.331851, -0.387647, 0.108080, 62.871932, 3.603914, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1220, "箱子 2",11, 0.331851, -0.387647, 0.108080, 62.871932, 3.603914, 279.105468, 1.500000, 1.500000, 1.500000},
	    {2912, "箱子 3", 10, -0.117735, -0.402220, -0.766344, 356.370971, 357.288360, 5.631556, 1.500000, 1.600000, 1.500000},
	    {964, "槍械箱子", 11, 0.180357, 0.045067, -0.323517, 63.705467, 4.868588, 165.003601, 1.000000, 1.000000, 1.299999},
	    {1271, "木頭箱子", 11, 0.316308, -0.396371, 0.129949, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1367, "信箱 1", 11, 0.230588, -0.647528, 0.151942, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1291, "信箱 2", 11, 0.285487, -0.645864, 0.129949, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {800, "草 1", 11, 0.366527, -0.542696, -0.005478, 35.919593, 8.222164, 141.222518, 0.432692, 0.400000, 0.400000},
	    {823, "草 2", 11, 0.366527, -0.542696, -0.005478, 60.612785, 10.375102, 165.003601, 0.312109, 0.300000, 0.300000},
	    {824, "草 3", 11, 0.366527, -0.542696, -0.005478, 60.612785, 10.375102, 165.003601, 0.312109, 0.300000, 0.300000},
	    {825, "草 4", 11, 0.366527, -0.542696, -0.005478, 60.612785, 10.375102, 165.003601, 0.312109, 0.300000, 0.300000},
	    {754, "仙人掌 1", 11, 0.312796, 0.180289, -0.285668, 63.705467, 4.868588, 165.003601, 1.200027, 1.252762, 2.480148},
	    {653, "仙人掌 2", 11, -0.121614, 0.075794, -0.285668, 63.705467, 4.868588, 165.003601, 0.800000, 0.800000, 0.800000},
	    {831, "树桩", 11, 0.366527, -0.542696, -0.005478, 60.612785, 10.375102, 165.003601, 0.600000, 0.600000, 0.600000},
	    {1370, "液化氣罐", 11, 0.230588, -0.647528, 0.151942, 63.663352, 5.211647, 103.045799, 1.500000, 1.500000, 1.500000},
	    {1371, "河馬", 11, 0.230588, -0.647528, 0.151942, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1225, "桶 1", 11, 0.331851, -0.387647, 0.108080, 62.871932, 3.603914, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1222, "桶 2", 11, 0.331851, -0.387647, 0.108080, 62.871932, 3.603914, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1218, "桶 3", 11, 0.331851, -0.387647, 0.108080, 62.871932, 3.603914, 279.105468, 1.500000, 1.500000, 1.5000},
	    {1217, "桶 4", 11, 0.331851, -0.387647, 0.108080, 62.871932, 3.603914, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1362, "桶 5", 11, 0.230588, -0.647528, 0.151942, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1347, "垃圾桶", 11, 0.230588, -0.647528, 0.151942, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1339, "桶 1", 11, 0.230588, -0.647528, 0.151942, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1337, "桶 2", 11, 0.230588, -0.647528, 0.151942, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1330, "垃圾桶 1", 11, 0.285487, -0.587944, 0.121327, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1329, "垃圾桶 2", 11, 0.285487, -0.645864, 0.129949, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1328, "垃圾桶 3", 11, 0.285487, -0.645864, 0.129949, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1264, "垃圾袋", 11, 0.331851, -0.534445, -0.022953, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1237, "桶", 11, 0.331851, 0.015704, -0.173188, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1208, "洗衣機", 11, 0.292449, 0.018611, -0.236802, 64.272399, 6.367418, 97.481346, 1.500000, 1.500000, 1.500000},
	    {1304, "石頭 1", 11, 0.285487, -0.645864, 0.129949, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1303, "石頭 2", 11, 0.285487, -0.645864, 0.129949, 65.029396, 4.721271, 279.105468, 1.500000, 1.500000, 1.500000},
	    {1305, "石頭 3", 11, 0.285487, -0.645864, 0.129949, 65.029396, 4.721271, 279.105468, 0.800000, 0.800000, 0.800000}
	};
	
	
	

stock GetWeaponIDFromModel(weaponid)
{
	switch(weaponid)
	{
	    case 331: return 1;
	    case 333: return 12;
	    case 334: return 3;
	    case 335: return 4;
	    case 336: return 5;
	    case 337: return 6;
	    case 338: return 7;
	    case 339: return 8;
	    case 341: return 9;
	    case 321: return 10;
	    case 322: return 11;
	    case 323: return 12;
	    case 324: return 13;
	    case 325: return 14;
	    case 326: return 15;
	    case 342: return 16;
	    case 343: return 17;
	    case 344: return 18;
	    case 346: return 22;
	    case 347: return 23;
	    case 348: return 24;
	    case 349: return 25;
	    case 350: return 26;
	    case 351: return 27;
	    case 352: return 28;
	    case 353: return 29;
	    case 355: return 30;
	    case 356: return 31;
	    case 372: return 32;
	    case 357: return 33;
	    case 358: return 34;
	    case 360: return 36;
	    case 361: return 37;
	    case 362: return 38;
	    case 363: return 39;
	    case 364: return 40;
	    case 365: return 41;
	    case 366: return 42;
	    case 367: return 43;
	    case 368: return 44;
	    case 369: return 45;
	    case 371: return 46;
	}
	return 0;
}

new aVehicleNames[212][] =
{
	{"Landstalker"},
	{"Bravura"},
	{"Buffalo"},
	{"Linerunner"},
	{"Perrenial"},
	{"Sentinel"},
	{"Dumper"},
	{"Firetruck"},
	{"Trashmaster"},
	{"Stretch"},
	{"Manana"},
	{"Infernus"},
	{"Voodoo"},
	{"Pony"},
	{"Mule"},
	{"Cheetah"},
	{"Ambulance"},
	{"Leviathan"},
	{"Moonbeam"},
	{"Esperanto"},
	{"Taxi"},
	{"Washington"},
	{"Bobcat"},
	{"Mr Whoopee"},
	{"BF Injection"},
	{"Hunter"},
	{"Premier"},
	{"Enforcer"},
	{"Securicar"},
	{"Banshee"},
	{"Predator"},
	{"Bus"},
	{"Rhino"},
	{"Barracks"},
	{"Hotknife"},
	{"Trailer 1"},
	{"Previon"},
	{"Coach"},
	{"Cabbie"},
	{"Stallion"},
	{"Rumpo"},
	{"RC Bandit"},
	{"Romero"},
	{"Packer"},
	{"Monster"},
	{"Admiral"},
	{"Squalo"},
	{"Seasparrow"},
	{"Pizzaboy"},
	{"Tram"},
	{"Trailer 2"},
	{"Turismo"},
	{"Speeder"},
	{"Reefer"},
	{"Tropic"},
	{"Flatbed"},
	{"Yankee"},
	{"Caddy"},
	{"Solair"},
	{"Berkley's RC Van"},
	{"Skimmer"},
	{"PCJ-600"},
	{"Faggio"},
	{"Freeway"},
	{"RC Baron"},
	{"RC Raider"},
	{"Glendale"},
	{"Oceanic"},
	{"Sanchez"},
	{"Sparrow"},
	{"Patriot"},
	{"Quad"},
	{"Coastguard"},
	{"Dinghy"},
	{"Hermes"},
	{"Sabre"},
	{"Rustler"},
	{"ZR-350"},
	{"Walton"},
	{"Regina"},
	{"Comet"},
	{"BMX"},
	{"Burrito"},
	{"Camper"},
	{"Marquis"},
	{"Baggage"},
	{"Dozer"},
	{"Maverick"},
	{"News Chopper"},
	{"Rancher"},
	{"FBI Rancher"},
	{"Virgo"},
	{"Greenwood"},
	{"Jetmax"},
	{"Hotring"},
	{"Sandking"},
	{"Blista Compact"},
	{"Police Maverick"},
	{"Boxville"},
	{"Benson"},
	{"Mesa"},
	{"RC Goblin"},
	{"Hotring Racer A"},
	{"Hotring Racer B"},
	{"Bloodring Banger"},
	{"Rancher"},
	{"Super GT"},
	{"Elegant"},
	{"Journey"},
	{"Bike"},
	{"Mountain Bike"},
	{"Beagle"},
	{"Cropdust"},
	{"Stunt"},
	{"Tanker"},
	{"Roadtrain"},
	{"Nebula"},
	{"Majestic"},
	{"Buccaneer"},
	{"Shamal"},
	{"Hydra"},
	{"FCR-900"},
	{"NRG-500"},
	{"HPV1000"},
	{"Cement Truck"},
	{"Tow Truck"},
	{"Fortune"},
	{"Cadrona"},
	{"FBI Truck"},
	{"Willard"},
	{"Forklift"},
	{"Tractor"},
	{"Combine"},
	{"Feltzer"},
	{"Remington"},
	{"Slamvan"},
	{"Blade"},
	{"Freight"},
	{"Streak"},
	{"Vortex"},
	{"Vincent"},
	{"Bullet"},
	{"Clover"},
	{"Sadler"},
	{"Firetruck LA"},
	{"Hustler"},
	{"Intruder"},
	{"Primo"},
	{"Cargobob"},
	{"Tampa"},
	{"Sunrise"},
	{"Merit"},
	{"Utility"},
	{"Nevada"},
	{"Yosemite"},
	{"Windsor"},
	{"Monster A"},
	{"Monster B"},
	{"Uranus"},
	{"Jester"},
	{"Sultan"},
	{"Stratum"},
	{"Elegy"},
	{"Raindance"},
	{"RC Tiger"},
	{"Flash"},
	{"Tahoma"},
	{"Savanna"},
	{"Bandito"},
	{"Freight Flat"},
	{"Streak Carriage"},
	{"Kart"},
	{"Mower"},
	{"Duneride"},
	{"Sweeper"},
	{"Broadway"},
	{"Tornado"},
	{"AT-400"},
	{"DFT-30"},
	{"Huntley"},
	{"Stafford"},
	{"BF-400"},
	{"Newsvan"},
	{"Tug"},
	{"Trailer 3"},
	{"Emperor"},
	{"Wayfarer"},
	{"Euros"},
	{"Hotdog"},
	{"Club"},
	{"Freight Carriage"},
	{"Trailer 3"},
	{"Andromada"},
	{"Dodo"},
	{"RC Cam"},
	{"Launch"},
	{"Police Car (LSPD)"},
	{"Police Car (SFPD)"},
	{"Police Car (LVPD)"},
	{"Police Ranger"},
	{"Picador"},
	{"S.W.A.T. Van"},
	{"Alpha"},
	{"Phoenix"},
	{"Glendale"},
	{"Sadler"},
	{"Luggage Trailer A"},
	{"Luggage Trailer B"},
	{"Stair Trailer"},
	{"Boxville"},
	{"Farm Plow"},
	{"Utility Trailer"}
};

new	playerColors[500] = {
	-8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513,
	-2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585,
	-32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945,
	16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433,
	-16744193, -8339201, -8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201,
	-8323073, -2130771713, 16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713,
	16728319, -8355585, -32513, -2130738945, 16744703, -2130706433, -16744193, -8339201, -8323073, -2130771713, 16728319
};

new aWeaponNames[][32] = {
	{"Unarmed (Fist)"}, // 0
	{"Brass Knuckles"}, // 1
	{"Golf Club"}, // 2
	{"Night Stick"}, // 3
	{"Knife"}, // 4
	{"Baseball Bat"}, // 5
	{"Shovel"}, // 6
	{"Pool Cue"}, // 7
	{"Katana"}, // 8
	{"Chainsaw"}, // 9
	{"Purple Dildo"}, // 10
	{"Big White Vibrator"}, // 11
	{"Medium White Vibrator"}, // 12
	{"Small White Vibrator"}, // 13
	{"Flowers"}, // 14
	{"Cane"}, // 15
	{"Grenade"}, // 16
	{"Teargas"}, // 17
	{"Molotov"}, // 18
	{" "}, // 19
	{" "}, // 20
	{" "}, // 21
	{"Colt 45"}, // 22
	{"Colt 45 (Silenced)"}, // 23
	{"Desert Eagle"}, // 24
	{"Normal Shotgun"}, // 25
	{"Sawnoff Shotgun"}, // 26
	{"Combat Shotgun"}, // 27
	{"Micro Uzi (Mac 10)"}, // 28
	{"MP5"}, // 29
	{"AK47"}, // 30
	{"M4"}, // 31
	{"Tec9"}, // 32
	{"Country Rifle"}, // 33
	{"Sniper Rifle"}, // 34
	{"Rocket Launcher"}, // 35
	{"Heat-Seeking Rocket Launcher"}, // 36
	{"Flamethrower"}, // 37
	{"Minigun"}, // 38
	{"Satchel Charge"}, // 39
	{"Detonator"}, // 40
	{"Spray Can"}, // 41
	{"Fire Extinguisher"}, // 42
	{"Camera"}, // 43
	{"Night Vision Goggles"}, // 44
	{"Infrared Vision Goggles"}, // 45
	{"Parachute"}, // 46
	{"Fake Pistol"} // 47
};
//Evalator Settings ===========================
#define ELEVATOR_SPEED      (5.0)   // Movement speed of the elevator.
#define DOORS_SPEED         (5.0)   // Movement speed of the doors.
#define ELEVATOR_WAIT_TIME  (5000)  // Time in ms that the elevator will wait in each floor before continuing with the queue.
									// Be sure to give enough time for doors to open.

#define DIALOG_ELEVATOR           (874)

// Private:
#define X_DOOR_CLOSED       (1786.627685)
#define X_DOOR_R_OPENED     (1785.027685)
#define X_DOOR_L_OPENED     (1788.227685)
#define GROUND_Z_COORD      (14.511476)
#define ELEVATOR_OFFSET     (0.059523)

/* ------------------
// Constants:
-------------------*/
static FloorNames[21][] =
{
    "大厅",
	"LV1",
	"LV2",
	"LV3",
	"LV4",
	"LV5",
	"LV6",
	"LV7",
	"LV8",
	"LV9",
	"LV10",
	"LV11",
	"LV12",
	"LV13",
	"LV14",
	"LV15",
	"LV16",
	"LV17[Office]",
	"LV18[赌场]",
	"LV19[总部办公室]",
	"LV20[顶楼]"
};

static Float:FloorZOffsets[21] =
{
    0.0,		// 0.0,
    8.5479,		// 8.5479,
    13.99945,   // 8.5479 + (5.45155 * 1.0),
    19.45100,   // 8.5479 + (5.45155 * 2.0),
    24.90255,   // 8.5479 + (5.45155 * 3.0),
    30.35410,   // 8.5479 + (5.45155 * 4.0),
    35.80565,   // 8.5479 + (5.45155 * 5.0),
    41.25720,   // 8.5479 + (5.45155 * 6.0),
    46.70875,   // 8.5479 + (5.45155 * 7.0),
    52.16030,   // 8.5479 + (5.45155 * 8.0),
    57.61185,   // 8.5479 + (5.45155 * 9.0),
    63.06340,   // 8.5479 + (5.45155 * 10.0),
    68.51495,   // 8.5479 + (5.45155 * 11.0),
    73.96650,   // 8.5479 + (5.45155 * 12.0),
    79.41805,   // 8.5479 + (5.45155 * 13.0),
    84.86960,   // 8.5479 + (5.45155 * 14.0),
    90.32115,   // 8.5479 + (5.45155 * 15.0),
    95.77270,   // 8.5479 + (5.45155 * 16.0),
    101.22425,  // 8.5479 + (5.45155 * 17.0),
    106.67580,	// 8.5479 + (5.45155 * 18.0),
    112.12735	// 8.5479 + (5.45155 * 19.0)
};

/* ------------------
// Variables:
-------------------*/
new Obj_Elevator, Obj_ElevatorDoors[2],
	Obj_FloorDoors[21][2];

new Text3D:Label_Elevator, Text3D:Label_Floors[21];

#define ELEVATOR_STATE_IDLE     (0)
#define ELEVATOR_STATE_WAITING  (1)
#define ELEVATOR_STATE_MOVING   (2)

new ElevatorState,
	ElevatorFloor;  // If Idle or Waiting, this is the current floor. If Moving, the floor it's moving to.

#define INVALID_FLOOR           (-1)

new ElevatorQueue[21],  	// Floors in queue.
	FloorRequestedBy[21];   // FloorRequestedBy[floor_id] = playerid; - Points out who requested which floor.

new ElevatorBoostTimer;     // Timer that makes the elevator move faster after players start surfing the object.

/* ------------------
*  Function forwards:
-------------------*/
// Public:
forward CallElevator(playerid, floorid);    // You can use INVALID_PLAYER_ID too.
forward ShowElevatorDialog(playerid);

// Private:
forward Elevator_Initialize();
forward Elevator_Destroy();

forward Elevator_OpenDoors();
forward Elevator_CloseDoors();
forward Floor_OpenDoors(floorid);
forward Floor_CloseDoors(floorid);

forward Elevator_MoveToFloor(floorid);
forward Elevator_Boost(floorid);        	// Increases the elevator speed until it reaches 'floorid'.
forward Elevator_TurnToIdle();

forward ReadNextFloorInQueue();
forward RemoveFirstQueueFloor();
forward AddFloorToQueue(floorid);
forward IsFloorInQueue(floorid);
forward ResetElevatorQueue();

forward DidPlayerRequestElevator(playerid);

forward Float:GetElevatorZCoordForFloor(floorid);
forward Float:GetDoorsZCoordForFloor(floorid);


IsNumeric(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}



//------------------------------------------------


Load3DTextLabels(){
	Create3DTextLabel("欢迎来到拍摄现场",0xFFFFFFFF,1699.5048,1431.4244,16.00,40,0);
	Create3DTextLabel("程序开发:Episodes",0xFFFF00FF,1699.5048,1431.4244,15.5029,40,0);
	Create3DTextLabel("技术支持:GTAYY",0xFFFF00FF,1699.5048,1431.4244,15.00,40,0);
	Create3DTextLabel("网站:www.easy-mp.co.cc",0xFFFF00FF,1699.5048,1431.4244,14.50,40,0);
	Create3DTextLabel("请输入/help 查看基本的命令",0xFF0000FF,1699.5048,1431.4244,14.00,40,0);
	//-------------------------------------------------------------------------------------
	Create3DTextLabel("GTAIP-电影拍摄世界",0x00FF00FF,1477.8623,-1668.2054,23.00,40,0);
	Create3DTextLabel("[出生地]",0xFFFF00FF,1477.8623,-1668.2054,22.50,40,0);
    //Create3DTextLabel("[IP]:mov.gtaun.net:4444",0x00CDFFFF,1477.8623,-1668.2054,22.00,40,0);
	Create3DTextLabel("需要帮助请输入/help",0xFF0000FF,1477.8623,-1668.2054,21.50,40,0);
    //-------------------------------------------------------------------------------------
	Create3DTextLabel("拍摄现场1.0[经典出生地]",0xFFFF00AA,917.5461,-1221.1047,25.63,20,0,1);
	Create3DTextLabel("服务器汉化者:Jeffery",0xFFFFFFAA,917.5461,-1221.1047,25.3,20,0,1);
	Create3DTextLabel("服务器制作者Episodes",0xFFFFFFAA,917.5461,-1221.1047,24.83,20,0,1);
	Create3DTextLabel("技术提供：GTA-YY",0xFFFFFFAA,917.5461,-1221.1047,24.63,20,0,1);
	Create3DTextLabel("---------------------",0xAA3333AA,917.5461,-1221.1047,24.43,20,0,1);
	Create3DTextLabel("输入/help查看帮助",0xFF6347AA,917.5461,-1221.1047,24.23,20,0,1);
	//-------------------------------------------------------------------------------------
	Create3DTextLabel("私人机场",0x00FF00FF,178.0179,-4200.6860,7.00,40,0);
	Create3DTextLabel("[出生地]",0xFFFF00FF,178.0179,-4200.6860,6.50,40,0);
	Create3DTextLabel("需要帮助请输入/help",0xFF0000FF,178.0179,-4200.6860,6.00,40,0);
    //--------------------------------------------------------------------------------------
	Create3DTextLabel("GTA-IP 自由/拍摄现场(Miku)",0x00FF00FF,1212.6550,-2041.4308,69.0078,40,0);
	Create3DTextLabel("[出生地]",0xFFFF00FF,1212.8279,-2032.8019,68.9984,40,0);
	Create3DTextLabel("需要帮助请输入/help",0xFF0000FF,1217.2535,-2033.0454,67.3203,40,0);
	//--------------------------------------------------------------------------------------
	
	Create3DTextLabel("新拍摄现场2.6",0x00FF00FF,1824.6461,-1302.6840,111.0,40,0);
	Create3DTextLabel("[出生地]",0xFFFF00FF,1824.6461,-1302.6840,110.5,40,0);
	Create3DTextLabel("需要帮助请输入/help",0xFF0000FF,1824.6461,-1302.6840,110.0,40,0);

	Create3DTextLabel("-->下楼这边走-->",0x0080FFFF,1824.5540,-1288.2131,109.3594,20,0);
	Create3DTextLabel("<--下楼这边走<--",0x808000FF,1812.5935,-1285.1497,109.3594,20,0);
	Create3DTextLabel("-->下楼这边走-->",0xFF8080FF,1798.2651,-1300.6011,109.3594,20,0);
	Create3DTextLabel("↓在此乘坐电梯↓",0xFFFF00FF,1783.8798,-1300.7666,112.3594,20,0);
}




stock LoadStaticVehiclesFromFile(const filename[])
{
	new File:file_ptr;
	new line[256];
	new var_from_line[64];
	new vehicletype;
	new Float:SpawnX;
	new Float:SpawnY;
	new Float:SpawnZ;
	new Float:SpawnRot;
    new Color1, Color2;
	new index;
	new vehicles_loaded;

	file_ptr = fopen(filename,filemode:io_read);
	if(!file_ptr) return 0;

	vehicles_loaded = 0;

	while(fread(file_ptr,line,256) > 0)
	{
	    index = 0;

	    // Read type
  		index = token_by_delim(line,var_from_line,',',index);
  		if(index == (-1)) continue;
  		vehicletype = strval(var_from_line);
   		if(vehicletype < 400 || vehicletype > 611) continue;

  		// Read X, Y, Z, Rotation
  		index = token_by_delim(line,var_from_line,',',index+1);
  		if(index == (-1)) continue;
  		SpawnX = floatstr(var_from_line);

  		index = token_by_delim(line,var_from_line,',',index+1);
  		if(index == (-1)) continue;
  		SpawnY = floatstr(var_from_line);

  		index = token_by_delim(line,var_from_line,',',index+1);
  		if(index == (-1)) continue;
  		SpawnZ = floatstr(var_from_line);

  		index = token_by_delim(line,var_from_line,',',index+1);
  		if(index == (-1)) continue;
  		SpawnRot = floatstr(var_from_line);

  		// Read Color1, Color2
  		index = token_by_delim(line,var_from_line,',',index+1);
  		if(index == (-1)) continue;
  		Color1 = strval(var_from_line);

  		index = token_by_delim(line,var_from_line,';',index+1);
  		Color2 = strval(var_from_line);

  		//printf("%d,%d,%f,%f,%f,%f,%d,%d",total_vehicles_from_files+vehicles_loaded+1,vehicletype,SpawnX,SpawnY,SpawnZ,SpawnRot,Color1,Color2);

		AddStaticVehicleEx(vehicletype,SpawnX,SpawnY,SpawnZ,SpawnRot,Color1,Color2,(30*60)); // respawn 30 minutes
		vehicles_loaded++;
	}

	fclose(file_ptr);
	printf("Loaded %d vehicles from: %s",vehicles_loaded,filename);
	return vehicles_loaded;
}
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

stock ToggleTagName(playerid, toggle)
{
	Loop:<I, MAX_PLAYERS>
	{
	    if(I != INVALID_PLAYER_ID)
	    {
	    	ShowPlayerNameTagForPlayer(I, playerid, toggle);
	    }
	}
}
stock StealthMode(playerid)
{
	Hidden{playerid} = true;
	ToggleTagName(playerid, 0);
	
    SetPlayerColor(playerid, GetPlayerColor(playerid) - (GetPlayerColor(playerid) & 0x000000FF) - 255);
	
	SetPlayerAttachedObject
 	(
		playerid,
		0,
		ObjectInfo[CurrentObject{playerid}][o_id],
		ObjectInfo[CurrentObject{playerid}][o_b],
		ObjectInfo[CurrentObject{playerid}][o_x],
		ObjectInfo[CurrentObject{playerid}][o_y],
		ObjectInfo[CurrentObject{playerid}][o_z],
		ObjectInfo[CurrentObject{playerid}][o_rx],
		ObjectInfo[CurrentObject{playerid}][o_ry],
		ObjectInfo[CurrentObject{playerid}][o_rz],
		ObjectInfo[CurrentObject{playerid}][o_sx],
		ObjectInfo[CurrentObject{playerid}][o_sy],
		ObjectInfo[CurrentObject{playerid}][o_sz]
	);
}
stock PlaySoundForPlayersInRange(soundid, Float:range, Float:x, Float:y, Float:z)
{
	for(new i=0; i<MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i) && IsPlayerInRangeOfPoint(i,range,x,y,z))
	    {
		    PlayerPlaySound(i, soundid, x, y, z);
	    }
	}
}

stock RevealPlayer(playerid, toggle = 1)
{
    Hidden{playerid} = false;
	SetPlayerColor(playerid, GetPlayerColor(playerid) - (GetPlayerColor(playerid) & 0x000000FF) + 255);
	RemovePlayerAttachedObject(playerid, 0);
	ToggleTagName(playerid, toggle);
}
stock ShowContent()
{
	new Content[512];

	strcat(Content, "{94ED40}0Hide - Stealthy Filterscript V2{FFFFFF}\n\n", 512);
	strcat(Content, "Created by {94ED40}Zh3r0{FFFFFF} on {94ED40}17 June{FFFFFF}\n", 512);
	strcat(Content, "Type {94ED40}/hide{FFFFFF} to activate/deactivate the stealth mode.!\n", 512);
	strcat(Content, "Type {94ED40}/hideo{FFFFFF} and choose your hiding object!\n\n", 512);
	strcat(Content, "(C)Zh3r0 - Keep the credits");

	return Content;
}
stock GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
		new Float:a;
		GetPlayerPos(playerid, x, y, a);
		GetPlayerFacingAngle(playerid, a);
		if (GetPlayerVehicleID(playerid))
		{
			GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
		}
		x += (distance * floatsin(-a, degrees));
		y += (distance * floatcos(-a, degrees));
}

stock Elevator_Initialize()
{
	// Initializes the elevator.

	Obj_Elevator 			= CreateObject(18755, 1786.678100, -1303.459472, GROUND_Z_COORD + ELEVATOR_OFFSET, 0.000000, 0.000000, 270.000000);
	Obj_ElevatorDoors[0] 	= CreateObject(18757, X_DOOR_CLOSED, -1303.459472, GROUND_Z_COORD, 0.000000, 0.000000, 270.000000);
	Obj_ElevatorDoors[1] 	= CreateObject(18756, X_DOOR_CLOSED, -1303.459472, GROUND_Z_COORD, 0.000000, 0.000000, 270.000000);

	Label_Elevator          = Create3DTextLabel("{CCCCCC}按下 '{FFFFFF}~k~~CONVERSATION_YES~{CCCCCC}' 按电梯", 0xCCCCCCAA, 1784.9822, -1302.0426, 13.6491, 4.0, 0, 1);

	new string[128],
		Float:z;

	for(new i; i < sizeof(Obj_FloorDoors); i ++)
	{
	    Obj_FloorDoors[i][0] 	= CreateObject(18757, X_DOOR_CLOSED, -1303.171142, GetDoorsZCoordForFloor(i), 0.000000, 0.000000, 270.000000);
		Obj_FloorDoors[i][1] 	= CreateObject(18756, X_DOOR_CLOSED, -1303.171142, GetDoorsZCoordForFloor(i), 0.000000, 0.000000, 270.000000);

		format(string, sizeof(string), "{CCCCCC}[%s]\n{CCCCCC}按下 '{FFFFFF}~k~~CONVERSATION_YES~{CCCCCC}' 按电梯", FloorNames[i]);

		if(i == 0)
		    z = 13.4713;
		else
		    z = 13.4713 + 8.7396 + ((i-1) * 5.45155);

		Label_Floors[i]         = Create3DTextLabel(string, 0xCCCCCCAA, 1783.9799, -1300.7660, z, 10.5, 0, 1);
		// Label_Elevator, Text3D:Label_Floors[21];
	}

	// Open ground floor doors:
	Floor_OpenDoors(0);
	Elevator_OpenDoors();

	return 1;
}

stock Elevator_Destroy()
{
	// Destroys the elevator.

	DestroyObject(Obj_Elevator);
	DestroyObject(Obj_ElevatorDoors[0]);
	DestroyObject(Obj_ElevatorDoors[1]);
	Delete3DTextLabel(Label_Elevator);

	for(new i; i < sizeof(Obj_FloorDoors); i ++)
	{
	    DestroyObject(Obj_FloorDoors[i][0]);
		DestroyObject(Obj_FloorDoors[i][1]);
		Delete3DTextLabel(Label_Floors[i]);
	}

	return 1;
}

stock Elevator_OpenDoors()
{
	// Opens the elevator's doors.

	new Float:x, Float:y, Float:z;

	GetObjectPos(Obj_ElevatorDoors[0], x, y, z);
	MoveObject(Obj_ElevatorDoors[0], X_DOOR_L_OPENED, y, z, DOORS_SPEED);
	MoveObject(Obj_ElevatorDoors[1], X_DOOR_R_OPENED, y, z, DOORS_SPEED);

	return 1;
}

stock Elevator_CloseDoors()
{
    // Closes the elevator's doors.

    if(ElevatorState == ELEVATOR_STATE_MOVING)
	    return 0;

    new Float:x, Float:y, Float:z;

	GetObjectPos(Obj_ElevatorDoors[0], x, y, z);
	MoveObject(Obj_ElevatorDoors[0], X_DOOR_CLOSED, y, z, DOORS_SPEED);
	MoveObject(Obj_ElevatorDoors[1], X_DOOR_CLOSED, y, z, DOORS_SPEED);

	return 1;
}

stock Floor_OpenDoors(floorid)
{
    // Opens the doors at the specified floor.

    MoveObject(Obj_FloorDoors[floorid][0], X_DOOR_L_OPENED, -1303.171142, GetDoorsZCoordForFloor(floorid), DOORS_SPEED);
	MoveObject(Obj_FloorDoors[floorid][1], X_DOOR_R_OPENED, -1303.171142, GetDoorsZCoordForFloor(floorid), DOORS_SPEED);
	
	PlaySoundForPlayersInRange(6401, 50.0, X_DOOR_CLOSED, -1303.171142, GetDoorsZCoordForFloor(floorid) + 5.0);

	return 1;
}

stock Floor_CloseDoors(floorid)
{
    // Closes the doors at the specified floor.

    MoveObject(Obj_FloorDoors[floorid][0], X_DOOR_CLOSED, -1303.171142, GetDoorsZCoordForFloor(floorid), DOORS_SPEED);
	MoveObject(Obj_FloorDoors[floorid][1], X_DOOR_CLOSED, -1303.171142, GetDoorsZCoordForFloor(floorid), DOORS_SPEED);
	
	PlaySoundForPlayersInRange(6401, 50.0, X_DOOR_CLOSED, -1303.171142, GetDoorsZCoordForFloor(floorid) + 5.0);

	return 1;
}

stock Elevator_MoveToFloor(floorid)
{
	// Moves the elevator to specified floor (doors are meant to be already closed).

	ElevatorState = ELEVATOR_STATE_MOVING;
	ElevatorFloor = floorid;

	// Move the elevator slowly, to give time to clients to sync the object surfing. Then, boost it up:
	MoveObject(Obj_Elevator, 1786.678100, -1303.459472, GetElevatorZCoordForFloor(floorid), 0.25);
    MoveObject(Obj_ElevatorDoors[0], X_DOOR_CLOSED, -1303.459472, GetDoorsZCoordForFloor(floorid), 0.25);
    MoveObject(Obj_ElevatorDoors[1], X_DOOR_CLOSED, -1303.459472, GetDoorsZCoordForFloor(floorid), 0.25);
    Delete3DTextLabel(Label_Elevator);

	ElevatorBoostTimer = SetTimerEx("Elevator_Boost", 2000, 0, "i", floorid);

	return 1;
}

public Elevator_Boost(floorid)
{
	// Increases the elevator's speed until it reaches 'floorid'
	StopObject(Obj_Elevator);
	StopObject(Obj_ElevatorDoors[0]);
	StopObject(Obj_ElevatorDoors[1]);
	
	MoveObject(Obj_Elevator, 1786.678100, -1303.459472, GetElevatorZCoordForFloor(floorid), ELEVATOR_SPEED);
    MoveObject(Obj_ElevatorDoors[0], X_DOOR_CLOSED, -1303.459472, GetDoorsZCoordForFloor(floorid), ELEVATOR_SPEED);
    MoveObject(Obj_ElevatorDoors[1], X_DOOR_CLOSED, -1303.459472, GetDoorsZCoordForFloor(floorid), ELEVATOR_SPEED);

	return 1;
}

public Elevator_TurnToIdle()
{
	ElevatorState = ELEVATOR_STATE_IDLE;
	ReadNextFloorInQueue();

	return 1;
}

stock RemoveFirstQueueFloor()
{
	// Removes the data in ElevatorQueue[0], and reorders the queue accordingly.

	for(new i; i < sizeof(ElevatorQueue) - 1; i ++)
	    ElevatorQueue[i] = ElevatorQueue[i + 1];

	ElevatorQueue[sizeof(ElevatorQueue) - 1] = INVALID_FLOOR;

	return 1;
}

stock AddFloorToQueue(floorid)
{
 	// Adds 'floorid' at the end of the queue.

	// Scan for the first empty space:
	new slot = -1;
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    if(ElevatorQueue[i] == INVALID_FLOOR)
	    {
	        slot = i;
	        break;
	    }
	}

	if(slot != -1)
	{
	    ElevatorQueue[slot] = floorid;

     	// If needed, move the elevator.
	    if(ElevatorState == ELEVATOR_STATE_IDLE)
	        ReadNextFloorInQueue();

	    return 1;
	}

	return 0;
}

stock ResetElevatorQueue()
{
	// Resets the queue.

	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    ElevatorQueue[i] 	= INVALID_FLOOR;
	    FloorRequestedBy[i] = INVALID_PLAYER_ID;
	}

	return 1;
}

stock IsFloorInQueue(floorid)
{
	// Checks if the specified floor is currently part of the queue.

	for(new i; i < sizeof(ElevatorQueue); i ++)
	    if(ElevatorQueue[i] == floorid)
	        return 1;

	return 0;
}

stock ReadNextFloorInQueue()
{
	// Reads the next floor in the queue, closes doors, and goes to it.

	if(ElevatorState != ELEVATOR_STATE_IDLE || ElevatorQueue[0] == INVALID_FLOOR)
	    return 0;

	Elevator_CloseDoors();
	Floor_CloseDoors(ElevatorFloor);

	return 1;
}

stock DidPlayerRequestElevator(playerid)
{
	for(new i; i < sizeof(FloorRequestedBy); i ++)
	    if(FloorRequestedBy[i] == playerid)
	        return 1;

	return 0;
}

stock ShowElevatorDialog(playerid)
{
	new string[512];
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    if(FloorRequestedBy[i] != INVALID_PLAYER_ID)
	        strcat(string, "{FF0000}");

	    strcat(string, FloorNames[i]);
	    strcat(string, "\n");
	}

	ShowPlayerDialog(playerid, DIALOG_ELEVATOR, DIALOG_STYLE_LIST, "电梯", string, "选择", "关闭");

	return 1;
}

stock CallElevator(playerid, floorid)
{
	// Calls the elevator (also used with the elevator dialog).

	if(FloorRequestedBy[floorid] != INVALID_PLAYER_ID || IsFloorInQueue(floorid))
	    return 0;

	FloorRequestedBy[floorid] = playerid;
	AddFloorToQueue(floorid);

	return 1;
}

stock Float:GetElevatorZCoordForFloor(floorid)
    return (GROUND_Z_COORD + FloorZOffsets[floorid] + ELEVATOR_OFFSET); // A small offset for the elevator object itself.

stock Float:GetDoorsZCoordForFloor(floorid)
	return (GROUND_Z_COORD + FloorZOffsets[floorid]);
//Radom Tun Vechicle

TuneVehicleRandomly(VehicleID)
{
    new Tuningpart[36],Tick=0,Model=GetVehicleModel(VehicleID);
    for(new i=999;i<1194;i++){if(i>=1000&&i<=1993&&GetVehicleUpgrade(Model,i)){Tuningpart[Tick]=i;Tick++;}}
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[0],Tuningpart[1],Tuningpart[2],Tuningpart[3],Tuningpart[4],Tuningpart[5]));
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[6],Tuningpart[7],Tuningpart[8],Tuningpart[9],Tuningpart[0]));
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[11],Tuningpart[12],Tuningpart[13],Tuningpart[14],Tuningpart[15]));
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[16],Tuningpart[17],Tuningpart[18],Tuningpart[19],Tuningpart[20]));
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[20],Tuningpart[21],Tuningpart[22],Tuningpart[23],Tuningpart[24]));
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[26],Tuningpart[27],Tuningpart[28],Tuningpart[29],Tuningpart[30]));
    AddVehicleComponent(VehicleID,randomEx(Tuningpart[30],Tuningpart[31],Tuningpart[32],Tuningpart[33],Tuningpart[34],Tuningpart[35]));
    ChangeVehicleColor(VehicleID,randomEx(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,28,32,41,42,43,44,45,46,47,48,49,50,123,124,125,126,130,131,132,142,144,146,147,148,149,150,141,128,129,130,131,132,142,144,145,1146,147,148,149,150,151,160,165,166,181,182,183,184,185,186,255,252),
    randomEx(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,28,32,41,42,43,44,45,46,47,48,49,50,123,124,125,126,130,131,132,142,144,146,147,148,149,150,141,128,129,130,131,132,142,144,145,1146,147,148,149,150,151,160,165,166,181,182,183,184,185,186,255,252));
    return 1;
}
 
//______________________________________________________________________________
GetVehicleUpgrade(VehicleModel,ComponentID){
        switch(VehicleModel){case 400:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}
                                case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 401:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}
                        }}case 404:{switch(ComponentID){
                                case 1000:{return 1;}case 1002:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1016:{return 1;}case 1017:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}
                                case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 405:{switch(ComponentID){
                                case 1000:{return 1;}case 1001:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1014:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 410:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1023:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}
                                case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 415:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}
                                case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 418:{switch(ComponentID){
                                case 1002:{return 1;}case 1006:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1016:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}
                                case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 420:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1019:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}
                                case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 421:{switch(ComponentID){
                                case 1000:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1014:{return 1;}case 1016:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 422:{switch(ComponentID){
                                case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}
                                case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 426:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1019:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}
                                case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 436:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1022:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 439:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}
                                case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 477:{switch(ComponentID){
                                case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}
                                case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 478:{switch(ComponentID){
                                case 1004:{return 1;}case 1005:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1012:{return 1;}case 1013:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1022:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 489:{switch(ComponentID){
                                case 1000:{return 1;}case 1002:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1016:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}
                                case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}
                                case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 491:{switch(ComponentID){
                                case 1003:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1014:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}
                                case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 492:{switch(ComponentID){
                                case 1000:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1016:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}
                                case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 496:{switch(ComponentID){
                                case 1001:{return 1;}case 1002:{return 1;}case 1003:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1011:{return 1;}case 1017:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}
                        }}case 500:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}
                                case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 516:{switch(ComponentID){
                                case 1000:{return 1;}case 1002:{return 1;}case 1004:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1015:{return 1;}case 1016:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}
                                case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 517:{switch(ComponentID){
                                case 1002:{return 1;}case 1003:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1016:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}
                                case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 518:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 527:{switch(ComponentID){
                                case 1001:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1014:{return 1;}case 1015:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 529:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1011:{return 1;}case 1012:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}
                                case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 534:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                                case 1100:{return 1;}case 1101:{return 1;}case 1106:{return 1;}case 1122:{return 1;}case 1123:{return 1;}case 1124:{return 1;}case 1125:{return 1;}case 1126:{return 1;}case 1127:{return 1;}case 1178:{return 1;}case 1179:{return 1;}case 1180:{return 1;}case 1185:{return 1;}
                        }}case 535:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                                case 1109:{return 1;}case 1110:{return 1;}case 1113:{return 1;}case 1114:{return 1;}case 1115:{return 1;}case 1116:{return 1;}case 1117:{return 1;}case 1118:{return 1;}case 1119:{return 1;}case 1120:{return 1;}case 1121:{return 1;}
                        }}case 536:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                                case 1103:{return 1;}case 1104:{return 1;}case 1105:{return 1;}case 1107:{return 1;}case 1108:{return 1;}case 1128:{return 1;}case 1181:{return 1;}case 1182:{return 1;}case 1183:{return 1;}case 1184:{return 1;}
                        }}case 540:{switch(ComponentID){
                                case 1001:{return 1;}case 1004:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 542:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1014:{return 1;}case 1015:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}
                                case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 546:{switch(ComponentID){
                                case 1001:{return 1;}case 1002:{return 1;}case 1004:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1023:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 547:{switch(ComponentID){
                                case 1000:{return 1;}case 1003:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1016:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}
                                case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}
                        }}case 549:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1011:{return 1;}case 1012:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 550:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}
                                case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 551:{switch(ComponentID){
                                case 1002:{return 1;}case 1003:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1016:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1021:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 558:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1088:{return 1;}case 1089:{return 1;}case 1090:{return 1;}
                                case 1091:{return 1;}case 1092:{return 1;}case 1093:{return 1;}case 1094:{return 1;}case 1095:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1163:{return 1;}case 1164:{return 1;}case 1165:{return 1;}case 1166:{return 1;}case 1167:{return 1;}case 1168:{return 1;}
                        }}case 559:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1065:{return 1;}case 1066:{return 1;}case 1067:{return 1;}case 1068:{return 1;}case 1069:{return 1;}case 1070:{return 1;}case 1071:{return 1;}case 1072:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1158:{return 1;}case 1159:{return 1;}case 1160:{return 1;}case 1161:{return 1;}case 1162:{return 1;}case 1173:{return 1;}
                        }}case 560:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1026:{return 1;}case 1027:{return 1;}case 1028:{return 1;}case 1029:{return 1;}case 1030:{return 1;}case 1031:{return 1;}case 1032:{return 1;}case 1033:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1138:{return 1;}case 1139:{return 1;}case 1140:{return 1;}case 1141:{return 1;}case 1169:{return 1;}case 1170:{return 1;}
                        }}case 561:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1055:{return 1;}case 1056:{return 1;}case 1057:{return 1;}case 1058:{return 1;}case 1059:{return 1;}case 1060:{return 1;}case 1061:{return 1;}case 1062:{return 1;}case 1063:{return 1;}case 1064:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1154:{return 1;}case 1155:{return 1;}case 1156:{return 1;}case 1157:{return 1;}
                        }}case 562:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1034:{return 1;}case 1035:{return 1;}case 1036:{return 1;}case 1037:{return 1;}case 1038:{return 1;}case 1039:{return 1;}case 1040:{return 1;}case 1041:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}
                                case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1146:{return 1;}case 1147:{return 1;}case 1148:{return 1;}case 1149:{return 1;}case 1171:{return 1;}case 1172:{return 1;}
                        }}case 565:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1045:{return 1;}case 1046:{return 1;}case 1047:{return 1;}case 1048:{return 1;}case 1049:{return 1;}case 1050:{return 1;}case 1051:{return 1;}case 1052:{return 1;}case 1053:{return 1;}case 1054:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1150:{return 1;}case 1151:{return 1;}case 1152:{return 1;}case 1153:{return 1;}
                        }}case 567:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                                case 1102:{return 1;}case 1129:{return 1;}case 1130:{return 1;}case 1131:{return 1;}case 1132:{return 1;}case 1133:{return 1;}case 1186:{return 1;}case 1187:{return 1;}case 1188:{return 1;}case 1189:{return 1;}
                        }}case 575:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1042:{return 1;}case 1043:{return 1;}case 1044:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}
                                case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1099:{return 1;}case 1174:{return 1;}case 1175:{return 1;}case 1176:{return 1;}case 1177:{return 1;}
                        }}case 576:{switch(ComponentID){
                                case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                                case 1134:{return 1;}case 1135:{return 1;}case 1136:{return 1;}case 1137:{return 1;}case 1190:{return 1;}case 1191:{return 1;}case 1192:{return 1;}case 1193:{return 1;}
                        }}case 580:{switch(ComponentID){
                                case 1001:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}
                                case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 585:{switch(ComponentID){
                                case 1001:{return 1;}case 1003:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}
                                case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 589:{switch(ComponentID){
                                case 1000:{return 1;}case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1016:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1020:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}
                                case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}case 600:{switch(ComponentID){
                                case 1004:{return 1;}case 1005:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1013:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1020:{return 1;}case 1022:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}
                                case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
                        }}case 603:{switch(ComponentID){
                                case 1001:{return 1;}case 1006:{return 1;}case 1007:{return 1;}case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1017:{return 1;}case 1018:{return 1;}case 1019:{return 1;}case 1020:{return 1;}case 1023:{return 1;}case 1024:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}
                                case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}case 1142:{return 1;}case 1143:{return 1;}case 1144:{return 1;}case 1145:{return 1;}
                        }}default:{
                        switch(ComponentID){case 1008:{return 1;}case 1009:{return 1;}case 1010:{return 1;}case 1025:{return 1;}case 1073:{return 1;}case 1074:{return 1;}case 1075:{return 1;}case 1076:{return 1;}case 1077:{return 1;}case 1078:{return 1;}case 1079:{return 1;}case 1080:{return 1;}case 1081:{return 1;}case 1082:{return 1;}case 1083:{return 1;}case 1084:{return 1;}case 1085:{return 1;}case 1087:{return 1;}case 1096:{return 1;}case 1097:{return 1;}case 1098:{return 1;}
        }}}return 0;
}
randomEx(...)return getarg(random(numargs()));