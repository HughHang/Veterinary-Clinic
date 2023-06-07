#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Animal.h"
#include "List.h"
#include "Appt.h"
#include "Date.h"
#include "CompareBehaviour.h"
#include "defs.h"
#include "Time.h"

class Schedule{

		friend ostream& operator<<(ostream&, Schedule&);

	public:
		//Purpose: Constructor and Destructors
		Schedule(bool = true);
		~Schedule();
		
		/*
		In: animal, year, month, day, hours, mins
		Out: Bool
		Purpose: To add an appointment
		*/
		bool addAppt(Animal*, int, int, int, int, int);
	
	private:
		int numAppts;
		List<Appt*> appts;
		
		/*
		In: year
		Out: Bool
		Purpose: To check if it is the current year
		*/
		bool currentYear(int);	

		/*
		In: hours
		Out: Bool
		Purpose: Check if the hours are within opening hours
		*/
		bool checkOpHours(int);
		
		/*
		In: mins
		Out: Bool
		Purpose: Check if minutes are valid
		*/
		bool checkMins(int);
		
		/*
		In: a, size, date, conflict
		Out: Bool
		Purpose: Check if an appointment can be made
		*/
		bool checkOverlaps(Appt**, Appt*, int, Date*, Appt**);
		
		/*
		In: d1, d2
		Out: Bool
		Purpose: To check if there is an overlap
		*/
		bool overlap(Date, Date);
		
};

#endif
