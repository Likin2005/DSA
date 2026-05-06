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

Node* reverseList(Node* head)
{
    if(head == NULL) return NULL;
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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

Node* removeNthFromEnd(Node* head, int n)
{
    int count = countNodes(head);
    Node* temp = head;
    while(count--){
        temp = temp->link;
    }
    temp = temp->link->link;
    return head;
}

Node* removeByValue(Node* head, int val)
{
    if(head == NULL) return NULL;

    Node* temp = head;

    while(temp->link != NULL)
    {
        if(temp->link->data == val)
        {
            temp->link = temp->link->link;
        }
        else
        {
            temp = temp->link;
        }
    }
    return head;
}

int main()
{
    Node* n1 = new Node(7);
    Node* n2 = new Node(7);
    Node* n3 = new Node(7);
    Node* n4 = new Node(7);
    Node* n5 = new Node(7);
    Node* n6 = new Node(7);
    Node* n7 = new Node(7);

    n1->link = n2;
    n2->link = n3;
    n3->link = n4;
    n4->link = n5;
    n5->link = n6;
    n6->link = n7;

    Node* head = n1;
    traverse(head);
    cout << "\n";
    Node* res = removeByValue(head, 7);
    traverse(res);
    return 0;
}