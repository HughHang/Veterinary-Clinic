#ifndef DATE_H
#define DATE_H

#include "Time.h"
#include "defs.h"

class Date{

	friend ostream& operator<<(ostream&, Date&);

	public:
		Date(int = 0, int = 0, int = 2000, int = 0, int = 0);
		~Date();
		Date(Date&);
		void setDate(int, int, int);
		
		//Getters
		int getYear();
		int getMonth();
		int getDay();
		Time getTime();
		
		/*
		In: day, month, year
		Out: bool
		Purpose: To check if the date is a valid date
		*/
		static bool validate(int, int, int);
		
		/*
		In: date
		Out: Bool
		Purpose: Check if there is an overlap
		*/	
		bool overlaps(Date);	
		
		/*
		In: date
		Purpose: Check if date is equal to another
		*/
		bool operator==(Date&);
		
		/*
		In date
		Purpose: Check if date is less than another
		*/
		bool operator<(Date&);
		
		/*
		In: date
		Purpose: Check if date is greater than another
		*/
		bool operator>(Date&);
		
		/*
		In: date
		Purpose: To check if there is an overlap in appointment times
		*/
		
		/*
		In: Date
		Purpose: Check if date is the same day
		*/
		bool sameDay(Date&);

	private:
		int day;
		int month;
		int year;
		Time time;
		bool leapYear();
		int lastDayInMonth();
		
};

#endif
