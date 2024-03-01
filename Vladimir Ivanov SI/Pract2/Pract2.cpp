#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

constexpr char FILE_NAME[] = "result.txt";

void writeToResult(const char* fileName, const double sum, const double multiplied) {
	if (!fileName) {
		return;
	}

	std::ofstream out(fileName);
	if (!out.is_open()) {
		return;
	}

	out << sum << std::endl;
	out << multiplied << std::endl;

	out.close();
}

void readStudentsFromFile(const char* fileName, size_t& length) {
	if (!fileName) {
		length = 0;
		return;
	}

	std::ifstream in(fileName);
	if (!in.is_open()) {
		length = 0;
		return;
	}

	in >> length;
	if (length == 0) {
		return;
	}

	char* sum;
	in.getline(sum, 10);

	char* multiplied;
	in.getline(multiplied, 10);

	int differnce;
	differnce = (int)multiplied - (int)sum;

	cout << differnce;

	in.close();

int main()
{
    double num1;
	cin >> num1;

	double num2;
	cin >> num2;

	double num3;
	cin >> num3;

	double sum = num1 + num2 + num3;
	double multiplied = num1 * num2 * num3;

	writeToResult(FILE_NAME, sum, multiplied);

	readFromResult();
}