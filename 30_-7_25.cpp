#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<int> intersection(vector<int> n1, vector<int> n2)
{
    unordered_set<int> s(n1.begin(),n1.end());
    unordered_set<int> res;

    for(int i : n2)
    {
        if(s.count(i))
        {
            res.insert(i);
        }
    }

    vector<int> x(res.begin(),res.end());
    return x;
}

int sum_of_border(vector<vector<int>>& nums)
{
    int sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums[i].size();j++)
        {
            if(i == 0 || j == 0 || i == nums.size()-1 || j == nums[i].size()-1)
            {
                sum+=nums[i][j];
            }
        }
    }
    //(0,0),(0,1),(0,2)
    //(1,0),(1,1),(1,2)
    //(2,0),(2,1),(2,2)
    //(3,0),(3,1),(3,2)
    return sum;
}
void transpose(vector<vector<int>>& nums)
{
    int m = nums.size();
    int n = nums[0].size();

    vector<vector<int>> transposed(n,vector<int>(m,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            transposed[j][i] = nums[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

void first_non_repeating(string str)
{
    int a[256] = {0};
    for(char i : str)
    {
        a[i]++;
    }
    for(char s : str)
    {
        if(a[s] == 1)
        {
            cout << s;
            return;
        }
    }
    cout << "Not found" << endl;
}

void has(string str)
{
    unordered_map<char,int> dict;
    for(char i : str)
    {
        dict[i]++;
    }
    for(char s : str)
    {
        if(dict[s] == 1)
        {
            cout << s;
            return;
        }
    }
    cout << "\n";
}

int main()
{
    vector<vector<int>> n = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    cout << sum_of_border(n) << endl;
    return 0;
}