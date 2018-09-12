//旋转数组的最小数字 O(logn)采用二分法
//345612 找1 遍历则需要O(n)
int Min(* numbers,int length)
{
	if (number==nullptr||length<=0)
		throw new std::exception("Invalid parameters");
	
	int index1=0;//两个地址
	int index2=length-1;
	int indexMid=index1;
	while(numbers[index1]>=numbers[index2])
	{
		if(index2-index1==1)
		{
			indexMid=index2;
			break;		
		}
		indexMid=(index1+index2)/2;
		if(numbers[indexMid]>=numbers[index])
			index1=indexMid;
		else if (numbers[indexMid]<=numbers[index2])
			index2=indexMid;
		
	}
	return numbers[indexMid];
}

//还有一版修正版