#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#define M 10
using namespace std;

int remove_element(vector<int>& n,int target)
{
    int index = 0,count = 0;
    for(int i=0;i<n.size();i++)
    {
        if(n[i] != target)
        {
            n[index++] = n[i];
            count++;
        }
    }
    return count;
}

void sort_two_vector(vector<int>& n1, int m,vector<int>& n2,int n)
{
    //nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i >= 0 && j >= 0)
    {
        if(n1[i] < n2[j])
        {
            n1[k--] = n2[j--];
        }
        else
        {
            n1[k--] = n1[i--];
        }
    }

    while( j>= 0)
    {
        n1[k--] = n2[j--];
    }
    for(int i : n1)
    {
        cout << i << " ";
    }
}

bool valid_anagrams(string s1,string s2)
{
    if(s1.length() != s2.length()) return false;
    unordered_map<char,int> freq;
    for(char i : s1)
    {
        freq[i]++;
    }
    for(char i : s2)
    {
        freq[i]--;
    }
    for(auto it : freq)
    {
        if(it.second != 0)
        {
            return false;
        }
    }
    return true;
}

int longest_substring(string s)
{
    if(s.empty()) return 0;
    unordered_set<char> seen;
    int left=0,max_len = 0;
    for(int i=0;i<s.size();i++)
    {
        while(seen.count(s[i]))
        {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[i]);
        max_len = max(max_len,i-left+1);
    }
    return max_len;
}

int third_largest(vector<int>& n)
{
    int largest = INT16_MIN;
    int second = INT16_MIN;
    int third = INT16_MIN;
    for(int i : n)
    {
        if(i > largest)
        {
            third = second;
            second = largest;
            largest = i;
        }
        else if( i < largest && i > second)
        {
            third = second;
            second = i;
        }
        else if(i < second && i > third)
        {
            third = i;  
        }
    }
    return third;
}

int main()
{
    vector<int> n = {1,2};
    return 0;
}