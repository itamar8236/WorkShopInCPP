//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 11 Question 1
//this program checks binary search tree as int class.

//
//  BinarySearchTree.h  (BST)
//  
//
//  

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
	void add(T val);
	bool search(T val);
	void remove(T val); // TODO
	int level(T val);
private:
	void add(typename BinaryTree<T>::Node * current, T val);
	bool search(typename BinaryTree<T>::Node * current, T val);
	void remove(typename BinaryTree<T>::Node * current, T val);
	typename BinaryTree<T>::Node * minNode(typename BinaryTree<T>::Node * current);
	typename BinaryTree<T>::Node * parent(typename BinaryTree<T>::Node * grandfather, typename BinaryTree<T>::Node * current);
	int level(typename BinaryTree<T>::Node * current, T val);

};

template <typename T>
bool BinarySearchTree<T>::search(typename BinaryTree<T>::Node * current, T val)
{
	if (!current)
		return false;
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <typename T>
void BinarySearchTree<T>::add(typename BinaryTree<T>::Node * current, T val)
{
	if (current->value < val)
		if (!current->right)
		{
			current->right = new typename BinaryTree<T>::Node(val);
			return;
		}
		else
			add(current->right, val);
	else
		if (!current->left)
		{
			current->left = new typename BinaryTree<T>::Node(val);
			return;
		}
		else
			add(current->left, val);
}

template <typename T>
bool BinarySearchTree<T>::search(T val)
{
	return search(this->root, val);
}

template <typename T>
void BinarySearchTree<T>::add(T val)
{
	if (!this->root)
	{
		this->root = new typename BinaryTree<T>::Node(val);
		return;
	}
	add(this->root, val);
}

template <typename T>
void BinarySearchTree<T>::remove(T val)
{
	if (search(val))
	{
		if (this->root->value == val)
		{
			//case 1: root is the only node
			if (this->root->left == NULL && this->root->right == NULL)
			{
				typename BinaryTree<T>::Node * temp = this->root;
				this->root = NULL;
				delete temp;
			}
			//case 2: root have 1 son.
			else if (this->root->left == NULL || this->root->right == NULL)
			{
				typename BinaryTree<T>::Node * temp = this->root;
				if (this->root->left == NULL)
					this->root = this->root->right;
				else this->root = this->root->left;
				delete temp;
			}
			//case 3: root have 2 sons.
			else
			{
				typename BinaryTree<T>::Node * temp = minNode(this->root->right);
				this->root->value = temp->value;
				remove(temp, temp->value);
			}
		}
		else remove(this->root, val);
	}
}

template <typename T>
void BinarySearchTree<T>::remove(typename BinaryTree<T>::Node * current, T val)
{
	if (search(current, val))
	{
		if (current->value != val)
		{
			remove(current->left, val);
			remove(current->right, val);
		}
		else//delete current
		{
			//case 3:current to delete  have 2 sons
			if (current->right != NULL && current->left != NULL)
			{
				typename BinaryTree<T>::Node * temp = minNode(current->right);
				current->value = temp->value;
				remove(temp, temp->value);
			}
			else
			{
				typename BinaryTree<T>::Node * father = parent(this->root, current);
				//case 1: cuurent to delete have no sons
				if (current->right == NULL && current->left == NULL)
				{
					if (father->right == current)
						father->right = NULL;
					else father->left = NULL;
					delete current;
				}
				//case 2: cuurent to delete have 1 son
				else
				{
					if (father->right == current)
						if (current->right != NULL)
							father->right = current->right;
						else father->right = current->left;
					else
						if (current->right != NULL)
							father->left = current->right;
						else father->left = current->left;
					delete current;
				}
			}
		}
	}
}

template <typename T>
typename BinaryTree<T>::Node * BinarySearchTree<T>::minNode(typename BinaryTree<T>::Node * current)
{
	if (current->left == NULL)
		return current;
	return minNode(current->left);
}

template <typename T>
typename BinaryTree<T>::Node * BinarySearchTree<T>::parent(typename BinaryTree<T>::Node * grandfather, typename BinaryTree<T>::Node * current)
{
	if (grandfather->right == current || grandfather->left == current)
		return grandfather;
	if (grandfather->value > current->value)
		return parent(grandfather->left, current);
	else return parent(grandfather->right, current);
}

template <typename T>
int BinarySearchTree<T>::level(T val)
{
	if (!search(val))
		return -1;
	return level(this->root, val);
}
template <typename T>
int BinarySearchTree<T>::level(typename BinaryTree<T>::Node * current, T val)
{
	if (current->value == val)
		return 0;
	if (current->value > val)
		return 1 + level(current->left, val);
	else return 1 + level(current->right, val);
}

#endif /* BINARY_SEARCH_TREE_H */

