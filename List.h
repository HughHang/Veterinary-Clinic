#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;
#include <cstdlib>

#include "CompareBehaviour.h"

template <class T>
class Node {
	
	public:
		T data;
		Node* next;
		Node* prev;
};

template <class T>
class List{

	template <class V>
	friend ostream& operator<<(ostream&, List<V>&);
	
	public:
		//Purpose: Constructor and destructor
		List(bool = true);
		~List();
		
		/*
		In: o
		Purpose: Setter
		*/
		void setComp(CompareBehaviour<T>*);
		
		/*
		In: obj
		Purpose: Add data object to list
		*/
		bool add(T);

		/*
		In: id, foundObj
		Purpose: Find a specific id
		*/
		virtual bool find(int, T*);
		
		/*
		In: arr, size
		Purpose: Convert the linked list to an array
		*/
		virtual void convertToArray(T* arr, int& size);
		
		void cleanUpData();
		
	private:
		Node<T>* head;
		CompareBehaviour<T>* comp;

};

template <class T>
List<T>::List(bool o) : 
	head(NULL),
	comp(NULL){
}

template <class T>
List<T>::~List(){

	Node<T>* currNode = head;
	Node<T>* nextNode;
	
	while(currNode != NULL){
	
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	
	}

	delete comp;

}

template <class T>
void List<T>::setComp(CompareBehaviour<T>* o){
	
	comp = o;
	
}

template <class T>
bool List<T>::add(T obj){

	Node<T>* tmpNode;
	Node<T>* currNode;
	Node<T>* prevNode;
	
	tmpNode = new Node<T>;
	tmpNode->data = obj;
	tmpNode->next = NULL;
	tmpNode->prev = NULL;
	
	prevNode = NULL;
	currNode = head;
	
	while(currNode != NULL){
		
		if(comp->compare(obj, currNode->data)){
		
			break;
		
		}
		
		prevNode = currNode;
		currNode = currNode->next;
	
	}
	
	if(prevNode == NULL){
	
		head = tmpNode;
	
	}else{
	
		prevNode->next = tmpNode;
	
	}
	
	if(currNode != NULL){
	
		currNode->prev = tmpNode;
	
	}
	
	tmpNode->next = currNode;
	tmpNode->prev = prevNode;
	
	return true;

}

template <class T>
bool List<T>::find(int id, T* foundObj){

	Node<T>* currNode = head;
	
	while(currNode != NULL){
	
		if(currNode->data->getId() == id){
		
			*foundObj = currNode->data;
			return true;
		
		}
		
		currNode = currNode->next;
	
	}
	
	return false;

}

template <class T>
void List<T>::convertToArray(T* arr, int& size){

	Node<T>* currNode = head;
	
	int index = 0;
	while(currNode != NULL){
	
		arr[index] = currNode->data;
		index++;
		currNode = currNode->next;
	
	}
	
	size = index;

}

template <class T>
void List<T>::cleanUpData(){

	Node<T>* currNode = head;
	Node<T>* nextNode;
	
	while(currNode != NULL){
		nextNode = currNode->next;
		delete currNode->data;
		currNode = nextNode;
	}
	
}

template <class T>
ostream& operator<<(ostream& output, List<T>& list){

	
	Node<T>* currNode = list.head;
	Node<T>* savePrev = NULL;
	
	output << "--- FORWARD: " << endl;
	
	while(currNode != NULL){
	
		output << *currNode->data;
		savePrev = currNode;
		currNode = currNode->next;
	}
	
	currNode = savePrev;
	output << endl;
	
	output << "--- BACKWARD: " << endl;
	
	while (currNode != NULL){
	
		output << *currNode->data;
		currNode = currNode->prev;
	
	}
	
	return output;

}

#endif
