/** @file  Evaluator.cc
    @brief  This file contains implementation of class Evaluator.hh.
    @author Ankush Rana
*/

#include "Evaluator.hh"

Evaluator::Evaluator(){}

// Methods

void Evaluator::read_problems(){
    problems_set.read();
}

void Evaluator::read_sessions(){
    sessions_set.read();
}

void Evaluator::read_courses(){
    courses_set.read(sessions_set);
}

void Evaluator::read_users(){
    users_set.read();
}

void Evaluator::new_problem(const string& p){
    if(problems_set.add(p)) cout << problems_set.n_problems() << endl;
    else cout << "error: el problema ya existe" << endl;
} 

void Evaluator::new_session(const string& s){
    if(sessions_set.add(s)) cout << sessions_set.n_sessions() << endl;
    else cout << "error: la sesion ya existe" << endl;
} 

void Evaluator::new_course(){
    int n = courses_set.new_course(sessions_set);
    if(n != 0) cout << n << endl;
    else cout << "error: curso mal formado" << endl;
}

void Evaluator::register_user(const string& u){
     if(users_set.add(u)) cout << users_set.n_users() << endl;
     else cout << "error: el usuario ya existe" << endl;
} 

void Evaluator::remove_user(const string& u){
    int n = users_set.remove(u);
    if(n == -1) cout << "error: el usuario no existe" << endl;
    else {
        cout << users_set.n_users() << endl;
        if(n > 0) courses_set.reduce_current_user(n);
    }
}

void Evaluator::subscribe_curse(const string& u, int c){
    if(not courses_set.exist(c)){
        if(not users_set.exist(u)) cout << "error: el usuario no existe" << endl;
        else cout << "error: el curso no existe" << endl;
    }
    else{
        const Course& crs = courses_set.find(c);
        pair<bool, int> res = users_set.subscribe_course(u, crs, sessions_set);
        //If res.first is true, it mean user as been subscrib to the course.
        if(res.first){
            int n = courses_set.increment_current_user(crs.get_id());
            // res.second the number of sendable problems of "u".
            // If its equal to 0, it means "c" is completed by "u" and has no more problems to solve in "c".
            if(res.second == 0){
                courses_set.increment_completed(crs.get_id());
                courses_set.reduce_current_user(crs.get_id());
                --n;
            }
            cout << n << endl;
        }
    }
}

void Evaluator::user_course(const string& u){
    if(not users_set.exist(u)) cout << "error: el usuario no existe" << endl;
    else cout << users_set.find(u).get_course_id() << endl;;
} 

void Evaluator::session_problem(int c, const string& p){
    if(not courses_set.exist(c)) cout << "error: el curso no existe" << endl;
    else if(not problems_set.exist(p)) cout << "error: el problema no existe" << endl;
    else{
        pair<bool, string> res = courses_set.find(c).session_problem(p);
        if(res.first) cout << res.second << endl;
        else cout << "error: el problema no pertenece al curso" << endl;
    }
}

void Evaluator::solved_problems(const string& u){
    users_set.write_solved_probs(u);
}

void Evaluator::problems_sendable(const string& u){
    users_set.write_sendable_probs(u);
} 

void Evaluator::send(const string& u, const string& p, bool r){
    problems_set.update_on_send(p, r);
    if(not r) users_set.update_on_send(u, p);
    else{
        unsigned int crs_id;
        if(users_set.update_on_send(u, p, sessions_set, courses_set, crs_id)){
            courses_set.increment_completed(crs_id);
            courses_set.reduce_current_user(crs_id);
        }
    }
}

void Evaluator::list_problems(){
    problems_set.write();
}

void Evaluator::write_problems(const string& p){
    problems_set.write(p);
} 

void Evaluator::list_sessions(){
    sessions_set.write();    
}

void Evaluator::write_session(const string& s){
    sessions_set.write(s);    
} 

void Evaluator::list_courses(){
    courses_set.write();
}

void Evaluator::write_course(int c){
    courses_set.write(c);
}

void Evaluator::list_users(){
    users_set.write();
}

void Evaluator::write_users(const string& u){
    users_set.write(u);
} 
