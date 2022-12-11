
class Task{
private:
int timeNeed;
int priority;
int arrivalTime;
int jobNbr;
int taskNbr;
int ServedAtTime;

public:

Task(int j, int tn){
    jobNbr = j;
    taskNbr = tn;
    cout << "Enter time execution of the task : " << endl;
    cin >> timeNeed;
    cout << "Enter priority of the task : " << endl;
    cin >> priority;
    cout << "Enter arrival time of the task : " << endl;
    cin >> arrivalTime;
}

Task(int j, int tn, int timeNeedMax, int priorityMax, int arrivalTimeMax){
    jobNbr = j;
    taskNbr = tn;
    timeNeed = rand() % timeNeedMax + 1;
    priority = rand() % priorityMax + 1;
    arrivalTime = rand() % arrivalTimeMax +1;

}


int get_timeNeed(){
    return timeNeed;
}
int get_priority() {
    return priority;
}
int get_arrivalTime(){
    return arrivalTime;
}

int get_servedTime(){
    return ServedAtTime;
}

int get_job(){
    return jobNbr;
}
int get_taskNbr(){
    return taskNbr;
}

void set_servedTime(int clock){
    ServedAtTime = clock;
}


void print(){
    cout << "Task " << taskNbr << " of job " << jobNbr << endl;
    cout << "Time execution : " << timeNeed << endl;
    cout << "Priority : " << priority << endl;
    cout << "Time arrival : " << arrivalTime << endl;
}


};
