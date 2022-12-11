
vector<Job*> CreateJobs(){
    int jobNbrChoice;
    int MaxTasksChoice;
    int MaxTimeChoice;
    int MaxPriorityChoice;
    int MaxArrivalTimeChoice;
    vector<Job*> VecJob;
    
    cout << "Enter the number of desired Jobs : " << endl;
    cin >> jobNbrChoice;
    cout << "Enter maximum Tasks range : " << endl;
    cin >> MaxTasksChoice;
    cout << "Enter maximum TIME NEEDED range : " << endl;
    cin >> MaxTimeChoice;
    cout << "Enter maximum PRIORITY range : " << endl;
    cin >> MaxPriorityChoice;
    cout << "Enter maximum ARRIVAL TIME range : " << endl;
    cin >> MaxArrivalTimeChoice;

    for (int i=0; i < jobNbrChoice; i++){
            Job* job_i = new Job(MaxTasksChoice, i, MaxTimeChoice, MaxPriorityChoice, MaxArrivalTimeChoice);
            VecJob.push_back(job_i);
            vector<Task> ve = job_i->get_taskVec();
        for (int j = 0; j < job_i->get_totalTaskNbr(); j++){
            ve[j].print();
        }
    }
    return VecJob;
}