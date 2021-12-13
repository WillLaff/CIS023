#pragma once
#include <iostream>
using namespace std;

//Definition of the node  
template <class elemType>  
struct nodeType  
{  
	elemType info;  
	nodeType<elemType> *lLink;  
	nodeType<elemType> *rLink;  
}; 

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:  
	const binaryTreeType<elemType>& operator=
		(const binaryTreeType<elemType>&);

	bool isEmpty() const;
	
	void inorderTraversal() const; 
	void preorderTraversal() const;
	void postorderTraversal() const;
	
	int treeHeight() const;
	int treeNodeCount() const;
	int treeLeavesCount() const;
	
	void destroyTree() const;
	
	virtual bool search(const elemType& searchItem) const = 0;
	virtual void insert(const elemType& insertItem) = 0;
	virtual void deleteNode(const elemType& deleteItem) = 0;
	
	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	binaryTreeType();
	~binaryTreeType();

protected: 
	nodeType<elemType>* root;

private: 
	void copyTree(nodeType<elemType>*& copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
	void destroy(nodeType<elemType>*& p);
	void inorder(nodeType<elemType>* p) const;
	void preorder(nodeType<elemType>* p) const;
	void postorder(nodeType<elemType>* p) const;

	int height(nodeType<elemType>* p) const;
	int max(int x, int y) const;
	int nodeCount(nodeType<elemType>* p) const;
	int leavesCount(nodeType<elemType>* p) const;
}; 

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == nullptr);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = nullptr;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::inorder
(nodeType<elemType>* p) const
{
	if (p != nullptr)
	{
		inorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::preorder
(nodeType<elemType>* p) const
{
	if (p != nullptr)
	{
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder
(nodeType<elemType>* p) const
{
	if (p != nullptr)
	{
		postorder(p->lLink);
		postorder(p->rLink);
		cout << p->info << " ";
	}
}

template<class elemType>
int binaryTreeType<elemType>::height
(nodeType<elemType>* p) const
{
	if (p == nullptr)
		return 0;
	else
		return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}