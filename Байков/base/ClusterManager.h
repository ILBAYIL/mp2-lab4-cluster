#ifndef CLUSTERMANAGER_H
#define CLUSTERMANAGER_H

#include <vector>
#include <iostream>
#include "ClusterNode.h"
#include "queue.h"


class ClusterManager {
private:
    std::vector<ClusterNode> nodes;  
    Queue taskQueue; 
    int completedTasks = 0;  
    int failedTasks = 0;  
    int totalTasks = 0;  
    int totalTicks = 0;  
    double totalLoad = 0.0; 

public:
   
    ClusterManager(int nodeCount) : nodes(nodeCount) {}


    void addTaskToQueue(const Task& task) {
        taskQueue.addTask(task);
        totalTasks++;
    }

    void processTasks() {
        int busyNodes = 0;


        for (auto& node : nodes) {
            node.processTick();
            if (node.isBusy) {
                busyNodes++;
            }
        }

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


        totalLoad += static_cast<double>(busyNodes) / nodes.size();
        totalTicks++;
    }


    void printStatistics() const {
        std::cout << "Общее количество тактов: " << totalTicks << "\n";
        std::cout << "Выполнено задач: " << completedTasks << "\n";
        std::cout << "Невыполнено задач: " << failedTasks << "\n";
        std::cout << "Общее количество задач: " << totalTasks << "\n";
        std::cout << "Загрузка кластера: " << (totalLoad / totalTicks) * 100 << "%\n";
    }

    void visualizeCluster() const {
        std::cout << "Состояние кластера: ";
        for (const auto& node : nodes) {
            std::cout << (node.isBusy ? 'X' : '.');
        }
        std::cout << "\n";
    }

    int getCompletedTasks() const { return completedTasks; }
    int getFailedTasks() const { return failedTasks; }
    int getTotalTasks() const { return totalTasks; }
    int getTotalTicks() const { return totalTicks; }
    double getTotalLoad() const { return totalLoad; }
};

#endif // CLUSTERMANAGER_H
