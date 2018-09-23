//打印从1到最大的n位数(考虑整数或者长整数溢出的问题)
//通过字符串表达数字
void Print1ToMaxOfNDigits_2(int n)
{
	if (n<=0)
		return;
	char *number = new char[n+1];//字符串最后为'\0',总长度为n+1
	memset(number,'0',n);//初始化为0
	number[n]='\0';
	
	while(!Increment(number))
	{
		PrintNumber(number);
	}
	delete []number;
}

bool Increment(char* number)
{
	bool isOverflow =false;
	int nTakeOver=0;
	int nLength = strlen(number);//字符串长度 5
	for (int i= nLength -1; i>=0;i--)//0 1 2 3 4
	{
		int nSum = number[i]-'0'+nTakeOver;
		if (i==nLength-1)
			nSum++;
		if (nSum>=10)
		{
			if(i==0)
				isOverflow=true;
			else
			{
				nSum -=10;
				nTakeOver=1;
				number[i]='0'+nSum
			}
		}
		else
		{
			number[i]='0'+nSum;
			break;
			
		}
	}
	return isOverflow;
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