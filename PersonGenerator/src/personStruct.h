#pragma once

struct Person {
	std::string firstName, lastname, email;


	int phoneArea, phonePrefix, phoneLast; //phone number


	std::string birthMonth;
	int birthDay, birthYear, age; //deals with birthday


	std::string streetAddress, city, state, zipcode; //address


	std::string SSN_First, SSN_Second; //SSN
	int SSN_Third;


	std::string creditCard_Number, creditCard_Provider;
	int CVV2, exp_month, exp_year;						//credit card info


	int currentDay, currentMonth, currentYear;


	int NumberOfKids;
	std::string MaritalStatus;
	std::vector<std::string> Kids_Names; //Kids and married


	std::string race, blood_type;
	int hight_Feet, hight_Inches;
};

