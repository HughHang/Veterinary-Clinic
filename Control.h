#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "Schedule.h"
#include "Animal.h"
#include "List.h"

class Control
{
  public:
	Control();
	~Control();
	void launch();

  private:
  	Schedule* schedule;
  	List<Animal*> animals;
  	View view;
	void initAnimals();
	void initSchedule();
	
	/*
	In: animalId, year, month, day, hours, mins
	Out: Bool
	Purpose: To populate animal and schedule
	*/
	bool addAppt(int, int, int ,int ,int, int);

};

#endif
