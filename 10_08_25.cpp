#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;

string remove_vowel(string s)
{
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    string new_str = "";
    for(char i : s)
    {
        if(!vowels.count(i))
        {
            new_str+=i;
        }
    }
    return new_str;
}

vector<int> square_sort(vector<int>& nums)
{
    vector<int>res;
    for(int i : nums)
    {
        res.push_back(i*i);
    }
    sort(res.begin(),res.end());
    return res;
}

void square(vector<int>& nums)
{
    int n = nums.size();
    vector<int> res(n);
    int pos = n-1,right = n-1,left = 0;
    while(left <= right)
    {
        if(abs(nums[left]) > abs(nums[right]))
        {
            res[pos--] = nums[left] * nums[left];
            left++;
        }
        else{
            res[pos--] = nums[right] * nums[right];
            right--;
        }
    }
}

int subarray_sum_equals_k(vector<int>& nums, int k)
{
    int sum,count=0;
    for(int i=0;i<nums.size();i++)
    {
        sum = 0;
        for(int j=i;j<nums.size();j++)
        {
            sum+=nums[j];
            if(sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

int remove_duplicates_allow_twice(vector<int>& nums)
{
    if(nums.size() == 0)
    {
        return 0;
    }
    unordered_map<int ,int> freq;
    for(int i : nums)
    {
        freq[i]++;
    }
    int len=0;
    for(auto it : freq)
    {
        if(it.second > 2)
        {
            len+=2;
        }
        else
        {
            len+=it.second;
        }
    }
    return len;
}

int main()
{
    vector<int> s = {1,1,1,2,2,3};
    cout << remove_duplicates_allow_twice(s) << endl; 
    return 0;
}