#include "stack.h"
#include<iostream>
#include<string>

using namespace std;


int temp;

void stack_to_que(Extended_stack stack, Extended_queue que)
{
    while (!stack.empty())
    {
        stack.top(temp);
        que.append(temp);
        stack.pop();
    }

    cout << "Queue looks like" << endl;
    while (!que.empty())
    {
        que.retrieve(temp);
        cout << temp << endl;
        que.serve();
    }
}

void que_to_stack(Extended_stack stack, Extended_queue que)
{
    while (!que.empty())
    {
        que.retrieve(temp);
        stack.push(temp);
        que.serve();
    }

    cout << "Stack looks like" << endl;
    while (!stack.empty())
    {
        stack.top(temp);
        cout << temp << endl;
        stack.pop();
    }
}

void one_to_another(Extended_stack s1, Extended_stack &s2)
{
    Extended_stack var;
    while (!s1.empty())
    {
        s1.top(temp);
        var.push(temp);
        s1.pop();
    }

    while (!var.empty())
    {
        var.top(temp);
        s2.push(temp);
        var.pop();
    }

    cout << "Stack looks like" << endl;
    while (!s2.empty())
    {
        s2.top(temp);
        cout << temp << endl;
        s2.pop();
    }
}

void reverse_stack(Extended_queue q)
{
    Extended_stack stack;
    while (!q.empty())
    {
        q.retrieve(temp);
        stack.push(temp);
        q.serve();
    }
    while (!stack.empty())
    {
        stack.top(temp);
        q.append(temp);
        stack.pop();
    }

    cout << "Queue looks like" << endl;
    while (!q.empty())
    {
        q.retrieve(temp);
        cout << temp << endl;
        q.serve();
    }
}

void reverse_que(Extended_stack s)
{
    Extended_queue que;

    while (!s.empty())
    {
        s.top(temp);
        que.append(temp);
        s.pop();
    }
    while (!que.empty())
    {
        que.retrieve(temp);
        s.push(temp);
        que.serve();
    }

    cout << "Stack looks like" << endl;
    while (!s.empty())
    {
        s.top(temp);
        cout << temp << endl;
        s.pop();
    }
}

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    Extended_queue que;
    Extended_stack stack, s2;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    que.append(10);
    que.append(9);
    que.append(8);

    s2.push(100);
    s2.push(200);

    //Function to move entries from a stack to queue

    //stack_to_que(stack, que);

    //Function to move entries from a que to stack

    //que_to_stack(stack, que);

    //Empty one stack from another

    //one_to_another(stack, s2);

    //reverse_stack(que);

    reverse_que(s2);
    

    // Uncomment each function to run it.


    return 0;
}
