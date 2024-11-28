#ifndef CLUSTERMANAGER_H
#define CLUSTERMANAGER_H

#include <vector>
#include <iostream>
#include "ClusterNode.h"
#include "queue.h"

// Класс управления кластером
class ClusterManager {
private:
    std::vector<ClusterNode> nodes;  // Узлы кластера
    Queue taskQueue;  // Очередь задач
    int completedTasks = 0;  // Количество выполненных задач
    int failedTasks = 0;  // Количество невыполненных задач
    int totalTasks = 0;  // Общее количество задач
    int totalTicks = 0;  // Общее количество тактов
    double totalLoad = 0.0;  // Общая загрузка кластера

public:
    // Конструктор: инициализация с количеством узлов в кластере
    ClusterManager(int nodeCount) : nodes(nodeCount) {}

    // Добавление задачи в очередь
    void addTaskToQueue(const Task& task) {
        taskQueue.addTask(task);
        totalTasks++;
    }

    // Обработка задач в кластере
    void processTasks() {
        int busyNodes = 0;

        // Освобождение узлов
        for (auto& node : nodes) {
            node.processTick();
            if (node.isBusy) {
                busyNodes++;
            }
        }

        // Постановка новых задач
        while (taskQueue.hasTasks()) {
            bool assigned = false;
            Task task = taskQueue.getNextTask();

            if (task.nodesRequired <= nodes.size() - busyNodes) {
                for (auto& node : nodes) {
                    if (!node.isBusy && task.nodesRequired > 0) {
                        node.assignTask(task.duration);
                        busyNodes++;
                        task.nodesRequired--;
                    }
                }
                assigned = true;
            }

            if (!assigned) {
                failedTasks++;
            } else {
                completedTasks++;
            }
        }

        // Статистика загрузки
        totalLoad += static_cast<double>(busyNodes) / nodes.size();
        totalTicks++;
    }

    // Вывод статистики
    void printStatistics() const {
        std::cout << "Общее количество тактов: " << totalTicks << "\n";
        std::cout << "Выполнено задач: " << completedTasks << "\n";
        std::cout << "Невыполнено задач: " << failedTasks << "\n";
        std::cout << "Общее количество задач: " << totalTasks << "\n";
        std::cout << "Загрузка кластера: " << (totalLoad / totalTicks) * 100 << "%\n";
    }

    // Визуализация состояния кластера
    void visualizeCluster() const {
        std::cout << "Состояние кластера: ";
        for (const auto& node : nodes) {
            std::cout << (node.isBusy ? 'X' : '.');
        }
        std::cout << "\n";
    }

    // Методы для получения значений
    int getCompletedTasks() const { return completedTasks; }
    int getFailedTasks() const { return failedTasks; }
    int getTotalTasks() const { return totalTasks; }
    int getTotalTicks() const { return totalTicks; }
    double getTotalLoad() const { return totalLoad; }
};

#endif // CLUSTERMANAGER_H
