#define MAX_SNOW_OBJECTS    20
#define UPDATE_INTERVAL     750
#define MAX_SONGS           4
 
#undef MAX_PLAYERS
#define MAX_PLAYERS 50
 
//COLORS

 
#define V03c
 new
 
        Text:Textdraw0,   Text:Textdraw1,   Text:Textdraw2,
    Text:Textdraw3,       Text:Textdraw4,   Text:Textdraw5,
    Text:Textdraw6,       Text:Textdraw7,   Text:Textdraw8,
    Text:Textdraw9,       Text:Textdraw10,  Text:Textdraw11,
    Text:Textdraw12,  Text:Textdraw13,  Text:Textdraw14,
    Text:Textdraw15,  Text:Textdraw16,  Text:Textdraw17,
    Text:Textdraw19,  Text:Textdraw20,
 //   Float:TheX = 508.000000,
   //     Float:BoxY = 0.499999,
     //   gDirection,
       // gCount,
        bool:pLogo[MAX_PLAYERS];
 
 
forward LoadTextdraws();
forward HideLogo(playerid);
forward ShowLogo(playerid);
public LoadTextdraws(  )
{
 
        // Create the textdraws:
        Textdraw0 = TextDrawCreate(501.000000, 402.000000, "O");
        TextDrawBackgroundColor(Textdraw0, 255);
        TextDrawFont(Textdraw0, 1);
        TextDrawLetterSize(Textdraw0, 0.899999, 3.000000);
        TextDrawColor(Textdraw0, -1);
        TextDrawSetOutline(Textdraw0, 0);
        TextDrawSetProportional(Textdraw0, 1);
        TextDrawSetShadow(Textdraw0, 0);
 
        Textdraw1 = TextDrawCreate(521.000000, 412.000000, "~n~");
        TextDrawBackgroundColor(Textdraw1, 255);
        TextDrawFont(Textdraw1, 1);
        TextDrawLetterSize(Textdraw1, 2.099999, 0.499999);
        TextDrawColor(Textdraw1, -1);
        TextDrawSetOutline(Textdraw1, 0);
        TextDrawSetProportional(Textdraw1, 1);
        TextDrawSetShadow(Textdraw1, 1);
        TextDrawUseBox(Textdraw1, 1);
        TextDrawBoxColor(Textdraw1, -1);
        TextDrawTextSize(Textdraw1, 504.000000, 0.000000);
 
        Textdraw2 = TextDrawCreate(496.000000, 412.000000, "O");
        TextDrawBackgroundColor(Textdraw2, 255);
        TextDrawFont(Textdraw2, 1);
        TextDrawLetterSize(Textdraw2, 1.329998, 4.899999);
        TextDrawColor(Textdraw2, -1);
        TextDrawSetOutline(Textdraw2, 0);
        TextDrawSetProportional(Textdraw2, 1);
        TextDrawSetShadow(Textdraw2, 0);
 
        Textdraw3 = TextDrawCreate(527.000000, 429.000000, "~n~");
        TextDrawBackgroundColor(Textdraw3, 255);
        TextDrawFont(Textdraw3, 1);
        TextDrawLetterSize(Textdraw3, 2.099999, 1.400000);
        TextDrawColor(Textdraw3, -1);
        TextDrawSetOutline(Textdraw3, 0);
        TextDrawSetProportional(Textdraw3, 1);
        TextDrawSetShadow(Textdraw3, 1);
        TextDrawUseBox(Textdraw3, 1);
        TextDrawBoxColor(Textdraw3, -1);
        TextDrawTextSize(Textdraw3, 501.000000, -2.000000);
 
        Textdraw4 = TextDrawCreate(511.000000, 418.000000, ":");
        TextDrawBackgroundColor(Textdraw4, 255);
        TextDrawFont(Textdraw4, 1);
        TextDrawLetterSize(Textdraw4, 0.469999, 1.500000);
        TextDrawColor(Textdraw4, 255);
        TextDrawSetOutline(Textdraw4, 0);
        TextDrawSetProportional(Textdraw4, 1);
        TextDrawSetShadow(Textdraw4, 0);
 
        Textdraw5 = TextDrawCreate(550.000000, 427.000000, "O");
        TextDrawBackgroundColor(Textdraw5, 255);
        TextDrawFont(Textdraw5, 1);
        TextDrawLetterSize(Textdraw5, 2.029999, 4.899999);
        TextDrawColor(Textdraw5, -1);
        TextDrawSetOutline(Textdraw5, 0);
        TextDrawSetProportional(Textdraw5, 1);
        TextDrawSetShadow(Textdraw5, 0);
 
        Textdraw6 = TextDrawCreate(512.000000, 432.000000, "O");
        TextDrawBackgroundColor(Textdraw6, -1);
        TextDrawFont(Textdraw6, 1);
        TextDrawLetterSize(Textdraw6, 2.029999, 4.899999);
        TextDrawColor(Textdraw6, -1);
        TextDrawSetOutline(Textdraw6, 0);
        TextDrawSetProportional(Textdraw6, 1);
        TextDrawSetShadow(Textdraw6, -2);
 
        Textdraw7 = TextDrawCreate(553.000000, 433.000000, "O");
        TextDrawBackgroundColor(Textdraw7, 20);
        TextDrawFont(Textdraw7, 1);
        TextDrawLetterSize(Textdraw7, 2.029999, 4.899999);
        TextDrawColor(Textdraw7, -1);
        TextDrawSetOutline(Textdraw7, 0);
        TextDrawSetProportional(Textdraw7, 1);
        TextDrawSetShadow(Textdraw7, 0);
 
        Textdraw8 = TextDrawCreate(573.000000, 427.000000, "O");
        TextDrawBackgroundColor(Textdraw8, -1);
        TextDrawFont(Textdraw8, 1);
        TextDrawLetterSize(Textdraw8, 3.789998, 4.899999);
        TextDrawColor(Textdraw8, -1);
        TextDrawSetOutline(Textdraw8, 0);
        TextDrawSetProportional(Textdraw8, 1);
        TextDrawSetShadow(Textdraw8, 4);
 
        Textdraw9 = TextDrawCreate(500.000000, 405.000000, "O");
        TextDrawBackgroundColor(Textdraw9, 255);
        TextDrawFont(Textdraw9, 1);
        TextDrawLetterSize(Textdraw9, 0.949999, 0.799998);
        TextDrawColor(Textdraw9, 255);
        TextDrawSetOutline(Textdraw9, 1);
        TextDrawSetProportional(Textdraw9, 1);
 
        Textdraw10 = TextDrawCreate(527.000000, 406.000000, "~n~");
        TextDrawBackgroundColor(Textdraw10, 255);
        TextDrawFont(Textdraw10, 1);
        TextDrawLetterSize(Textdraw10, 0.500000, 0.099999);
        TextDrawColor(Textdraw10, -1);
        TextDrawSetOutline(Textdraw10, 0);
        TextDrawSetProportional(Textdraw10, 1);
        TextDrawSetShadow(Textdraw10, 1);
        TextDrawUseBox(Textdraw10, 1);
        TextDrawBoxColor(Textdraw10, 255);
        TextDrawTextSize(Textdraw10, 498.000000, 0.000000);
 
 
 
        Textdraw12 = TextDrawCreate(511.000000, 428.000000, ":");
        TextDrawBackgroundColor(Textdraw12, 255);
        TextDrawFont(Textdraw12, 1);
        TextDrawLetterSize(Textdraw12, 0.469999, 1.500000);
        TextDrawColor(Textdraw12, 255);
        TextDrawSetOutline(Textdraw12, 0);
        TextDrawSetProportional(Textdraw12, 1);
        TextDrawSetShadow(Textdraw12, 0);
 
        Textdraw13 = TextDrawCreate(512.000000, 420.000000, "/");
        TextDrawBackgroundColor(Textdraw13, 255);
        TextDrawFont(Textdraw13, 1);
        TextDrawLetterSize(Textdraw13, 0.449998, -0.399998);
        TextDrawColor(Textdraw13, -15466241);
        TextDrawSetOutline(Textdraw13, 0);
        TextDrawSetProportional(Textdraw13, 1);
        TextDrawSetShadow(Textdraw13, 0);
 
        Textdraw14 = TextDrawCreate(530.000000, 380.000000, ".     ~n~  .  .    .      . ~n~ .   .   .     . .  .~n~     .    . ~n~ .    .       .       . ~n~    .    .     .  . ~n~ .  .   ");
        TextDrawBackgroundColor(Textdraw14, -206);
        TextDrawFont(Textdraw14, 1);
        TextDrawLetterSize(Textdraw14, 0.330000, 0.999998);
        TextDrawColor(Textdraw14, -1);
        TextDrawSetOutline(Textdraw14, 0);
        TextDrawSetProportional(Textdraw14, 1);
        TextDrawSetShadow(Textdraw14, 10);
 
        Textdraw15 = TextDrawCreate(576.000000, 482.000000, ".     ~n~  .  .    .      . ~n~ .   .   .     . .  .~n~     .    . ~n~ .    .       .       . ~n~    .    .     .  . ~n~ .  .   ");
        TextDrawBackgroundColor(Textdraw15, -206);
        TextDrawFont(Textdraw15, 1);
        TextDrawLetterSize(Textdraw15, 0.330000, -1.000000);
        TextDrawColor(Textdraw15, -1);
        TextDrawSetOutline(Textdraw15, 0);
        TextDrawSetProportional(Textdraw15, 1);
        TextDrawSetShadow(Textdraw15, -60);
 
        Textdraw16 = TextDrawCreate(526.000000, 422.000000, "Merry Xmas!");
        TextDrawBackgroundColor(Textdraw16, -1);
        TextDrawFont(Textdraw16, 1);
        TextDrawLetterSize(Textdraw16, 0.430000, 2.000000);
        TextDrawColor(Textdraw16, -1);
        TextDrawSetOutline(Textdraw16, 0);
        TextDrawSetProportional(Textdraw16, 1);
        TextDrawSetShadow(Textdraw16, 0);
 
        Textdraw17 = TextDrawCreate(505.000000, 419.000000, "/");
        TextDrawBackgroundColor(Textdraw17, 255);
        TextDrawFont(Textdraw17, 1);
        TextDrawLetterSize(Textdraw17, -0.889999, 1.299998);
        TextDrawColor(Textdraw17, -1656160001);
        TextDrawSetOutline(Textdraw17, 0);
        TextDrawSetProportional(Textdraw17, 1);
        TextDrawSetShadow(Textdraw17, 0);
 
        Textdraw19 = TextDrawCreate(498.000000, 410.000000, "/");
        TextDrawBackgroundColor(Textdraw19, 255);
        TextDrawFont(Textdraw19, 1);
        TextDrawLetterSize(Textdraw19, -0.889999, 1.299998);
        TextDrawColor(Textdraw19, -1656160001);
        TextDrawSetOutline(Textdraw19, 0);
        TextDrawSetProportional(Textdraw19, 1);
        TextDrawSetShadow(Textdraw19, 0);
 
        Textdraw20 = TextDrawCreate(528.000000, 424.000000, "Merry Xmas!");
        TextDrawBackgroundColor(Textdraw20, -1);
        TextDrawFont(Textdraw20, 1);
        TextDrawLetterSize(Textdraw20, 0.409999, 1.700000);
        TextDrawColor(Textdraw20, 50);
        TextDrawSetOutline(Textdraw20, 0);
        TextDrawSetProportional(Textdraw20, 1);
        TextDrawSetShadow(Textdraw20, 0);
 
        Textdraw11 = TextDrawCreate(508.000000, 405.000000, "..");
        TextDrawBackgroundColor(Textdraw11, 255);
        TextDrawFont(Textdraw11, 1);
        TextDrawLetterSize(Textdraw11, 0.400000, 1.500000);
        TextDrawColor(Textdraw11, 255);
        TextDrawSetOutline(Textdraw11, 0);
        TextDrawSetProportional(Textdraw11, 0);
        TextDrawSetShadow(Textdraw11, 0);
 
        for(new i; i < MAX_PLAYERS; i ++)
        {
                if(IsPlayerConnected(i))
                {
                        HideLogo( i );
                }
        }
}
 
public ShowLogo( playerid )
{
    TextDrawShowForPlayer(playerid, Textdraw0);
    TextDrawShowForPlayer(playerid, Textdraw1);
    TextDrawShowForPlayer(playerid, Textdraw2);
    TextDrawShowForPlayer(playerid, Textdraw3);
    TextDrawShowForPlayer(playerid, Textdraw4);
    TextDrawShowForPlayer(playerid, Textdraw5);
    TextDrawShowForPlayer(playerid, Textdraw6);
    TextDrawShowForPlayer(playerid, Textdraw7);
    TextDrawShowForPlayer(playerid, Textdraw8);
    TextDrawShowForPlayer(playerid, Textdraw9);
    TextDrawShowForPlayer(playerid, Textdraw10);
    TextDrawShowForPlayer(playerid, Textdraw11);
    TextDrawShowForPlayer(playerid, Textdraw12);
    TextDrawShowForPlayer(playerid, Textdraw13);
    TextDrawShowForPlayer(playerid, Textdraw14);
    TextDrawShowForPlayer(playerid, Textdraw15);
    TextDrawShowForPlayer(playerid, Textdraw16);
    TextDrawShowForPlayer(playerid, Textdraw17);
    TextDrawShowForPlayer(playerid, Textdraw19);
    TextDrawShowForPlayer(playerid, Textdraw20);
}
public HideLogo( playerid )
{
    TextDrawHideForPlayer(playerid, Textdraw0);
    TextDrawHideForPlayer(playerid, Textdraw1);
    TextDrawHideForPlayer(playerid, Textdraw2);
    TextDrawHideForPlayer(playerid, Textdraw3);
    TextDrawHideForPlayer(playerid, Textdraw4);
    TextDrawHideForPlayer(playerid, Textdraw5);
    TextDrawHideForPlayer(playerid, Textdraw6);
    TextDrawHideForPlayer(playerid, Textdraw7);
    TextDrawHideForPlayer(playerid, Textdraw8);
    TextDrawHideForPlayer(playerid, Textdraw9);
    TextDrawHideForPlayer(playerid, Textdraw10);
    TextDrawHideForPlayer(playerid, Textdraw11);
    TextDrawHideForPlayer(playerid, Textdraw12);
    TextDrawHideForPlayer(playerid, Textdraw13);
    TextDrawHideForPlayer(playerid, Textdraw14);
    TextDrawHideForPlayer(playerid, Textdraw15);
    TextDrawHideForPlayer(playerid, Textdraw16);
    TextDrawHideForPlayer(playerid, Textdraw17);
    TextDrawHideForPlayer(playerid, Textdraw19);
    TextDrawHideForPlayer(playerid, Textdraw20);
}
 