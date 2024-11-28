#ifndef CLUSTERNODE_H
#define CLUSTERNODE_H


class ClusterNode {
public:
    bool isBusy; 
    int remainingTime;  

    ClusterNode() : isBusy(false), remainingTime(0) {}


    void assignTask(int duration) {
        isBusy = true;
        remainingTime = duration;
    }


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
