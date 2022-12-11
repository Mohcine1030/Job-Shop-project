
bool update_condition(vector<Job*> dataJb){

    bool stat = true;

    for (int i=0; i < dataJb.size(); i++){
        bool Job_i_state = dataJb[i]->get_done();
        stat = stat && Job_i_state;
    }

    return stat;
}