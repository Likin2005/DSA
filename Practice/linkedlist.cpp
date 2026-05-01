#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* link;

    Node(int data)
    {
        this->data = data;
        link = NULL;
    }
};

void traverse(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->link;
    }
}

int main()
{
    // Creation of nodes
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);
    Node* n6 = new Node(60);

    // Linking of nodes
    n1->link = n2;
    n2->link = n3;
    n3->link = n4;
    n4->link = n5;
    n5->link = n6;

    // Creating the head
    Node*head = n1;

    // Function call
    traverse(head);
    return 0;
}