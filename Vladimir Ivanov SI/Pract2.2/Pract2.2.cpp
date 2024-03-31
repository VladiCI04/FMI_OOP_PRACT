#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

struct Number {
	size_t numLength;
	char* num = new char[numLength + 1];
};

size_t findNumberLength(ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);

	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

void readNumberFromFile(const char* fileName) {
	if (!fileName) {
		return;
	}

	ifstream in(fileName);
	if (!in.is_open()) {
		in.close();
		return;
	}

	size_t numberLength = findNumberLength(in);
	if (numberLength == 0) {
		in.close();
		return;
	}

	Number* n = new Number();
	(*n).numLength = numberLength + 1;
	in.read((*n).num, numberLength);
	(*n).num[numberLength] = '\0';

	cout << "Number is: " << (*n).num << endl;

	in.close();
	delete n;
}

int main()
{
	char fileName[] = "number.txt";
	readNumberFromFile(fileName);
}