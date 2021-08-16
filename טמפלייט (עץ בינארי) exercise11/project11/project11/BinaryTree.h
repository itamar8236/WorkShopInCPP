//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 11 Question 1
//this program checks binary search tree as int class.

//
//  binaryTree.h
//  
//  


#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

using namespace std;


// ------------------------------------------
//     class BinaryTree
//     process nodes in Pre/In/Post order
// -------------------------------------------

template <typename T>
class BinaryTree
{
protected:
	// --------------------------------------------------------
	//      inner struct Node.
	//      a single Node of a binary tree.
	//---------------------------------------------------------
	struct Node
	{
		T value;
		Node * left;
		Node * right;
		Node(T val) :value(val), left(NULL), right(NULL) {}
		Node(T val, Node * l, Node * r) :value(val), left(l), right(r) {}
	};
	Node * root;
public:
	BinaryTree() { root = NULL; }
	~BinaryTree();
	bool isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }

	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


	int leaves() { return leaves(root); }
	int height() { return height(root); }
	void reflect() { reflect(root); }
	int onlyLeftSon() { return onlyLeftSon(root); }

private:

	void clear(Node * current);
	void preOrder(Node * current);
	void inOrder(Node * current);
	void postOrder(Node * current);

	int leaves(Node * current);
	int height(Node * current);
	void reflect(Node * current);
	int onlyLeftSon(Node * current);
	int max(int n1, int n2);
};


// ------------------------------
//   class BinaryTree implementation
// ------------------------------

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	if (root != NULL)
		clear(root);
}

template <typename T>
void BinaryTree<T>::clear(Node * current)
{
	if (current)
	{
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <typename T>
bool BinaryTree<T>::isEmpty() const
{
	return  root == NULL;
}

template <typename T>
void BinaryTree<T>::preOrder(Node * current)
{
	if (current)
	{
		process(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}
}

template <typename T>
void BinaryTree<T>::inOrder(Node * current)
{
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template <typename T>
void BinaryTree<T>::postOrder(Node * current)
{
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
template <typename T>
int BinaryTree<T>::leaves(Node * current)
{
	if (current == NULL)
		return 0;
	if (current->left == NULL && current->right == NULL)
		return 1;
	return leaves(current->left) + leaves(current->right);
}
template <typename T>
int BinaryTree<T>::height(Node * current)
{
	if(current == NULL)
		return 0;
	if (current->left == NULL && current->right == NULL)
		return 1;
	return 1 + max(height(current->left), height(current->right));
}

template <typename T>
void BinaryTree<T>::reflect(Node * current)
{
	if (current != NULL)
	{
		Node * temp = current->left;
		current->left = current->right;
		current->right = temp;
		reflect(current->left);
		reflect(current->right);
	}
}

template <typename T>
int BinaryTree<T>::onlyLeftSon(Node * current)
{
	if (current == NULL)
		return 0;
	if ((current->left != NULL) && (current->right == NULL))
		return 1 + onlyLeftSon(current->left);
	return onlyLeftSon(current->left) + onlyLeftSon(current->right);
}
template <typename T>
int BinaryTree<T>::max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else return n2;
}
#endif /* BINARY_TREE_H */
