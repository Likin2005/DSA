#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
#define M 100
using namespace std;

vector<int> merge_sorted_array(vector<int> &n)
{
    if(n.size() == 0) return n;
    int index = 0;
    for(int i = 0;i<n.size();i++)
    {
        if(n[i]!= 0)
        {
            n[index++] = n[i];
        }
    }
    while(index < n.size())
    {
        n[index++] = 0;
    }
    return n;
}

int firstUniqChar(const string& s)
{
    unordered_map<char,int> freq;
    for(char i : s)
    {
        freq[i]++;
    }   
    for(int i = 0;i<s.size(); i++)
    {
        if(freq[s[i]] == 1)
        {
            return i;
        }
    }
}

int lengthOfLongestSubstring(const string& s)
{
    if(s.size() == 0) return 0;
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

class Stack
{
    public:
        int stack[M];
        int top = -1;
        void push(int x)
        {
            stack[++top] = x;
        }

        void pop()
        {
            top++;
        }

        int top()
        {

        }
};
int main()
{
    string s = "eetchode";
    cout << lengthOfLongestSubstring(s);
    return 0;
}