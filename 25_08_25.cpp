#include<bits/stdc++.h>
using namespace std;

vector<int> rotate_array(vector<int>& nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    return nums;
}

int second_largest(vector<int>& n)
{
    if(n.empty()) return -1;
    int largest = INT16_MIN;
    int second = INT16_MIN;
    for(int i : n)
    {
        if(i > largest)
        {
            second = largest;
            largest = i;
        }
        else if(i > second && i < largest)
        {
            second = i;
        }
    }
    return second;
}

bool valid_anagrams(string n1,string n2)
{
    if(n1.length() != n2.length()) return false;
    unordered_map<char,int> seen;
    for(char i : n1)
    {
        seen[i]++;
    }
    for(char i : n2)
    {
        seen[i]--;
    }
    for(auto it : seen)
    {
        if(it.second != 0)
        {
            return false;
        }
    }
    return true;
}

void print(int x)
{
    cout << x << endl;
}

void print(double x)
{
    cout << x << endl;
}

void print(string x)
{
    cout << x << endl;
}

int main()
{
    print(9);    
    print(34.566);    
    print("Apple");   
    return 0;
}