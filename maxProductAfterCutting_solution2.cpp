//动态规划与贪婪算法
//剪绳子，使分段乘积最大,18=2*3*3 ,贪婪算法 O(1)时间，O(1)空间
int maxProductAfterCutting_solution2(int length)
{
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;
	
	//尽可能多留3
	int timesOf3=length/3;
	
	//剩下4，为2*2
	if (length-timesOf3*3==1)
		timesOf3 -=1;
	int timesOf2=(length-timesOf3*3)/2;
	
	return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));
}	
	