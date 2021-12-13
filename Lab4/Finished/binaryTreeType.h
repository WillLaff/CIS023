/*
	Program name    : L4-1.cpp

	Written by      : William Laffey

	Purpose         : Creates 3 binary trees and traverses them inorder, 
	                  preorder, and postorder. Then it displays the tree 
					  heights and swaps the last tree's order. 

	Inputs          : Any amounter of numbers as long as it ends with -999

	Outputs         : Tree 1 inorder and postorder.
                      Tree 2 preorder.
					  Tree 3 inorder.
					  Every tree height and number of leaves.
					  Tree 3 swapped inorder.

	Methods         : inorderTraversal()
	                  preorderTraversal()
	                  postorderTraversal()
					  treeHeight()
					  treeLeavesCount()
					  swapSubtrees()

   ---------------------------------------------------------------------
	Change Log:
							   Revision
	  Date        Changed  Rel Ver Mod Purpose
	12/09/21      wlaffey  001.000.000 Initial release of program
																		*/

#pragma once
#include <iostream>
using namespace std;

//Definition of the node  
template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType>* lLink;
	nodeType<elemType>* rLink;
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

template <class elemType>
void binaryTreeType<elemType>::copyTree
(nodeType<elemType>*& copiedTreeRoot,
	nodeType<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == nullptr)
		copiedTreeRoot = nullptr;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>*& p)
{
	if (p != nullptr)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = nullptr;
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree() const
{
	destroy(root);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == nullptr) //otherTree is empty
		root = nullptr;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{
	if (this != &otherTree) //avoid self-copy
	{
		if (root != nullptr) //if the binary tree is not empty,
		//destroy the binary tree
			destroy(root);
		if (otherTree.root == nullptr) //otherTree is empty
			root = nullptr;
		else
			copyTree(root, otherTree.root);
	}//end else
	return *this;
}

//Worked with/written by Darroll Saddi
template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType>* p) const {
	if (p == nullptr)
		return 0;
	if (p->lLink == nullptr && p->rLink == nullptr)
		return 1;
	else
		return leavesCount(p->lLink) + leavesCount(p->rLink);
}
template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType>* p) const {
	if (p = nullptr)
		return 0;
	else return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}
