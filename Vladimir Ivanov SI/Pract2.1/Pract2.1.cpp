#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


size_t getFileSize(ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);

	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

void writeFile(const char* fileName, const char* finalFile, const size_t finalFileSize) {
	if (!fileName) {
		return;
	}

	ofstream out(fileName);
	if (!out.is_open()) {
		return;
	}

	out.write(finalFile, finalFileSize);
	out.close();
}

void concatArrays(const char* file1, const char* file2, char* finalFile) {
	unsigned int index = 0;
	while (*file1) {
		finalFile[index++] = *file1;
		file1++;
	}

	while (*file2) {
		finalFile[index++] = *file2;
		file2++;
	}
}

void changeSpacesWithComa(char* finalFile) {
	while (*finalFile) {
		if (*finalFile == ' ') {
			*finalFile = ',';
		}

		finalFile++;
	}
}

void concatFiles(const char* fileName1, const char* fileName2) {
	if (!fileName1 || !fileName2) {
		return;
	}

	ifstream in1(fileName1);	
	if (!in1.is_open()) {
		return;
	}

	ifstream in2(fileName2);
	if (!in2.is_open()) {
		in1.close();
		return;
	}

	size_t fileSize1 = getFileSize(in1);
	char* file1 = new char[fileSize1 + 1];
	in1.read(file1, fileSize1);
	file1[fileSize1] = '\0';
	in1.close();

	size_t fileSize2 = getFileSize(in2);
	char* file2 = new char[fileSize2 + 1];
	in2.read(file2, fileSize2);
	file2[fileSize2] = '\0';
	in2.close();

	size_t finalFileSize = fileSize1 + fileSize2;
	char* finalFile = new char[finalFileSize + 1];
	concatArrays(file1, file2, finalFile);
	finalFile[finalFileSize] = '\0';
	cout << "'" << finalFile << "' is written in 'outFile.txt'." << endl;

	char outFileName[] = "outFile.txt";
	writeFile(outFileName, finalFile, finalFileSize);
	
	changeSpacesWithComa(finalFile);
	cout << "'" << finalFile << "' is written in 'outFile.txt'." << endl;
	writeFile(outFileName, finalFile, finalFileSize);

	delete[] file1;
	delete[] file2;
	delete[] finalFile;
}

int main()
{
	char inFileName1[] = "file1.txt";
	char inFileName2[] = "file2.txt";

    concatFiles(inFileName1, inFileName2);
}