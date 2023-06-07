#ifndef APPT_H
#define APPT_H

#include "defs.h"
#include "Date.h"
#include "Time.h"
#include "Animal.h"

class Appt{

	friend ostream& operator<<(ostream&, Appt&);

	public:
		//Purpose: Constructor and destructor
		Appt(Animal*, Date*);
		~Appt();
		
		//Getters
		Date* getDate();
		int getId();
		
		/*
		In: other
		Purpose: To check if it is on the same day as another appointment
		*/
		bool sameDay(Appt*);
		
		
	private:
		static int nextId;
		int id; 
		Animal* animal;
		Date* date;


};

#endif
