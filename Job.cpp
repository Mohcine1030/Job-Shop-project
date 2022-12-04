#include <iostream>
#include <vector>
#include "Task.cpp"
using namespace std;



class Job{
private:

int totalTaskNbr;
int currentTask = 1;
int jobNbr;

vector<Task> vecTask;

public:

Job(int tN, int nj){
    jobNbr = nj;
    totalTaskNbr = tN;

    for (int i = 0; i < tN; i++){
        vecTask.push_back(Task(nj, i));
    }
}

Job(int tN, int nj, int tnm,int pm, int atm){
    totalTaskNbr = tN;
    jobNbr = nj;
    cout << "On est rentre dans Job" << endl;

     for (int i = 0; i < tN; i++){
        cout << "creation de task " << i << endl;
        vecTask.push_back(Task(nj, i, tnm, pm, atm));
    }

}

void incrCurrent(){
    currentTask ++;
}

void printCurrentTask(){
    cout << currentTask << endl;
}
void set_jobNbr(int i){
    jobNbr = i;
}
vector<Task> get_taskVec(){
    return vecTask;
}
// void add_task(Task taskx){
//     taskVector.push_back(taskx);
// }

};