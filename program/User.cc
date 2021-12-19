/** @file  User.cc
    @brief  This file contains implementation of class User.hh.
    @author Ankush Rana
*/

#include "User.hh"

//Constructers
User::User(){
    course_id = 0;
    n_probs_tried = 0;
    n_sent = 0;
}

// Modifiers
void User::set_course_id(int c){
    course_id = c;
}

void User::add_sendable(const string& p){
    sendable_probs.insert({p, 0}).second;
}

void User::update_on_send(const string& p, bool r){
    map<string, int>::iterator it = sendable_probs.find(p);
    ++n_sent;
    n_probs_tried += (++it->second == 1);

    if(r){
        solved_probs.insert(*it);
        sendable_probs.erase(it);
    }
}

// Consultor.
int User::get_course_id() const{
    return course_id;
}

int User::n_sendable() const{
    return sendable_probs.size();
}

bool User::is_solved(const string& p) const{
    return solved_probs.find(p) != solved_probs.end();
}

bool User::is_subscribable() const{
    return sendable_probs.size() == 0;
}

// Read & Write
void User::write() const{
    cout << '(' << n_sent << ',' << solved_probs.size()  << ',';
    cout << n_probs_tried << ',' <<  course_id << ')' << endl;
}

void User::write_solved_probs() const{
    for(map<string, int>::const_iterator it = solved_probs.begin(); it != solved_probs.end(); ++it){
        cout << it->first << '(' << it->second << ')' << endl;
    }
}

void User::write_sendable_probs() const{
    for(map<string, int>::const_iterator it = sendable_probs.begin(); it !=  sendable_probs.end(); ++it){
        cout << it->first << '(' << it->second << ')' << endl;
    }
}