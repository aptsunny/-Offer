//用两个栈实现队列
template<typename T>void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T>T CQueue<T>::deleteHead()
{
	if(stack2.size()<=0)
	{
		while(stack.size()>0)//栈1还有值
		{
			T& data=stack1.top();
			stack1.pop();
			stack2.push(data);//悉数推到栈2
		}
	}	
	if(stack2.size()==0)
		throw new exception("queue is empty");
	
	T head=stack2.top();
	stack2.pop();
	
	return head;
	
}