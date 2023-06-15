#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *remove(ListNode *head, int n)
{
    ListNode *slow = head, *fast = head;
    while (n > 0)
        fast = fast->next, n -= 1;

    // remove 1st Node
    if (!fast)
        return head->next;

    while (fast->next)
        fast = fast->next, slow = slow->next;

    slow->next = slow->next->next;
    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;

    while (n > 0)
    {
        fast = fast->next;
        n -= 1;
    }

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for (int i = 2; i <= 5; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    temp = head;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "After removing 2nd node from back:\n";

    head = remove(head, 2);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}