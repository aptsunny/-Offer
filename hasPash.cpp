//回溯法 矩阵中的路径
//判断矩阵中是否存在一条包含字符串所有字符的路径
bool hasPath(char* martix,int rows,int cols,char* str)
{
	if(matrix==nullptr||rows<1||cols<1||str==nullptr)
		return false;
	
	bool *visited=new bool[rows * cols];//？
	memset(visited,0,rows * cols);//void *memset(void *s , int ch , size_t  n )函数解释：将s中的前n个字节用ch替换并且返回s
	
	int pathLength=0;
	for(int row=0;row<rows;++row)//遍历每个位置
	{
		for(int col=0;col<cols;++col)
		{
			if (hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))				
			{
				return true;	
			}
		}
	}
	delete[] visited;
	return false;
}

bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLength,bool* visited)
{
	if(str[pathLength]=='\0')//如果str遍历完成都找到，返回true
		return true;
	
	bool hasPath=false;
	if(row>=0 && row<rows && col>=0 && col<cols
			&&matrix[row*cols+col]==str[pathLength]
			&&!vistied[row*cols+col])
	{
		++pathLength;
		visited[row*cols+col]=true;
		
		hasPath=hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)
				||hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
				||hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
				||hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited)
		if(!hasPath)
		{
			--pathLength;
			visited[row * cols +col]=false;
		}
				
	}
	return hasPath;
}