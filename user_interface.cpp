// user_interface.cpp
#include "user_interface.h"
#include <limits>

void UserInterface::displayMenu() {
    std::cout << "\nTo-Do List App Menu:\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Update Task Status\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Save Tasks to File\n";
    std::cout << "6. Load Tasks from File\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

void UserInterface::handleUserInput(TaskList& taskList) {
    int choice;

    std::cin >> choice;

    while (std::cin.fail() || choice < 1 || choice > 7) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the last input
        std::cout << "Invalid input. Please enter a number between 1 and 7: ";
        std::cin >> choice;
    }

    switch (choice) {
        case 1: {
            // Add Task
            std::string name, dueDate;
            std::cout << "Enter task name: ";
            std::cin.ignore(); // Ignore newline left in buffer
            std::getline(std::cin, name);
            std::cout << "Enter due date: ";
            std::getline(std::cin, dueDate);

            Task newTask(name, dueDate);
            taskList.addTask(newTask);

            std::cout << "Task added successfully.\n";
            break;
        }
        case 2:
            // View Tasks
            taskList.viewTasks();
            break;
        case 3: {
            // Update Task Status
            std::string taskName;
            bool newStatus;

            std::cout << "Enter task name: ";
            std::cin.ignore(); // Ignore newline left in buffer
            std::getline(std::cin, taskName);
            std::cout << "Enter new status (1 for completed, 0 for incomplete): ";
            std::cin >> newStatus;

            taskList.updateTaskStatus(taskName, newStatus);

            std::cout << "Task status updated successfully.\n";
            break;
        }
        case 4: {
            // Delete Task
            std::string taskName;
            std::cout << "Enter task name: ";
            std::cin.ignore(); // Ignore newline left in buffer
            std::getline(std::cin, taskName);

            taskList.deleteTask(taskName);

            std::cout << "Task deleted successfully.\n";
            break;
        }
        case 5: {
            // Save Tasks to File
            std::string filename;
            std::cout << "Enter file name to save tasks: ";
            std::cin.ignore(); // Ignore newline left in buffer
            std::getline(std::cin, filename);

            FileManager::saveTasks(filename, taskList);

            std::cout << "Tasks saved to file successfully.\n";
            break;
        }
        case 6: {
            // Load Tasks from File
            std::string filename;
            std::cout << "Enter file name to load tasks from: ";
            std::cin.ignore(); // Ignore newline left in buffer
            std::getline(std::cin, filename);

            TaskList loadedTaskList = FileManager::loadTasks(filename);
            taskList = loadedTaskList;

            std::cout << "Tasks loaded from file successfully.\n";
            break;
        }
        case 7:
            // Exit the program
            std::cout << "Exiting the To-Do List App. Goodbye!\n";
            break;
    }
}
