//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 4 Question 1
//this program simulate bank account. 
#include "Account.h"
#include <iostream>
using namespace std;

int Account::sumWithdraw = 0;//at start = 0
int Account::sumDeposit = 0;//same
//this functions sets new balance account
void Account::setBalance(int bal)
{
	this->balance = bal;
}
//this functions returns the balance.
int Account::getBalance() { return balance; }
//this functions returns the code.
int Account::getCode() { return code; }
//this functions returns the accountNumber.
int Account::getAccountNumber() { return accountNumber; }
//this functions withdraw money if sum of nis to withdraw is legal.
void Account::withdraw(int nis)
{
	if (balance - nis < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	balance -= nis;
	sumWithdraw += nis;
}
//this function deposit money if sum of nis is legal
void Account::deposit(int nis)
{
	if (nis > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
	balance += nis;
	sumDeposit += nis;
}
//this functions returns the sumWithdraw.
int Account::getSumWithdraw() { return sumWithdraw; }
//this functions returns the sumDeposit.
int Account::getSumDeposit() { return sumDeposit; }
//the operator >> for input
istream& operator>>(istream& is, Account& ac)
{
	int acNum, acCode;
	is >> acNum;
	is >> acCode;
	if (acCode < 1000 || acCode > 9999)
		throw "ERROR: code must be of 4 digits!\n";
	ac = Account(acNum, acCode, 0);
}
//ctr.
Account::Account(int accnum, int c, int bal)
{
	accountNumber = accnum;
	code = c;
	balance = bal;
}
Account::~Account()
{
}
