//位运算：与、或、异或，左移<<，右移>>
//二进制中1的个数，9二进制为1001，输出2
//常规解法：循环次数是整数二进制位数
int NumberOf2(int n)
{
	int count=0;
	unsigned int flag=1;
	
	while(flag)
	{
		if(n&flag)
			count++;
		flag=flag<<1;//左移一位
	}
	return count;
}