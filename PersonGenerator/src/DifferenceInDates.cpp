#include "CommonInclude.h"
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost;

int DateDiff(const int& startingDay, const int& startingMonth, const int& startingYear, const int& endingDay, const int& endingMonth, const int& endingYear) {
	// Initializing Date object with 21st March 2016
	gregorian::date::day_type startDay = startingDay;
	gregorian::date::month_type startMonth = startingMonth;
	gregorian::date::year_type startYear = startingYear;
	gregorian::date::day_type endDay = endingDay;
	gregorian::date::month_type endMonth = endingMonth;
	gregorian::date::year_type endYear = endingYear;
	gregorian::date dateObj1{ startYear, startMonth, startDay };

	// Initializing Date object with 1st October 2016
	gregorian::date dateObj2{ endYear, endMonth, endDay };

	// Get the Duration between 2 Dates
	gregorian::date_duration dur = dateObj2 - dateObj1;

	//cout << "Date 1 : " << dateObj1 << std::endl;
	//cout << "Date 2 : " << dateObj2 << std::endl;

	// Fetch Days from date_duration object
	//cout << "Difference b/w 2 Dates in days : " << dur.days() << std::endl;
	int days = dur.days();
	if (days < 0) {
		days = abs(days);
	}
	return days;
}
void findCurrentDate(int& currentDay, int& currentMonth, int& currentYear) {
	// current date/time based on current system
	time_t now = time(0);

	tm* ltm = localtime(&now);

	// print various components of tm structure.
	currentYear = 1900 + ltm->tm_year;
	currentMonth = 1 + ltm->tm_mon;
	currentDay = ltm->tm_mday;
	/*cout << "Year:" << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;*/
}