#ifndef TASK_H
#define TASK_H


class Task {
public:
    int duration; 
    int nodesRequired;  

    Task(int t, int p) : duration(t), nodesRequired(p) {}
};

#endif // TASK_H