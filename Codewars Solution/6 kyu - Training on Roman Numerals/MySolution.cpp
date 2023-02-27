#include <iostream>
#include <string>
using namespace std;

string solution(int n) {
	string result;
	bool hundredDone = false, tenDone = false, oneDone = false;

	if ((n / 1000) != 0) {
		int i = n / 1000;
		for (int j = 0; j < i; j++) result += "M";
	}
	n %= 1000;

	if ((n - 900) >= 0) {
		result += "CM";
		hundredDone = true;
	}

	if ((n - 400) >= 0 && (n - 500) < 0) {
		result += "CD";
		hundredDone = true;
	}

	if ((n / 100) != 0 && hundredDone == false) {
		int i = n / 100;
		if (i >= 5) {
			result += "D";
			i -= 5;
		}
		for (int j = 0; j < i; j++) result += "C";
	}
	n %= 100;

	if ((n - 90) >= 0) {
		result += "XC";
		tenDone = true;
	}
	if ((n - 40) >= 0 && (n - 50) < 0) {
		result += "XL";
		tenDone = true;
	}
	if ((n / 10) != 0 && tenDone == false) {
		int i = n / 10;
		if (i >= 5) {
			result += "L";
			i -= 5;
		}
		for (int j = 0; j < i; j++) result += "X";
	}
	n %= 10;

	if (n == 9) {
		result += "IX";
		oneDone = true;
	}
	if (n == 4) {
		result += "IV";
		oneDone = true;
	}
	if (n > 0 && oneDone == false) {
		if (n >= 5) {
			result += "V";
			n -= 5;
		}
		for (int i = 0; i < n; i++) result += "I";
	}
	return result;
}

int main(void) {
	cout << solution(1000) << endl;
	cout << solution(182) << endl;
	cout << solution(1990) << endl;
	cout << solution(1875) << endl;
	return 0;
}
