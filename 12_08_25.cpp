#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;

int insert_position(vector<int>& n,int target)
{
    //1,2,4,5,6 tar=3
    int start = 0,end = n.size()-1;
    while(start <= end)
    {
        int mid = start+end;
        if(target > n[mid-1] && target < n[mid+1])
        {
            return mid;
        }
        else if(n[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;//log(N)
}

vector<int> move_zeros(vector<int>& num)
{
    int index = 0;
    for(int i=0;i<num.size();i++)
    {
        if(num[i] != 0)
        {
            num[index++] = num[i];
        }
    }
    while(index < num.size())
    {
        num[index++] = 0;
    }
    return num;
}

bool valid_Anagram(string s, string t)
{
    if(s.size() != t.size()) return false;
    unordered_map<char,int> freq;
    for(char i : s)
    {
        freq[i]++;
    }
    for(char i : t)
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

int main()
{
    string s = "anagram";
    string t = "nagaram";
    cout << valid_Anagram(s,t); 
    return 0;
}