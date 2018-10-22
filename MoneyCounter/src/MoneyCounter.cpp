//============================================================================
// Name        : MoneyCounter.cpp
// Author      : Mick Campittelli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

void prompt();

class Counter {

	int count, maxCount;
public:
	Counter() {
		maxCount = 9999;
		count = 0;
		cout << "Maximum value of the counter is " << maxCount << endl;
		cout << "Current value of the counter is " << count << endl;
	}
	Counter(int max) {
		maxCount = max;
		count = 0;
		cout << "Maximum value of the counter is " << maxCount << endl;
		cout << "Current value of the counter is " << count << endl;
	}

	void amount() {
		char inputArray[2];
		char number;
		int factor, amount;
		while (cin >> inputArray) {

			if (inputArray[0] == 'a')
				factor = 1;
			else if (inputArray[0] == 's')
				factor = 10;
			else if (inputArray[0] == 'd')
				factor = 100;
			else if (inputArray[0] == 'f')
				factor = 1000;
			else if (inputArray[0] == 'o') {
				break;
			}
			number = inputArray[1];
			amount = number - '0';
			count += factor * amount;

		}

	}

	bool checkOverflow(int count) {
		if (count <= maxCount) {
			cout << "No overflow....yet\n" << endl;
			return false;
		} else  {
			cout << "Overflow error\n" << endl;
			return true;
		}


	}
	int getCount() {
		return count;
	}

	void setCount() {
		count = 0;
		cout
				<< "Please enter an integer amount less than 9999 to initialize the counter.\n";
		cin >> maxCount;
		cout << "Maximum value of the counter is " << maxCount << endl;
		cout << "Current value of the counter is 0." << endl;
	}
};

void prompt() {
	cout << "Enter a key, either a, s, d, f, followed by 1-9, or o for overflow"
			<< endl;
	cout << "a = cents, s = dimes, d = dollars, f = tens of dollars" << endl;
}

int main(void) {

	Counter demo;
	while (demo.checkOverflow(demo.getCount()) == false) {
		prompt();
		demo.amount();
	}
	demo.setCount();

}

