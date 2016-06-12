//******************************************************************************
//
//	File:			myNode.h 
//	Author:			Raul Zuniga
//	Description:	Provides a template class for a node in a binary tree and 
//					functions for manipulating binary trees.  the template
//					parameter is the type of data in each node.
//
//	TYPEDEFS for the myNode<Item> template class:
//		Each node of the tree contains a piece of data and pointers to its
//		children.  Teh type of the data (myNode<Item>::value_type)
//		is the Item type from the template parameter.  The type may be any of 
//		the C++ built-in types(int, char, etc.), or a class with a default 
//		constructor, and an assignment operator.
//	
//	CONSTRUCTOR for myNode<Item> class:
//		myNode( 
//			const Item& init_data = Item(), 
//          myNode* init_left = NULL, 
//          myNode* init_right = NULL );
//		Postcondition:  The new node has its data equal to init_data, and its
//		child pointers equal to init_left and init_right.
//
//	MEMBER FUNCTIONS for the myNode<Item> class:
//	const Item&data() const		  			<----- const version
//	and
//	Item& data()							<----- non-const version
//		Postcondition: The return value is a reference to the data from this 
//		myNode.
//
//	const myNode* left() const	<----- const version
// 	and
//	myNode*& left()				<----- non-const version
//	and
//	const myNode* right() const 	<----- const version
//	and
//	myNode*& right()				<----- non_const version
//		Postcondition: The return value is a pointer to the left or right child
//		(which will be NULL if there is no child ).
//
//	void set_data(const Item& new_data)
//		Postcondition: The myNode now contains the specified new data.
//
//	void set_left(myNode* new_link)
//	and
//	void set_right(myNode* new_link)
//		Postcondition: The myNode now contains the specified new
//		link to a child.
//
//	bool is_leaf()
//		Postcondition: The return value is true if the node is a leaf; 
//		otherwise the return value is false.
//
//	NONMEMBER FUNCTIONS to manipulate binary tree nodes:
//
//	template <class Item>
//	void tree_clear(myNode<Item>*& root_ptr)
//		Precondition: root_ptr is the root pointer of a binary tree(whic may be
//		NULL for the empty tree).
//		Postcondition: All nodes at the root or below have been returned to the 
//		heap, and root_ptr has been set to NULL.	
//
//	template <class Item>
//	myNode<Item>* tree_copy(const myNode<Item>* root_ptr)
//		Precondition: root_ptr is the root pointer of a binary tree(which may 
//		be NULL for the empty tree).
//		Postcondition: A copy of the binary tree has been made, and the return
//		value is a pointer to the root of this copy.
//
//	DYNAMIC MEMORY usage:
//		If there is insufficient dynamic memory, then the following functions
//		throw bad_alloc:  tree _copy.
//
//******************************************************************************

#ifndef	MYNODE_H
#define MYNODE_H

#include <cstdlib>
using namespace std;

	template <class Item>
	class myNode
	{
	public:
		// TYPEDEF
		typedef Item value_type;
		// CONSTRUCTOR
		myNode( 
			const Item& init_data = Item(), 
            myNode* init_left = NULL, 
            myNode* init_right = NULL )
		{ 
			data_field = init_data;
			left_field = init_left;
  			right_field = init_right;
		};
		// MODIFICATION MEMBER FUNCTIONS
		Item& data();
		myNode*& left();
		myNode*& right();
		void set_data( const Item& new_data);
		void set_left( myNode* new_left);
		void set_right(myNode* new_right);
		// CONST MEMBER FUNCTIONS
		const Item& data() const;
		const myNode* left() const;
		const myNode* right() const;
		bool is_leaf() const;
	private:
		Item data_field;
		myNode *left_field;
		myNode *right_field;
	};

//	NONMEMBER FUNCTIONS to manipulate binary tree nodes:		
			
	template <class Item>
	myNode<Item>* tree_copy(const myNode<Item>* root_ptr);					 		
	 
	template <class Item>
	void tree_clear(myNode<Item>*& root_ptr);

	template <class Item>
	Item& myNode<Item>::data()
	{
		return data_field;
	}

	template <class Item>
	myNode<Item>*& myNode<Item>::left()
	{
		return left_field;
	}

	template <class Item>
	myNode<Item>*& myNode<Item>::right()
	{
		return right_field;
	}

	template <class Item>
	void myNode<Item>::set_data( const Item& new_data )
	{
		data_field = new_data;
	}

	template <class Item>
	void myNode<Item>::set_left( myNode* new_left )
	{
		left_field = new_left;
	}

	template <class Item>
	void myNode<Item>::set_right( myNode* new_right )
	{
		right_field = new_right;
	}

	template <class Item>
	const Item& myNode<Item>::data() const
	{
		return data_field;
	}

	template <class Item>
	const myNode<Item>* myNode<Item>::left() const
	{
		return left_field;
	}

	template <class Item>
	const myNode<Item>* myNode<Item>::right() const 
	{
		return right_field;
	}

	template <class Item>
	bool myNode<Item>::is_leaf() const
	{
		return (left_field == NULL) && ( right_field == NULL );
	}
	
	template <class Item>
	void tree_clear(myNode<Item>*& root_ptr)
	{
		myNode<Item>* cursor = NULL;
		
		if (root_ptr != NULL)
		{
			tree_clear( root_ptr->left() );
			tree_clear( root_ptr->right() );
			delete root_ptr;
			root_ptr = NULL;
		}
	}
	
	template <class Item>
	myNode<Item>* tree_copy(const myNode<Item>* root_ptr)	
	{
		myNode<Item> *l_ptr;
		myNode<Item> *r_ptr;
		
		if (root_ptr == NULL)
			return NULL;
		else
		{
			l_ptr = tree_copy( root_ptr->left() );
			r_ptr = tree_copy( root_ptr->right() );
			return
				new myNode<Item>(root_ptr->data(), l_ptr, r_ptr);
		}
	}	


#endif MYNODE_H

