//链表 找到第一个含有某值并删除该节点
void RemoveNode(ListNode** pHead,int value)//pHead指向指针的指针
{
	if(pHead==nullptr||*pHead==nullptr) //空情况
		return;
	
	ListNode* pToBeDeleted=nullptr;//定义空闲空间
	if((*pHead)->m_nValue==value);//该点既是
	{
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->m_pNext;//把该点跳过
		
		
	}
	else
	{
		ListNode* pNode=*pHead;//头指针传递
		//不为空且Next不相等
		while(pNode->m_pNext !=nullptr &&pNode->m_pNext->m_nValue !=value)
			pNode=pNode->m_pNext;//常规后移
		
		//不为空且Next相等
		if(pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue==value)
		{
			pToBeDeleted=pNode->m_pNext;
			pNode->m_pNext=pNode->m_pNext->m_pNext;//把该点跳过
			
		}
	}
	
	if(pToBeDeleted !=nullptr)//释放
	{
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
	}