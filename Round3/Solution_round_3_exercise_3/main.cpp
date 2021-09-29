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
    string str;
    char ch;

    cout << "Enter a string of characters" << endl;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    cout << endl << "In reversed order it is" << endl;
    while (!s.empty())
    {
        s.top(ch);
        cout << ch;
        s.pop();
    }

    return 0;
}
