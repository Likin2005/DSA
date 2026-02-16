#include<bits/stdc++.h>
using namespace std;

vector<int> selection_sort(vector<int> &nums)
{
    int x = nums.size();
    for(int i=0;i<x;i++)
    {
        int index = i;
        for(int j=i+1;j<x;j++)
        {
            if(nums[i] > nums[j])
            {
                index = j;
            }
        }
        if(i != index)
        {
            swap(nums[i],nums[index]);
        }
    }
    return nums;
}

vector<int> bubble_sort(vector<int> &nums)
{
    int x = nums.size();
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j+1],nums[j]);
            }
        }
    }
    return nums;
}

vector<int> insertion_sort(vector<int> &nums)
{
    int x = nums.size();
    for(int i=0;i<x;i++)
    {
        int j=i;
        while(j>0 && nums[j-1] > nums[j])
        {
            swap(nums[j-1],nums[j]);
            j--;
        }
    }
    return nums;
}

vector<int> removeDuplicates(vector<int>& nums) 
{
    int index = 1,item = nums[0],x=nums.size();
    for(int i=1;i<x;i++)
    {
        if(nums[i] != item)
        {
            nums[index++] = nums[i];
            item = nums[i];
        }
    }
    while(index != x)
    {
        nums[index++] = -1;
    }
    return nums;
}
    
int main()
{
    vector<int> x = {3,2,1,0};
    vector<int> res = selection_sort(x);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}