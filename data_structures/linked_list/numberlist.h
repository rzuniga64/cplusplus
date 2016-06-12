#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <cstddef>   // for NULL

class   NumberList
{
private:
    struct ListNode    // a data type
    {
        double value;           // data
        struct ListNode *next;  // ptr to next node
    };
    ListNode *head;          // the list head
    
public:
    NumberList();
    NumberList(const NumberList &);
    
    ~NumberList();
    
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList();

    void operator= (const NumberList &);
};
#endif
