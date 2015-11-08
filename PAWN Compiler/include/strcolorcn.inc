//字符串转色处理函数 BY GTAYY
#include <a_samp>

stock strcolorcn(const string[])
{
    new color[][][] =//这里添加对因的颜色查询字符
    {
        {"*红色","{F81414}"},
        {"*绿色","{6EF83C}"},
        {"*蓝色","{0049FF}"},
        {"*白色","{FFFFFF}"},
        {"*黄色","{FFFA00}"},
        {"*粉色","{FF00F5}"},
        {"*淡蓝色","{00CDFF}"},
        {"*淡绿色","{00FFE6}"}

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
