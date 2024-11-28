#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <queue>
#include "task.h"

class Queue {
private:
    std::queue<Task> tasks;  
public:
    void addTask(const Task& task) {
        tasks.push(task);
    }

    bool hasTasks() const {
        return !tasks.empty();
    }

    Task getNextTask() {
        if (tasks.empty()) {
            throw std::runtime_error("Очередь пуста");
        }
        Task task = tasks.front();
        tasks.pop();
        return task;
    }
};

#endif // QUEUE_H
