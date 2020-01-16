
#include"CommonInclude.h"
#include "RandNum.h"

using namespace std;


int GenAreaCode(int randLine) {
	ifstream inFile;
	inFile.open("AreaCodes.txt");
	int AreaCodes[322];
	int a = 0;
	while (!inFile.eof()) {
		inFile >> AreaCodes[a];
		a++;
	}
	inFile.close();
	int areaCode = AreaCodes[randLine];

	return areaCode;
}

string GenAreaState(int randNum, string areaState) {

	ifstream inFile;
	inFile.open("AreaCodeState.txt");
	string AreaStates[322];
	int a = 0;
	while (!inFile.eof()) {
		getline(inFile, AreaStates[a]);
		a++;
	}
	inFile.close();
	areaState = AreaStates[randNum];

	return areaState;

}

int genPrefix() {
	int prefix = randomNum(200, 999);
	ifstream inFile;
	inFile.open("NonPrefixes.txt");
	int Prefixes[414];
	int a = 0;
	while (!inFile.eof()) {
		inFile >> Prefixes[a];
		a++;
	}
	inFile.close();

	for (int i = 0; i < 414; i++) {
		if (prefix == Prefixes[i]) {
			prefix = randomNum(200, 999);
			i = 0;
		}
	}
	return prefix;
}

void Gen_PhoneNum() {
	int randLine = randomNum(0, 321);
	int areacode = GenAreaCode(randLine);
	int prefix = genPrefix();
	int lastFour = randomNum(1111, 9999);
	cout << "Phone Number: ";
	cout << areacode << "-" << prefix << "-" << lastFour << endl;;
	ofstream file;
	file.open("person.txt", ios::app);
	file << "Phone Number: " << areacode << "-" << prefix << "-" << lastFour << endl;
	file.close();
	person.phoneArea = areacode;
	person.phonePrefix = prefix;
	person.phoneLast = lastFour;
}