#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
	int data;
	Node *next;
	Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// /*
Node* mergeSort(Node* head1, Node* head2)
{
	if(!head2) return head1;
	head2 = mergeSort(head1->next, head2->next);

	// actually merge
	Node* first = head1, *second = head2;
	first->next = NULL;

	Node* start = new Node();
	start->child = head1;
	first = start;

	while(first->child && second)
	{
		if(first->child->data > second->data) {
			Node* temp = second->child;
			second->child = first->child;
			first->child = second;

			second = temp;
		}
		first = first->child;
	}

	if(second) {
		first->child = second;
	}

	return start->child;
}
// */

Node* solve(Node* a, Node* b)
{
	if(!a) {
		b->next = NULL;
		return b;
	}
	if(!b) {
		a->next = NULL;
		return a;
	}

	Node* ans;
	if(a->data < b->data) {
		ans = a;
		ans->child = solve(a->child, b);
	} 
	else {
		ans = b;
		ans->child = solve(a, b->child);
	}

	ans->next = NULL;
	return ans;
}

Node* flattenLinkedList(Node* head) 
{
	// return mergeSort(head, head->next);
	
	if(!head || !head->next) return head;
	
	return solve(head, flattenLinkedList(head->next));
}


int main()
{
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
   
    Node* head = new Node(5);
    auto temp = head;
    auto bt = head;
    bt->child = new Node(7);
    bt->child->child = new Node(8);
    bt->child->child->child = new Node(30);
    temp->next = new Node(10);

    temp = temp->next;
    bt = temp;
    bt->child = new Node(20);
    temp->next = new Node(19);
    temp = temp->next;
    bt = temp;
    bt->child = new Node(22);
    bt->child->child = new Node(50);
    temp->next = new Node(28);
    temp = temp->next;
    bt = temp;
    bt->child = new Node(35);
    bt->child->child = new Node(40);

    bt->child->child->child = new Node(45);

    Node* ans = flattenLinkedList(head);
    while(ans) {
    	cout << ans->data << " ";
    	ans = ans->child;
    }
           

    return 0;
}