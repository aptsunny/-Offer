//位运算：与、或、异或，左移<<，右移>>
//二进制中1的个数，9二进制为1001，输出2
//可能引起死循环（如果输入负数）
int NumberOf1(int n)
{
	int count=0;
	while(n)
	{
		if(n&1)
			count++;
		n=n>>1;//右移一位
	}
	return count;
}
