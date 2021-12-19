/** @file  Problems_set.cc
    @brief  This file contains implementation of class Problems_set.hh.
    @author Ankush Rana
*/

#include "Problems_set.hh"

// Constructer & Destructer
Problems_set::Problems_set(){}

// Modifiers

bool Problems_set::add(const string& p){
    return probs_set.insert({p, Problem()}).second;
}

void Problems_set::update_on_send(const string& p, bool r){
    probs_set.find(p)->second.increment_values(r);
}

// Consultor

bool Problems_set::exist(const string& p) const{
    return probs_set.find(p) != probs_set.end();
}

int Problems_set::n_problems() const{
    return probs_set.size();
}

// Read & Write
void Problems_set::read(){
    int n_prob;
    cin >> n_prob;
    probs_set = map<string, Problem>();
    for (int i = 0; i < n_prob; ++i){
        string p;
        cin >> p;
        probs_set.insert({p, Problem()});
    }    
}

void Problems_set::write() const{
    vector<pair<string, Problem> > v(this->probs_set.begin(), this->probs_set.end());
    sort(v.begin(), v.end(), Problem::comp_ratio);
    for(int i = 0; i < v.size(); ++i){
        cout << v[i].first;
        v[i].second.write();
    }
}

void Problems_set::write(const string& name) const{
    map<string, Problem>::const_iterator it = probs_set.find(name);
    if(it != probs_set.end()) {
        cout << it->first;
        it->second.write();
    }
    else cout << "error: el problema no existe" << endl;
}
