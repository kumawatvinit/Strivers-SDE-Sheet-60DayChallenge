#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseLL(Node* head)
{
	if(!head || !head->next) return head;

	Node* prev = NULL, *curr = head, *nextNode = head->next;

	while(curr && nextNode)
	{
		curr->next = prev;
		prev = curr;
		curr = nextNode;
		nextNode = nextNode->next;
	} 

	curr->next = prev;
	return curr;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node* start = new Node(0);
	Node* curr = start;
	curr->next = head;

	
		for(int i=0; curr->next &&  i<n; ++i)
		{
			Node* itr = curr;
			int k = b[i];

			// moving to next sub-LL
			for(; itr && k>0; --k)
			{
				itr = itr->next;
			}

			Node* nextLL = NULL;

			// separating the LL
			if(itr) {
				// nextLL: TO Track next LL
				nextLL = itr->next;
				itr->next = NULL;
			}

			// reverse the LL of max size K
			curr->next = reverseLL(curr->next);

			// traverse till last node of reversed LL
			while(curr->next) curr = curr->next;

			// connect it to nextLL
			curr->next = nextLL;

		}
	return start->next;
}


ListNode* reverseLL(ListNode* head)
{
    if(!head || !head->next) return head;
    ListNode* prev = NULL, *curr = head, *nextNode = head->next;
    while(curr && nextNode)
    {
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    } 
    curr->next = prev;
    return curr;
}

ListNode* reverseKGroup(ListNode* head, int b) {
    ListNode* start = new ListNode(0);
	ListNode* curr = start;
	curr->next = head;

	for(; curr->next;)
	{
		ListNode* itr = curr;
		int k = b;
		// moving to next sub-LL
		for(; itr && k>0; --k)
		{
			itr = itr->next;
		}
		if(!itr) break;
		ListNode* nextLL = NULL;
		// separating the LL
		if(itr) {
			// nextLL: TO Track next LL
			nextLL = itr->next;
			itr->next = NULL;
		}
		// reverse the LL of max size K
		curr->next = reverseLL(curr->next);
		// traverse till last node of reversed LL
		while(curr->next) curr = curr->next;
		// connect it to nextLL
		curr->next = nextLL;
	}
	return start->next;
}

void printNodeLL(Node* curr)
{
    while(curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);


    int b[] = {2, 3};

    printNodeLL(head);
    cout << "After reverse operation:\n";
    Node* ans = getListAfterReverseOperation(head, 2, b);

    printNodeLL(ans);
    cout << endl;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    printListNodeLL(head2);
    cout << "After reverse operation: \n";
    ListNode* ans2 = reverseKGroup(head2, 2);
    
    printListNodeLL(ans2);
    cout << endl;

    return 0;
}