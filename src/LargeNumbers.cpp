//============================================================================
// Name        : LargeNumbers.cpp
// Author      : Job
// Date		   : 10/28/2017
// Description : Adds two large numbers with stacks
//============================================================================

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {
	LinkedStack<int> num1;
	LinkedStack<int> num2;

	LinkedStack<int> answer;

	string stringNum1;
	cout<<"Enter a large number: ";
	cin>>stringNum1;
	for(char& charNum : stringNum1){
		//converts each char into an int and pushes it into the first number stack
		num1.push(*(new int(charNum - '0')));
	}

	string stringNum2;
	cout<<"Enter a large number: ";
	cin>>stringNum2;
	for(char& charNum : stringNum2){
		//converts each char into an int and pushes it into the second number stack
		num2.push(*(new int(charNum - '0')));
	}

	//pops all the ints from their respective stacks and adds them into the last stack
	int carry = 0;
	while(num1.isEmpty() == 0 || num2.isEmpty() == 0){
		int n1 = 0;
		int n2 = 0;

		//gets next int from the first number stack if any
		if(num1.isEmpty() == 0){
			n1 = num1.pop();
		}
		//gets next int from the second number stack if any
		if(num2.isEmpty() == 0){
			n2 = num2.pop();
		}

		//adds the two numbers and previous carried number
		int sum = n1 + n2 + carry;
		//finds the carry amount
		carry = (sum - (sum)%10)/10;
		//gets the 1's digit
		int* digit = new int(sum%10);
		//pushes the digit to the last stack
		answer.push(*digit);
	}

	//pops the whole last stack and outputs the digit as it goes
	while(answer.isEmpty() == 0){
		cout<<answer.pop();
	}

	return 0;
}
