//将字符串中空格替换为‘20%’
void ReplaceBlank(char string[],int length)//string 不能更改
{
	if (string == nullptr||length<=0)
		return;
	int originalLength=0;
	int numberOfBlank=0;
	int i=0;
	while(string[i]!='\0')//从头遍历至尾,获取信息
	{
		++originalLength；
		if(string[i]==' ')
			++numberOfBlank;
		++i;
	}
	
	int newLength=originalLength+numberOfBlank*2;
	if (newLength>length)
		return;//?
	
	int indexOfOriginal=originalLength;
	int indexOfNew=newLength;
	
	while(indexOfOriginal>=0&&indexOfNew>indexOfOriginal)
	{
		if(string[indexOfOriginal]==' ')//空格情况，前推
		{
			string[indexOfNew--]='0';
			string[indexOfNew--]='2';
			string[indexOfNew--]='%';
			
		}
		else
		{
			string[indexOfNew--]=string[indexOfOriginal];//正常
			
		}
		--indexOfOriginal;//不管怎样，原始都要向前遍历
	}
	

}