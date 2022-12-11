#include "Task.cpp"

class Job{
private:


int totalTaskNbr;
int currentTask = 0;
int jobNbr;
bool done = false;
int firstArrivalTime;
int waitedTime = 0; // Comptabilise (incrémente) le temps durant lequel le job a attendu (ne prend pas en compte le temps de réalisation... )
                    // (... de ses propres tâches !)

vector<Task> vecTask;

public:

Job(int tN, int nj){
    jobNbr = nj;
    totalTaskNbr = tN;

    for (int i = 0; i < tN; i++){
        Task Task_i = Task(nj, i);
        vecTask.push_back(Task_i);
        if (i == 0){
            firstArrivalTime = Task_i.get_arrivalTime();
        }
        else{
            if (Task_i.get_arrivalTime() < firstArrivalTime){
                firstArrivalTime = Task_i.get_arrivalTime();
            }
        }
    }

}

Job(int tN, int nj, int tnm,int pm, int atm){

    totalTaskNbr = rand() % tN + 1;
    jobNbr = nj;
    cout << "On est rentre dans Job" << nj << endl;

     for (int i = 0; i < totalTaskNbr; i++){
        cout << "creation de task " << i << endl;
        Task Task_i = Task(nj, i, tnm, pm, atm);
        vecTask.push_back(Task_i);
        if (i == 0){
            firstArrivalTime = Task_i.get_arrivalTime();
        }
        else{
            if (Task_i.get_arrivalTime() < firstArrivalTime){
                firstArrivalTime = Task_i.get_arrivalTime();
            }
        }
    }

}


void update(Task NextTask){
    if (!done){
        if (NextTask.get_job() == jobNbr){
            if (NextTask.get_taskNbr() == totalTaskNbr-1){
                set_done();                                  // Job fini !

            }
            else{
                incrCurrent();                                // Job pas encore fini -> Task suivante..
            } 
        }

        else{
            if (NextTask.get_servedTime() >= firstArrivalTime){
                incr_waitedTime(NextTask.get_timeNeed());         // Les jobs comptabilisent le temps d'attente de cette tâche..
            }
            else{
                if(NextTask.get_servedTime() + NextTask.get_timeNeed() <= firstArrivalTime){

                }
                else{
                    incr_waitedTime(NextTask.get_servedTime() + NextTask.get_timeNeed() - firstArrivalTime);
                }

            }
        }
    }
    else{
    }
}

void incrCurrent(){
    currentTask ++;
}

void incr_waitedTime(int incr){
    waitedTime = waitedTime + incr;
}

void set_waitedTime(int wt){
    waitedTime = wt;
}

int get_currentTask(){
    return currentTask;
}

int get_waitedTime(){
    return waitedTime;
}

int get_totalTaskNbr(){
    return totalTaskNbr;
}

int get_done(){
    return done;
}

vector<Task> get_taskVec(){
    return vecTask;
}

void set_jobNbr(int i){
    jobNbr = i;
}

void set_done(){
    done = true;
}

void set_currentTask(int curr){
    currentTask = curr;
}

void reset_done(){
    done = false;
}

void ResetJob(){
    reset_done();
    set_currentTask(0);
    set_waitedTime(0);
}

void showResult(){
    cout << "The Job " << jobNbr << " was done after a waiting time of : " << waitedTime << " [Time Units]" << endl;
}

};