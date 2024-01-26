// task.h
#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
    std::string name;
    std::string dueDate;
    bool completed;

    // Constructor
    Task(const std::string& taskName, const std::string& taskDueDate)
        : name(taskName), dueDate(taskDueDate), completed(false) {}
};

#endif // TASK_H
