#include<bits/stdc++.h>
using namespace std;

int maximum_ones(vector<int> n)
{
    int count=0,max_count=0;
    for(int i : n)
    {
        if(i == 1)
        {
            count++;
            max_count = max(max_count,count);
        }
        else
        {
            count = 0;
        }
    }
    return max_count;
} 

int appearing_once(vector<int> n)
{
    int res = 0;
    for(int i : n)
    {
        res ^= i;
    }
    return res;
}

int kadane_algo(vector<int> n, int k)
{
    int x = n.size(),sum = 0,len = 0,max_len = 0;
    for(int i=0;i<x;i++)
    {
        sum = 0;
        for(int j=i;j<x;j++)
        {
            sum += n[j];
            if(sum == k)
            {
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

int main()
{
    vector<int> n = {1,0,-7,5,4,-1,3};
    int k = 3;
    int length = kadane_algo(n,k);
    cout << "Length : " << length << endl;
    return 0;
}