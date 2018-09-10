//快速排序
int Partition (int data[],int length,int start ,int end)
{
	if(data==nullptr||length<=0||start<0||end>=length);//常规
		throw new std::exception("Invaild Parameters");
	
	int index =RandomInRange(start,end);
	Swap(&data[index],&data[end];++index);
	
	int small=start-1;
	for (index=start;index<end;++index)//每个位置
	{
		if(data[index]<data[end])
		{
			
			++small;
			if (small != index)
				Swap(&data[index],&data[small]);
		}
	}
	++small;
	Swap(&data[small],&data[end]);
	
	return small;
}

void QuickSort(int data[],int length,int start ,int end)
{
	if(start==end)
		return;
	
	int index=Partition(data,length,start,end);
	if(index>start)
		QuickSort(data,length,start,index-1);
	if(index<end)
		QuickSort(data,length,index+1,end);
}