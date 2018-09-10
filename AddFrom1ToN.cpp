//递归、循环1+2+3+4+,,,+n
//递归较简洁
int AddFrom1ToN_Recursive(int n)
{
	return n<=0 ? 0:n+AddFrom1ToN_Recursive(n-1);
}

int AddFrom1ToN_Iterative(int n)
{
	int result=0;
	for (int i=1;i<=n;++i )
		result +=i;
	return result;
}
