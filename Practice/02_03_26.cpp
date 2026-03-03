#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int> &num, int target)
{
    if(num.size() < 3) return {{}};
    vector<vector<int>> res;
    sort(num.begin(), num.end());

    for(int i=0;i<num.size();i++)
    {
        if(num[i] == num[i-1]) continue;
        int item = num[i];
        int left = i+1, right = num.size()-1;
        while(left < right)
        {
            if(num[left] + num[right] == target - item)
            {
                res.push_back({item, num[left], num[right]});
                left++,right--;

                while(left < right && num[left] == num[left-1])left++;
                while(left < right && num[right] == num[right+1])right--;
            }
            else if(num[left] + num[right] + item < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return res;
}

int threeSum_closest(vector<int> &nums, int target)
{
    if(nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for(int i=0;i<nums.size();i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        int item = nums[i];
        int left = i+1, right = nums.size()-1;
        while(left < right)
        {
            int sum = nums[left] + nums[right] + item;
            if(abs(target - sum) < abs(target - closest))
            {
                closest = sum;
            }
            else if(sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return closest;
}

int closest(vector<int> num)
{
    int value = abs(num[0]), closest = num[0];
    for(int i=1;i<num.size();i++)
    {
        if(abs(num[i]) < value)
        {
            closest = num[i];
            value = abs(num[i]);
        }
    }
    return max(value, closest);
}

int main()
{
    vector<int> res = {-1,2,1,-4};
    cout << threeSum_closest(res, 1) << endl;
    return 0;
}