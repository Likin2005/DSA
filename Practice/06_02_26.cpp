#include<bits/stdc++.h>
using namespace std;

int longest_consecutive_sequence(vector<int>& num)
{
    if(num.size() == 0) return 0;
    if(num.size() == 1) return 1;
    int longest = 1;
    unordered_set<int> seen(num.begin(), num.end());
    for(auto it : seen)
    {
        if(seen.find(it-1) == seen.end())
        {
            int item = it;
            int count = 1;
            while(seen.find(item + 1) != seen.end())
            {
                item++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

string multiply(string num1, string num2)
{
    long n1 = 0, n2 = 0;
    for(int i=0;i<num1.length();i++)
    {
        int x = num1[i] - '0';
        n1 = n1 * 10 + x;
    }
    for(int i=0;i<num2.length();i++)
    {
        int x = num2[i] - '0';
        n2 = n2 * 10 + x;
    }
    n1 = n1 * n2;
    return to_string(n1);
}

int main()
{
    cout << multiply("12", "12") << endl;
    return 0;
}