#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode *curr)
{
    int n = 0;

    while (curr)
    {
        curr = curr->next;
        ++n;
    }
    return n;
}

ListNode* bruteForce(ListNode *headA, ListNode *headB)
{
    // Hash Table
    // TC: O(m+n) | SC: O(m)
    unordered_map<ListNode*, int> hash;
    ListNode* curr = headA;
    while(curr) {
        hash[curr] = 1;
        curr = curr->next;
    }
    curr = headB;
    while(curr)
    {
        if(hash.find(curr) != hash.end()) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;

    /*
    // TC: O(n^2) | SC: O(1)
    ListNode *currA = headA;
    ListNode *currB = headB;

    while (currA)
    {
        while (currB)
        {
            if (currA == currB)
                return currA;
            currB = currB->next;
        }
        currA = currA->next;
        currB = headB;
    }
    return NULL;
    */
}

ListNode* spaceOpt(ListNode *headA, ListNode *headB)
{
    // TC: O(m+n) | SC: O(1)
    int m = length(headA), n = length(headB);
    
    if(m != n) {
        int steps = abs(m-n);
        
        if(n>m) swap(headA, headB);
        while(steps) {
            headA = headA->next;
            --steps;
        }
    }
    while(headA) {
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

ListNode* Optimized(ListNode *headA, ListNode *headB)
{
    ListNode* a = headA, *b = headB;

    while(a != b) 
    {
        a = a? a->next: headB;
        b = b? b->next: headA;
    }
    return a;
}

int main()
{   
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    ListNode *ans = Optimized(headA, headB);
    cout << ans->val << endl;


    return 0;
}