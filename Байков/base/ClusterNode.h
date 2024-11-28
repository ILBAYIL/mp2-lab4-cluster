#ifndef CLUSTERNODE_H
#define CLUSTERNODE_H

// Класс узла кластера
class ClusterNode {
public:
    bool isBusy;  // Занят ли узел
    int remainingTime;  // Оставшееся время выполнения задачи

    ClusterNode() : isBusy(false), remainingTime(0) {}

    // Назначить задачу на узел
    void assignTask(int duration) {
        isBusy = true;
        remainingTime = duration;
    }

    // Обработка такта
    void processTick() {
        if (isBusy) {
            remainingTime--;
            if (remainingTime <= 0) {
                isBusy = false;
            }
        }
    }
};

#endif // CLUSTERNODE_H
