#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout << " ";
        }
        cout << i+1;
        for(int k=0;k<(2*(n-i-1))-1;k++)
        {
            cout << " ";
        }
        if(i != n-1)
        {
            cout << i+1;
        }
        cout << endl;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout << " ";
        }
        if(i != n-1)
        {
            cout << i+1;
        }
        for(int k=0;k<(2*(n-i-1))-1;k++)
        {
            cout << " ";
        }
        if(i != n-1)
        {
            cout << i+1;
        }
        cout << endl;
    }
    return 0;
}

/*Initialize a variable sum to 0.
Initialize a variable number to 1.
In each iteration, add number to sum.
Increment number by 2 in each iteration (i.e., 1, 3, 5, ...).
print number and sum:
Sum is: [The sum value]
Num is: [The number value]
Continue the loop as long as number is less than or equal to 50.
Print the final value of sum after the loop finishes: Final Sum: [The final sum value]*/