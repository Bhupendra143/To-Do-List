#include <iostream>
#include "task.h"
using namespace std;

int main()
{
    int choice;
    cout << "--------------To Do List App--------------\n";
    cout<<"         1. Add Task" << endl;
    cout<<"         2. View Tasks" << endl;
    cout<<"         3. Update Task Status" << endl;
    cout<<"         4. Delete Task"<< endl;
    cout<<"         5. Exit" << endl;
    cout<<"Enter your choice: " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        AddTask();
        break;
    
    default:
        break;
    }
    return 0;
}