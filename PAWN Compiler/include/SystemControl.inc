/*
System Control Plugin by jhonyxakep
Mail:jhonyxakep@qip.ru
ICQ:354794596
Jabber:jhonyxakep@qip.ru
*/

#include <a_samp>


/* Definitions of useful mathematical constants
 * M_E        - e
 * M_LOG2E    - log2(e)
 * M_LOG10E   - log10(e)
 * M_LN2      - ln(2)
 * M_LN10     - ln(10)
 * M_PI       - pi
 * M_PI_2     - pi/2
 * M_PI_4     - pi/4
 * M_1_PI     - 1/pi
 * M_2_PI     - 2/pi
 * M_2_SQRTPI - 2/sqrt(pi)
 * M_SQRT2    - sqrt(2)
 * M_SQRT1_2  - 1/sqrt(2)
 */
#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

//Show Params
#define SW_HIDE             0
#define SW_SHOWNORMAL       1
#define SW_NORMAL           1
#define SW_SHOWMINIMIZED    2
#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_SHOWNOACTIVATE   4
#define SW_SHOW             5
#define SW_MINIMIZE         6
#define SW_SHOWMINNOACTIVE  7
#define SW_SHOWNA           8
#define SW_RESTORE          9
#define SW_SHOWDEFAULT      10
#define SW_FORCEMINIMIZE    11
#define SW_MAX              11


//Natives
/*
WinExec - Runs the specified application.

If the function succeeds, the return value is greater than 31.

Example:
WinExec("notepad.exe",SW_NORMAL); //Run Notepad

For more info: http://msdn.microsoft.com/en-us/library/windows/desktop/ms687393(v=vs.85).aspx
*/

native WinExec(file[],ShowParam); //WinExec Function

/*
Sleep - Suspends the execution of the current thread until the time-out interval elapses.


Example:
Sleep(1000); //One second delay

For more info: http://msdn.microsoft.com/en-us/library/windows/desktop/ms686298(v=vs.85).aspx
*/

native Sleep(milliseconds); //Sleep Function

/*
GetCursorPos - Retrieves the cursor's position, in screen coordinates.


Example:
new x, y;
GetCursorPos(x,y); //x,y contain cursor position

For more info: http://msdn.microsoft.com/en-us/library/windows/desktop/ms648390(v=vs.85).aspx
*/

native GetCurPosX(); 
native GetCurPosY(); 


stock GetCursorPos(&x,&y)    //GetCursorPos Function
{
x =  GetCurPosX();
y =  GetCurPosY();
}

/*
GetAudioURLFileLengthSec/GetAudioURLFileLengthBytes - Retrieves the audio stream length from URL in seconds/bytes

Returns -1 if radio stream


Example:
GetAudioURLFileLengthSec("http://listen.radio-mixer.ru:8000/DNB"); //Radio length. Returns -1
GetAudioURLFileLengthSec("http://upload.wikimedia.org/wikipedia/ru/4/4d/Omen.ogg");  //OGG stream length 35 sec (Prodigy-Omen)

BASS library based function.
*/

native GetAudioURLFileLengthSec(URL[]); 
native GetAudioURLFileLengthBytes(URL[]); 

/*
system - Run the specified application in self thread.

Function return process exit code.

C system function eqialent

Example:
system("CLS");//Clear console window in Windows

For more info: http://www.cplusplus.com/reference/clibrary/cstdlib/system/
*/

native system(file[]); 

/*
ClearConsole - clear console window.

Using "CLS" command for windows, "clear" for *nix enviroment.

Example:
ClearConsole();//Clear console window


*/
native ClearConsole(); 

/*
ListDirs, ListFiles - list all files, subdirectories from dir.

Callbacks:
OnListDir(dir[]) - called if directory founded
OnListFile(file[]) - called if file founded



*/

native ListDirs(path[]); 
native ListFiles(path[]); 

forward OnListDir(dir[]);
forward OnListFile(file[]);