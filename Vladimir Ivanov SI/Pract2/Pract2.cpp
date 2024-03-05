#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

constexpr char FILE_NAME[] = "result.txt";

void writeToResult(const char* fileName, const int num1, const int num2, const int num3) {
	if (!fileName) {
		return;
	}

	std::ofstream out(fileName);
	if (!out.is_open()) {
		return;
	}

	int sum = num1 + num2 + num3;
	int multiplied = num1 * num2 * num3;

	cout << endl;
	cout << "Sum: " << sum << endl;
	cout << "Multiplied: " << multiplied << endl;

	out << sum << endl;
	out << multiplied << endl;

	out.close();
}

int createNumFromStr(char* sum) {
	int num = 0;

	while (*sum) {
		num = (num * 10) + (*sum - '0');
		sum++;
	}

	return num;
}

void readFromResult(const char* fileName) {
	if (!fileName) {
		return;
	}

	std::ifstream in(fileName);
	if (!in.is_open()) {
		return;
	}

	char* sum = new char[10];
	in.getline(sum, 10, '\n');
	int intSum = createNumFromStr(sum);

	char* multiplied = new char[10];
	in.getline(multiplied, 10, '\n');
	int intMultiplied = createNumFromStr(multiplied);

	int differnce;
	differnce = intMultiplied - intSum;

	cout << "Difference: " << differnce << endl;

	delete[] sum;
	delete[] multiplied;
	in.close();
}

int main()
{
	cout << "Enter number 1: ";
    int num1;
	cin >> num1;

	cout << "Enter number 2: ";
	int num2;
	cin >> num2;

	cout << "Enter number 3: ";
	int num3;
	cin >> num3;

	writeToResult(FILE_NAME, num1, num2, num3);

	readFromResult(FILE_NAME);
}