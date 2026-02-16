#include<bits/stdc++.h>
using namespace std;

vector<int> duplicates(vector<int> arr)
{
    unordered_map<int,int> freq;
    vector<int> res;
    for(int i : arr)
    {
        freq[i]++;
    }
    for(auto i : freq)
    {
        if(i.second > 1)
        {
            res.push_back(i.first);
        }
    }
    return res;
}

vector<int> findTwoElement(vector<int>& arr) 
{
    int missing, repeated,x=arr.size()+1;
    vector<int> hash(x,0);
    for(int i=0;i<x-1;i++)
    {
        hash[arr[i]]++;
    }
    for(int i : hash)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i=1;i<=x;i++)
    {
        if(hash[i] == 0)
        {
            missing = hash[i];
        }
        if(hash[i] == 2)
        {
            repeated = hash[i];
        }
    }
    return {repeated,missing};
}

int main()
{
    vector<int> a = {1,2,2,3,5,6};
    vector<int> res = findTwoElement(a);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}