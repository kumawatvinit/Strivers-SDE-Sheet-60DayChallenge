#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// rotate right by k
Node *rotate(Node *head, int k)
{
    int size = 1;

    Node *temp = head;

    while (temp->next)
    {
        size += 1;
        temp = temp->next;
    }

    k %= size;

    k = size - k;
    temp->next = head;

    Node *prev = temp;
    temp = head;

    while (k > 0)
    {
        k -= 1;
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    return temp;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;

    for (int i = 2; i <= 5; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    cout << "Before rotation: " << endl;
    temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int k = 2;
    cout << "After rotating LL right by " << k << endl;
    head = rotate(head, k);
    temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}