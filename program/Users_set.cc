/** @file  Users_set.cc
    @brief  This file contains implementation of class Users_set.hh.
    @author Ankush Rana
*/

#include "Users_set.hh"
#include "Courses_set.hh"
#include "Sessions_set.hh"
// Constructors

Users_set::Users_set(){}

bool Users_set::add(const string& u){
    return users_set.insert({u, User()}).second;
}

int Users_set::remove(const string& u){
    map<string, User>::iterator it = users_set.find(u);
    if(it != users_set.end()){
        int c = it->second.get_course_id();
        users_set.erase(it);
        it = users_set.end();
        return c;
    }
    return -1;
}

pair<bool, int> Users_set::subscribe_course(const string& u, const Course& crs, const Sessions_set& sessions){
    map<string, User>::iterator it = users_set.find(u);
    if(it == users_set.end()) cout << "error: el usuario no existe" << endl;
    else if(not it->second.is_subscribable()) cout << "error: usuario inscrito en otro curso" << endl;
    else{
        // Updating sendable problems of user from sesions of course "c".
        for(unsigned int i = 1; i <= crs.n_sessions(); ++i){
            sessions.find(crs.session_id(i)).update_sendable(it->second);
        }
        // Number of sendable problems after updated
        unsigned int num_sendable = it->second.n_sendable();
        // If number  of sendable problems is not 0, then set the course id to user.
        if(num_sendable != 0) it->second.set_course_id(crs.get_id());
        return {true, num_sendable};
    }
    return {false, 0};
}

bool Users_set::update_on_send(const string& u, const string& p, const Sessions_set& sessions, 
                               const Courses_set& courses, unsigned int& crs_id)
{
    map<string, User>::iterator it = users_set.find(u);
    
    //Update user's statistics and move sendable problem to solve.
    it->second.update_on_send(p, true);
    crs_id = it->second.get_course_id();
    string sess_id = courses.find(crs_id).session_problem(p).second;
    sessions.find(sess_id).update_sendable(it->second, p);
    
    //If user has not any more sendabel problem, then unsubscribe the user.
    // And return true.
    if(it->second.n_sendable() == 0){
        it->second.set_course_id(0);
        return true;
    }
    return false;
}

void Users_set::update_on_send(const string& u, const string& p){
    map<string, User>::iterator it = users_set.find(u);
    it->second.update_on_send(p, false);
}

// Consulters
int Users_set::n_users() const{
    return users_set.size();
}

bool Users_set::exist(const string& u) const{
    map<string, User>::const_iterator it = users_set.find(u);
    return it != users_set.end();
}

const User& Users_set::find(const string& u) const{
    return users_set.find(u)->second;
}

// Read & Write
void Users_set::read(){
    int n_usr;
    cin >> n_usr;
    string name;
    users_set = map<string, User>();
    for(int i = 0; i < n_usr; ++i){
        cin >> name;
        users_set.insert({name, User()});
    }
}

void Users_set::write() const{
    for(map<string, User>::const_iterator it = users_set.begin(); it != users_set.end(); ++it){
        cout << it->first;
        it->second.write();
    }
}

void Users_set::write(const string& u){
    // map<string, User>::const_iterator it = users_set.find(u);
    map<string, User>::iterator it = users_set.find(u);
    if(it != users_set.end()){
        cout << it->first;
        it->second.write();
    }
    else cout << "error: el usuario no existe" << endl;
}

void Users_set::write_solved_probs(const string& u){
    map<string, User>::iterator it = users_set.find(u);
    if(it != users_set.end()){
        it->second.write_solved_probs();
    }
    else cout << "error: el usuario no existe" << endl;
}


void Users_set::write_sendable_probs(const string& u){
    map<string, User>::iterator it = users_set.find(u);
    if(it != users_set.end() and not it->second.is_subscribable()){
        it->second.write_sendable_probs();
    }
    else if(it != users_set.end()) cout << "error: usuario no inscrito en ningun curso" << endl;
    else cout << "error: el usuario no existe" << endl;
}
