/** @file  Sessions_set.cc
    @brief  This file contains implementation of class Sessions_set.hh.
    @author Ankush Rana
*/

#include "Sessions_set.hh"

Sessions_set::Sessions_set(){}

// Modifiers
bool Sessions_set::add(const string& s){
    pair<map<string, Session>::iterator, bool> res = sessions_set.insert({s, Session()});
    if(res.second) res.first->second.read();
    // fake_read() is a public static function of Session, 
    // that only reads sequence of strings from the input, but doesn't save it.
    else Session::fake_read();
    return res.second;
}

int Sessions_set::n_sessions() const{
    return sessions_set.size();
}

const Session& Sessions_set::find(const string& s) const{
    return sessions_set.find(s)->second;
}

// Read & Write
void Sessions_set::read(){
    int n_sess;
    cin >> n_sess;
    sessions_set =  map<string, Session>();
    for (int i = 0; i < n_sess; ++i){
        string name;
        cin >> name;
        map<string, Session>::iterator it = sessions_set.insert({name, Session()}).first;
        // Reading the sequence of problems. Inserting before read sequence, it not doing copies of much data.
        // So sequece is read directly to the object corresponding, after inserted.
        it->second.read();
    }
}

void Sessions_set::write() const{
    map<string, Session>::const_iterator it = sessions_set.begin();
    while (it != sessions_set.end()){
        cout << it->first;
        it->second.write();
        ++it;
    }
}
 
void Sessions_set::write(const string& s) const{
    map<string, Session>::const_iterator it = sessions_set.find(s);
    if(it != sessions_set.end()){
        cout << it->first;
        it->second.write();
    }
    else cout << "error: la sesion no existe" << endl;
}