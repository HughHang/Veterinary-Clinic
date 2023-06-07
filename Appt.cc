#include <iostream>
using namespace std;
#include <iomanip>

#include "Appt.h"

int Appt::nextId = APPT_IDS;

Appt::Appt(Animal* a, Date* d){

	animal = a;
	date = d;
	id = nextId++;

}

Appt::~Appt(){

	delete date;

}

Date* Appt::getDate(){

	return date;

}

int Appt::getId(){

	return id;

}

bool Appt::sameDay(Appt* other){

	if(date->sameDay(*other->getDate())){
	
		return true;
	
	}
	
	return false;

}

ostream& operator<<(ostream& output, Appt& appt){

	output << setw(4) << appt.id << "   " << 
		*(appt.date) << " -- ";
	output << setfill(' ') << setw(8) << appt.animal->getName() << left;
	output << "with parent: " << appt.animal->getParent() << endl;
	
	return output;

}
