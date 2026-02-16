#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> set_zero(vector<vector<int>> &nums)
{
    vector<int> row(nums.size(),1), column(nums[0].size(),1);
    int r = nums.size(), c = nums[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(nums[i][j] == 0)
            {
                row[i] = 0, column[j] = 0;
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(row[i] == 0 || column[j] == 0)
            {
                nums[i][j] = 0;
            }
        }
    }
    return nums;
}

int number_of_subarray(vector<int> &nums, int target)
{
    int right = 0, left = 0, x = nums.size(), sum = 0,count = 0;
    while(right < x)
    {
        sum += nums[right];

        while(sum > target)
        {
            sum -= nums[left];
            left++;
        }

        if(sum == target)
        {
            count++;
        }
        right++;
    }
    return count;
}

int main()
{
    vector<int> x = {1,2,3,-3,1,1,1,4,2,-3};
    cout << number_of_subarray(x, 3) << endl;
    return 0;
}