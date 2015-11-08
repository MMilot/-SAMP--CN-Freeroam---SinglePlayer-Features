/*
	Script by mick88 - encode
		4th March 2012
		
	You are free to change and distribute
	this code as long as credits remain intact.
		
	Function headers :

	native EncodeIP(ip[], size=sizeof(ip));
	    -- encodes string with an ip address to a single-cell value

	native DecodeIP(value, ip[], size=sizeof(ip));
	    -- decodes value into an ip address

    native DecodeIP2(value)
        -- Same as above, but returns string with the ip address.

	native CompareIP(ip1, ip2, mask=0xFFFF0000);
	    -- compares two ip addresses.
	    -- you can use this to check if ips are in the same range (for range ban, etc)
	
	macros:

	COMPARE_IP_RANGE(ip1, ip2)
		-- check if both encoded ip addresses are in the same range
		-- eg. 192.168.0.1 compared to 192.168.1.2 returns true
		
    COMPARE_IP(ip1, ip2, mask)
        -- compares two encoded addresses using custom mask.
		-- Mask has to be encoded too, you can specify mask and IP addresses as:
			* a hexadecimal value (0xFFFF0000 for 255.255.0.0)
			* an integer (-1 for 255.255.255.255)
			* text format converted using EncodeIP function, ie. EncodeIP("127.0.0.1")
		-- You can check if two addresses are identical by using IP_FULL_MASK,
		-- but it's more efficient to just compare two variables using ==
*/

//Some potentially useful defines:
#define IP_LOCAL                (0x7F000001)        									//127.0.0.1
#define IP_RANGE_MASK           (0xFFFF0000)        									//255.255.0.0
#define IP_FULL_MASK           	(0xFFFFFFFF)        									//255.255.255.255

#define COMPARE_IP_RANGE(%0,%1)	(((%0) & IP_RANGE_MASK) == ((%1) & IP_RANGE_MASK))      //compare 2 ips with default range mask
#define COMPARE_IP(%0,%1,%2)	(((%0) & (%2)) == ((%1) & (%2)))                        //compare 2 ips with custom mask

#define IP_LENGTH				(16)                                                   	//default size for string containing an IP address

stock CompareIP(ip1, ip2, mask=IP_RANGE_MASK)
{
	/*
		Checks if the 2 IPs are in the same range.
		You can use the COMPARE_IP_RANGE or COMPARE_IP macro instead
	*/
	return ((ip1 & mask) == (ip2 & mask));
}

stock EncodeIP(ip[], size=sizeof(ip))
{
	new val=0, acc=0, s=3;
	for(new i=0; i < size; i++)
	{
	    switch(ip[i])
	    {
	        case '.', '\0':
	        {
	            val += acc << (s*8);
				acc = 0;
				if ((s--) == 0 || ip[i] == '\0') break;
	        }
	        case '0'..'9':
	        {
	            acc = (acc * 10) + (ip[i] - '0');
			}
			case '*': continue;
			default: printf("WARNING: unknown character #%d in ip address '%s': %c", ip[i], ip, ip[i]);
	    }
	}
	return val;
}

stock DecodeIP(value, ip[], size=sizeof(ip))
{
	return format(ip, size, "%i.%i.%i.%i", (value >> 24) & 0x000000FF, (value >> 16) & 0x000000FF, (value >> 8) & 0x000000FF, (value) & 0x000000FF);
}

stock DecodeIP2(value)
{
	new ip[IP_LENGTH];
	format(ip, IP_LENGTH, "%i.%i.%i.%i", (value >> 24) & 0x000000FF, (value >> 16) & 0x000000FF, (value >> 8) & 0x000000FF, (value) & 0x000000FF);
	return ip;
}

/*
	Script by mick88 - encode
		4th March 2012

	You are free to change and distribute
	this code as long as credits remain intact.
*/