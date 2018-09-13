//动态规划与贪婪算法
//剪绳子，使分段乘积最大,18=2*3*3 ,O(n^2)时间，O(n)空间
int maxProductAfterCutting_solution1(int length)
{
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;
	
	int* products =new int[length +1]
	products[0]=0;
	products[1]=1;
	products[2]=2;
	products[3]=3;
	
	int max=0;
	
	for (int i=4;i<=length；++i)
	{
		max=0;
		for(int j=1;j<=i/2 ;++j)
		{
			int product=products[j]* products[i-j];
			if(max<product)//比较每一轮的乘积，取最大值保留至max
				max=product;
			
			products[i]=max;
		}
	}
	max=products[length];
	delete[] products;
	
	return max;
}