//树
/* 
   X               
	A
   B C   
   
     X
	A
   B C
  前序：ABC 中序：BAC 后序：BCA
  给出中序遍历，从二叉树中找出一个节点的下一个节点
*/
BinaryTreeNode*GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)//常规
		return nullptr;
	
	BinaryTreeNode*pNext=nullptr;//？先给个空闲空间
	
	if (pNode->m_pRight != nullptr;)//假如右不为空
	{
		BinaryTreeNode*pRight=pNode->m_pRight;
		while(pRight->m_pLeft !=nullptr)
			pRight=pRight->m_pLeft;
		
		pNext=pRight;	
	}
	else if(pNode->m_pParent !=nullptr)//父节点不为空，两种情况
	{
		BinaryTreeNode*pCurrent=pNode;
		BinaryTreeNode*pParent=pNode->m_pParent;
		while(pParent !=nullptr && pCurrent==pParent->m_pRight)//存在且是该点为右子节点
		{
			pCurrent=pParent;
			pParent=pParent->m_pParent;			
		}
		
		pNext=pParent;	//存在且是该点为左子节点，此时父节点直接下一个节点
	}
	return pNext;
}