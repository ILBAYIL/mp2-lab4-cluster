#ifndef TASK_H
#define TASK_H

// Класс задачи
class Task {
public:
    int duration;  // Сколько тактов будет выполняться задача
    int nodesRequired;  // Сколько узлов требуется для выполнения задачи

    Task(int t, int p) : duration(t), nodesRequired(p) {}
};

#endif // TASK_H