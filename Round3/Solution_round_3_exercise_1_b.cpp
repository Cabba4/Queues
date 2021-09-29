#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
    //int n;
    string input;
    double item;
    stack<char> characters;  //  declares and initializes a stack of numbers

    cout << " Type in a string." << endl
        << " The string will be printed in reverse order." << endl;
    getline(cin,input);

    for (int i = 0; i < input.length(); i++) {
        characters.push(input[i]);
    }

    cout << endl << endl;
    while (!characters.empty()) {
        cout << characters.top();
        characters.pop();
    }
    cout << endl;
}