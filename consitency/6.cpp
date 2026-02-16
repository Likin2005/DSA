#include<bits/stdc++.h>
using namespace std;

bool linear_search(vector<int> &n, int k)
{
    for(int i : n)
    {
        if(i == k)
        {
            return true;
        }
    }
    return false;
}

int longest_consecutive_sequence(vector<int> &n)
{
    int last = n[0],x = n.size(),count = 0, max_count = 0;
    sort(n.begin(),n.end());
    for(int i=1;i<x;i++)
    {
        if(last+1 == n[i])
        {
            count++;
            last = n[i];
        }
        else if(last+1 != n[i])
        {
            count = 0;
            last = n[i];
        }
        max_count = max(count, max_count);
    }
    return max_count;
}

int longest(vector<int> &n)
{
    int x = n.size(), longest = 1;
    unordered_set<int> s(n.begin(), n.end());
    for(auto it : s)
    {
        if(!s.count(it-1)) //finding starting point and counting only the starting point
        {
            int curr = it;
            int count = 1;
            while(s.find(curr+1) != s.end())
            {
                count++;        // increment the count and increment to it's next value.
                curr++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main()
{
    vector<int> n = {2,5,9,10,77,6,1,3,66,4,67,69,100,68};
    vector<vector<int>> a;
    cout << longest(n); 
    return 0;
}