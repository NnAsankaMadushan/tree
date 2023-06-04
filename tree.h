#include<iostream>
using namespace std;

class Node//creating the Node calss
{
public:
	Node* parent;
	Node* right;
	Node* left;
	int key;

	Node()//Node constructor
	{
		parent = NULL;
		right = NULL;
		left = NULL;
		key = -1;
	}
	Node(int k)//parameterized Node constructor
	{
		parent = NULL;
		right = NULL;
		left = NULL;
		key = k;
	}
};

class BST//class of binary search tree
{
private:
	Node* root;
	int size;

public:
	BST()//constructor of the binary search tree
	{
		root = NULL;
		size = 0;
	}

	void insert(int key)//function that inserting the elements to the tree
	{
		Node* temp = new Node(key);
		Node* current = root;
		Node* previous = NULL;

		while (current != NULL)
		{
			previous = current;
			if (key > current->key)
			{
				current = current->right;
			}
			else if (key < current->key)
			{
				current = current->left;
			}
			else if (key == current->key)
			{
				cout << " " << current->key << " is a duplicate Value" << endl << endl;
				return;
			}
		}
		if (previous == NULL)
		{
			root = temp;
		}
		else if (key < previous->key)
		{
			previous->left = temp;
			temp->parent = previous;
		}
		else if (key > previous->key)
		{
			previous->right = temp;
			temp->parent = previous;
		}
		size++;
	}

	void removeVal(Node* &current, int key)//node removing recursion function
	{
		if (current == NULL)//checking whether the tree is empty or not 
		{
			return;
		}
		else if (key > current->key)//finding the correct path acording to the key value
		{
			removeVal(current->right, key);//recursion
		}
		else if (key < current->key)//finding the correct path acording to the key value
		{
			removeVal(current->left, key);//recursion
		}
		else//deleting process
		{
			//deleting a leaf node(case 1)
			if (current->right == NULL && current->left == NULL)
			{
				delete current;
				current = NULL;
				
			}

			//deleting a node which have only one child(case 2)
			else if (current->left == NULL)//deleting a node which having a right child
			{
				Node* temp = current;
				current = current->right;
				delete temp;
			}
			else if (current->right == NULL)//deleting a node which having a left child
			{
				Node* temp = current;
				current = current->left;
				delete temp;
			}

			//deleting a node which having two children(case 3)
			else
			{
				Node* temp = min(current->right);/*returning the minimum value of the right branch
												 of current node to temp*/
				current->key = temp->key;//replace the value of the minimum value to the current
				removeVal(current->right, temp->key);//using recursion node deleting function
			}
		}
	}

	Node* min(Node* t)//returning the node which has minimum value of the right branch of 
	{
		while (t->left != NULL)
		{
			t = t->left;
		}
		return t;//returning the node
	}

	void deleteNode(int key)//function that calling to the removeVal function to delete the node
	{
		removeVal(root, key); //calling to the removeVal function
	}

	void preOrder(Node* node)//function of pre order traverse
	{
		if (node != NULL)
		{
			cout << " | " << node->key;
			preOrder(node->left);
			preOrder(node->right);
			return;
		}
	}

	void traverse()//printing the node in pre order traverse
	{
		cout << " Pre order traverse: ";
		preOrder(root);
		cout << endl << endl;
	}

};