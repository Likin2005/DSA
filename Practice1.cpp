#include<iostream>

using namespace std;

int main()
{
    int n,count=1;
    cin >> n ;
    for(int i = 1;i <= n ;i ++)
    {
        for(int j = 1;j <=i;j++)
        {

        }
        cout << "\n";
    }
    return 0;
}


/* for(int i=1;i<=n;i++)(Inverted half pyramid)
{
    for(int j=n;j>=1;j--)
    {
        (j >= i) ? cout << "* ":cout << " ";
    }
    cout << "\n";

    for(int i=1;i<=n;i++)(Half pyramid)
    {
    for(int j=1;j<=n;j++)
    {
        (j <= i) ? cout << "* ":cout << " ";
    }
    cout << "\n";

    for(int i=1;i<=m;i++)(Hollow rectangle)
    {
        for(int j=1;j<=n;j++)
        {
            if(i == 1 or i == m or j == 1 or j == n)
            {
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
    }
    for(int i=1;i<=n;i++) (Right aligned Half pyramid)
    {
        for(int j =n;j>=1;j--)
        {
            (i >= j) ? cout << "* ":cout << "  ";
        }
        cout << "\n";
    }
    for(int i=1;i<=n;i++)(Half pyramid with numbers)
    {
        for(int j =1;j<=n;j++)
        {
            (j <= i) ? cout << j << " " : cout << " ";
        }
        cout << "\n";
    }
    for(int i=1;i<=n;i++)(Floyd's triangle)
    {
        for(int j =1;j<=i;j++)
        {
            cout << count << " ";
            count+=1;
        }
        cout << "\n";
    }
    for(int i = 1;i <= n ;i ++)(0 and 1 triangle)
    {
        for(int j = 1;j <=i;j++)
        {
            if ((i + j)% 2 == 0)
            {
                cout << "1 " ;
            }
            else{
                cout <<"0 ";
            }
        }
        cout << "\n";
    }
    
}*/