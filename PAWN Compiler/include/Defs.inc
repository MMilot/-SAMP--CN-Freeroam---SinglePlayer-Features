//============================defines================================/

#define SKIN_SELECT   	true
#define	VEHI_SELECT   	true
#define WORL_SELECT     true
#define CAME_SELECT     true
#define OBJE_SELECT	true
#define CCOL_SELECT     true

#define MISCEL_CMDS     true
#define ADMINS_ONLY     false

#define SKIN_SEL_STAT   1
#define VEHI_SEL_STAT   2
#define WORL_SEL_STAT   3
#define CAME_SEL_STAT   4
#define OBJE_SEL_STAT	5
#define CCOL_SEL_STAT   6

#define COLOR_RED   	0xFF4040FF
#define COLOR_GREEN 	0x40FF40FF
#define COLOR_BLUE  	0x4040FFFF
#define COLOR_PURPLE    0xC2A2DAAA

#define COLOR_CYAN  	0x40FFFFFF
#define COLOR_PINK  	0xFF40FFFF
#define COLOR_YELLOW    0xFFFF40FF

#define COLOR_WHITE	0xFFFFFFFF
#define COLOR_BLACK	0x000000FF
#define COLOR_NONE      0x00000000

#define MIN_SKIN_ID		0
#define MAX_SKIN_ID		299

#define MIN_VEHI_ID		400
#define MAX_VEHI_ID		611

#define MIN_TIME_ID		0
#define MAX_TIME_ID		23

#define MIN_WEAT_ID     	0
#define MAX_WEAT_ID		45

#define MIN_OBJE_ID		615
#define MAX_OBJE_ID		13563

#define VEHI_DIS        	5.0
#define OBJE_DIS		10.0

#define CMODE_A			0
#define CMODE_B			1

#define O_MODE_SELECTOR	0
#define O_MODE_MOVER	1
#define O_MODE_ROTATOR	2

#define CAMERA_TIME     40

#define INTERIORMENU 1500

#define dcmd(%1,%2,%3) if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1
