//			EG/2019/3659
//			Madushan N.N.A.
//			Assignment 2.1

#include<iostream>
#include"tree.h"//including the header file tree
using namespace std;

int main()
{
	BST tree;
	tree.insert(2);//inserting elements to the tree
	tree.insert(0);
	tree.insert(1);
	tree.insert(9);
	tree.insert(3);
	tree.insert(6);
	tree.insert(5);
	tree.insert(9);

	tree.insert(12);
	

	cout << " Tree (Before deleting nodes):" << endl;
	tree.traverse();//printing the elemnts of the tree

	tree.deleteNode(1);//deleting a leaf node
	//tree.deleteNode(0);//deleting a node with one child
	//tree.deleteNode(9);//deleting a node with 2 children
	
	cout << " Tree (After deleting nodes):" << endl;
	tree.traverse();//printing the tree after deleting the element
	
}