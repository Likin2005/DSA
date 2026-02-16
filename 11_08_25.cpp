#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;

// vector<int> remove_element(vector<int>& n,int val)
// {
//     int left=0;
//     for(int i=1;i,n.size();i++)
//     {
//         if(n[left] == val)
//         {
//             n[left] = n[i];
//         }
//         left++;
//     }
//     return n;
// }

int find_index(vector<int>&n ,int target)
{
    for(int i=0;i<n.size();i++)
    {
        if(n[i] == target)
        {
            return i;
        }
    }
    return -1;
}

bool is_palindrome(string s)
{
    string new_str = "";
    for(int i=0;i<s.size();i++)
    {
        if(int(s[i]) >= 65 && int(s[i]) < 91)
        {
            new_str+=s[i]+32;
        }
        else if (int(s[i]) >= 97 && int(s[i]) < 123)
        {
            new_str += s[i];
        }
    }
    cout << new_str << endl;
    int i=0,j=new_str.size()-1;
    while(i <= j)
    {
        if(new_str[i] != new_str[j])
        {
            return false;
        }
        i++,j--;
    }
    return true;
}

int length_of_longes_substring(string s)
{
    unordered_set<char> seen;
    int left=0,max_len=0;
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

int number_of_subarray_sum(vector<int> &n, int target)
{
    int sum,count=0;
    for(int i=0;i<n.size();i++)
    {
        sum = 0;
        for(int j=i;j<n.size();j++)
        {
            sum+=n[j];
            if(sum == target)
            {
                count++;
            }
        }
    }
    return count;
}

vector<int> square_negative_array(vector<int>& n)
{
    vector<int> squares(n);
    int right=n.size()-1,left=0,pos=n.size()-1;
    while(left <= right)
    {
        if(abs(n[left]) > abs(n[right]))
        {
            squares[pos--] = n[left] * n[left];
            left++;
        }
        else 
        {
            squares[pos--] = n[right] * n[right];
            right--;
        }
    }
    return squares;
}

string convertToTitle(int columnNumber) 
    {
        string res = "";
        while(columnNumber != 0)
        {
            int rem = columnNumber % 26;
            res += char(65+rem);
            columnNumber = columnNumber / 26;
        }
        return res;
    }

int main()
{   
    string res = convertToTitle(701);
    cout << res ;
    return 0;
}