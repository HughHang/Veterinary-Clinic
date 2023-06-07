#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "CompareBehaviour.h"

Control::Control(){

	schedule = new Schedule();
	animals.setComp(new CompareAge<Animal*>(false));
	
}

Control::~Control(){
	delete schedule;
	animals.cleanUpData();
}

void Control::launch(){

	initAnimals();
	initSchedule();
	
	while(true){
	
		int choice;
		view.showMenu(choice);
		
		switch(choice){
		
			case 1:{
			
				cout << *schedule << endl;
				break;
				
			}
			case 2:{
			
				int id;
				cout << "Please enter appointment animal id: ";
				view.readInt(id);
				
				int year, month, day;
				cout << "Please enter appointment year: ";
				view.readInt(year);
				
				cout << "Please enter appointment month : ";
				view.readInt(month);
				
				cout << "Please enter appointment day: ";
				view.readInt(day);
				
				int hour, min;
				cout << "Please enter appointment hour: ";
				view.readInt(hour);
				
				cout << "Please enter appointment minute: ";
				view.readInt(min);
				
				cout << endl;
				
				if(addAppt(id, year, month, day, hour, min)){
				
					cout << "STATUS: Appointment was added" << endl;
				
				}else{
				
					cout << "STATUS: Appointed could not be added" << endl;
				
				}
				
				
				break;
			
			}
			case 3:{
			
				cout << animals;
				break;
			
			}
			case 0:{
			
				return;
			
			}
		
		}
	
	}


}

void Control::initAnimals()
{
  animals.add(new Animal(C_DOG, "Lily", "F", 1, 6, "Sonja"));
  animals.add(new Animal(C_DOG, "Betsy", "F", 5, 0, "NONE"));
  animals.add(new Animal(C_DOG, "Killer", "F", 3, 5, "Lee"));
  animals.add(new Animal(C_DOG, "Fluffy", "M", 2, 7, "NONE"));
  animals.add(new Animal(C_CAT, "Lady", "F", 11, 0, "Laura"));
  animals.add(new Animal(C_SPEC_OTHER, "Pecorino", "M", 0, 3, "Kara"));
  animals.add(new Animal(C_DOG, "Leon", "M", 4, 0, "Sonja"));
  animals.add(new Animal(C_SPEC_OTHER, "Quasar", "M", 1, 4, "Sharon"));
  animals.add(new Animal(C_CAT, "Shadow", "M", 5, 2, "Bill"));
  animals.add(new Animal(C_CAT, "Luka", "M", 7, 0, "Bill"));
  animals.add(new Animal(C_CAT, "Fiona", "F", 8, 0, "NONE"));
  animals.add(new Animal(C_CAT, "Ruby", "F", 5, 0, "NONE"));
  animals.add(new Animal(C_SPEC_OTHER, "Ziggy", "F", 3, 8, "Laura"));
  animals.add(new Animal(C_SPEC_OTHER, "Quark", "M", 9, 0, "Sharon"));
  animals.add(new Animal(C_SPEC_OTHER, "Gruyere", "M", 0, 3, "Kara"));
  animals.add(new Animal(C_SPEC_OTHER, "Limburger", "M", 0, 3, "Kara"));
}

void Control::initSchedule()
{
  addAppt(1002, 2023, 5, 10, 11, 15);
  addAppt(1005, 2023, 5, 10, 11, 30);	// conflict
  addAppt(1005, 2023, 5, 10, 11, 45);
  addAppt(1012, 2023, 5, 10, 11, 45);	// conflict
  addAppt(1012, 2023, 5, 10, 12, 0);	// conflict
  addAppt(1015, 2023, 5, 10, 11, 0);	// conflict
  addAppt(1015, 2023, 5, 10, 11, 0);	// conflict
  addAppt(1013, 2023, 6, 8, 10, 0);
  addAppt(1007, 2023, 6, 8, 9, 45);	// conflict
  addAppt(1007, 2023, 6, 8, 9, 30);
  addAppt(1010, 2023, 5, 9, 11, 15);

  addAppt(1035, 2023, 6, 8, 11, 15);	// error
  addAppt(1006, 2018, 5, 8, 11, 45);	// error
  addAppt(1006, 2023, 14, 1, 11, 45);	// error
  addAppt(1006, 2023, 5, 41, 11, 45);	// error
  addAppt(1006, 2023, 5, 8, 1, 45);	// error
  addAppt(1006, 2023, 5, 8, 11, 25);	// error
}

bool Control::addAppt(int animalId, int year, int month, int day, int hours, int mins){

	Animal* animal;

	if(!animals.find(animalId, &animal)){
	
		cout << "Animal id " << animalId << " was not found" << endl;
		return false;
	
	}
	
	if(schedule->addAppt(animal, year, month, day, hours, mins)){
	
		return true;
	
	}
	
	return false;

}

