#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "Job.cpp"
#include "CreateJobs.cpp"
#include "resolv.cpp"


int main(){
    srand((unsigned) time(NULL));
    int answer;
    cout << "Press 1 to create a random set of Jobs (press any other number otherwise...)" << endl;
    cin >> answer;
    vector<Job*> dataJob;
    if (answer == 1){
        dataJob = CreateJobs();
    }
    else{
        
        int customjobs;
        cout << "How many Jobs do you want to construct ?" << endl;
        cin >> customjobs;
        for (int i=0; i < customjobs; i++){
            int tN_i;
            cout << "Number of Tasks wanted for Job " << i << " :" << endl;
            cin >> tN_i;
            Job* job_i = new Job(tN_i, i);
            dataJob.push_back(job_i);
        }
    }
    int FCFS = 1;
    int SNT = 2;
    int Priority = 3;

    resolv(dataJob, FCFS);
    resolv(dataJob, SNT);
    resolv(dataJob, Priority);

    
    return 0; 
}