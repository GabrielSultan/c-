#include <iostream>
#include <vector>
#include <string>
using namespace std;



//crreating  our Account class
class Account {
public:
    int accnum;              
    string name;             
    double balance;         
    vector<string> transac;  

    //the constructor 
    Account(int a, string n, double init) {
        accnum = a;
        name = n;
        balance = init;
        transac.push_back("Initial deposit: " + to_string(init));
    }

    //deposit money in the account
    void depo(double amount) {
        balance = balance+ amount ;
        transac.push_back("deposit : "+ to_string(amount));
        cout << "deposit is succesful. new balance now : " << balance << endl;
    }


    // method to withdraw money from the accout
    bool withdraw(double amount) {
        if (amount>balance) {
            cout<< "withdraw impossible" << endl; // checking if ther is enough funds to withdraw
            return false;
        }
        balance= balance-amount ;
        transac.push_back("withdrawal:" + to_string(amount));
        cout << "withdrawal have been succesful! new balance : " << balance << endl;
        return true ;
    }
    // display method
    void display() {
        cout <<"account number: "<<accnum<< endl;
        cout <<"name: "<< name<< endl;
        cout<<"balance :"<< balance <<endl;
        cout << "transaction :" <<endl ;
        for (int i = 0; i<transac.size(); i++) {
            cout << "-" << transac[i] << endl;
        }
    }
};





// Our bank class
class Bank {
public:
    vector<Account> accounts; 
    int nextAccountNumber ;    // next account number to assign

//constructor
    Bank() {
        nextAccountNumber=1001;
    }


//creating a new account
    void creation() {
        string name;
        double initial ;
        cout<< "enter name:";
        cin.ignore(); // cleaning the input buffer
        getline(cin, name);
        cout << "Enter initial deposit: ";
        cin >> initial;
        
        //add it to the list
        Account a(nextAccountNumber,name,initial);
        accounts.push_back(a);
        cout<<"Account creation successful. Number: " << nextAccountNumber<<endl;
        nextAccountNumber++ ;
    }

    // find an accout
    Account*FindIt(int num) {
        for (int i=0; i<accounts.size(); i++){
            if(accounts[i].accnum == num)
                return &accounts[i];
        }
        return NULL;
    }





//deposit money into an account
    void depositMoney() {
        int num;
        double amount; //using double for the cents
        cout<<"enter an account number: ";
        cin>> num;
        Account*a=FindIt(num);
        if(a==NULL){
            cout <<"this account doesn t exist..." <<endl;
            return;
        }
        cout << "enter deposit amount : ";
        cin>>amount;
        a->depo(amount);
    }





//withdraw money from an account
    void withdrawMoney() {
        int num;
        double amount;
        cout <<"enter an account number: ";
        cin >>num;
        Account* a =FindIt(num);
        if(a==NULL){
            cout << "his account doesn t exist..." <<endl;
            return;
        }
        cout << "withdrawal amount : " ;
        cin >>amount;
        a->withdraw(amount);
    }



//transfer funds between two accounts
    void transferFund() {
        int fromNum, toNum;
        double amount;
        cout<<"enter sender account number: ";
        cin >>fromNum;
        Account* sender = FindIt(fromNum);
        if (sender== NULL) {
            cout <<"this account doesn t exist..." << endl;
            return;
        }
        cout<< "enter recipient account number : ";
        cin >>toNum;
        Account* receiver =FindIt(toNum);
        if (receiver==NULL) {
            cout << "this account doesn t exist..." <<endl;
            return;
        }

        cout << "enter transfer amount: " ;
        cin >>amount;
        if (sender->withdraw(amount)) {
            receiver->depo(amount);
            cout<< "transfer have been successful!" << endl;
        }
    }



//display details of an account
    void displayAccount() {
        int num;
        cout<<"enter an account number : ";
        cin>> num;
        Account* a=FindIt(num);
        if (a ==NULL) {
            cout <<"his account doesn t exist..." <<endl;
            return ;
        }

        a->display();
    }
};




int main() {
    Bank bank;
    int choice;
    
//loop
    while (true) {
        cout <<"choose an option" << endl;
        cout <<"-------------------------------------" << endl;
        cout <<"1. create an account" << endl;
        cout <<"2. deposit money" << endl;
        cout <<"3. withdraw money" << endl;
        cout <<"4. transfer fund" << endl;
        cout <<"5. display account informations" << endl;
        cout <<"6. end" << endl;
        cout <<"enter your choice : ";
        cin >> choice;


        
        if (choice== 1)
            bank.creation();
        else if (choice== 2)
            bank.depositMoney();
        else if (choice== 3)
            bank.withdrawMoney();
        else if (choice== 4)
            bank.transferFund();
        else if (choice== 5)
            bank.displayAccount();
        else if (choice== 6) {
            break;
        }
        else
            cout << "try again please"<< endl;
    }
    return 0;
}
