#include<bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int maximum = candies[0];
    for(int i : candies)
    {
        if(i > maximum)
        {
            maximum = i;
        }
    }

    vector<bool> res(candies.size(), false);
    for(int i=0;i<candies.size();i++)
    {
        if(candies[i] + extraCandies >= maximum)
        {
            res[i] = true;
        }
    }
    return res;
}

int main()
{
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;

    vector<bool> res = kidsWithCandies(candies, extraCandies);
    for(int i : res)
    {
        cout << i << endl;
    }
    return 0;
}