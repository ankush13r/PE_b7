/** @file  Course.cc
    @brief  This file contains implementation of class Course.hh.
    @author Ankush Rana
*/

#include "Course.hh"

Course::Course() {
    completed_users = 0;
    current_users = 0;
    id = 0;
}

Course::Course(unsigned int id) {
    completed_users = 0;
    current_users = 0;
    this->id = id;
}

// Modifiers
void Course::increment_completed(){
    ++completed_users;
}

unsigned int Course::increment_current_user(){
    return ++current_users;
}

void Course::reduce_current_user(){
    --current_users;
}

void Course::add_session(const string& s){
    v_sessions.push_back(s);
}

void Course::add_session_problema(const string& p, const string& s){
    problems_session.insert({p, s});
}

// Consultors

unsigned int Course::n_problems() const{
    return problems_session.size();
}

unsigned int Course::n_subscribed() const{
    return current_users;
}

const string& Course::session_id(unsigned int i) const{
    return v_sessions[i - 1];
}

unsigned int Course::n_sessions() const{
    return v_sessions.size();
}

unsigned int Course::get_id() const{
    return id;
}

pair<bool, string> Course::session_problem(const string& p) const{
    map<string, string>::const_iterator it = problems_session.find(p);
    if(it != problems_session.end()) return {true, it->second};
    return {false, ""};
}

void Course::write() const{
    cout << id << ' ' << completed_users << ' ' << current_users << ' ' << v_sessions.size() << ' '  << '(';

    cout << v_sessions[0];
    unsigned int n = v_sessions.size();
    for(unsigned int i = 1; i < n; ++i){
        cout << ' ' << v_sessions[i];
    }
    cout << ')' << endl;
}
