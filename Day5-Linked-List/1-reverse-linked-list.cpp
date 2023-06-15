#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* recursive(ListNode* head, ListNode* prev)
    {
        if(!head) return prev;

        ListNode* next = head->next;
        head->next = prev;

        return recursive(next, head);
    }

    ListNode* iterative(ListNode* curr)
    {
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            ListNode* nextEl = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextEl;
        }

        return prev;
    }

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->next = second;
    second->next = third;

    ListNode* curr = head;
    while(curr) 
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n------------------\n";

    ListNode* newHead = recursive(head, NULL);

    while(newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }



    return 0;
}