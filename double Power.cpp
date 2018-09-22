//数值的整数次方
double Power(double base,int exponent)//底数和指数
{
	double result=1.0;
	for(int i=1;i<=exponent;++i)
		result*=base;
	return result;
	
}