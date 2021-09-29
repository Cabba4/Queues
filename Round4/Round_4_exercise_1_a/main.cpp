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

    while(!dest.empty())
    {
        dest.top(x);
        cout << x << endl;
        dest.pop();
    }
    return 0;
}
