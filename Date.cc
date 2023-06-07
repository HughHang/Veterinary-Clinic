#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y, int hour, int min){
	setDate(d, m, y);
	time = Time(hour, min);
}

Date::Date(Date& d){

	setDate(d.day, d.month, d.year);
	time = d.getTime();

}

Date::~Date(){
}

void Date::setDate(int d, int m, int y){
	year = ((y > 0) ? y : 0);
	month = ((m > 0 && m <= 12) ? m : 0);
	day = ((d > 0 && d <= lastDayInMonth()) ? d : 0);
}

int Date::lastDayInMonth(){
	switch(month){
		case 2:
			if (leapYear()){
				return 29;
			}else{
				return 28;
			}
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		default:
			return 30;
	}
}

bool Date::leapYear(){
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		return true;
	}else{
		return false;
	}
}

bool Date::validate(int day, int month, int year){

	Date copyDate(day, month, year);
	
	if(day < 1 || day > copyDate.lastDayInMonth() || 
			month < 1 || month > 12){
			
		return false;
		
	}
	
	return true;

}

int Date::getYear(){

	return year;

}

int Date::getMonth(){

	return month;

}

int Date::getDay(){

	return day;

}

Time Date::getTime(){

	return time;

}

bool Date::operator==(Date& date){

	if(sameDay(date) && (time == date.time)){
	
		return true;
	
	}
	
	return false;

}

bool Date::operator<(Date& date){

	if(sameDay(date)){
	
		if(time < date.time){
		
			return true;
		
		}
	
	}

	if(year < date.year){
	
		return true;
		
	}
	else if(year == date.year){
		if(month < date.month){
		
			return true;
			
		}
		else if(month == date.month){
			
			if(day < date.day){
			
				return true;
			
			}
		}	
	}
	
	return false;

}

bool Date::operator>(Date& date){

	if(sameDay(date) && (time >= date.time)){
	
		return true;
	
	}
	
	if(year > date.year){
	
		return true;
		
	}
	
	else if(year == date.year){
	
		if(month > date.month){
		
			return true;
			
		}
		else if(month == date.month){
			
			if(day > date.day){
			
				return true;
			
			}
			
		
		}
	
	}
	
	return false;

}

bool Date::sameDay(Date& date){

	if(day == date.day && month == date.month && year == date.year){

		return true;

	}

	return false;
	

}

ostream& operator<<(ostream& output, Date& d){

	output << setfill('0') << setw(4) << d.year << "-" <<
		setfill('0') << setw(2) << d.month << "-" <<
		setfill('0') << setw(2) << d.day << " @ " << d.time;
		
	return output;
			
}
