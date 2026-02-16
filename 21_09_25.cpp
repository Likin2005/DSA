#include <iostream>
#include <vector>
using namespace std;

int missingNum(vector<int> &arr)
{

    int n = arr.size() + 1;
    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n - 1; i++) 
    {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n; i++) 
    {
        if (hash[i] == 0) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int n;
    cout << "Enter n : \n";
    cin >> n;
    int c = 97;
    for(int i=1;i<=n;i++)
    {
        for(int j=2*(n-i);j>=1;j--)
        {
            cout << "-";
        }
        for(int j=1;j<=i;j++)
        {
            cout << char(c+n-j);
            if(j != i) cout << '-';
        }
        for(int j=i-1;j>=1;j--)
        {
            cout << "-";
            cout << char(c+n-j);
        }
        for(int j=2*(n-i);j>=1;j--)
        {
            cout << "-";
        }
        cout << endl;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=2*(n-i);j>=1;j--)
        {
            cout << "-";
        }
        for(int j=1;j<=i;j++)
        {
            cout << char(c+n-j);
            if(j != i) cout << '-';
        }
        for(int j=i-1;j>=1;j--)
        {
            cout << "-";
            cout << char(c-j+n);
        }
        for(int j=2*(n-i);j>=1;j--)
        {
            cout << "-";
        }
        cout << endl;
    }
    return 0;
}