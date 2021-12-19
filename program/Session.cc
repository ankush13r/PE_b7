/** @file  Session.cc
    @brief  This file contains implementation of class Session.hh.
    @author Ankush Rana
*/

#include "Session.hh"
#include "User.hh"
#include "Course.hh"

Session::Session() {
    n_probs = 0;
}

// Private Statics

void Session::read_BinTree(BinTree<string>& tree, int& n){
    string value;
    cin >> value;
    if(value != "0"){
        ++n;
        BinTree<string> l, r;
        read_BinTree(l, n);
        read_BinTree(r, n);
        tree = BinTree<string>(value, l, r);
    }
}

void Session::write_BinTree(const BinTree<string>& tree){
    if (not tree.empty()){
        cout << '(';
        write_BinTree(tree.left());
        write_BinTree(tree.right());
        cout << tree.value() << ')';
    }
}

void Session::iupdate_sendable(User& user, const BinTree<string>& tree){
    if(not tree.empty()){
        if(not user.is_solved(tree.value())){
            user.add_sendable(tree.value());
        }
        else {
            iupdate_sendable(user, tree.left());
            iupdate_sendable(user, tree.right());
        }
    }
}

void Session::get_subtree(const BinTree<string>& tree, BinTree<string>& subtree, const string& p){
    if(not tree.empty()){
        if(tree.value() == p) subtree = tree;
        else{
            get_subtree(tree.left(), subtree, p);
            get_subtree(tree.right(), subtree, p);
        }
    }
}

void Session::iproblems_to_course(const BinTree<string>& tree, Course& crs, const string& s){
    if(not tree.empty()){
        crs.add_session_problema(tree.value(), s);
        iproblems_to_course(tree.left(), crs, s);
        iproblems_to_course(tree.right(), crs, s);
    }
}

void Session::fake_read(){
    string value;
    cin >> value;
    if(value != "0"){
        fake_read();
        fake_read();
    }
}

// Consulters
int Session::n_problems() const{
    return n_probs;
}

void Session::problems_to_course(Course& crs, const string& s) const{
    iproblems_to_course(problems_structure, crs, s);
}

void Session::update_sendable(User& user) const{
    iupdate_sendable(user, problems_structure);
}

//Overload function with more parameter "p". It's faster then other one,
// because it will ignore all problems before "p"
void Session::update_sendable(User& user, const string& p) const{
    BinTree<string> tree;
    get_subtree(problems_structure, tree, p);
    if(not tree.empty()) {
        iupdate_sendable(user, tree.left());
        iupdate_sendable(user, tree.right());
    }
}

// Read & Write
void Session::read(){
    n_probs = 0;
    problems_structure = BinTree<string>();
    read_BinTree(problems_structure, n_probs);
}

void Session::write() const{
    cout << ' ' << n_probs << ' ';
    write_BinTree(problems_structure);
    cout << endl;
}
