#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#define M 10
using namespace std;

vector<int> unique_element(vector<int>& r)
{
    if(r.empty()) return r;
    int j=0;
    for(int i=1;i<r.size();i++)
    {
        if(r[i] != r[j])
        {
            j++;
            r[j] = r[i];
        }
    }
    r[j++] = r[r.size()-1];
    while(j < r.size())
    {
        r[j++] = 0;
    }
    return r;
}

int s1[M];
int s2[M];
int top1 = -1, top2 = -1;

void push1(int item)
{
    s1[++top1] = item;
}

void push2(int item)
{
    s2[++top2] = item;
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void enqueue(int item)
{
    while(top1 != -1)
    {
        push2(pop1());
    }

    s1[++top1] = item;
    while(top2 != -1)
    {
        push1(pop1());
    }
}

int dequeue()
{
    if(top1 == -1)
    {
        cout << "Queue empty\n";
        return -1;
    }
    return pop1();
}

int peak()
{
    if(top1 == -1)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    return s1[top1];
}

int main()
{
    return 0;
}