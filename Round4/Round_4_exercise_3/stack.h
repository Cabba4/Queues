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