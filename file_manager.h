// file_manager.h
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include "task.h"
#include "task_list.h"

class FileManager {
public:
    static void saveTasks(const std::string& filename, const TaskList& taskList);
    static TaskList loadTasks(const std::string& filename);
};

#endif // FILE_MANAGER_H
