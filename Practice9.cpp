#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int max_element_in_array(vector<int>& nums)
{
    int max_element = INT16_MIN;
    for(int i : nums)
    {
        if( i > max_element)
        {
            max_element = i;
        }
    }
    return max_element;
}

bool check_palindrome(string str)
{
    int i=0,j=str.length()-1;
    while(i <= j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
        i++,j--;
    }
    return true;
}

void two_sum(vector<int>& nums,int target)
{   // 2,5,4,8,6  target = 13
    unordered_map<int,int> dict;
    for(int i=0;i<nums.size();i++)
    {
        int item = target - nums[i];
        if(dict.find(item) != dict.end())
        {
            cout << i << " " << dict[item] << endl;
            return;
        }
        dict[nums[i]] = i;
    }
    cout << "Not found" << endl;
}

void move_zeros(vector<int>& nums)
{
    int pos = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] != 0)
        {
            nums[pos++] = nums[i];
        }
    }
    for(int i = pos;i<nums.size();i++)
    {
        nums[i] = 0;
    }

    for(int i : nums)
    {
        cout << i << " ";
    }
    
    cout << endl;

    int position = nums.size()-1;
    for(int i=nums.size()-1;i>-1;i--)
    {
        if(nums[i] != 0)
        {
            nums[position--] = nums[i];
        }
    }

    for(int i=position;i>-1;i--)
    {
        nums[i] = 0;
    }

    for(int i : nums)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> nums = {8,1,3,5,4,6};
    two_sum(nums, 12);
    return 0;
}