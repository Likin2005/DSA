#include<bits/stdc++.h>
using namespace std;

void row_zero(vector<vector<int>> &n,int i)
{
    int column = n[0].size();
    for(int k=0;k<column;k++)
    {
        if(n[i][k] != 0)
        {
            n[i][k] = -1;
        }
    }
}

void column_zero(vector<vector<int>> &n,int j)
{
    int row = n.size();
    for(int i=0;i<row;i++)
    {
        if(n[i][j] != 0)
        {
            n[i][j] = -1;
        }
    }
}

vector<vector<int>> mark_zeros(vector<vector<int>> &n)
{
    int r = n.size(), c = n[0].size();
    vector<int> rows(r,1), columns(c,1);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(n[i][j] == 0)
            {
                rows[i] = 0, columns[j] = 0;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(rows[i] == 0 || columns[j] == 0)
            {
                n[i][j] = 0;
            }
        }
    }
    return n;
}

bool verify(char i, char j)
{
    if((i == '(' && j == ')') || (i == '{' && j == '}') || (i == '[' && j == ']'))
    {
        return true;
    }
    return false;
}

bool valid_parenthesis(string &s)
{
    if(s.length() % 2 == 1) return false;
    stack<char> a;
    for(char i : s)
    {
        if(i == '(' || i == '[' || i == '{')
        {
            a.push(i);
        }
        else
        {
            if(a.empty()) return false;
            int item = a.top();
            a.pop();
            if(!verify(item,i))
            {
                return false;
            }
        }
    }
    if(a.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    for(int i=0;i<5;i++)
    {
        cin >> s;
        cout << valid_parenthesis(s) << endl;
    }
    return 0;
}