#include<bits/stdc++.h>
using namespace std;

int longest_subarray(vector<int> &n,int k)
{
    int right = 0, left = 0, x = n.size(), sum = 0, len = 0;
    while(right != x)
    {
        sum += n[right];

        while(sum > k)
        {
            sum -= n[left];
            left++;
        }

        if(sum == k)
        {
            len = max(len, right-left+1);
        }
        right++;
    }
    return len;
}

pair<int, int> two_sum(vector<int> &n ,int k)
{
    pair<int, int> res;
    unordered_map<int, int> map;
    int x = n.size(),target;
    for(int i=0;i<x;i++)
    {
        target = k - n[i];
        if(map.count(target))
        {
            res.first = i,res.second = map[target];
            return res;
        }
        map[n[i]] = i;
    }
}

vector<int> sort_zeros_ones_twos(vector<int> n)
{
    // int count_ones = 0, index = 0,x = n.size();
    // for(int i=0;i<x;i++)
    // {
    //     if(n[i] == 0)
    //     {
    //         n[index++] = 0;
    //     }
    //     else if(n[i] == 1)
    //     {
    //         count_ones++;
    //     }
    // }
    // while(count_ones--)
    // {
    //     n[index++] = 1;
    // }
    // while(index != x)
    // {
    //     n[index++] = 2;
    // }
    // return n;
    int x = n.size();
    int low = 0, mid = 0, high = x-1;
    while(mid <= high)
    {
        if(n[mid] == 0)
        {
            swap(n[mid],n[low]);
            mid++,low++;
        }
        else if(n[mid] == 1)        
        {
            mid++;
        }
        else
        {
            swap(n[mid],n[high]);
            high--;
        }
    }
    return n;
}

int main()
{
    vector<int> n = {1,0,0,2,2,1,2,0,0,1,2,0,2};
    vector<int> res = sort_zeros_ones_twos(n);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}