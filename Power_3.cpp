//数值的整数次方（指数为负数）
//提升多次相乘的效率

bool g_InvaildInput = false;
double Power_3(double base,int exponent)
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
	if (exponent ==0)
		return 1;
	if (exponent ==1)
		return base;
	double result =PowerWithUnsignedExponent(base,exponent>>1);
	result *=result;

	if(exponent&0X1==1)
	//该式也可以用做判断exponent的奇偶性， 如果k为奇数，其计算结果为1，否则为0。
		return *=base;

	
	return result;
}