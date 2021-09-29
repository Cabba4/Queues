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
    Extended_stack s;

    int n, num;
    cout << "Enter number of variables you want to push to stack" << endl;
    cin >> n;
    cout << "Enter values now" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s.push(num);
    }

    cout << "Current size is " << s.size() << endl;

    cout << "Checking if stack is full 0 = no // 1 = yes " << s.full() << endl;

    cout << "Clearing stack" << endl;
    s.clear();

    cout << "Now size is " << s.size() << endl;
    return 0;
}
