#include<iostream>
#include<vector>
using namespace std;

class Account
{
    private:
    string accHolder;
    int pin;
    float balance = 0;

    public:
    void setPin(int x){ pin = x; }
    void setName(string name){ accHolder = name; }
    void withDrawal(float amount)
    {
        if(balance>0 && amount <= balance)
        {
            cout << "Withdrawing "<< amount << " ......"<<endl;
            balance -= amount;
            cout << "Successfully withdrawn " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance....." << endl;
        }
    }
    int get_balance()
    {
        return balance;
    }
    void deposit(float amount)
    {
        cout << "Depositing " << amount <<  " ....."<<endl;
        balance+=amount;
        cout << "Amount of " << amount << " is successfully deposited into your account" << endl;
    }
    bool verify(int id)
    {
        return id == pin;
    }
    string getName()
    {
        return accHolder;
    }
    int getpin()
    {
        return pin;
    }
};

void createAccount(vector<Account>& acc)
{
    string name;
    cout << "Enter your name : "<<endl;
    cin.ignore();
    getline(cin,name);
    int pin;
    cout << "Enter your secret pin : "<<endl;
    cin >> pin;
    Account newUser;
    newUser.setName(name);
    newUser.setPin(pin);
    acc.push_back(newUser);
    cout << "Account created successfully for " << name << " !\n\n";
}

Account* login(vector<Account>& acc)
{
    string name;
    int pin;
    cout << "Enter your name : "<<endl;
    cin.ignore();
    getline(cin,name);
    cout << "Enter your secret pin : "<<endl;
    cin >> pin;
    for(auto& i : acc)
    {
        if(i.getName() == name && i.getpin() == pin)
        {
            cout << "Login successful!!!" <<endl;
            return& i;
        }
    }
    cout << "Invalid Username or Password" << endl;
    return nullptr;    
}

void greet()
{
    cout << "Welcome...."<<endl;
}

int main()
{
    vector <Account> acc;
    while(true)
    {
        cout << "1.Create Account and Pin\n2.Withdraw\n3.Deposit\n4.Check Balance\n5.Exit"<<endl;
        int choice;
        cout << "Enter your option : "<<endl;
        cin >> choice;
        if(choice == 1)
        {
            greet();
            createAccount(acc);
        }
        else if(choice == 2)
        {   
            Account* x = login(acc);
            if(x != nullptr)
            {
                cout << "Enter the amount to withdraw : " << endl;
                float amount;
                cin >> amount;
                x->withDrawal(amount);
            }
            else
            {
                cout << "User Doesn't exist, Create a new account "<<endl;
            }
        }
        else if(choice == 3)
        {
            Account* x = login(acc);
            if(x != nullptr)
            {
                cout << "Enter the amount to deposit : "<<endl;
                float amount;
                cin >> amount;
                x->deposit(amount);
            }
            else
            {
                cout << "User Doesn't exist, Create a new account "<<endl;
            }
        }
        else if(choice == 4)
        {
            Account* x = login(acc);
            if(x != nullptr)
            {
                cout << "Your current balance is : " << x->get_balance() << endl;
            }
            else
            {
                cout << "User Doesn't exist, Create a new account "<<endl;
            }
        }
        else if(choice == 5)
        {
            exit(0);
        }
        else
        {
            cout << "Invalid Option !!"<<endl;
        }
    }
    return 0;
}