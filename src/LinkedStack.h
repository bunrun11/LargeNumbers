/*
 * LinkedStack.h
 *
 *  Created on: Oct 28, 2017
 *      Author: Job
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>

template <class T>
struct Node{
    T& data;
    Node<T>* next;

    Node(T&);
    ~Node();
};

template <class T>
class LinkedStack{
	Node<T> *top;

	public:
	LinkedStack();
	~LinkedStack();

	void deleteAll();

	bool isEmpty();
    void push(T&);
    T& pop();
    T& peek();
};

template<class T>
Node<T>::Node(T& data):data(data){
	next = 0;
}

template<class T>
LinkedStack<T>::LinkedStack(){
	top = 0;
}

template<class T>
LinkedStack<T>::~LinkedStack(){
	deleteAll();
}

//deletes all data in the stack
template<class T>
void LinkedStack<T>::deleteAll(){
	while(!isEmpty()){
		T data = pop();
		delete &data;
	}
}

//checks to see of the stack is empty
template<class T>
bool LinkedStack<T>::isEmpty(){
	return !top;
}

//pushes data onto the stack
template<class T>
void LinkedStack<T>::push(T& data){
	Node<T>* newNode = new Node<T>(data);
	newNode->next = top;
	top = newNode;
}

//returns the data on the top and removes it from the stack
template<class T>
T& LinkedStack<T>::pop(){
	if(isEmpty() == 0){
		T &data = top->data;
		top = top->next;
		return data;
	}
	throw std::exception();
}

//peeks at the top of the stack
template<class T>
T& LinkedStack<T>::peek(){
	if(isEmpty() == 0){
		return top->data;
	}
	throw std::exception();
}


#endif /* LINKEDSTACK_H_ */
