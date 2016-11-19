#include "BSTree.h"

using namespace std;

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