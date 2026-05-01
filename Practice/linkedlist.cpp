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

struct linkedlist
{
    int item;
    linkedlist* next;
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

Node* insertAtHead(Node* head, int item)
{
    if(head == NULL)
    {
        Node* n1 = new Node(item);
        return n1;
    }
    Node* temp = new Node(item);
    temp->link = head;
    head = temp;
    return head;
}

Node* insertAtTail(Node* head, int item)
{
    if(head == NULL)
    {
        Node* temp = new Node(item);
        return temp;
    }

    Node* temp = head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    
    Node* newNode = new Node(item);
    temp->link = newNode;
    return head;
}

Node* deleteHead(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* temp = head;
    head = head->link;
    delete (temp);
    return head;
}

Node* deleteTail(Node* head)
{
    if(head == NULL) return NULL;
    
    Node* temp = head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    delete(temp);

    return head;
}

int countNodes(Node* head)
{
    int len = 0;
    if(head == NULL) return 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->link;
    }
    return len;
}

bool searchElement(Node* head, int item)
{
    if(head == NULL) return false;
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == item)
        {
            return true;
        }
        temp = temp->link;
    }
    return false;
}

Node* deleteByValue(Node* head, int item)
{
    if(head == NULL) return NULL;
    Node* temp = head;
    if(temp->data == item)
    {
        head = head->link;
    }
    while(temp->link != NULL)
    {
        if(temp->link->data == item)
        {
            temp->link = temp->link->link;
        }
        temp = temp->link;
    }
    return head;
}

Node* arrayToList(vector<int>& num)
{
    if(num.empty()) return NULL;

    Node* head = new Node(num[0]);
    Node* tail = head;

    for(int i=1;i<num.size();i++)
    {
        Node* temp = new Node(num[i]);
        tail->link = temp;
        tail = temp;
    }
    return head;
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

    // Node creation using structures
    linkedlist* l1 = new linkedlist{10, NULL};

    // Linking of nodes
    n1->link = n2;
    n2->link = n3;
    n3->link = n4;
    n4->link = n5;
    n5->link = n6;

    // Creating the head
    Node*head = n1;
    // traverse(head);
    // Function call
    vector<int> n = {2,4,6,8,10};
    Node* x = arrayToList(n);
    traverse(x);
    return 0;
}