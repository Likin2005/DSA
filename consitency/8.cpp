#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_90(vector<vector<int>> &n)
{
    int size = n.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            swap(n[i][j],n[j][i]);
        }
    }

    for(int z=0;z<size;z++)
    {
        for(int i=0,j=size-1;i<=j;i++,j--)
        {
            swap(n[z][i],n[z][j]);
        }
    }
    return n;
}

int main()
{
    vector<vector<int>> v(3, vector<int>(3));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> res = rotate_90(v);
    for(vector<int> i : res)
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}