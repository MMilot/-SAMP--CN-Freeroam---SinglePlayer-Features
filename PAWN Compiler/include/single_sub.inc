/*
								The MIT License  
								
	Copyright (c) 2015 JavaSparrow Project
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
	=====================================
	<Single_sub.inc>
	This is the libary that handles all the subtites and texdraw acted like in
	single player.
	Developer:Episodes
	=====================================   
*/	

#include <a_samp>
#include <YSI\y_hooks>
new PlayerText:PCommon[MAX_PLAYERS];
new PlayerText:PCSub[MAX_PLAYERS];
//new TdelyTimer[MAX_PLAYERS];


hook OnPlayerConnect(playerid)
{
	//Sub 
	PCommon[playerid] = CreatePlayerTextDraw(playerid, 20.333337, 117.392578, "This is the sample Text");
	PlayerTextDrawLetterSize(playerid, PCommon[playerid],0.453666, 2.010666);
	PlayerTextDrawTextSize(playerid, PCommon[playerid], 216.999969, 141.451797);
	PlayerTextDrawAlignment(playerid, PCommon[playerid], 1);
	PlayerTextDrawColor(playerid, PCommon[playerid], 0xC0C0C0FF);
	PlayerTextDrawUseBox(playerid, PCommon[playerid], true);
	PlayerTextDrawBoxColor(playerid, PCommon[playerid], 255);
	PlayerTextDrawSetShadow(playerid, PCommon[playerid], 2);
	PlayerTextDrawSetOutline(playerid, PCommon[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PCommon[playerid], 51);
	PlayerTextDrawFont(playerid, PCommon[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PCommon[playerid], 1);
	//TextDraw
	PCSub[playerid] = CreatePlayerTextDraw(playerid, 396.666595, 343.051971, "This is the area that will be used to display ~r~subtitles~w~.");
	PlayerTextDrawLetterSize(playerid, PCSub[playerid],0.453666, 2.010666);
	PlayerTextDrawAlignment(playerid, PCSub[playerid], 2);
	PlayerTextDrawColor(playerid, PCSub[playerid], -1);
	PlayerTextDrawSetShadow(playerid, PCSub[playerid], 2);
	PlayerTextDrawSetOutline(playerid, PCSub[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, PCSub[playerid], 255);
	PlayerTextDrawFont(playerid, PCSub[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PCSub[playerid], 1);

}

hook OnPlayerDisconnect(playerid,reason)
{
	PlayerTextDrawDestroy(playerid,PCSub[playerid]);
	PlayerTextDrawDestroy(playerid,PCommon[playerid]);
	
}


stock SG_Textbox(playerid,string[],time)
{
	PlayerTextDrawSetString(playerid,PCommon[playerid],string);
	PlayerTextDrawShow(playerid,PCommon[playerid]);
	SetTimerEx("TextboxDistoryTimer",time, false, "d", playerid);

}

forward TextboxDistoryTimer(playerid);
public TextboxDistoryTimer(playerid)
{
	PlayerTextDrawHide(playerid,PCommon[playerid]);


}
forward TextSubDistoryTimer(playerid);
public TextSubDistoryTimer(playerid)
{
	PlayerTextDrawHide(playerid,PCSub[playerid]);

}


stock SG_Sub(playerid,string[],time)
{
	PlayerTextDrawSetString(playerid,PCSub[playerid],string);
	PlayerTextDrawShow(playerid,PCSub[playerid]);
	SetTimerEx("TextSubDistoryTimer",time, false, "d", playerid);
}




