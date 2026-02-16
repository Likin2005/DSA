#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int vowel_count(string str)
{
    int count = 0;
    for(char i : str)
    {
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
        {
            count++;
        }
    }
    return count;
}

int is_palindrome(int n)
{
    int temp = n;
    if(n < 0)
    {
        return false;
    }
    int rev=0;
    while(n != 0)
    {
        int rem = n % 10;
        n = n/10;
        rev = rem + rev*10;
    }
    return (temp == rev) ? true : false;
}

vector<int> intersection_arrays(vector<int>& a, vector<int>& b)
{
    unordered_set<int> x(a.begin(),a.end());
    unordered_set<int> res;
    for(int i : b)
    {
        if(x.count(i))
        {
            res.insert(i);
        }
    }
    vector<int> result(res.begin(),res.end());
    return result;
}

vector<int> intersection(vector<int>& a, vector<int>& b)
{
    vector<int> res;
    int i=0,j=0;
    int item = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] == b[j] && item != a[i])
        {
            item = a[i];
            res.push_back(a[i]);
            i++,j++;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return res;
}

vector<int> rotate_array(vector<int> & n,int k)
{
    int times = 0,x = n.size();
    if(k == 0) return n;

    k = k % x;
    while(times != k)
    {
        int item = n[0];
        for(int i=0;i<x-1;i++)
        {
            n[i] = n[i+1];
        }
        n[x-1] = item;
        times++;
    }
    return n;
}

int longest_substring(string s)
{
    unordered_set<char> seen;
    int left = 0,max_len = 0;
    for(int right = 0;right < s.size();right++)
    {
        while(seen.count(s[right]))
        {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        max_len = max(max_len,right-left+1);
    }
    return max_len;
}

int main()
{
    string s = "abcababcda";
    cout << longest_substring(s) << endl;
    return 0;
}