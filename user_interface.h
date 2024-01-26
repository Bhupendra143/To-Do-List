// user_interface.h
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <iostream>
#include "task_list.h"
#include "file_manager.h"

class UserInterface {
public:
    static void displayMenu();
    static void handleUserInput(TaskList& taskList);
};

#endif // USER_INTERFACE_H
