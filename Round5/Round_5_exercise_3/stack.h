#pragma once
#include "Utility.h"
typedef int Stack_entry;
const int maxstack = 10;   //  small value for testing

class Extended_stack {
public:
	Extended_stack();
	Error_code pop();
	Error_code push(Stack_entry item);
	Error_code top(Stack_entry& item) const;
	
	bool empty() const;
	void clear(); //  Reset the stack to be empty.
	bool full() const; //  If the stack is full, return true; else return false.
	int size() const;   //  Return the number of entries in the stack.

		
private:
	int count;
	Stack_entry entry[maxstack];


	friend Error_code copy_stack(Extended_stack& dest, Extended_stack& source);
};

//Error_code copy_stack(Extended_stack& dest, Extended_stack& source);

bool full(Extended_stack& s);

Error_code pop_top(Extended_stack& s, Stack_entry& t);

void clear(Extended_stack& s);

int size(Extended_stack& s);

void delete_all(Extended_stack& s, Stack_entry x);


///////////////////////////////////////////////////////////////////////////////


typedef int Queue_entry;
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