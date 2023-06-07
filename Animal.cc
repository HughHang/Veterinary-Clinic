#include <iostream>
#include <string>

#include "Animal.h"

int Animal::nextId = ANIMAL_IDS;

Animal::Animal(SpeciesType st, string n, string g, int y, int m, string p){

	id = nextId++;
	species = st;
	name = n;
	gender = g;
	age = (y * 12) + m;
	parent = p;

}

int Animal::getId(){

	return id;

}

int Animal::getAge(){

	return age;

}

string Animal::getName(){

	return name;

}

string Animal::getParent(){

	return parent;

}

ostream& operator<<(ostream& output, Animal& animal){

	string type = "Unknown";

	if(animal.species == C_DOG){
	
		type = "Dog";
	
	}
	else if(animal.species == C_CAT){
	
		type = "Cat";
	
	}else{
	
		type = "Other";
	
	}

	output << setw(4) << left << animal.id;
	output << ":  ";
	output << setfill(' ') << setw(10) << left << animal.name;
	output << ":";
	output << setw(7) << right << type;
	output << ";  Age: ";
	output << setfill(' ') << setw(2) << right << (animal.age / 12);
	output << " yrs, ";
	output << setw(2) << left << (animal.age % 12);
	output << "mths;  Parent: " << animal.parent;
	output << endl;
	
	return output;

}
