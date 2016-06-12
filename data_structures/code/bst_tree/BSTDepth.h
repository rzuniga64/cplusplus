//******************************************************************************
//
//	File:			BSTDepth.h
//	Author:			Raul Zuniga
//	Description:	Provides a template class for a binary search tree and 
//					functions for manipulating a binary search tree.
//
//	TEMPLATE PARAMETER, TYPEDEFS, and MEMBER CONSTANTS for the BSTree<Item> class:
// 	The template parameter, Item, is the data type of the items in the tree, 
//  also defined as BSTDepth<Item>::value_type.  It may be any of the C++ built-in 
//  types (int, char, etc.), or a class with a defalut constructor, a copy 
//  constructor, and an assignment operator.  The definition BSTree<Item>::size_type
//  is the data type of any variable that keeps track of how may items are in a 
//  stack.
//	
//	CONSTRUCTOR for the BSTDepth class
//	BSTDepth();		
//		Postcondition: The BSTree is empty.
//		
//	MODIFICATION MEMBER FUNCTIONS:		
//		void computeDepth() 
//			Postcondition:  Returns the depth of the binary search tree.
//		void FindMaxDepth(myNode<Item> *rootPtr, std::size_t Depth,std::size_t *MaxDepth )
//			Postcondition:  Helper function that returns the depth of the binary
//			search tree and returns the depth in the variable MaxDepth through the
//			reference.
//
//******************************************************************************

#ifndef	BSTDEPTH_H
#define BSTDEPTH_H
				
#include "BSTree.h"

using namespace std;
	template <class Item>
	class BSTDepth
	{
	public:
		BSTree<Item> myBST;	// A binary search tree

		// MODIFICIATION MEMBER FUNCTION
		void FindMaxDepth(myNode<Item> *rootPtr, std::size_t Depth, std::size_t *MaxDepth);	
		// CONST MEMBER FUNCTION
		std::size_t computeDepth();
	};	
	
	template <class Item>
	std::size_t BSTDepth<Item>::computeDepth() 
	{
		std::size_t Depth=0, MaxDepth=0;
		myNode<Item>* root_ptr;
		root_ptr = myBST.root();
	 	FindMaxDepth( root_ptr, Depth, &MaxDepth );
	 	return MaxDepth;
	}
	
	template <class Item>
	void BSTDepth<Item>::FindMaxDepth(myNode<Item> *rootPtr, std::size_t Depth,std::size_t *MaxDepth )
	{
    	if(rootPtr != NULL) 
        {
        	Depth++;
           	if(Depth > *MaxDepth)
            	*MaxDepth = Depth;
           	FindMaxDepth(rootPtr->left(),Depth,MaxDepth);
           	FindMaxDepth(rootPtr->right(),Depth,MaxDepth);
        }
	}

#endif BSTDEPTH_H