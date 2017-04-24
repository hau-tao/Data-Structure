/********************************************************************************
 * Hau Tao
 * lab1.cpp
 * 01/17/2016
 * This program implement infix-to-postfix expression conversion 
 * Valid operands are single digits and characters: 0-9 a-z A-Z
 * For example,   a + b - c     translates to   a b + c -
 *                a + b * c     translates to   a b c * +
 *               (a + 2) / (5 - d)   	goes to   a 2 + 5 d - /
 *               a + ((b - c) * d) / e   to   	a b c - d * e / +
 * Valid operators are: + - * / ( )
 * Highest precedence:  * /
 * Lowest precedence:   + -
 * ( has lowest precedence on the stack and highest precedence outside of stack.
 * ) never goes on stack.
 * Bottom of the stack has the lowest precedence than any operator.
 * Use a prec() function to compare the precedence of the operators based 
 * on the above rules.
 ********************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
int prec(char );
main()
{
    char in ;
	stack <int> my_stack;
	cout <<"Enter your input " << endl;
	cin >> in ;
	while(!cin.eof()){
		if((in >='a' && in <= 'z' )||(in >= '0' && in <= '9')|| (in >= 'A' && in <= 'Z'))
			cout << in;
		else {
			if(in == '(')
				my_stack.push(in);
			else if (in == ')'){
				if(!my_stack.empty() && my_stack.top() != '('  ){
					cout <<char( my_stack.top());
					my_stack.pop();
				} else
					cout <<"Error: No matching '('";
				
			}
			else if (in =='*'|| in =='/'|| in =='+'|| in=='-'){
				if(my_stack.empty() || prec(my_stack.top()) < prec(in))
					my_stack.push(in);
				else {
					cout << char(my_stack.top());
					my_stack.pop();
					my_stack.push(in);
				}
			}
			else
				cout << "Error input:";
		}
		cin >> in;
	}

	// print out the stack when stopping input
	while(!my_stack.empty()){
		if(my_stack.top()!= '('){
			cout << char(my_stack.top());
			my_stack.pop();
		} else
		      my_stack.pop();
	}
	cout << endl;

}

// Check precedence
int prec(char in )
{
	if(in =='*'|| in =='/')
		return 2;
	else if (in =='+'|| in =='-')
		return 1;
	else
		return 0;
	
}
