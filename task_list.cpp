// task_list.cpp
#include "task_list.h"
#include <iostream>
#include<algorithm>
void TaskList::addTask(const Task& newTask) {
    tasks.push_back(newTask);
}

void TaskList::viewTasks() const {
    for (const Task& task : tasks) {
        std::cout << "Task: " << task.name << "\tDue Date: " << task.dueDate;
        std::cout << "\tStatus: " << (task.completed ? "Completed" : "Incomplete") << std::endl;
    }
}

void TaskList::deleteTask(const std::string& taskName) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
                             [taskName](const Task& task) { return task.name == taskName; });

    tasks.erase(it, tasks.end());
}

void TaskList::updateTaskStatus(const std::string& taskName, bool newStatus) {
    for (Task& task : tasks) {
        if (task.name == taskName) {
            task.completed = newStatus;
            break;
        }
    }
}

const std::vector<Task>& TaskList::getTasks() const {
    return tasks;
}
