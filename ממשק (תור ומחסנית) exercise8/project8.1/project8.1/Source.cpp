//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 1
//this program reads infex expression, prints the postfix and its value. 
#include "StackList.h"
#include<string>
#include <iostream>
using namespace std;
//this function gets infix string and returns its postfix.
string infixToPostfix(string infix)
{
	string str = "";
	StackList stk;
	char ch;
	for (int i = 0; i < infix.length(); i++)
	{
		ch = infix[i];
		if (ch == '(')
			stk.push(ch);
		else if (ch == ')')
		{
			str += ' ';
			while (stk.top() != '(')
				str += (char)stk.pop();
			stk.pop();
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')//operator
		{
			str += ' ';
			while ((ch == '+' || ch == '-') && (stk.top() == '*' || stk.top() == '/'))
			{
				str += (char)stk.pop();
				str += ' ';
			}
			stk.push(ch);
		}
		else//number
			str+= ch;
	}
	str += ' ';
	while (!stk.isEmpty())
	{
		str += stk.pop();
		str += ' ';
	}
	return str;
}
//this function gets string in postfix and return the value of expression 
int CalcPostfix(string postfix)
{
	StackList st;
	float num1 = 0, num2 = 0;
	int	ind = 0;
	while (ind < postfix.length())
	{
		if (postfix[ind] >= '0' && postfix[ind] <= '9')
		{
			num1 = 0;
			while (postfix[ind] != ' ')//calculating number
			{
				num1 = 10 * num1 + postfix[ind] - '0';
				ind++;
			}
			ind++;//skip ' '
			st.push(num1);
		}
		else
		{
			num1 = st.pop();
			num2 = st.pop();
			switch (postfix[ind])//active operator
			{
			case '+':
				num2 += num1;
				break;
			case '-':
				num2 -= num1;
				break;
			case '*':
				num2 *= num1;
				break;
			case '/':
				num2 /= num1;
				break;
			}
			st.push(num2);
			ind += 2;//skip ' '
		}
	}
	return st.pop();
}
int main()
{//main copied from the question
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << CalcPostfix(postfix) << endl;
	//system("pause");
	return 0;
}
//Running example:
//enter an infix expression as a string
//(5 + 3)*((20 / 10) + (8 - 6))
//5 3 + 20 10 / 8 6 - +*
//32
//Press any key to continue . . .