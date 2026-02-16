#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

bool valid(char a,char b)
{
    return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
}
bool valid_parenthesis(string symbol)
{
    stack<char> s;
    for(int i=0;i<symbol.size();i++)
    {
        if(symbol[i] == '(' || symbol[i] == '[' || symbol[i] == '{')
        {
            s.push(symbol[i]);
        }
        else
        {
            if(!s.empty())
            {
                int item = s.top();
                s.pop();
                if(!(valid(item,symbol[i])))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty();
}

bool valid_anagrams(string s,string t)
{
    if(s.size() != t.size()) return false;
    int freq[26] = {0};

    for(int i=0;i<s.size();i++) freq[s[i]-'0']++;
    for(int i=0;i<t.size();i++) freq[t[i]-'0']--;

    for(int i=0;i<26;i++)
    {
        if(freq[i] != 0) return false;
    }
    return true;
}

bool frequency(string str1,string str2)
{
    unordered_map<char,int> dict;
    for(char i : str1)
    {
        dict[i]++;
    }
    for(char i : str2)
    {
        dict[i]--;
    }
    for(auto i : dict)
    {
        if(i.second != 0)
        {
            return false;
        }
    }
    return true;
}

int diagonal_sum(vector<vector<int>>& nums)
{
    int primary=0,secondary=0,total=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums[i].size();j++)
        {
            if(i==j)
            {
                primary+=nums[i][j];
            }
            if(i == nums[i].size()-1-j)
            {
                secondary+=nums[i][j];
            }
        }
    }
    if(nums.size() % 2 !=0)
    {
        return primary+secondary-nums[(nums.size()-1)/2][(nums.size()-1)/2];
    }
    else{
        return primary+secondary;
    }
}

void rotate_matrix(vector<vector<int>>& nums)
{
    int n = nums.size();
    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            res[j][n-1-i] = nums[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    rotate_matrix(nums);
    return 0;
}