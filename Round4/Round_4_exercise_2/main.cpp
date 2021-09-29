#include "stack.h"
#include<iostream>
#include<string>

using namespace std;

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    Extended_stack dest, source;

    source.push(5);
    source.push(10);
    source.push(15);
    
    copy_stack(dest, source);

    int x;

    cout << "Size of Dest is = " <<dest.size()<< endl;
    cout << "Values of Dest are " << endl;

    while(!dest.empty())
    {
        dest.top(x);
        cout << x << endl;
        dest.pop();
    }

    //Exercise 2 part a

    cout << endl << "Checking if Destination stack is full or not" << endl;
    if (full(dest) == 0)
    {
        cout << "Stack still has space" << endl;
    }
    else
    {
        cout << "Full stack" << endl;
    }

    //Exercise 2 part b
    int t = 0;
    pop_top(source, t);

    cout << endl << "Value of top of source is = " << t << endl;

    //Exercise 2 part c

    cout << endl << "Current size of Source is " << source.size() << endl;
    clear(source);
    
    //Pushing new values to stack

    source.push(20);
    source.push(25);

    //Exercise 2 part d

    cout << endl << "New size after adding elements to source is " << size(source) << endl;

    //Exercise 2 part e

    source.push(30);
    source.push(35);
    source.push(30);
    
    int num;

    cout << endl << "Input number which you want to delete from stack" << endl;
    cin >> num;
    delete_all(source, num);
    cout << "New stack is " << endl;
    while (!source.empty())
    {
        source.top(x);
        cout << x << endl;
        source.pop();
    }
    return 0;
}
