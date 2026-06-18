#pragma once

#include<iostream>
using namespace std;
namespace MathNumber {
	int RandomNumber(int f, int t) {

		return rand() % (t - f + 1) + f;

	}


	int Power(int a, int b) {
		if (b == 0) {
			return 1;
		}
		else {
			return (a * Power(a, b - 1));
		}
	}

	short readnumber(string messag) {

		cout << "\n" << messag << ":";
		short number = 0;
		cin >> number;
		return number;
	}

	int BitWaisAND2Number(int num1,int num2) {
		return (num1 & num2);
	}

	int BitWaisOR2Number(int num1, int num2) {
		return (num1 | num2);
	}

	int ReadNumber() {
		cout << "Pless Enter Number >>\n";
		int num;
		cin >> num;
		while(cin.fail()){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number ,Enter Avalid On :" << endl;;
			cin >> num;
		
		}
		return num;
	}
}