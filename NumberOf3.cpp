//位运算：与、或、异或，左移<<，右移>>
//二进制中1的个数，9二进制为1001，输出2
//有几个1就循环几次
int NumberOf3(int n)
{
	int count=0;
	
	while(n)
	{
		++count;
		n=(n-1)&n;
	}
	return count;
}