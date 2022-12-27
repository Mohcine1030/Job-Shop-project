
vector<Task> FindCandidates(vector<Job*> dataJob){

    vector<Task> TasksCandidates;
    
    for (int i=0; i < dataJob.size(); i++){
        Job* J_i = dataJob[i];
        if (J_i->get_done()){
        }
        else{
        // vector<Task> vecTasks_i = J_i->get_taskVec();
        // int T_index = J_i->get_currentTask();
        // TasksCandidates.push_back(vecTasks_i[T_index]);

        TasksCandidates.push_back(J_i->get_taskVec()[J_i->get_currentTask()]);
        }
    }

    return TasksCandidates;
}