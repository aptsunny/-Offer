//树
/*  A
   B C
   
  前序：ABC 中序：BAC 后序：BCA
  已知前序和中序序列，得出全树，需要递归。
*/
BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
	if (preorder==nullptr||inorder==nullptr||length<=0)//必要检验
		return nullptr;
	
	return ConstructCore
	(preorder, preorder+length-1, inorder, inorder+length-1);
	
}
BinaryTreeNode* ConstructCore// 主函数，反复递归
(	int* startPreorder,int* endPreorder,
	int* startInorder, int* endInorder)
{
	//前序第一个数字是根节点
	int rootValue=startPreorder[0];
	BinaryTreeNode* root= new BinaryTreeNode();
	root->m_nValue=rootValue;//赋值
	root->m_pLeft=root->m_pRight=nullptr;//
	
	if (startPreorder==endPreorder)//第二次检验
	{
		if(startInorder==endInorder
			&& *startPreorder==*startInorder)
			return root;
		else
			throw std::exception("Invaild input.")
	}
	//中序根节点左边是左子树，右边是右子树
	int* rootInorder = startInorder;
		//从头到尾找root
	while(rootInorder<= endInorder && *rootInorder !=rootValue)
		++rootInorder;
		//没找到root,无效输入
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invaild input.")
	
	int leftLength=rootInorder-startInorder;//左边长度
	int* leftPreorderEnd=startPreorder + leftLength;//右边子树地址
	if(leftLength>0)
	{
		//构建左子树
		root->m_pLeft=ConstructCore(startPreorder+1,
			leftPreorderEnd,startInorder,rootInorder-1);
	}
	int(leftLength<endPreorder-startPreorder)	
		//构建右子树
		root->m_pRight=ConstructCore(leftPreorderEnd+1,
			endPreorder,rootInorder+1,endInorder);
	}
	return root;
	
	
}

