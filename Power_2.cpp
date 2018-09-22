//数值的整数次方（指数为负数）

bool g_InvaildInput = false;
double Power_2(double base,int exponent)
{
	g_InvaildInput=false;
	
	if(equal(base,0.0) && exponent <0)
		//底数为0.指数为负数
	{
		g_InvaildInput=true;
		return 0.0;
	}
	
	unsigned int absExponent=(unsigned int)(exponent)
	//无符号整型
	if (exponent<0)
		absExponent=(unsigned int)(-exponent);
	double result =PowerWithUnsignedExponent(base,absExponent)
	if (exponent<0)
		result=1.0/result;
	return result;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
	double result=1.0;
	for (int i=1;i<=exponent;++i)
		result *=base;
	return result;
}