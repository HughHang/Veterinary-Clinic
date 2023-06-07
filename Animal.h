#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;
#include <iomanip>
#include "defs.h"

class Animal{

	friend ostream& operator<<(ostream&, Animal&);

	public:
		//Constructor
		Animal(
			SpeciesType = C_DOG, 
			string = "Unknown", 
			string = "Unknown", 
			int = 0, 
			int = 0,
			string = "Unknown"); 
		
		//Getters
		int getId();
		int getAge();
		string getName();
		string getParent();
	
	private:
		static int nextId;
		int id;
		SpeciesType species;
		string name;
		string gender;
		int age;
		string parent;

};


#endif
