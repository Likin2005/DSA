#include<bits/stdc++.h>
using namespace std;

int maximum_ones(vector<int> &n)
{
    int max_one = 0, ones = 0,x = n.size();
    for(int i=0;i<x;i++)
    {
        if(n[i] == 1)
        {
            ones++;
        }
        else
        {
            ones = 0;
        }
        max_one = max(max_one, ones);
    }    
    return max_one;
}

int maxPower(string s) 
{
    int count = 0, max_count = 0,x = s.length();
    char item = s[0];
    for(int i=1;i<x;i++)
    {
        if(item == s[i])
        {
            count++;
        }
        else
        {
            count = 0;
            item = s[i];
        }
        max_count = max(count, max_count);
    }
    return max_count+1;
}

int longestSubarray(vector<int> &nums, int k)
{
    int right = 0, left = 0,x = nums.size(),sum = 0;
    int length = 0, max_length = 0;
    while(right < x)
    {
        sum += nums[right];
        
        while(sum > k)
        {
            sum -= nums[left];
            left+=1;
        }

        if(sum == k)
        {
            max_length = max(max_length, right - left + 1);
        }
        right+=1;
    }    
    return max_length;
}

int main()
{
    vector<int> n = {1,2,0,3,2,7,1,10,-1,5,4};
    // cout << maximum_ones(n) << endl;
    // string s = "a";
    // cout << maxPower(s) << endl;
    cout << longestSubarray(n,8) << endl;
    return 0;
}