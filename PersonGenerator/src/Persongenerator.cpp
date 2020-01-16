// Person generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonInclude.h"
#include "phoneNumber.h"
#include "addressXMLParser.h"
#include "RandNum.h"
#include "DifferenceInDates.h"



using namespace std;

Person person;

void RandomFirstName(string & first_name) { // allows the ability to return a string
	first_name.clear();
	ifstream myFile;
	myFile.open("FirstNames.txt");
	string names[1000]; // holds the 1000 names in the file.
	int a = 0;
	int randLine;
	while (!myFile.eof()) {
		getline(myFile, names[a]); // reads the names from the text file, into an array named "names[]."
		a++;
	}
	randLine = randomNum(0, 999); // gets a random number between 0, and 999.
	first_name = names[randLine];
	cout << "First Name: " << first_name << endl; // outputs first name
	ofstream file;
	file.open("Person.txt"); //open file
	file << "Personal Information:" << endl << "---------------------------" << endl;
	file << "First Name: " << first_name << endl;// outputs first name to file
	file.close(); //close file
	myFile.close();
	//person.firstName = name;
}

void RandomKidsName(string & name) { // allows the ability to return a string
	name.clear();
	ifstream myFile;
	myFile.open("FirstNames.txt");
	string names[1000]; // holds the 1000 names in the file.
	string firstName;
	int a = 0;
	int randLine;
	while (!myFile.eof()) {
		getline(myFile, names[a]); // reads the names from the text file, into an array named "names[]."
		a++;
	}
	randLine = randomNum(0, 999); // gets a random number between 1, and 1000.
	name = names[randLine];
}

void RandomLastName(string & last_name) { // allows the ability to return a string
	last_name.clear();
	ifstream myFile;
	myFile.open("LastNames.txt");
	string names[1000]; // holds the 1000 names in the file.
	int a = 0;
	int randLine;
	while (!myFile.eof()) {
		getline(myFile, names[a]); // reads the names from the text file, into an array named "names[]."
		a++;
	}
	randLine = randomNum(0, 999); // gets a random number between 1, and 1000.
	last_name = names[randLine];
	cout << "Last name: " << last_name << endl; // outputs last name
	ofstream file;
	file.open("Person.txt", ios::app);
	file << "Last name: " << last_name << endl;
	file.close();
	myFile.close();
}


void SSN() {
	ofstream file;
	cout << "SSN: ";
	file.open("Person.txt", ios::app);
	file << "SSN: ";
	int firstThree, secondTwo, lastFour;
	firstThree = randomNum(1, 800); // gets a random number between 1 and 800
	secondTwo = randomNum(1, 99); // gets a random number between 1 and 99
	lastFour = randomNum(1111, 8999); // gets a random number between 1 and 899
	if (lastFour == 6666) {
		lastFour = randomNum(1111, 8999); // gets a random number between 1 and 899
	}
	if (firstThree < 10) {
		cout << "00" << firstThree << "-";
		file << "00" << firstThree << "-";
		person.SSN_First = "00" + to_string(firstThree);
	}
	else if (firstThree >= 10 && firstThree < 100) {
		cout << "0" << firstThree << "-";
		file << "0" << firstThree << "-";
		person.SSN_First = "0" + to_string(firstThree);
	}
	else if (firstThree > 100) {
		cout << firstThree << "-";
		file << firstThree << "-";
		person.SSN_First = to_string(firstThree);
	}
	if (secondTwo < 10) {
		cout << "0" << secondTwo << "-";
		file << "0" << secondTwo << "-";
		person.SSN_Second = "0" + to_string(secondTwo);
	}
	else if (secondTwo > 10) {
		cout << secondTwo << "-";
		file << secondTwo << "-";
		person.SSN_Second = to_string(secondTwo);
	}
	cout << lastFour << endl;
	file << lastFour << endl;
	file.close();
	person.SSN_Third = lastFour;
}


void Email(string FName, string LName) {
	ofstream file;
	int rand_endNum, domain;
	file.open("Person.txt", ios::app);
	string domains[] = { "@yahoo.com", "@gmail.com", "@hotmail.com", "@outlook.com" };
	rand_endNum = randomNum(1, 800); // gets a random number between 1, and 800.
	domain = randomNum(0, 3); // gets a number 0-3
	cout << "Email: " << FName << "." << LName << rand_endNum << domains[domain] << endl;
	file << "Email: " << FName << "." << LName << rand_endNum << domains[domain] << endl;
	file.close();
	person.email = FName + "." + LName + to_string(rand_endNum) + domains[domain];
}

void CreditCard() {
	ifstream myFile;
	myFile.open("CreditCardNum.txt");
	string cards[200]; // holds the 100 cards and companies in the file.
	string randomCard_Provider;// holds the randomly generated card provider
	string randomCardNum;// holds the randomly generated card number 
	int a = 0;
	int randLine;
	while (myFile.good()) {
		getline(myFile, cards[a]); // reads the cards from the text file, into an array named "cards[]."
		a++;
	}
	randLine = (2 * (randomNum(0, 99)));// gets a random number even between 0, and 99.
	randomCard_Provider = cards[randLine];
	randomCardNum = cards[randLine + 1];
	//cout << randLine << endl; // prints random line number
	ofstream file;
	file.open("Person.txt", ios::app); //open file
	cout << "Credit Card Provider: " << randomCard_Provider << endl; // outputs Card Provider
	cout << "Credit Card Number: " << randomCardNum << endl; // outputs Card Number
	file << "Credit Card Provider: " << randomCard_Provider<< endl; // outputs Card Provider to file
	file << "Credit Card Number: " << randomCardNum << endl; // outputs Card Number to file


	int month, year; //stores values for CVV2, month and year
	int CVV2 = randomNum(101, 999);
	cout << "CVV2: " << CVV2;
	file << "CVV2: " << CVV2;
	cout << endl;
	file << endl;
	month = randomNum(1, 12); // gets a random number between 1 and 12
	year = person.currentYear + randomNum(0, 5); // gets a random number between 0 and 5
	cout << "Expires: " << month << "/" << year << endl;
	file << "Expires: " << month << "/" << year << endl;
	file.close(); //close file
	myFile.close();

	person.creditCard_Number = randomCardNum;
	person.creditCard_Provider = randomCard_Provider;
	person.CVV2 = CVV2;
	person.exp_month = month;
	person.exp_year = year;
}

void Education() {
	string education[] = {"Highschool Diploma, GED or equivilant","Some College", "Associate degree", "Bachelor's degree", "Master's Degree", "Doctoral Degree or PHD."};
	int LevelOfEducation;
	if (person.age < 20) { //Max of some college
		LevelOfEducation = randomNum(0, 1);
	}
	else if (person.age <= 21 && person.age >= 20) { //Max of an assosiates
		LevelOfEducation = randomNum(0, 2);
	}
	else if (person.age <= 24 && person.age >21) { //Max of Bachelor's
		LevelOfEducation = randomNum(0, 3);
	}
	else if (person.age <= 26 && person.age > 24) { //Max of Masters
		LevelOfEducation = randomNum(0, 4);
	}
	else {
		LevelOfEducation = randomNum(0, 5); //max of Dr.
	}
	cout << "Level of Education: " << education[LevelOfEducation] << endl;
	ofstream file;
	file.open("Person.txt", ios::app);
	file << "Level of Education: " << education[LevelOfEducation] << endl;
	file.close();
}

void Race() {
	string race[] = { "White", "Asian", "Black", "Hispanic or Latino" };
	int randNum = randomNum(0, 3); // gets a random number between 0 and 3
	cout << "Ethnicity: " << race[randNum] << endl;
	ofstream file;
	file.open("Person.txt", ios::app);
	file << "Ethnicity: " << race[randNum] << endl;
	file.close();
	person.race = race[randNum];
}

void Hight() {
	person.hight_Feet = randomNum(4, 6);
	if (person.hight_Feet == 4) {
		person.hight_Inches = randomNum(8, 11);
	}
	else if (person.hight_Feet == 6)
		person.hight_Inches = randomNum(0, 3);
	else {
		person.hight_Inches = randomNum(0, 11);
	}
	ofstream file;
	file.open("Person.txt", ios::app);
	cout << "Hight: " << person.hight_Feet << "\'" << person.hight_Inches << "\"" << endl;
	file << "Hight: " << person.hight_Feet << "\'" << person.hight_Inches << "\"" << endl;
	file.close();
}
void BloodType() {
	string type[] = { "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-" };
	int randNum;
	randNum = randomNum(0, 7); // gets a random number between 0 and 4
	cout << "Blood Type: " << type[randNum] << endl;
	ofstream file;
	file.open("Person.txt", ios::app);
	file << "Blood Type: " << type[randNum] << endl;
	file.close();
	person.blood_type = type[randNum];
}

#define MAX_AGE 40
#define MIN_AGE 20
void genBirthday_Age() {
	int month, day, year, difference;
	string months[] = {"this is a placeholder", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	month = randomNum(1, 12);
	day = randomNum(1, 30);
	year = randomNum(person.currentYear - MAX_AGE , person.currentYear - MIN_AGE);
	difference = DateDiff(person.currentDay, person.currentMonth, person.currentYear, day, month, year);
	int differenceInYears = difference / 365;
	cout << "Birthday: " << months[month] << " " << day << ", " << year;
	cout << "\t(" << differenceInYears << " years old)" << endl;
	ofstream file;
	file.open("Person.txt", ios::app);
	file << "Birthday: " << months[month] << " " << day << ", " << year;
	file << "\t(" << differenceInYears << " years old)" << endl;
	file.close();
	person.age = differenceInYears;
	person.birthDay = day;
	person.birthMonth = months[month];
	person.birthYear = year;
}

vector<string> generateKids(int numberOfKids, string lastName) {
	vector<string> kidsNames;
	for (int i = 0; i < numberOfKids; i++) {
		string kidsname;
		RandomKidsName(kidsname);
		kidsname += " " + lastName;
		kidsNames.push_back(kidsname);
	}
	return kidsNames;
}

void maritalStatus_Kids(string lastName) {
	ofstream file;
	file.open("Person.txt", ios::app);
	string status[] = { "Single / Never Married", "Married", "Divorced"};
	int randStatus = randomNum(0, 2);
	int randKids = 0;
	if (randStatus != 0) {
		randKids = randomNum(0, 5);
	}
	person.MaritalStatus = status[randStatus];
	cout << "Marital Status: " << status[randStatus] << endl;
	file << "Marital Status: " << status[randStatus] << endl;
	if (randKids == 0) {
		cout << "Kids: None" << endl;
		file << "Kids: None" << endl;
	}
	vector<string> kidsNames = generateKids(randKids, lastName);
	if (randKids != 0) {
		cout << "Kids:";
		file << "Kids:";
		for (unsigned int i = 0; i < kidsNames.size(); i++) {
			if (i == 0) {
				cout << "\t" << kidsNames.at(i) << endl;
				file << "\t" << kidsNames.at(i) << endl;
			}
			else{
				cout << "\t" << kidsNames.at(i) << endl;
				file << "\t" << kidsNames.at(i) << endl;
			}
			person.Kids_Names.push_back(kidsNames.at(i));
		}
	}
	person.NumberOfKids = randKids;
	file.close();
}

#define NUM_OF_ADDRESSES 316
void GenAddress() {
	string textFile = "StreetAddresses.xml";
	vector<string> allInformation = parseAddressXML(textFile); //parse file and output to vector
	int randAddress = randomNum(0, 315);
	cout << "Address: " << allInformation.at(randAddress) << endl;
	cout << "City: " << allInformation.at(randAddress + NUM_OF_ADDRESSES) << endl;
	cout << "State: " << allInformation.at(randAddress + (2 * (NUM_OF_ADDRESSES))) << endl;
	cout << "Zip Code: " << allInformation.at(randAddress + (3 * (NUM_OF_ADDRESSES))) << endl;
	ofstream file;
	file.open("Person.txt", ios::app);
	file << "Address: " << allInformation.at(randAddress) << endl;
	file << "City: " << allInformation.at(randAddress + NUM_OF_ADDRESSES) << endl;
	file << "State: " << allInformation.at(randAddress + (2 * (NUM_OF_ADDRESSES))) << endl;
	file << "Zip Code: " << allInformation.at(randAddress + (3 * (NUM_OF_ADDRESSES))) << endl;
	file.close();
	person.streetAddress = allInformation.at(randAddress);
	person.city = allInformation.at(randAddress + NUM_OF_ADDRESSES);
	person.state = allInformation.at(randAddress + (NUM_OF_ADDRESSES * 2));
	person.zipcode = allInformation.at(randAddress + (NUM_OF_ADDRESSES * 3));
}



int main(void) {
	findCurrentDate(person.currentDay, person.currentMonth, person.currentYear);
	ofstream file;
	file.open("Person.txt", ios::app);
	cout << "Personal Information:" << endl << "---------------------------" << endl;
	RandomFirstName(person.firstName); //Generate a first name and store it in "firstName"
	RandomLastName(person.lastname); //Generate a last name and store it in "lastName"
	Email(person.firstName, person.lastname); //Generate an email based on first and last name
	Gen_PhoneNum(); //Generate a phone number
	genBirthday_Age();//Generate Birthday and time in years since
	GenAddress(); //Generate an address 
	

	cout << endl << endl << "Sensitive info:" << endl << "---------------------------" << endl;
	file << endl << endl << "Sensitive info:" << endl << "---------------------------" << endl;
	SSN(); //Generate a Social Security Number
	CreditCard(); //Generate Credit Card Information


	cout << endl << endl << "Demographic Information:" << endl << "---------------------------" << endl;
	file << endl << endl << "Demographic Information:" << endl << "---------------------------" << endl;
	maritalStatus_Kids(person.lastname); //Random Marital status and number of kids
	Race(); //Random Race
	Education(); //Random Level of Education
	BloodType(); //Random Blood Type
	Hight(); //Random Hight
	cin.get();
	//system("pause");
	file.close();
	return 0;
}