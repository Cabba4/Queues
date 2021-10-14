#pragma once
#include<iostream>
#include "utility.h"
typedef char Queue_entry;
using namespace std;

const int maxqueue = 10; //  small value for testing


class Queue {
public:
	Queue();
	bool empty() const;
	Error_code append(const Queue_entry& x);		//adds new element to rear
	Error_code serve();								//front of the queue is removed
	Error_code retrieve(Queue_entry& x) const;		//shows the front of the queue
	// Additional members will represent queue data.

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};

class Extended_queue : public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry& item);
};