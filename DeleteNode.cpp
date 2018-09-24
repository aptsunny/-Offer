//在O(1)时间内删除链表节点
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
	if(!pListHead||!pToBeDeleted)
		return;
	//删除的不是尾节点
	//O(1)的时间内把下一个节点的内存复制覆盖到要删除的节点
	if (pToBeDeleted->m_pNext!=nullptr)
	{
		ListNode* pNext=pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue=pNext->m_nValue;
		pToBeDeleted->m_pNext=pNext->m_pNext;
		
		delete pNext;
		pNext=nullptr;
	}
	//链表只有一个节点，删除头结点，要把链表的头结点设为nullptr
	else if (*pListHead)
	{
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
		*pListHead=nullptr;
	}
	
	//链表有多个节点，删除尾节点
	//对于尾节点仍然需要顺序查找O(n)
	else 
	{
		ListNode* pNode =*pListHead;
		while(pNode->m_pNext!=pToBeDeleted)
		{
			pNode=pNode->m_pNext;
		}
		pNode->m_pNext=nullptr;
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
	}
}