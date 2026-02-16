#include<bits/stdc++.h>
using namespace std;

void rearrangeArray(vector<int>& nums) 
{
    int pos = 0, neg = 1;
    int n = nums.size();

    while (pos < n && neg < n)
    {
        if (nums[pos] >= 0)
        {
            pos += 2;
        }
        else if (nums[neg] < 0)
        {
            neg += 2;
        }
        else
        {
            swap(nums[pos], nums[neg]);
            pos += 2;
            neg += 2;
        }
    }
    for(int i : nums)
    {
        cout << i << ' ';
    }
}

vector<int> leaders(vector<int> &nums)
{
    int x = nums.size(), maximum_left = nums[x-1];
    vector<int> lead;
    lead.push_back(nums[x-1]);
    for(int i = x-2;i>=0;i--)
    {
        if(nums[i] > maximum_left)
        {
            lead.push_back(nums[i]);
        }
        maximum_left = max(maximum_left, nums[i]);
    }
    return lead;
}

vector<int> x(vector<int> &nums)
{
    int x = nums.size(), maximum_left = nums[x-1], index = 1;
    vector<int> lead(x);
    lead[0] = nums[x-1];
    for(int i = x-2;i>=0;i--)
    {
        if(nums[i] > maximum_left)
        {
            lead[index++] = nums[i];
        }
        maximum_left = max(maximum_left, nums[i]);
    }
    return lead;
}

int main()
{
    vector<int> num = {1, 2, 5, 3, 1, 2};
    vector<int> res = x(num);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}