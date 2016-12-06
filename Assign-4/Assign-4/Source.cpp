/*
Title: Assignment - 4
Author : Annik Cherton
Objective : Creating a simple bank transaction system with a parent class called "Transaction" 
and three child classes called "Withdraw", "Deposit" and "Transfer".
Object Description : 

	class Transaction
		public:
			int UserID
			float Amount
			virtual int Report();

	class Withdraw : public Transaction
		public: 
			[members]
			virtual int Report();

	class Deposit : public Transaction
		public: 
			[members]
			virtual int Report();

	class Transfer : public Transaction
		public:
			[members]
			virtual int Report();

*/

#include "stdio.h"
#include "math.h"
#include "iostream"
using namespace std;
#define NUM_TRANS 100
#define NUM_USERS 100

//Create a base Transaction class with members UserID and Amount, and a function Report that prints the transaction data.
class Transaction
{
public:
	int uID;
	int Amount;

	Transaction()
	{
		
	}

	virtual double Report() = 0;
};

//Create Child classes based on Transaction for Withdraw, Deposit, and Transfer.

//Add proper members and modify Report function to write a suitable report of that transaction type.
class Withdraw : public Transaction
{
public:
	//members

	Withdraw()
	{

	}

	double Withdrawl()
	{
		cout << "Enter the amount you wish to withrdaw: ";
		cin >> Amount;
		return Amount;
	}

	double Report(Transaction* t)
	{
		
		return printf("Withdrawl = $%f \n", t->Report());
		
	}
};

class Deposit : public Transaction
{
public:
	//members

	Deposit()
	{

	}

	double Report()
	{
		
	}

};

class Transfer : public Transaction
{
public:
	//members

	Transfer()
	{

	}

	double Report()
	{
		
	}

};

//Create a User class that has ID, a variable numTrans for number of transactions, and an array of Transaction pointers, with the size of 100.
class User
{
public:
	int UserID;
	int numTrans;
	Transaction* t[NUM_TRANS]; // No transaction created at first
	//Transactions will be created using child types: t[numTrans] = new Deposit();

	User()
	{
		numTrans = 0;
	}
};

//Create proper UI that allows the users to
void UI(User u[])
{
	int option;
	int uID;
	Transaction* trans;
	Withdraw* with;
	Deposit dep;
	Transfer tran;

	//Enter their ID
	cout << "Hello. Please enter your User ID: ";
	cin >> uID;

	while (u->numTrans <= 100)
	{
		//Do a transaction(choose type and enter the required information for it)
		cout << "Please choose an option: 1 - Withdraw   2 - Deposit   3 - Transfer   4 - Report   5 - Exit\n";
		cin >> option;
		//Create a proper transaction object and save it in the array
		if (option == 1)
		{	//u[uID].t[u[uID].numTrans] = new Withdraw();
			u->t[u->numTrans] = new Withdraw();
			with->Withdrawl();
		}
		if (option == 2)
		{
			u->t[u->numTrans] = new Deposit();

		}
		if (option == 3)
		{
			u->t[u->numTrans] = new Transfer();
		}
		u->numTrans++;
		//Get a report of all transactions
		if (option == 4)
			trans->Report(&trans);
		//Exit option
		if (option == 5)
			break;
	}
}

//MAIN FUNCTION
void main()
{
	//The system will have an array of user pointers: User* u[100];
	User u[NUM_USERS];
	//Every time the user enters an ID, if there is no user with that ID, then a new User object will be created : u[numUsers] = new User();
	UI(u);
}