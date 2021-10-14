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
    Extended_stack invest;
    int total = 0;
    int choice;
    Extended_queue invest2;
    cout << "Do you want to use 1) LIFO (stacks) or 2) FIFO (queue) " << endl;
    cin >> choice;
    if(choice == 2)
    {
        cout << "The month is January , you bought shares , rate is 10$ per share" << endl;
        invest2.append(-1000);
        cout << "The month is April , you bought shares , rate is 30$ per share" << endl;
        invest2.append(-3000);
        cout << "The month is July , you sold shares , rate is 20$ per share" << endl;
        invest2.append(2000);
        cout << "The month is September , you bought shares, rate is 50$ per share" << endl;
        invest2.append(-5000);
        cout << "The month is November , you sold shares , rate is 30$ per share" << endl;
        invest2.append(3000);


        cout << "Your total profit/loss is" << endl;
        while (!invest2.empty())
        {
            invest2.retrieve(total);
            total += total;
            invest2.serve();
        }

        if (total < 0)
        {
            cout << "Your loss is of" << endl;
        }
        else
        {
            cout << "Your profit is of" << endl;
        }
        cout << "Total = " << total << "$" << endl;

    }

    else
    {

        cout << "The month is January , you bought shares , rate is 10$ per share" << endl;
        invest.push(-1000);
        cout << "The month is April , you bought shares , rate is 30$ per share" << endl;
        invest.push(-3000);
        cout << "The month is July , you sold shares , rate is 20$ per share" << endl;
        invest.push(2000);
        cout << "The month is September , you bought shares, rate is 50$ per share" << endl;
        invest.push(-5000);
        cout << "The month is November , you sold shares , rate is 30$ per share" << endl;
        invest.push(3000);

        cout << "Your total profit/loss is" << endl;
        while (!invest.empty())
        {
            invest.top(total);
            total += total;
            invest.pop();
        }

        if (total < 0)
        {
            cout << "Your loss is of" << endl;
        }
        else
        {
            cout << "Your profit is of" << endl;
        }
        cout << "Total = " << total << "$" << endl;

    }

    return 0;
}
