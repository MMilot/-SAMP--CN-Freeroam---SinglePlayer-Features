/*
								The MIT License  
								
	Copyright (c) <2010> <yezizhu>  
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:  

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.  
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.  
	==================================
	��Ȩ(c) <2010> <yezizhu>  

	ʹ�ø�����֤����������������Ȩ�ޣ���ѣ��κ��˿��Եõ����������������ĵ���һ��������
	���Ҿ�Ӫ�����������κ����ƣ����������Ƶ�ʹ�á����ơ��޸ġ��ϲ������桢���С����Ŵ���֤�顢���߳��۸������Ŀ�����Ȩ����
	ͬʱ���������Щ�������û�������ЩȨ����ʹ����������������  
	
	���ϵİ�Ȩ֪ͨ��Ȩ��֪ͨӦ�ð��������и������Ŀ����л�������������������ʵ�����С�
	
	�������������������ṩ��û���κ���ʽ�ĵ�������������ȷ�ػ��߰����ģ�������Щ���ǲ�����ҵ���ʵĵ��������ơ�
	�ʺ�һ���ض�����;���Ҳ����ַ������ߺͰ�Ȩ���������κγ��϶�ʹ�ø������漰���κ�Ҫ���𺦻����������ζ���Ӧ����
	�����������������û���ֻ�Ǻ�ͬ��ʽ��������Ȩ����������ʽ�������������������÷�Χ�ڡ������������ϵ����������ʹ�û�����������������������Ϊ��  
	=====================================   
*/	


#if defined _gcs_streamer_object_included
	#endinput
#endif
#define _gcs_streamer_object_included
#pragma library gcs_streamer_object



#define MAX_OBJECTS				(3000)
#define OBJECT_DISTANCE			(220)
#define MAX_DYM_OBJECTS			(240)
#define INVALID_DYM_OBJECT_ID	(-1)


enum e_gcs_object{
	e_gcs_object_modelid,
	Float:e_gcs_object_ox,
	Float:e_gcs_object_oy,
	Float:e_gcs_object_oz,
	Float:e_gcs_object_rx,
	Float:e_gcs_object_ry,
	Float:e_gcs_object_rz
}

static
	gcs_objects[MAX_OBJECTS][e_gcs_object],
	gcs_objAmount;

stock gcs_obj_GetUnusedSlot(){
	new
		objAmount = -1;
	for(new i;i < MAX_OBJECTS;i++){
		if(!gcs_objects[i][e_gcs_object_modelid]){
			objAmount = i;
		}
	}
	if(objAmount == -1){
		print("Warning:Objects overload");
		SendClientMessageToAll(0,"Warning:Objects overload");
		return MAX_OBJECTS-1;
	}
	return objAmount;
}
	
stock gcs_obj_Create(om,Float:ox,Float:oy,Float:oz,Float:rx,Float:ry,Float:rz){
	new
		id = gcs_obj_GetUnusedSlot();
	gcs_objects[id][om] = om;
	gcs_objects[id][ox] = ox;
	gcs_objects[id][oy] = oy;
	gcs_objects[id][oz] = oz;
	gcs_objects[id][rx] = rx;
	gcs_objects[id][ry] = ry;
	gcs_objects[id][rz] = rz;
	return id;
}

forward gcs_obj_Stream();
public gcs_obj_Stream(){
	new
		tmpval[36]��
		Float:cx,Float:cy,Float:cz,
		objid,
		Float:distance
	for(new playerid;playerid < MAX_PLAYERS;playerid++){
		if(IsPlayerConnected(playerid)){
			GetPlayerCameraPos(playerid,cx,cy,cz);
			for(new i;i < MAX_DYM_OBJECTS;i++){
				format(tmpval,sizeof(tmpval),"gcs_obj_oid_%d",i);
				objid = GetPVarInt(playerid,tmpval);
				if(objid != INVALID_DYM_OBJ_ID){
					distance = getDisBetweenPoints(cx,cy,cz,gcs_objects[id][ox],gcs_objects[id][oy],gcs_objects[id][oz]);
					
				}





gcs_obj_playerConnect(playerid){
	new
		tmpval[36];
	for(new i;i < MAX_DYM_OBJECTS;i++){
		format(tmpval,sizeof(tmpval),"gcs_obj_oid_%d",i);
		SetPVarInt(playerid,tmpval,INVALID_DYM_OBJECT_ID);
	}
}








