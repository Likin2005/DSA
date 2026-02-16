#include<bits/stdc++.h>
using namespace std;

pair<int,int> x(vector<int>& arr)
{
    pair<int, int> res;
    int largest = INT_MIN, smallest = INT_MAX;
    for(int i : arr)
    {
        if(i > largest)
        {
            largest = i;
        }
        if(i < smallest)
        {
            smallest = i;
        }
    }
    res.first = smallest, res.second = largest;
    return res;
}

bool valid_anagrams(string &s1, string &s2)
{
    if(s1.length() != s2.length()) return false;
    int a[256] = {0};
    for(int i : s1)
    {
        a[i]++;
    }
    for(int i : s2)
    {
        a[i]--;
    }
    for(int i :a)
    {
        if(i != 0) return false;
    }
    return true;
}

int main()
{
    string s1 = "aab", s2 = "abb";
    cout << valid_anagrams(s1, s2) << endl;
    return 0;
}