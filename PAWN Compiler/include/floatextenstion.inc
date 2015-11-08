/*

	Additional Trig Library
	By Le Cai & Tom.Chen
*/

stock Float:floatcot(Float:value,anglemode:mode=radian)
{
	return (1.0 / floattan(value,mode));
}
