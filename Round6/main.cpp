// Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/

{
    cout << endl
        << "This program allows the user to enter one command" << endl
        << "(but only one) on each input line." << endl
        << "For example, if the command S is entered, then" << endl
        << "the program will serve the front of the queue." << endl
        << endl

        << " The valid commands are:" << endl
        << "A - Append the next input character to the extended queue" << endl
        << "S - Serve the front of the extended queue" << endl
        << "R - Retrieve and print the front entry." << endl
        << "# - The current size of the extended queue" << endl
        << "C - Clear the extended queue (same as delete)" << endl
        << "P - Print the extended queue" << endl
        << "H - This help screen" << endl
        << "Q - Quit" << endl

        << "Press <Enter> to continue." << flush;

    char c;
    do {
        cin.get(c);
    } while (c != '\n');
}

char get_command()
{
    char ch;
    cout << "Enter your choice" << endl;
    cin >> ch;
    ch = tolower(ch);
    return ch;
}

bool do_command(char c, Extended_queue& test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
      Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
*/

{
    bool continue_input = true;
    Queue_entry x;

    switch (c) {

    case 'a':
        cout << "Enter value to be added" << endl;
        cin >> x;
        test_queue.append(x);
        break;

    case 'c':
        test_queue.clear();
        break;

    case 'p':
        while (!test_queue.empty())
        {
            test_queue.retrieve(x);
            cout << x << endl;
            test_queue.serve();
        }

        break;

    case 'h':
        help();
        break;

    case 's':
        test_queue.serve();
        break;

    case '#':
        cout << "Current size is " << test_queue.size() << endl;
        break;

    case 'r':
        if (test_queue.retrieve(x) == underflow)
            cout << "Queue is empty." << endl;
        else
            cout << endl
            << "The first entry is: " << x
            << endl;
        break;

    case 'q':
        cout << "Extended queue demonstration finished." << endl;
        continue_input = false;
        break;
        //  Additional cases will cover other commands.
    }
    return continue_input;
}

void queAnalyzer(Extended_queue q1, Extended_queue q2)
{
   // cout << "made it here4" << endl;
    string temp1, temp2;
    char x;
    int i = 0;
    cout << q1.size() <<"   " << q2.size() << endl;
    if (q2.size() == 0)
    {
        cout << "N" << endl;
    }
    else if (q1.size() > q2.size())
    {
        cout << "L" << endl;
    }
    else if (q1.size() < q2.size())
    {
        cout << "R" << endl;
    }
    else
    {
        if (q1.size() == q2.size())
        {
            while (!q1.empty())
            {
                q1.retrieve(x);
                //cout << x <<i << endl;
                temp1.push_back(x);
                q1.serve();
            }
            //cout<<"What happended here "<<s<<endl;
            while (!q2.empty())
            {
                q2.retrieve(x);
                //cout << x << i << endl;
                temp2.push_back(x);
                q2.serve();
            }
            cout << " Temp 1 is " <<temp1 <<" and "<<temp2 << endl;
            if (temp1 == temp2)
            {
                cout << "S" << endl;
            }
            else
                cout << "D" << endl;
        }
    }

}

int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
      the class Extended_queue.
Uses: The class Extended_queue and the functions introduction,
      get_command, and do_command.
*/

{
    string input;
    int c = 0;
    Extended_queue q1,q2;
    cout << "Enter a string with/without a colon seperator and the program will check if theres a colon" << endl;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++)
    {

        //cout << "made it here" << endl;
        if (input[i] == ':')
        {
            c++;
            i++;
        }
        if (input[i] != ':' && c==0)
        {
            q1.append(input[i]);
        }
        else
        {
            q2.append(input[i]);
        }
        
        //cout << "made it here3" << endl;
    }

    queAnalyzer(q1, q2);

    //Extended_queue test_queue;
   // test_queue = q;

   // help();
    //while (do_command(get_command(), test_queue));
}


