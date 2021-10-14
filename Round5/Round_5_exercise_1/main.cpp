// Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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


int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
      the class Extended_queue.
Uses: The class Extended_queue and the functions introduction,
      get_command, and do_command.
*/

{
    Extended_queue q;
    q.append('a');
    //q.serve();
    q.append('b');
    //q.serve();
    q.append('c');
    q.append('d');
    //q.serve();

    Extended_queue test_queue;
    test_queue = q;

    help();
    while (do_command(get_command(), test_queue));
}


