#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool usingStack(ListNode *head)
{
    // TC: O(n) | SC: O(n)
    stack<int> st;
    ListNode *curr = head;

    while (curr)
    {
        st.push(curr->val);
        curr = curr->next;
    }

    curr = head;

    while (curr)
    {
        if (curr->val != st.top())
            return false;

        st.pop();
        curr = curr->next;
    }
    return true;
}

bool twoPointerRecursion(ListNode *right, ListNode **left)
{
    // TC: O(n) | SC: O(n)
    if (!right)
        return true;

    if (!twoPointerRecursion(right->next, left))
        return false;

    if (right->val != (*left)->val)
        return false;

    *left = (*left)->next;
    return true;
}

bool usingArray(ListNode *head)
{
    // TC: O(n) | SC: O(n)
    ListNode *curr = head;
    vector<int> arr;

    while (curr)
    {
        arr.push_back(curr->val);
        curr = curr->next;
    }

    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        if (arr[start] != arr[end])
            return false;
        ++start;
        --end;
    }
    return true;
}

ListNode *reverseLL(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *prev = NULL, *curr = head, *nextNode = head->next;
    while (curr && nextNode)
    {
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    curr->next = prev;
    return curr;
}

bool optimized(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverseLL(slow);
    fast = head;

    while (slow && fast)
    {
        if (slow->val != fast->val)
            return false;

        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
bool isPalindrome(ListNode *head)
{
    // return usingStack(head);

    // ListNode* left = head;
    // return twoPointerRecursion(head, &left);

    // return usingArray(head);

    return optimized(head);
}

void printListNodeLL(ListNode* curr)
{
    while(curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(1);

    cout << "Original LL: ";
    printListNodeLL(head);

    cout << isPalindrome(head) << endl;


    ListNode* head2 = new ListNode(1);
    curr = head2;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(1);
    
    cout << "Original LL: ";
    printListNodeLL(head2);
    cout << isPalindrome(head2) << endl;


    ListNode* head3 = new ListNode(1);
    curr = head3;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(0);

    cout << "Original LL: ";
    printListNodeLL(head3);
    cout << isPalindrome(head3) << endl;

    return 0;
}