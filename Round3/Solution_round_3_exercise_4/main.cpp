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
    Stack s;
    int x,num;
    cout << "Enter a list of numbers in ascending order, input a smaller number to terminate list " << endl;
    cin >> num;
    s.push(num);
    cin >> num;
    s.top(x);
    while (num >= x)
    {
        s.push(num);
        cin >> num;
        s.top(x);
    }

    cout << endl << "In reversed order it is" << endl;
    while (!s.empty())
    {
        s.top(x);
        cout << x;
        s.pop();
    }

    return 0;
}
