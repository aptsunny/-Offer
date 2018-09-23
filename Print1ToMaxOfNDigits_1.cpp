//打印从1到最大的n位数
//未考虑整数或者长整数溢出的问题
void Print1ToMaxOfNDigits_1(int n)
{
	int number=1;
	int i=0;
	while(i++<n)
		number *=10;
	
	for(i=1;i<number;++i)
		printf("%d\t",i);

}