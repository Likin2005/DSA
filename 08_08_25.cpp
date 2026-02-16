#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int second_largest(vector<int>& nums)
{
    int largest = INT16_MIN;
    int second = INT16_MIN;
    for(int i : nums)
    {
        if(i > largest)
        {
            second = largest;
            largest = i;
        }
        else if(i < largest && i > second)
        {
            second = i;
        }
    }
    return (second == INT16_MIN) ? -1 : second;
}

vector<int> move_zeros(vector<int>& nums)
{
    int index = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] != 0)
        {
            nums[index++] = nums[i];
        }
    }
    while(index < nums.size())
    {
        nums[index++] = 0;
    }
    return nums;
}

bool is_symmetric(vector<vector<int>>& nums)
{
    int n = nums.size();
    for(vector<int> i : nums)
    {
        if(i.size() != n)
        {
            return false;
        }
    }
    
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums[i].size();j++)
        {
            if(nums[i][j] != nums[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> n = {{1,2,3},{2,4,5},{3,5,6}};
    cout << is_symmetric(n) << endl;
    return 0;
}