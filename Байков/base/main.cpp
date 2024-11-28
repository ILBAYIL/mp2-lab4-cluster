#include <iostream>
#include <random>
#include <ctime>
#include "ClusterManager.h"
#include "queue.h"
#include "task.h"
#include "clusterNode.h"


int main() {
    setlocale(LC_ALL, "Russian");
    int nodeCount, k;
    double L;

    std::cout << "Введите количество узлов в кластере (по умолчанию от 16 до 64): ";
    std::cin >> nodeCount;
    std::cout << "Введите порог вероятности (0 < L < 1): ";
    std::cin >> L;
    std::cout << "Введите количество задач на такт (k >= 1): ";
    std::cin >> k;

    ClusterManager cluster(nodeCount);
    std::default_random_engine generator(static_cast<unsigned>(time(nullptr)));
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::uniform_int_distribution<int> durationDist(1, 10);
    std::uniform_int_distribution<int> nodesDist(1, nodeCount);

    int ticks = 0;
    while (ticks < 100) {
        for (int i = 0; i < k; ++i) {
            if (distribution(generator) < L) {
                int duration = durationDist(generator);
                int nodesRequired = nodesDist(generator);
                cluster.addTaskToQueue(Task(duration, nodesRequired));
            }
        }

        cluster.processTasks();
        cluster.visualizeCluster();
        ticks++;
    }

    cluster.printStatistics();
    return 0;
}
