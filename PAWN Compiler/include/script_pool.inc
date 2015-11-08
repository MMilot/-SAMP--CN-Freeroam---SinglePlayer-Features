#include <a_samp>
#include <YSI\y_hooks>
#include <physics>
#define MAX_GAME 100
#define GAME_ObjectFriction 0.08 // 游戏物体摩擦力设定
enum POOL_INFO
{
	bool:Taken,
	Float:X,
	Float:Y,
	Float:Z,
	Float:RX,
	Float:RY,
	Float:RZ,
	Float:PHY_WX,
	Float:PHY_WY,
	Float:PHY_WZ
}

new POOL[MAX_GAME][POOL_INFO];
enum BALL_INFO
{
	Handle,
	Float:X,
	Float:Y,
	Float:Z,
	Float:RX,
	Float:RY,
	Float:RZ,
}
new POOL_BALL[MAX_GAME][16][BALL_INFO];

/*
	创建桌球游戏
	参数:(X,Y,Z,RX,RY,RZ)
	返回:无
*/
forward SINGLE_PoolGameCreate(Float:x,Float:y,Float:z,Float:rx,Float:ry,Float:rz);
public SINGLE_PoolGameCreate(Float:x,Float:y,Float:z,Float:rx,Float:ry,Float:rz)
{	

	/* 
		OBJ 物体去理(非广义算法)
	*/
	//创建物理墙 
	PHY_CreateWall(1129.0635,-1440.5235,1129.0635,-1439.4765);
	PHY_CreateWall(1129.0635,-1440.5235,1130.9365,-1440.5235);
	PHY_CreateWall(1130.9365,-1439.4765,1130.9365,-1440.5235);
	PHY_CreateWall(1130.9365,-1439.4765,1129.0635,-1439.4765);
	
	//获取可用游戏ID
	new GameSlot = GetAvaiableGameSlotID();
	//创建球
	
	POOL_BALL[GameSlot][0][Handle] = CreateObject(3003, 510.11218261719, -84.40771484375, 998.86785888672, 0, 0, 0);//母球
    POOL_BALL[GameSlot][1][Handle] = CreateObject(3002, 510.10882568359, -85.166389465332, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][2][Handle] = CreateObject(3101, 510.14270019531, -85.232612609863, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][3][Handle] = CreateObject(2995, 510.0676574707, -85.232200622559, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][4][Handle] = CreateObject(2996, 510.18600463867, -85.295257568359, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][5][Handle] = CreateObject(3106, 510.11242675781, -85.297294616699, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][6][Handle] = CreateObject(3105, 510.03665161133, -85.299163818359, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][7][Handle] = CreateObject(3103, 510.22308349609, -85.362342834473, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][8][Handle] = CreateObject(3001, 510.14828491211, -85.365989685059, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][9][Handle] = CreateObject(3100, 510.07455444336, -85.365234375, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][10][Handle] = CreateObject(2997, 510.00054931641, -85.363563537598, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][11][Handle] = CreateObject(3000, 510.25915527344, -85.431137084961, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][12][Handle] = CreateObject(3102, 510.18399047852, -85.430549621582, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][13][Handle] = CreateObject(2999, 510.10900878906, -85.43196105957, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][14][Handle] = CreateObject(2998, 510.03570556641, -85.432624816895, 998.86749267578, 0, 0, 0);
    POOL_BALL[GameSlot][15][Handle] = CreateObject(3104, 509.96197509766, -85.427406311035, 998.86749267578, 0, 0, 0);
	//批处理物体碰撞加载
	   
	for(new i; i < sizeof POOL_BALL[][]; i++)
    {
        PHY_InitObject(POOL_BALL[GameSlot][15][Handle], 3003, _, _, PHY_MODE_2D); 
        PHY_SetObjectFriction(POOL_BALL[GameSlot][15][Handle],GAME_ObjectFriction);
        PHY_RollObject(POOL_BALL[GameSlot][15][Handle]);
	}
	
}

/*
	获取可用的槽位
	参数:无
	返回:可用的槽ID,如果全满则返回-1
*/
stock GetAvaiableGameSlotID()
{
	for(new i; i < MAX_GAME; i++)
    {
		if(!POOL[i][Taken]) return i;
	}
	return -1;
}