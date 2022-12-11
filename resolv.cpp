#include "update_condition.cpp"
#include "FindCandidates.cpp"
#include "SelectNextTask.cpp"

void resolv(vector<Job*> dataJob, int Algo){

    bool finished = update_condition(dataJob);
    float AverageTime = 0;
    float jobnumbers = dataJob.size();
    float AverageTaskTime = 0;
    int clock = 0;
    vector<Task> TaskInOrder; 
    while (!finished)
    {
        vector<Task> TasksCandidates = FindCandidates(dataJob);

        // On cherche la task qui arrive en premier
        int minArrivalTime = 1000000000;
        for (int i=0; i < TasksCandidates.size(); i++){
            if(TasksCandidates[i].get_arrivalTime() < minArrivalTime){
                minArrivalTime = TasksCandidates[i].get_arrivalTime();
            } 

        }
        if (clock < minArrivalTime){ 
            clock = minArrivalTime;
        }

        Task NextTaskTodo = SelectNextTask(TasksCandidates, Algo, clock);
        NextTaskTodo.set_servedTime(clock);
        
        for (int i=0; i < dataJob.size(); i++){
            dataJob[i]->update(NextTaskTodo);
        }

        clock = clock + NextTaskTodo.get_timeNeed();

        TaskInOrder.push_back(NextTaskTodo);
        finished = update_condition(dataJob);
    }
    
    ofstream myfile;
    if (Algo == 1){
        myfile.open ("FCFS.txt");
    }
    else if (Algo == 2){
        myfile.open ("SNT.txt");
    }
    else{
        myfile.open ("Priority.txt");
    }


    cout << "Here are the results for the given scheduling algorithm : " << Algo << endl;
    for (int i=0; i < dataJob.size(); i++){
            dataJob[i]->showResult();
            myfile << dataJob[i]->get_waitedTime() << endl;
            AverageTime = AverageTime + dataJob[i]->get_waitedTime();
        }

    AverageTime = AverageTime / jobnumbers;
    cout << "Average Time waited per Job : " << AverageTime << " [Time Units]" << endl;
    
    for (int i=0; i < TaskInOrder.size(); i++){
        int waited = TaskInOrder[i].get_servedTime() - TaskInOrder[i].get_arrivalTime();
        myfile << TaskInOrder[i].get_taskNbr() << " " << TaskInOrder[i].get_job() << " " << waited << endl;
        AverageTaskTime = AverageTaskTime + waited; 
        cout << "Task number " << TaskInOrder[i].get_taskNbr() << " of Job " << TaskInOrder[i].get_job();
        cout << " has waited " << waited << endl;
    }

    float TaskNumber = TaskInOrder.size();
    AverageTaskTime = AverageTaskTime / TaskNumber;
    cout << "Average Time waited per Task : " << AverageTaskTime << " [Time Units]" << endl;
    myfile.close();


    for (int i=0; i < dataJob.size(); i++){
        dataJob[i]->ResetJob();
    }
}