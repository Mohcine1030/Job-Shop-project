#include <iostream>
#include "Task.cpp"
#include <vector>
using namespace std;


vector<int>* createVecNbrTaskHasard(int nbrJob, int maxTask){
    vector<int> vecNbrTask[nbrJob];
    int nTask;
    for (int i = 0; i < nbrJob; i++){
        nTask = (rand() % (maxTask+1)) + 1;
        vecNbrTask->push_back(nTask);
    }
    return vecNbrTask;

}
vector<Job*>* createJobVec(int nbrJob, vector<int> vecNbrTask){
    vector<Job*> vecJob[nbrJob];
    for (int i = 0; i < nbrJob; i++){
            vecJob->push_back(new Job(vecNbrTask[i],i));
    }
    return vecJob;
}

vector<Task>* createVecTask(vector<Job*> vecJob){
    vector<Task> vecTask;
    for (int i = 0; i < vecJob.size(); i++){
        
    }
}

