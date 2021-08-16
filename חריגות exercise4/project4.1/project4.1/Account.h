//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 4 Question 1
//this program simulate bank account. 
#pragma once
#include <iostream>
using namespace std;
class Account
{
private:
	int accountNumber;
	int code;
	int balance;
	static int sumWithdraw;
	static int sumDeposit;
public:
	void setBalance(int bal);//only access to balance
	int getBalance();
	int getCode();
	int getAccountNumber();
	void withdraw(int nis);
	void deposit(int nis);
	static int getSumWithdraw();//getting static var
	static int getSumDeposit();
	friend istream& operator>>(istream& is, Account& ac);//input
	Account(int accnum = 0, int c = 0, int bal = 0);//constructor
	~Account();
};

