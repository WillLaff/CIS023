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
#include "binaryTreeType.h"

using namespace std;

template <class elemType>
class binarySearchTreeType : public binaryTreeType<elemType>
{
public:
	bool search(const elemType& searchItem) const;
	//Function to determine if searchItem is in the binary 
	//search tree.
	//Postcondition: Returns true if searchItem is found in 
	//               the binary search tree; otherwise, 
	//               returns false.

	void insert(const elemType& insertItem);
	//Function to insert insertItem in the binary search tree.
	//Postcondition: If there is no node in the binary search
	//               tree that has the same info as 
	//               insertItem, a node with the info 
	//               insertItem is created and inserted in the
	//               binary search tree.

	void deleteNode(const elemType& deleteItem);
	//Function to delete deleteItem from the binary search tree 
	//Postcondition: If a node with the same info as deleteItem
	//               is found, it is deleted from the binary 
	//               search tree.
	//               If the binary tree is empty or deleteItem
	//               is not in the binary tree, an appropriate
	//               message is printed.

	void preorderTraversal(binarySearchTreeType& tree) const;
	void postorderTraversal(binarySearchTreeType& tree) const;
	void swapSubtrees();

private:
	void deleteFromTree(nodeType<elemType>*& p);
	//Function to delete the node to which p points is 
	//deleted from the binary search tree.
	//Postcondition: The node to which p points is deleted
	//               from the binary search tree.
	
	void preorder(nodeType<elemType>* p, binarySearchTreeType& tree) const;
	void postorder(nodeType<elemType>* p, binarySearchTreeType& tree) const;
	void subtrees(nodeType<elemType>* tree);
};


template <class elemType>
bool binarySearchTreeType<elemType>::search
(const elemType& searchItem) const
{
	nodeType<elemType>* current;
	bool found = false;

	if (this->root == NULL)
		cout << "Cannot search an empty tree." << endl;
	else
	{
		current = this->root;

		while (current != NULL && !found)
		{
			if (current->info == searchItem)
				found = true;
			else if (current->info > searchItem)
				current = current->lLink;
			else
				current = current->rLink;
		}//end while
	}//end else

	return found;
}//end search

template <class elemType>
void binarySearchTreeType<elemType>::insert
(const elemType& insertItem)
{
	nodeType<elemType>* current; //pointer to traverse the tree
	nodeType<elemType>* trailCurrent = nullptr; //pointer behind current
	nodeType<elemType>* newNode;  //pointer to create the node

	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	if (this->root == NULL)
		this->root = newNode;
	else
	{
		current = this->root;

		while (current != NULL)
		{
			trailCurrent = current;

			//Allow duplicates--place in right subtree
			if (current->info == insertItem)
			{
				current = current->rLink;
			}
			else if (current->info > insertItem)
				current = current->lLink;
			else
				current = current->rLink;
		}//end while

		if (trailCurrent->info > insertItem)
			trailCurrent->lLink = newNode;
		else
			trailCurrent->rLink = newNode;
	}
}//end insert

template <class elemType>
void binarySearchTreeType<elemType>::deleteNode
(const elemType& deleteItem)
{
	nodeType<elemType>* current; //pointer to traverse the tree
	nodeType<elemType>* trailCurrent; //pointer behind current
	bool found = false;

	if (this->root == NULL)
		cout << "Cannot delete from an empty tree."
		<< endl;
	else
	{
		current = this->root;
		trailCurrent = this->root;

		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->info > deleteItem)
					current = current->lLink;
				else
					current = current->rLink;
			}
		}//end while

		if (current == NULL)
			cout << "The item to be deleted is not in the tree."
			<< endl;
		else if (found)
		{
			if (current == this->root)
				deleteFromTree(this->root);
			else if (trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->lLink);
			else
				deleteFromTree(trailCurrent->rLink);
		}
		else
			cout << "The item to be deleted is not in the tree."
			<< endl;
	}
} //end deleteNode

template <class elemType>
void binarySearchTreeType<elemType>::deleteFromTree
(nodeType<elemType>*& p)
{
	nodeType<elemType>* current; //pointer to traverse the tree
	nodeType<elemType>* trailCurrent;  //pointer behind current
	nodeType<elemType>* temp;      //pointer to delete the node

	if (p == NULL)
		cout << "Error: The node to be deleted is NULL."
		<< endl;
	else if (p->lLink == NULL && p->rLink == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->lLink == NULL)
	{
		temp = p;
		p = temp->rLink;
		delete temp;
	}
	else if (p->rLink == NULL)
	{
		temp = p;
		p = temp->lLink;
		delete temp;
	}
	else
	{
		current = p->lLink;
		trailCurrent = NULL;

		while (current->rLink != NULL)
		{
			trailCurrent = current;
			current = current->rLink;
		}//end while

		p->info = current->info;

		if (trailCurrent == NULL) //current did not move; 
			//current == p->lLink; adjust p
			p->lLink = current->lLink;
		else
			trailCurrent->rLink = current->lLink;

		delete current;
	}//end else
} //end deleteFromTree

template <class elemType>
void binarySearchTreeType<elemType>::preorder
(nodeType<elemType>* p, binarySearchTreeType& tree) const
{
	if (p != nullptr)
	{
		tree.insert(p->info);
		cout << p->info << " ";
		preorder(p->lLink, tree);
		preorder(p->rLink, tree);
	}
}

template <class elemType>
void binarySearchTreeType<elemType>::postorder
(nodeType<elemType>* p, binarySearchTreeType& tree) const
{
	if (p != nullptr)
	{
		postorder(p->lLink, tree);
		postorder(p->rLink, tree);
		cout << p->info << " ";
		tree.insert(p->info);
	}
}

template <class elemType>
void binarySearchTreeType<elemType>::preorderTraversal(binarySearchTreeType& tree) const
{
	preorder(this->root, tree);
}

template <class elemType>
void binarySearchTreeType<elemType>::postorderTraversal(binarySearchTreeType& tree) const
{
	postorder(this->root, tree);
}

template <class elemType>
void binarySearchTreeType<elemType>::swapSubtrees()
{
	subtrees(this->root);
}

template <class elemType>
void binarySearchTreeType<elemType>::subtrees
(nodeType<elemType>* tree)
{
	if (tree != nullptr)
	{
		nodeType<elemType> *temp;
		temp = tree->lLink;
		tree->lLink = tree->rLink;
		tree->rLink = temp;
		subtrees(tree->lLink);
		subtrees(tree->rLink);
	} 
}