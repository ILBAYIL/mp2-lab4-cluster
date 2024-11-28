#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <queue>
#include "task.h"

// Класс очереди задач
class Queue {
private:
    std::queue<Task> tasks;  // Очередь задач
public:
    // Добавление задачи в очередь
    void addTask(const Task& task) {
        tasks.push(task);
    }

    // Проверка наличия задач в очереди
    bool hasTasks() const {
        return !tasks.empty();
    }

    // Получение следующей задачи из очереди
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
