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
		num1.push(*(new int(charNum - '0')));
	}

	string stringNum2;
	cout<<"Enter a large number: ";
	cin>>stringNum2;
	for(char& charNum : stringNum2){
		num2.push(*(new int(charNum - '0')));
	}

	int carry = 0;
	while(num1.isEmpty() == 0 || num2.isEmpty() == 0){
		int n1 = 0;
		int n2 = 0;

		if(num1.isEmpty() == 0){
			n1 = num1.pop();
		}
		if(num2.isEmpty() == 0){
			n2 = num2.pop();
		}

		int sum = n1 + n2 + carry;
		carry = (sum - (sum)%10)/10;
		int* digit = new int(sum%10);
		answer.push(*digit);
	}

	while(answer.isEmpty() == 0){
		cout<<answer.pop();
	}

	return 0;
}
