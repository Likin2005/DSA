#include<bits/stdc++.h>
using namespace std;

int maximum_sum_window(vector<int> num, int k)
{
    if(num.empty()) return 0;
    int sum = 0, x = num.size();
    if(k > x) return -1;
    for(int i=0;i<k;i++) // First window sum
    {
        sum += num[i];
    }
    int max_sum = sum;
    for(int i=k;i<x;i++)
    {
        sum = sum - num[i-k] + num[i];
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int min_window(vector<int> &num, int k)
{
    if(num.empty()) return -1;
    int sum = 0, x = num.size(), left = 0, len = INT_MAX;
    for(int i=0;i<x;i++)
    {
        sum += num[i];
        
        while(sum >= k)
        {
            len = min(len, i-left+1);
            sum -= num[left];
            left++;
        }
        
    }
    return (len == INT_MAX) ? -1 : len;
}

int main()
{
    vector<int> n = {1,1,1,1,2,2,1,3,4};
    cout << min_window(n, 4) << endl;
    return 0;
}