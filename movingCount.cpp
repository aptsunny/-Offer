//机器人的运动范围 回溯法
//m行n列 行坐标和纵坐标的数位之和大于k的格子不能进入，k=18,(35,37)可进，(35,38)不可进
int movingCount(int threshold,int rows,int cols)
{
	if(threshold<0||rows<=0||cols<=0)
		return 0;
	
	bool *visited=new bool[rows * cols];
	for (int i=0;i<rows * cols;++i)
		visited[i]=false;
	
	int count=movingCountCore(threshold,rows,cols,0,0,visited);
	
	delete[] visited;
	
	return count;
}

int movingCountCore(int threshold,int rows,int cols,int row,int col,bool* visited)
{
	int count=0;
	if(check(threshold,rows,cols,row,col,visited))
	{
		visited[rows * cols +col]=true;
		
		count=1+movingCountCore(threshold,rows,cols,row-1,col,visited)
		       +movingCountCore(threshold,rows,cols,row,col-1,visited)
			   +movingCountCore(threshold,rows,cols,row+1,col,visited)
			   +movingCountCore(threshold,rows,cols,row,col+1,visited);
	}
	return count;
}


bool check(int threshold,int rows,int cols,int row,int col,bool* visited)//判断能否进入坐标为（row,col）的方格
{
	if(row>=0 && row<rows && col>=0 && col<cols
		&&getDigitSum(row)+getDigitSum(col)<=threshold
		&& !visited[row*cols +col])
		return true;
	return false;
}

int getDigitSum(int number)//返回数位之和
{
	int sum=0;
	while(number>0)
	{
		sum+=number%10;
		number/=10;
	}
	return sum;
}