#include<iostream>

using namespace std;

int main()
{
    int m,n;
    cout << "Enter the number of rows and columns : " << endl;
    cin >> m>>n;
    int arr[m][n];
    cout << "Enter the elements into the array : " << endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Normal Matrix : " << endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}