#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int> &num)
{
    if(num.size() < 0) return {};
    sort(num.begin(), num.end());
    vector<vector<int>> res;
    for(int i=0;i<num.size();i++)
    {
        if(i > 0 && num[i] == num[i-1]) continue;

        int left = i + 1, right = num.size() - 1;
        while(left < right)
        {
            if(num[left] + num[right] + num[i] == 0)
            {
                res.push_back({num[i], num[left], num[right]});
                left++, right--;

                while(left < right && num[left] == num[left-1])left++;
                while(left < right && num[right] == num[right+1])right--;
            }
            else if(num[left] + num[right] + num[i] > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return res;
}

string reverseWords(string s)
{
    if(s.empty()) return "";
    unordered_set<char> seen = {'a', 'e','i','o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = s.size()-1;

    while(left < right)
    {
        if(seen.find(s[left]) == seen.end())
        {
            left++;
        }
        else if(seen.find(s[right]) == seen.end())
        {
            right--;
        }
        else
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++, right--;
        }
    }
    return s;
}

vector<int> intersection(vector<int> num1, vector<int> num2)
{
    if(num1.empty()) return num2;
    if(num2.empty()) return num1;
    
    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());
    vector<int> res;

    int index_1 = 0, index_2 = 0, x = num1.size(), y = num2.size();
    while(index_1 < x && index_2 < y)
    {
        if(num1[index_1] == num2[index_2])
        {
            if(res.empty() || res.back() != num1[index_1])
            {
                res.push_back(num1[index_1]);
            }
            index_1++, index_2++;
        }
        else if(num1[index_1] > num2[index_2])
        {
            index_2++;
        }
        else
        {
            index_1++;
        }
    }
    return res;
}

string reverseStr(string s, int k)
{
    if(s.empty()) return "";
    if(k == 0) return s;

    
}

int main()
{
    // vector<int> n = {-1,0,1,2,-1,-4};
    // vector<vector<int>> res = three_sum(n);
    // for(vector<int> j : res)
    // {
    //     for(int i : j)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> n = {2,6,3,7,6}, m = {5,3,8,7};
    vector<int> res = intersection(n, m);
    for(int i : res)
    {
        cout << i << " ";
    }
    return 0;
}