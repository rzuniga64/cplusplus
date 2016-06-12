//******************************************************************************
//
//	File:			BSTree.h
//	Author:			Raul Zuniga
//	Description:	Provides a template class for a binary search tree and 
//					functions for manipulating a binary search tree.
//
//	TEMPLATE PARAMETER, TYPEDEFS, and MEMBER CONSTANTS for the BSTree<Item> class:
// 	The template parameter, Item, is the data type of the items in the stack, 
//  also defined as BSTree<Item>::value_type.  It may be any of the C++ built-in 
//  types (int, char, etc.), or a class with a defalut constructor, a copy 
//  constructor, and an assignment operator.  The definition BSTree<Item>::size_type
//  is the data type of any variable that keeps track of how may items are in a 
//  stack.
//	
//	CONSTRUCTOR for the BSTree class
//	BSTree();		
//		Postcondition: The BSTree is empty.
//		
//	MODIFICATION MEMBER FUNCTIONS:		
//
//	void insertItem(const value_type& entry)
//		Postcondition: A new copy of entry has been inserted into the binary search tree.
//
//	myNode<Item> *root()
//		Postcondition:   The return value is a pointer to the root.
//		(which will be NULL if there is no children ).
//
//	NONMEMBER FUNCTIONS for the BSTree class:
//
//	VALUE SEMANTICS for the BSTree class:
//		Assignments and the copy constructor may be used with BSTree objects.
//
//	DYNAMIC MEMORY USAGE by the myNode:
//		If there is insufficient dynamic memory, then the following functions
//		throw bad_alloc:  The copy constructor,insert, operator +=, 
//		operator +, and the assignment operator.
//
//******************************************************************************

#ifndef	BSTREE_H
#define BSTREE_H
				
#include "myNode.h"
using namespace std;

	template <class Item>
	class BSTree
	{
	public:
		// TYPEDEFS
		typedef Item value_type;
	
		//CONSTRUCTORS AND DESTRUCTORS
		BSTree();
		BSTree(const BSTree<Item>& source);
		~BSTree();
	
		//MODIFICATION MEMBER FUNCTIONS
		myNode<Item>* root(); 
		void insertItem(const Item& entry);
		void operator =(BSTree& source);
	private:
		myNode<Item> *root_ptr;	// Root pointer of binary search tree
	};
		
//	NONMEMBER FUNCTIONS to manipulate binary search tree

	template <class Item>
	BSTree<Item>::BSTree()
	{
		root_ptr = NULL;
	}
			
	template <class Item>
	BSTree<Item>::BSTree(const BSTree<Item>& source)
	{
		root_ptr = tree_copy(source.root_ptr);	
	}
	
	template <class Item>
	BSTree<Item>::~BSTree()
	{
		tree_clear(root_ptr);
	}
	
	template <class Item>
	myNode<Item>* BSTree<Item>::root() 
	{
		return root_ptr;
	}
	
	template <class Item>
	void BSTree<Item>::insertItem( const Item& entry)
	// Library facilities used: cstdlib
	{
		bool done = false;
		myNode<Item>* cursor;
		myNode<Item>* newcursor;
		
		if ( root_ptr == NULL)
		{
			root_ptr = new myNode<Item>(entry);
			return;
		}	
		
		cursor = root_ptr;
		
		while (!done)
		{	
			if (entry <= cursor->data())
			{
				if ( cursor->left() == NULL)
				{
					newcursor = new myNode<Item>(entry);
					cursor->set_left(newcursor);
					done = true;
				}
				else 
					cursor = cursor->left();
			}
			else if (entry > cursor->data())
			{
				if (cursor->right() == NULL)
				{	
					newcursor = new myNode<Item>(entry);
					cursor->set_right(newcursor);
					done = true;
				}
				else 
					cursor = cursor->right();
			}				
		}
	}
	
	/*
	template <class Item>
	BSTree<Item> operator =(BSTree<Item>& source)
	{
		if (this == &source)		// Handle self assignment
			return;
			
		tree_clear(root_ptr);
		root_ptr = tree_copy(source.root_ptr);
	}	
	*/

#endif BSTREE_H