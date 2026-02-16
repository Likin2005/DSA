#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

stack<int> linked_list;

void printLL(Node* head)
{
    Node* curr = head;
    while(curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void print_reverse(Node* head)
{
    Node* curr = head;
    while(curr != nullptr)
    {
        linked_list.push(curr->data);
        curr = curr->next;
    }
    cout << endl;
    while(!linked_list.empty())
    {
        cout << linked_list.top() << " ";
        linked_list.pop();
    }
}

int main()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Node* head = n1;
    printLL(head);
    print_reverse(head);
    return 0;
}