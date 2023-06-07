#include <iostream>
#include <iomanip>
using namespace std;

#include "Schedule.h"

Schedule::Schedule(bool o){

	appts.setComp(new CompareDate<Appt*>(true));
	numAppts = 0;
	
}

Schedule::~Schedule(){

	appts.cleanUpData();

}

bool Schedule::addAppt(Animal* animal, int year, int month, int day, int hours, int mins){

	if(!currentYear(year)){
	
		cout << "Year " << year << " is invalid" << endl;
		return false;
	
	}
	
	if(!Date::validate(day, month, year)){
		
		cout << "Date " << year << "/" << month << "/" << day << " is invalid" << endl;
		return false;
	
	}
	
	
	if(!checkOpHours(hours)){
	
		cout << "Hour " << hours << " is invalid" << endl;
		return false;
	
	}
	
	if(!checkMins(mins)){
	
		cout << "Minutes " << mins << " is invalid" << endl;
		return false;
		
	}
	
	Date* date = new Date(day, month, year, hours, mins);
	Appt* appt = new Appt(animal, date);
	
	Appt* tempAppt[MAX_ARR];
	int size;
	appts.convertToArray(tempAppt, size); 
	
	Appt* conflict;
	
	if(checkOverlaps(&*tempAppt, appt, size, date, &conflict)){
		cout << "ERROR: Appointment " << appt->getId() << " on " << *date << 
		" conflicts with " << conflict->getId() << " on " << *(conflict->getDate()) << endl;
		
		delete appt; 
	
		return false;
	}
	
	appts.add(appt);
	
	return true;

}

bool Schedule::currentYear(int year){

	if(year == CURR_YEAR){
	
		return true;
	
	}
	
	return false;

}

bool Schedule::checkOpHours(int hours){

	if((hours >= OPEN_HRS) && (hours <= CLOSE_HRS)){
	
		return true;
		
	}
	
	return false;

}

bool Schedule::checkMins(int mins){

	if(mins % 15 == 0){
		
		return true;
	
	}
	
	return false;

}

bool Schedule::checkOverlaps(Appt** a, Appt* appt, int  size, Date* date, Appt** conflict){

	for(int i = 0; i < size; i++){
	
		if(appt->sameDay(a[i])){
		
			if(overlap(*(a[i]->getDate()), *date)){	
			
				*conflict = a[i];
				return true;
			
			}
		
		}
	
	}
	
	return false;

}

bool Schedule::overlap(Date d1, Date d2){


	Time d1End = d1.getTime();
	d1End.add(0, APPT_DURATION);
	Time d2End = d2.getTime();
	d2End.add(0, APPT_DURATION);
	
	if(d2.getTime() < d1End && d1.getTime() < d2End){
	
		return true;
	
	}
	
	return false;

}

ostream& operator<<(ostream& output, Schedule& schedule){

	output << "SCHEDULE:" << endl;
	
	output << schedule.appts << endl;
	
	return output;
	
}

