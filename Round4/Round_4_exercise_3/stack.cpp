#include<iostream>
#include "stack.h"

using namespace std;

//////////////////////////

/*
    Pre: None.
    Post: The stack is initialized to be empty.
*/
Extended_stack::Extended_stack() {
    count = 0;
}


/*
    Pre: None.
    Post: If the Stack is empty,true is returned. Otherwise, false is returned.
*/
bool Extended_stack::empty() const {
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}


/*
    Pre: None.
    Post: If the Stack is not empty, the top of the Stack is removed. If the Stack is empty,an Error_code of underflow is returned.
*/
Error_code Extended_stack::pop() {
    Error_code outcome = success;
    if (count == 0) 
        outcome = underflow;
    else --count;
    return outcome;
}


/*
    Pre: None.
    Post: If the Stack is not empty,the top of the Stack is returned in item. If the Stack is empty an Error code of underflow is returned.
*/
Error_code Extended_stack::top(Stack_entry& item) const {
    Error_code outcome = success;
    if (count == 0) outcome = underflow;
    else item = entry[count - 1];
    return outcome;
}


/*
    Pre: None.
    Post: If the Stack is not full, item is added to the top of the Stack. If the Stack is full, an Error code of overflow is returned and the Stack is left unchanged.
*/
Error_code Extended_stack::push(Stack_entry item) {
    Error_code outcome = success;
    if (count >= maxstack) outcome = overflow;
    else entry[count++] = item;
    return outcome;
}



Error_code copy_stack(Extended_stack& dest, Extended_stack& source)
{
    Error_code outcome = success;
    if (source.size() > 0)
    {
        //cout << source.count << endl;
        for (int i = 0; i < source.count; i++)
        {
            dest.push(source.entry[i]);
        }
    }
    else
        outcome = error;
    return outcome;
}


//Sets count to zero 

void Extended_stack::clear()
{
    count = 0;
}


// Checks for maxsize

bool Extended_stack::full() const{

    if (count == maxstack)
    {
        return true;
    }
    else
        return false;
}

int Extended_stack::size() const {
    return count;
}


bool full(Extended_stack& s)
{
    if (s.size() == maxstack)
    {
        return true;
    }
    else
        return false;
}

Error_code pop_top(Extended_stack& s, Stack_entry& t)
{
    Error_code outcome = success;
    if (s.size() < 0)
    {
        outcome = error;
    }
    else
    {
        s.top(t);
        s.pop();
    }
    return outcome;
}

void clear(Extended_stack& s)
{
    Error_code outcome = success;
    if (s.size() == 0)
    {
        cout << "Already Empty" << endl;
    }
    else
    {
        cout << "Size was " << s.size() << endl;
        s.clear();
        cout << "Now Size is " << s.size() << endl;
    }
}

int size(Extended_stack& s)
{
    if (s.size() < 0)
    {
        return 0;
    }
    else
    {
        return s.size();
    }
}

void delete_all(Extended_stack& s, Stack_entry x)
{
    Extended_stack copy;
    if (s.size() < 0)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        int temp;
        while (!s.empty())
        {
            s.top(temp);
            if (temp == x)
            {
                s.pop();
            }
            else
            {
                copy.push(temp);
                s.pop();
            }
        }
    }

    int temp;
    while (!copy.empty())
    {
        copy.top(temp);
        s.push(temp);
        copy.pop();
    }
}