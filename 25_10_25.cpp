#include <bits/stdc++.h>
using namespace std;

vector<int> move_zeros(vector<int> zeros)
{
    int index = 0, x = zeros.size();
    for (int i = 0; i < x; i++)
    {
        if (zeros[i] != 0)
        {
            zeros[index++] = zeros[i];
        }
    }
    while (index < x)
    {
        zeros[index++] = 0;
    }
    return zeros;
}

vector<int> union_vector(vector<int> n1, vector<int> n2)
{
    int x = n1.size(), y = n2.size();
    int index_1 = 0, index_2 = 0;
    vector<int> union_vec;
    while(index_1 < x && index_2 < y)
    {
        if(n1[index_1] <= n2[index_2])
        {
            if(union_vec.empty() || union_vec.back() != n1[index_1])
            {
                union_vec.push_back(n1[index_1]);
            }
            index_1++;
        }
        else if(n1[index_1] > n2[index_2])
        {
            if(union_vec.empty() || union_vec.back() != n2[index_2])
            {
                union_vec.push_back(n2[index_2]);
            }
            index_2++;
        }
    }
    while(index_1 < x)
    {
        if(union_vec.empty() || union_vec.back() != n1[index_1])
        {
            union_vec.push_back(n1[index_1]);
        }
        index_1++;
    }
    while(index_2 < y)
    {
        if(union_vec.empty() || union_vec.back() != n2[index_2])
        {
            union_vec.push_back(n2[index_2]);
        }
        index_2++;
    }
    return union_vec;
}

vector<int> intersection(vector<int> &n1, vector<int> &n2)
{
    vector<int> cmn;
    int i=0,j=0,x = n1.size(), y = n2.size();
    while(i < x && j < y)
    {
        if(n1[i] == n2[j])
        {
            if(cmn.empty() || cmn.back() != n1[i])
            {
                cmn.push_back(n1[i]);
            }
            i++,j++;
        }
        else if(n1[i] < n2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return cmn;
}

int missing_number(vector<int> &n)
{
    int x = n.size();
    vector<int> hash(x+1, 0);
    for(int i=0;i<x;i++)
    {
        hash[n[i]]++;
    }
    for(int i=1;i<=x+1;i++)
    {
        if(hash[i] == 0)
        {
            return i;
        }
    }
}

int main()
{
    vector<int> x = {1, 2, 2, 3, 4, 5, 6}, y = {2, 3, 3, 5, 6, 6, 7};
    int res = missing_number(x);
    cout << res << endl;
    return 0;
}