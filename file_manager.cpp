// file_manager.cpp
#include "file_manager.h"
#include <fstream>
#include <iostream>

void FileManager::saveTasks(const std::string& filename, const TaskList& taskList) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
        return;
    }

    const std::vector<Task>& tasks = taskList.getTasks();

    for (const Task& task : tasks) {
        file << task.name << ',' << task.dueDate << ',' << task.completed << '\n';
    }

    file.close();
}

TaskList FileManager::loadTasks(const std::string& filename) {
    TaskList taskList;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading: " << filename << std::endl;
        return taskList;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Assuming the format is: name,dueDate,completed
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos) {
            std::string name = line.substr(0, pos1);
            std::string dueDate = line.substr(pos1 + 1, pos2 - pos1 - 1);
            bool completed = line.substr(pos2 + 1) == "1";

            Task task(name, dueDate);
            task.completed = completed;
            taskList.addTask(task);
        } else {
            std::cerr << "Error: Invalid format in file: " << filename << std::endl;
        }
    }

    file.close();
    return taskList;
}
