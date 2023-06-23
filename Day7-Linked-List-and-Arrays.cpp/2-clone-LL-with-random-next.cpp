#include<bits/stdc++.h>
using namespace std;

template <typename T>   
class LinkedListNode
{
    public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void print(LinkedListNode<int> * head)
{
    cout << "LL: \n";

    while(head)
    {
        cout << head->data << ", " << (head->random? head->random->data: -1) <<"\n";

        head = head->next;
    }
    cout << "Print done!\n\n";
}

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *old)
{
    if(!old) return NULL;


    LinkedListNode<int> * oldTemp = old;
    
    // clone nodes, and make zig zag
    while(oldTemp)
    {
        LinkedListNode<int> *neww = new LinkedListNode<int>(oldTemp->data);
        neww->next = oldTemp->next;
        oldTemp->next = neww;
        oldTemp = neww->next;
    }

    // clone random pointers
    oldTemp = old;
    
    while(oldTemp)
    {
        LinkedListNode<int> *random = oldTemp->random;

        if(random) {
            oldTemp->next->random = random->next;
        } else {
            oldTemp->next->random = NULL;
        }

        oldTemp = oldTemp->next->next;
    }

    // make it LL back from zig zag
    oldTemp = old;
    LinkedListNode<int> * newHead = old->next, *neww = old->next;

    while(neww->next)
    {
        oldTemp->next = neww->next;
        neww->next = oldTemp->next->next;

        oldTemp = oldTemp->next;
        neww = neww->next;
    }
    oldTemp->next = NULL;

    return newHead;
}


int main()
{
    // 1 2 2 -1 3 4 4 -1 5 1 -1
    /*
        1 3
        2 -1
        3 5
        4 -1
        5 2
    */
    LinkedListNode<int> * head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    head->random = head->next->next;
    head->next->random = NULL;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = NULL;
    head->next->next->next->next->random = head->next;

    print(head);

    LinkedListNode<int> * newHead = cloneRandomList(head);

    print(newHead);

    return 0;
}