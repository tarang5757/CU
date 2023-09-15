
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"
#include <iomanip> 

using namespace std;

template <class T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T);
		void remove(T);
		int size() const;
		bool isFull() const;
		void clear();
		//get
		T operator[](int);
		T operator[](int) const;
		Array<T>& operator+=(T);
		Array<T>& operator-=(T);

	
	private:
		int numElements;
		T* elements;
	
};

//methods
template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
Array<T>::~Array(){
    delete[] elements;
}

template <class T>
void Array<T>::add(T t){
	if (numElements >= MAX_ARRAY)   return;
  	elements[numElements++] = t;
}

template <class T>
void Array<T>::remove(T t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

template <class T>
int Array<T>::size() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull() const{
	return numElements >= MAX_ARRAY;
}

template<class T>
void Array<T>::clear() {
	numElements = 0;
}

template<class T>
Array<T>& Array<T>::operator-=(T t) {
	remove(t);
	return *this;
}

template<class T>
Array<T>& Array<T>::operator+=(T t) {
	add(t);
	return *this;
}

template <class T>
T Array<T>::operator[](int index){
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template<typename T>
T Array<T>::operator[](int index) const {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

#endif
