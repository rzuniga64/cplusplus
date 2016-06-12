#include "myNode.h"

using namespace std;
	
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
	void inorder_print( const myNode<Item>* node_ptr)
	{
		if (node_ptr != NULL)
		{
			inorder_print( node_ptr->left() );
			std::cout << node_ptr->data() << "\n";
			inorder_print( node_ptr->right() );
		}
	}
	
	template <class Item>
	void tree_clear(myNode<Item>* root_ptr)
	{
		myNode<Item>* cursor = root_ptr;
		
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