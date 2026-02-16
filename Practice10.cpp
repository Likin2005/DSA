#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<char> reverse(vector<char>& nums)
{
    int i = 0,j = nums.size()-1;
    while(i < j)
    {
        char item = nums[j];
        nums[j--] = nums[i];
        nums[i++] = item;
    }
    return nums;
}

int count_digits(int number)
{
    int count = 0;
    while(number != 0)
    {
        count++;
        number/=10;
    }
    return count;
}

int unique(vector<int>& nums)
{
    int item = nums[0];
    int number = 1;
    for(int i=1;i<nums.size();i++)
    {
        if(item != nums[i])
        {
            number++;
            item = nums[i];
        }
    }
    return number;
}

int missing_number(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int x = nums[0];
    int i = 0;
    while(x == nums[i] && i < nums.size())
    {
        i++;
        x++;
    }
    return x++;
}

int sub_array(vector<int> nums,int target)
{
    int total = 0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++)
            {
                sum+=nums[k];
            }
            if(sum == target)
            {
                total+=1;
            }
        }
    }
    return total;
}

int main()
{
    vector<int> x = {0,0,0,0};
    int k = 0;
    cout << sub_array(x,k);
    return 0;
}