#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* head = new Node<int>(0);
    Node<int>* curr = head;

    while(first && second)
    {
        if(first->data <= second->data) {
            curr->next = first;
            first = first->next;
        }
        else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    if(first) {
        curr->next = first;
    }

    if(second) {
        curr->next = second;
    }

    return head->next;
}

int main()
{
    Node<int>* first = new Node<int>(1);
    Node<int>* temp = first;
    for (int i = 3; i <= 7; i += 2)
    {
        temp->next = new Node<int>(i);
        temp = temp->next;
    }

    Node<int>* second = new Node<int>(2);
    temp = second;
    for (int i = 4; i <= 8; i += 2)
    {
        temp->next = new Node<int>(i);
        temp = temp->next;
    }

    Node<int>* curr = first;
    cout << "First:\n";
    while(curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    curr = second;
    cout << "Second:\n";
    while(curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    Node<int>* head = sortTwoLists(first, second);
    curr = head;

    cout << "\n------------------\n";
    cout << "Sorted:\n";
    while(curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}