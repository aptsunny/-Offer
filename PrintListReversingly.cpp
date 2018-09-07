//链表 从尾到头打印链表（不改变链表结构）栈的思想
void PrintListReversingly(ListNode* pHead)
{
	std::stack<ListNode*>nodes;//栈结构
	
	ListNode* pNode=pHead;//头指针传递
	
	while(pNode !=nullptr)
	{
		nodes.push(pNode);//压栈
		pNode=pNode->m_pNext;//常规移动
		
	}
	
	while(!nodes.empty())
	{
		pNode=nodes.top();//出栈
		printf("%d\t",pNode->m_nValue);
		nodes.pop();
	}
}