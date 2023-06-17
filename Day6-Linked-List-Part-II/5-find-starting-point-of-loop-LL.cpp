#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{

    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return NULL;
    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    curr->next = new ListNode(4);
    curr = curr->next;
    curr->next = new ListNode(5);
    curr = curr->next;
    curr->next = new ListNode(6);
    curr = curr->next;
    curr->next = new ListNode(7);

    curr->next = head->next->next;

    ListNode *res = detectCycle(head);

    if (res)
        cout << res->val << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}