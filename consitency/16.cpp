#include<bits/stdc++.h>
using namespace std;

vector<int> remove_duplicates(vector<int> &n)
{
    int item = n[0], x = n.size(),index = 1;
    for(int i=1;i<x;i++)
    {
        if(n[i] != item)
        {
            n[index++] = n[i];
            item = n[i];
        }
    }
    if(index <= x - 1)
    {
        while(index < x)
        {            
            n[index++] = 0;
        }
    }
    return n;
}

int buy_sell(vector<int> &n)
{
    int buy = n[0],profit = 0, x = n.size(),max_profit = 0;
    for(int i=1;i<x;i++)
    {
        profit = n[i] - buy;
        max_profit = max(profit, max_profit);
        buy = min(buy, n[i]);
    }
    return max_profit;
}

vector<int> leader(vector<int> &n)
{
    vector<int> res;
    int last = INT_MIN, x = n.size();
    for(int i = x-1; i>= 0; i--)
    {
        if(n[i] > last)
        {
            res.push_back(n[i]);
        }
        last = max(last, n[i]);
    }
    return res;
}

int longest_consecutive_sequence(vector<int> &n)
{
    if(n.empty()) return 0;
    unordered_set<int> seen(n.begin(), n.end());
    int max_count = 0;
    for(auto it : seen)
    {
        if(!seen.count(it - 1))
        {
            int item = it;
            int count = 1;
            while(seen.find(item+1) != seen.end())
            {
                item++;
                count++;
            }
            max_count = max(count, max_count);
        }
    }
    return max_count;
}

int main()
{
    cout << "I can do it and I will do it!!!" << endl;
    vector<int> n = {1,4,6,7,8,9,1,2,3,4,5,6,4};
    // vector<int> res = leader(n);
    // for(int i : res)
    // {
    //     cout << i << " ";
    // }
    cout << longest_consecutive_sequence(n) << endl;
    return 0;
}