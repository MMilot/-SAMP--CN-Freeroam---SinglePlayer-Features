//字符串转色处理函数 BY GTAYY
#include <a_samp>

stock strcolorcn(const string[])
{
    new color[][][] =//这里添加对因的颜色查询字符
    {
        {"*red","{F81414}"},
        {"*green","{6EF83C}"},
        {"*blue","{0049FF}"},
        {"*white","{FFFFFF}"},
        {"*yellow","{FFFA00}"},
        {"*pink","{FF00F5}"},
        {"*lightblue","{00CDFF}"},
        {"*lightgreen","{00FFE6}"}

        //添加如上在这里    //你可以这样 {"*red","{0049FF}"}
    };
	new tmp[256];
	new address;
	format(tmp,sizeof(tmp),"%s",string);
	for(new i = 0; i < sizeof(color); i++)
	{
	    while((address = strfind(tmp, color[i][0], false)) != -1)
	    {
	        strdel(tmp,address,address+strlen(color[i][0]));
	        strins(tmp,color[i][1],address);
	    }
	}
	return tmp;
}
