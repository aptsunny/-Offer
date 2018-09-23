//打印从1到最大的n位数(考虑整数或者长整数溢出的问题)
//通过递归使代码简洁
void Print1ToMaxOfNDigits_3(int n)
{
	if (n<=0)
		return;
	char *number = new char[n+1];//字符串最后为'\0',总长度为n+1
	number[n]='\0';
	
	for(int i=0;i<10;++i)
	{
		number[0]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,n,0);
	}
	delete []number;
}

void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index)
{
	if(index==length-1)
	{
		PrintNumber(number);
		return;
	}
	for (int i=0;i<10;++i)
	{
		number[index+1]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,length,index+1);
	}
	
}
//打印字符串表示的数字，且去掉前边的0
void PrintNumber(char* number)
{
	bool isBeginning0=true;
	int nLength =strlen(number);
	
	for(int i=0; i<nLength; ++i)
	{
		if (isBeginning0 && number[i]!='0')
			isBeginning0=false;
		
		if (!isBeginning0)//非0输出
		{
			printf("%c",number[i]);
		}
	}
	printf("\t");
}