/* 实现对话框现场保护功能
 * 作者:GOD
 * 注意: 调用此函数库
 *		'public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])'将无法使用
 * 需	'public OnDialogResponseEx(playerid, dialogid, response, listitem, inputtext[])' 替代使用
 * 使用'ShowPlayerDialogEx'创建被保护的对话框
 * 'ShowPlayerDialog'创建的对话框不受保护
 */
 
/*
native ShowPlayerDialogEx(playerid, dialogid, style, caption[], info[], button1[], button2[])
*/

#if defined dialog_stack_included
	#endinput
#endif
#define dialog_stack_included

stock ShowPlayerDialogEx(playerid, dialogid, style, caption[], info[], button1[], button2[]) {//PUSH
	new tmp[64], SP_DIALOG = GetPVarInt(playerid, "SP_DIALOG");
	SetPVarInt(playerid, "SP_DIALOG", ++SP_DIALOG);
	
	format(tmp, sizeof(tmp), "ex_dialogid_%d", SP_DIALOG);
	SetPVarInt(playerid, tmp, dialogid);
	format(tmp, sizeof(tmp), "ex_style_%d", SP_DIALOG);
	SetPVarInt(playerid, tmp, style);
	format(tmp, sizeof(tmp), "ex_caption_%d", SP_DIALOG);
	SetPVarString(playerid, tmp, caption);
	format(tmp, sizeof(tmp), "ex_info_%d", SP_DIALOG);
	SetPVarString(playerid, tmp, info);
	format(tmp, sizeof(tmp), "ex_button1_%d", SP_DIALOG);
	SetPVarString(playerid, tmp, button1);
	format(tmp, sizeof(tmp), "ex_button2_%d", SP_DIALOG);
	SetPVarString(playerid, tmp, button2);

	//printf("[push]%d", SP_DIALOG);

	return ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
}

PopPlayerDialog(playerid) {//POP
    new tmp[64], SP_DIALOG = GetPVarInt(playerid, "SP_DIALOG");
	if (SP_DIALOG == 0) return;
	//Release
	format(tmp, sizeof(tmp), "ex_dialogid_%d", SP_DIALOG);
	DeletePVar(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_style_%d", SP_DIALOG);
	DeletePVar(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_caption_%d", SP_DIALOG);
	DeletePVar(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_info_%d", SP_DIALOG);
	DeletePVar(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_button1_%d", SP_DIALOG);
	DeletePVar(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_button2_%d", SP_DIALOG);
	DeletePVar(playerid, tmp);

    //printf("[pop]%d", SP_DIALOG);

	new dialogid, style, caption[64], info[640], button1[64], button2[64];
    SetPVarInt(playerid, "SP_DIALOG", --SP_DIALOG);
    if (SP_DIALOG == 0) return;
    
	//show prev
	format(tmp, sizeof(tmp), "ex_dialogid_%d", SP_DIALOG);
	dialogid = GetPVarInt(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_style_%d", SP_DIALOG);
	style = GetPVarInt(playerid, tmp);
	format(tmp, sizeof(tmp), "ex_caption_%d", SP_DIALOG);
	GetPVarString(playerid, tmp, caption, sizeof(caption));
	format(tmp, sizeof(tmp), "ex_info_%d", SP_DIALOG);
	GetPVarString(playerid, tmp, info, sizeof(info));
	format(tmp, sizeof(tmp), "ex_button1_%d", SP_DIALOG);
	GetPVarString(playerid, tmp, button1, sizeof(button1));
	format(tmp, sizeof(tmp), "ex_button2_%d", SP_DIALOG);
	GetPVarString(playerid, tmp, button2, sizeof(button2));
    ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    PopPlayerDialog(playerid);
	return OnDialogResponseEx(playerid, dialogid, response, listitem, inputtext);
}

forward OnDialogResponseEx(playerid, dialogid, response, listitem, inputtext[]);