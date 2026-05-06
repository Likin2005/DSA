#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* link;

    ListNode(int val)
    {
        this->val = val;
        link = NULL;
    }
};

void traverse(ListNode* head)
{
    ListNode* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->link;
    }
}

ListNode* mergeList(ListNode* head1, ListNode* head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    ListNode* t1 = head1;
    ListNode* t2 = head2;
    ListNode* head = new ListNode(min(t1->val, t2->val));
    ListNode* tail = head;

    if(t1->val >= t2->val) t2 = t2->link;
    else t1 = t1->link;

    while(t1 != NULL && t2 != NULL)
    {
        if(t1->val > t2->val)
        {
            ListNode* x = new ListNode(t2->val);
            tail->link = x;
            tail = x;
            t2 = t2->link;
        }
        else
        {
            ListNode* x = new ListNode(t1->val);
            tail->link = x;
            tail = x;
            t1 = t1->link;
        }
    }

    while(t1 != NULL)
    {
        ListNode* x = new ListNode(t1->val);
        tail->link = x;
        tail = x;
        t1 = t1->link;
    }

    while(t2 != NULL)
    {
        ListNode* x = new ListNode(t2->val);
        tail->link = x;
        tail = x;
        t2 = t2->link;
    }

    return head;
}

vector<int> mergeVector(vector<int> &n, vector<int> &m)
{
    int i = 0, j = 0;
    vector<int> res;

    while(i < n.size() && j < m.size())
    {
        if(n[i] > m[j])
        {
            res.push_back(m[j++]);
        }
        else
        {
            res.push_back(n[i++]);
        }
    }

    while(i < n.size()) res.push_back(n[i++]);
    while(j < m.size()) res.push_back(m[j++]);

    return res;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(4);
    // ListNode* n4 = new ListNode(7);

    n1->link = n2;
    n2->link = n3;
    // n3->link = n4;

    ListNode* head1 = n1;

    ListNode* m1 = new ListNode(1);
    ListNode* m2 = new ListNode(3);
    ListNode* m3 = new ListNode(4);
    // ListNode* m4 = new ListNode(10);

    m1->link = m2;
    m2->link = m3;
    // m3->link = m4;

    ListNode* head2 = m1;

    traverse(head1);
    cout << endl;

    traverse(head2);
    cout << endl;

    ListNode dummy(0);
    ListNode* res = mergeList(head1, head2);
    traverse(res);
    return 0;
}