#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
vector <int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

void numerical_to_roman(int question)
{
    string answer = "";
    int size = sizeof(values)/sizeof(int);
    for(int i=0;i<size;i++)
    {
        while(values[i] <= question)
        {
            answer+=roman[i];
            question-=values[i];
        }
    }
    cout << answer << endl;
}

void roman_to_number(string str)
{
    if( str == " ")
    {
        cout << "NULL"<< endl;
    }
    //XLVII
    int i=0;
    while(i<str.size())
    {
        int item_1 = str[i];
        
    }
}
int main()
{
    string answer = "" ;
    int question ;
    cout << " Enter the number : ";
    cin >> question;
    numerical_to_roman(question);
    return 0;
}