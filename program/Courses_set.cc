/** @file  Courses_set.cc
    @brief  This file contains implementation of class Courses_set.hh.
    @author Ankush Rana
*/

#include "Courses_set.hh"
#include "Sessions_set.hh"

Courses_set::Courses_set() {}

// Private modifier
void Courses_set::read_session(const Sessions_set& sessions, Course& crs){
    unsigned int n;
    cin >> n;
    for(;0 < n; --n){
        string s;
        cin >> s;
        crs.add_session(s);
        sessions.find(s).problems_to_course(crs, s);
    }
}

// Modifiers

void Courses_set::increment_completed(unsigned int c){
    return courses[c - 1].increment_completed();
}

unsigned int Courses_set::increment_current_user(unsigned int c){
    return courses[c - 1].increment_current_user();
}

void Courses_set::reduce_current_user(unsigned int c){
    courses[c - 1].reduce_current_user();
}

unsigned int Courses_set::new_course(const Sessions_set& sessions){
    Course crs(courses.size() + 1);
    unsigned int n, n_probs = 0;
    cin >> n;
    string s;
    while(n_probs == crs.n_problems() and 0 < n){
        cin >> s;
        // Adding session to the course "crs"
        crs.add_session(s);
        const Session& sess = sessions.find(s);
        // Adding pair of problems from session sess, "s" to "crs".
        sess.problems_to_course(crs, s);
        // n_probs are total number of problems from sessions "s" read from standard input.
        n_probs += sess.n_problems();
        --n;
    }
 
    for(; 0 < n; --n) cin >> s;

    // If pair of (problems, sessions) added to crs is equal to "n_probs" total problems.
    // Then it will add crs to courses, because they has not any intersection between problems.
    if (n_probs == crs.n_problems()){
        courses.push_back(crs);
        return courses.size();
    }
    return 0;
}

// Consultors

bool Courses_set::exist(unsigned int c) const{
    return 0 < c and c <= courses.size();
}

const Course& Courses_set::find(unsigned int c) const{
    return courses[c - 1];
}

// Read & Write

void Courses_set::read(const Sessions_set& sessions){
    unsigned int n_crs;
    cin >> n_crs;
    courses = vector<Course>();
    for(unsigned int i = 0; i < n_crs; ++i){
        courses.push_back(Course(i + 1));
        // Read sessions and add to last course inserted to the courses.
        read_session(sessions, courses.back());
    }
}

void Courses_set::write() const{
    for(unsigned int i = 0; i < courses.size(); ++i){
        courses[i].write();
    }
}

void Courses_set::write(unsigned int c) const{
    if(exist(c)) courses[c - 1].write();
    else cout << "error: el curso no existe" << endl;
}