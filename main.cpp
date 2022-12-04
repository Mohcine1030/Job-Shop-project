#include <iostream>
#include "Job.cpp"
#include <vector>
#include <cstdlib>
#include <time.h> 
using namespace std;

int main(){
    srand((unsigned) time(NULL));

    Job* job1 = new Job(2, 1);
    vector<Task> ve = job1->get_taskVec();
    for (int i=0; i < 2; i++){
        ve[i].print();
    }
    return 0; 
}