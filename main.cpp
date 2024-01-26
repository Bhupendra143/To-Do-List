// main.cpp
#include "task_list.h"
#include "user_interface.h"

int main() {
    TaskList taskList;

    int choice;
    do {
        UserInterface::displayMenu();
        UserInterface::handleUserInput(taskList);
    } while (choice != 7);

    return 0;
}
