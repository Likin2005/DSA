#include<iostream>
using namespace std;

class Book
{
    public:
    string title;
    string author;
    float price;
    Book()
    {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
    }
    Book(string title, string author, float price)
    {
        this->title = title;
        this->author = author;
        this->price = price;
    }
    Book(Book &Obj)
    {
        this->title = Obj.title;
        this->author = Obj.author;
        this->price = Obj.price;
    }

    void getInfo()
    {
        cout << "Name : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Price : " << price << endl;
        cout << endl;
    }
};

int main()
{
    Book b1;
    b1.getInfo();

    Book b2("The Secrets of life","John",158.99);

    Book b3(b2);
    b3.author = "Ramesh";
    b2.getInfo();
    b3.getInfo();
    return 0;
}