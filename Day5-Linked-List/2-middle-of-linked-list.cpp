#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    for (int i = 2; i <= 5; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    ListNode* curr = head;

    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    ListNode *middle = middleNode(head);
    cout << "Middle: " << middle->val << endl;

    cout << "\n------------------\n";

    curr = head;
    while(curr->next) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    curr->next = new ListNode(6);
    cout << curr->val << endl;

    middle = middleNode(head);
    cout << "Middle: "  << middle->val << endl;

    return 0;
}