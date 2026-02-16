#include<bits/stdc++.h>
using namespace std;

void printing()
{
    static int n = 5;
    if(n > 0)
    {
        cout << "Hello.......!" << endl;
        n--;
        printing();
    }
}

void print_numbers(int n)
{
    if(n > 0)
    {
        cout << n << " ";
        n--;
        print_numbers(n);
    }
}

vector<int> leader(vector<int> &n)
{
    vector<int> res;
    int x = n.size();
    int last = INT_MIN;
    for(int i=x-1;i>=0;i--)
    {
        if(n[i] > last)
        {
            res.push_back(n[i]);
        }
        last = max(last, n[i]);
    }
    return res;
}

int main()
{
    vector<int> n = {10,22,12,3,0,6};
    vector<int> res = leader(n);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}