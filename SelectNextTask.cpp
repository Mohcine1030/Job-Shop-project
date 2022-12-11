
Task SelectNextTask(vector<Task> Candidates, int Algo, int clock){
    int Index;
    int best = 1000000000;
    int bestP = -1000000000;
    for (int i=0; i < Candidates.size(); i++){
    if (Algo == 1){
        if ((Candidates[i].get_arrivalTime() < best) && (Candidates[i].get_arrivalTime() <= clock)){
            best = Candidates[i].get_arrivalTime();
            Index = i;
        }
    }
    else if(Algo == 2){
            if ((Candidates[i].get_timeNeed() < best) && (Candidates[i].get_arrivalTime() <= clock)){
            best = Candidates[i].get_timeNeed();
            Index = i;
        }
    }
    else if(Algo == 3){
            if ((Candidates[i].get_priority() > bestP) && (Candidates[i].get_arrivalTime() <= clock)){
            bestP = Candidates[i].get_priority();
            Index = i;
        }
    }
    }

    return Candidates[Index];
}