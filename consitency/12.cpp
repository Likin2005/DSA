#include<bits/stdc++.h>
using namespace std;

vector<int> find_union(vector<int> &nums1, vector<int> &nums2)
{
    if(nums1.empty()) return nums2;
    if(nums2.empty()) return nums1;
    vector<int> res;
    int index_1 = 0,index_2 = 0,x = nums1.size(),y = nums2.size();
    while(index_1 < x && index_2 < y)   
    {
        if(nums1[index_1] >= nums2[index_2])
        {
            if(res.empty() || res.back() != nums2[index_2])
            {
                res.push_back(nums2[index_2]);
            }
            index_2++;
        }
        else if(nums2[index_2] > nums1[index_1])
        {
            if(res.empty() || res.back() != nums1[index_1])
            {
                res.push_back(nums1[index_1]);
            }
            index_1++;
        }
    }

    while(index_1 < x)
    {
        if(res.empty() || res.back() != nums1[index_1])
        {
            res.push_back(nums1[index_1]);
        }
        index_1++;
    }
    while(index_2 < y)
    {
        if(res.empty() || res.back() != nums2[index_2])
        {
            res.push_back(nums2[index_2]);
        }
        index_2++;
    }
    return res;
}

int main()
{
    vector<int> n1 = {1,3,5,6,7};
    vector<int> n2 = {2,4,6,8,10};
    vector<int> res = find_union(n1,n2);
    for(int i : res)
    {
        cout << i << ' ';
    }
    return 0;
}