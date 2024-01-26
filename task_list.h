// task_list.h
#ifndef TASK_LIST_H
#define TASK_LIST_H

#include <vector>
#include "task.h"

class TaskList {
private:
    std::vector<Task> tasks;

public:
    TaskList() {}

    void addTask(const Task& newTask);
    void viewTasks() const;
    void deleteTask(const std::string& taskName);
    void updateTaskStatus(const std::string& taskName, bool newStatus);

    const std::vector<Task>& getTasks() const; // Added this line
};

#endif // TASK_LIST_H
