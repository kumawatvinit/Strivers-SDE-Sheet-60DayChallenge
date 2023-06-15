#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

Node* bruteForce(Node* num1, Node* num2)
{
    int prev = 0;
    Node* head = new Node();
    Node* curr = head;

    while(num1 && num2)
    {
        int ans = num1->data + num2->data + prev;

        prev = ans/10;
        curr->next = new Node(ans%10);
        curr = curr->next;

        num1 = num1->next;
        num2 = num2->next;
    }

    while(num1) 
    {
        int ans = num1->data + prev;
        prev = ans/10;
        curr->next = new Node(ans%10);
        curr = curr->next;

        num1 = num1->next;
    }

    while(num2) 
    {
        int ans = num2->data + prev;
        prev = ans/10;
        curr->next = new Node(ans%10);
        curr = curr->next;

        num2 = num2->next;
    }

    if(prev) {
        curr->next = new Node(prev);
    }

    return head->next;
}

Node* opt(Node* num1, Node* num2)
{
    int prev = 0;
    Node* head = new Node();
    Node* curr = head;

    while(num1 || num2 || prev)
    {
        int ans = (num1? num1->data: 0) + (num2? num2->data: 0) + prev;

        prev = ans/10;
        curr->next = new Node(ans%10);
        curr = curr->next;

        num1 = num1? num1->next: num1;
        num2 = num2? num2->next: num2;
    }

    return head->next;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // return bruteForce(num1, num2);
    return opt(num1,num2);
}

void printReversed(Node* curr)
{
    if(curr == NULL) return;

    printReversed(curr->next);
    cout<<curr->data;
}


int main()
{
    Node* num1 = new Node(2, new Node(4, new Node(3)));
    Node* num2 = new Node(5, new Node(6, new Node(4)));

    cout << "First num: ";
    printReversed(num1);
    cout<<endl;
    cout << "Second num: ";
    printReversed(num2);
    cout<<endl;
    cout << "Sum: ";
    

    Node* ans = addTwoNumbers(num1, num2);
    printReversed(ans);
    cout<<endl;

    return 0;
}