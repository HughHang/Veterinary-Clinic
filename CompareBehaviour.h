#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <cstdlib>
#include "Date.h"
using namespace std;

template <class T>
class CompareBehaviour{
	
	public:
	
		CompareBehaviour(bool = true);
		virtual ~CompareBehaviour();
		virtual bool compare(T, T) = 0;
	
	protected:
		bool asc;

};

template <class T>
CompareBehaviour<T>::CompareBehaviour(bool o){

	asc = o;

}

template <class T>
CompareBehaviour<T>::~CompareBehaviour(){
}

/****************************************************************/
/****************************************************************/
/****************************************************************/

template <class T>
class CompareAge : public CompareBehaviour<T> {

	public:
		CompareAge(bool = true);
		virtual ~CompareAge();
		/*
		In: obj1, obj2
		Purpose: Compares age
		*/
		virtual bool compare(T, T);

};

template <class T>
CompareAge<T>::CompareAge(bool o) : 
	CompareBehaviour<T>(o){
}

template <class T>
CompareAge<T>::~CompareAge(){
}


template <class T>
bool CompareAge<T>::compare(T obj1, T obj2){

	int age1 = obj1->getAge();
	int age2 = obj2->getAge();
	
	if(this->asc){
	
		if((age1 == age2) || (age1 < age2)){
		
			return true;
		
		}
		
		return false;
	
	}else{
	
		if((age1 == age2) || (age1 < age2)){
		
			return true;
		
		}
		
		return false;
	
	}
	
}

/****************************************************************/
/****************************************************************/
/****************************************************************/

template <class T>
class CompareDate : public CompareBehaviour<T> {

	public:
		CompareDate(bool = true);
		virtual ~CompareDate();
		/*
		In: obj1, obj2
		Purpose: Compares date
		*/
		virtual bool compare(T, T);

};


template <class T>
CompareDate<T>::CompareDate(bool o) : 
	CompareBehaviour<T>(o){
}

template <class T>
CompareDate<T>::~CompareDate(){
}

template <class T>
bool CompareDate<T>::compare(T obj1, T obj2){

	Date date1 = *(obj1->getDate());
	Date date2 = *(obj2->getDate());

	if(this->asc){
		
		if(date1 < date2){
		
			return true;
		
		}
		
		return false;
	
	}else{
	
		if(date1 > date2){
		
			return true;
		
		}
		
		return false;
	
	}

}

#endif
