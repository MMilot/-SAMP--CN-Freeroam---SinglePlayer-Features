new Params[4][8];
new FileData[7][128];

GetParams(Source[]){
	new Destination[256];
	new SLen=strlen(Source);
	new at,pos=0,tp=0;
	new tempo[256];

	format(Params[0],sizeof(Params),"");
	format(Params[1],sizeof(Params),"");
	format(Params[2],sizeof(Params),"");
	format(Params[3],sizeof(Params),"");


	for(at=pos;at<=SLen;at++){
		strmid(tempo,Source,at,at+1,sizeof(tempo));
		if(!strcmp(tempo,".",true)){
			if(tp<=10){
				strmid(Destination,Source,pos,at,sizeof(Destination));
				format(Params[tp][0],256,"%s",Destination);
				tp=tp+1;
			}
			pos=at+1;
		}
	}
	return 1;
}
GetFileData(Source[]){
	new Destination[256];
	new SLen=strlen(Source);
	new at,pos=0,tp=0;
	new tempo[256];

	format(FileData[0],sizeof(FileData),"");
	format(FileData[1],sizeof(FileData),"");
	format(FileData[2],sizeof(FileData),"");
	format(FileData[3],sizeof(FileData),"");
	format(FileData[4],sizeof(FileData),"");
	format(FileData[5],sizeof(FileData),"");
	format(FileData[6],sizeof(FileData),"");

	for(at=pos;at<=SLen;at++){
		strmid(tempo,Source,at,at+1,sizeof(tempo));
		if(!strcmp(tempo,",",true)){
			if(tp<=10){
				strmid(Destination,Source,pos,at,sizeof(Destination));
				format(FileData[tp][0],256,"%s",Destination);
				tp=tp+1;
			}
			pos=at+1;
		}
	}
	return 1;
}

GetPlayerCountry(playerid,Country[256]){
   	new IPAddress[256];
   	new a,b,c,d,ipf;
   	new File:IPFile;
   	new Text[256],start,end;
   	GetPlayerIp(playerid,IPAddress,sizeof(IPAddress));
   	GetParams(IPAddress);
   	a=strval(Params[0]);
   	b=strval(Params[1]);
   	c=strval(Params[2]);
   	d=strval(Params[3]);
   	if(a==127 && b==0 && c==0 && d==1){
   		format(Country,sizeof(Country),"Localhost");
   		return 1;
   	}
   	ipf = (16777216*a) + (65536*b) + (256*c) + d;
   	if(!fexist("CountriesIPs/IPLIST.csv")) return format(Country,sizeof(Country),"Unknown Country");
   	IPFile=fopen("CountriesIPs/IPLIST.csv",io_read);
   	fread(IPFile,Text,sizeof(Text),false);
	while(strlen(Text)>0){
	    GetFileData(Text);
	    start=strval(FileData[0]);
	    end=strval(FileData[1]);
	    if(ipf>=start && ipf<=end){
			format(Country,sizeof(Country),"%s(%s)",FileData[6],FileData[5]);
			fclose(IPFile);
			return 1;
	    }else{
	    format(Country,sizeof(Country),"Unknown Country");
	    }
	    fread(IPFile,Text,sizeof(Text),false);
	}
	fclose(IPFile);
	return 1;
}

GetPName(playerid){
    new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	return name;
}