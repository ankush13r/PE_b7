/** @file  Problem.cc
    @brief  This file contains implementation of class Problem.hh.
    @author Ankush Rana
*/

#include "Problem.hh"

// Construntors & Destructors
Problem::Problem() {
    n_ok = 0;
    n_sent = 0;
    rat = 1;
}

// Public static method
bool Problem::comp_ratio(const pair<string, Problem>& p1, const pair<string, Problem>& p2){
    return (p1.second.rat == p2.second.rat and p1.first < p2.first) or p1.second.rat < p2.second.rat;
}

void Problem::increment_values(bool r){
    ++n_sent;
    n_ok += r;
    rat = (n_sent + 1) / double(n_ok + 1);
}

int Problem::get_n_sent() const{
    return n_sent;
}

int Problem::get_n_ok() const{
    return n_ok;
}

void Problem::write() const{
    cout << '(' << n_sent << ',' << n_ok << ',' << rat << ')' << endl; 
}
