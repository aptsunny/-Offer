//链表 尾部添加节点
void AddToTail(ListNode** pHead,int value)//pHead指向指针的指针
{
	//定义新节点，即为终点
	ListNode* pNew=new ListNode();
	pNew->m_nValue=value;
	pNew->m_pNext=nullptr;//亦为终点
	
	if (*pHead==nullptr)//头结点为空，
	{
		*pHead=pNew;
		
	}
	
	else//头结点非空
	{
		ListNode* pNode=*pHead;
		
		while(pNode->m_pNext !=nullptr)//确定位置
			pNode=pNode->m_pNext;
			
		pNode->m_pNext=pNew;
	}
}