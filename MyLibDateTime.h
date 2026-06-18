#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<ctime>
using namespace std;

namespace MyLibDateTime {
	string getLocalDataTime(){
	
		time_t t = time(0);
		char* dt = ctime(&t);
		return dt;
	}

	string getUtcDataTime() {
		time_t t = time(0);
		tm* gmtm = gmtime(&t);
		char* dt = asctime(gmtm);
		return dt;
	}
	time_t getLocalTime_t() {

		time_t t = time(0);
		 
	
		return t;
	}
	

	int getYearLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);
		
		return now->tm_year + 1900;
	}
	int getMonthLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_mon +1 ;
	}

	int getdayLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_mday;
	}

	int getHourLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_hour;
	}


	int getSecoundLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_sec;
	}

	int getMinutLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_min;
	}

	int getYearDayLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_yday;
	}

	int getWeekDayLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_wday;
	}


	int getMonthDayLocalTime() {
		time_t t = getLocalTime_t();
		tm* now = localtime(&t);

		return now->tm_mday;
	}
}