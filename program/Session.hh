/** @file   Session.hh
    @brief  Contains class Session.
    @author Ankush Rana
 */

#ifndef SESSION_HH
#define SESSION_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include "map"
#include "BinTree.hh"
using namespace std;
#endif // NO_DIAGRAM

class User;
class Course;

/** @class  Session
    @brief  This class contains a binTree of some different problems and infromtaion about a session.
    @author Ankush Rana
*/
class Session{
private:
    /*data*/
    /** @brief Number of problems */
    int n_probs;

    /** @brief BinTree of ids of problems, in pre order*/
    BinTree<string> problems_structure;

    /** @brief  Recurcive function to read sequence of problmes is format BinTree in pre order.
     *
     *  \pre    <em>TRUE</em>
     *  \post   "tree" has sequence of problems is read from the standard output.
     *          And "n" = "n" + number of problems read.
    */
    static void read_BinTree(BinTree<string>& tree, int& n);

    /** @brief  Write a binTree of strings to the standerd output, in post order.
     *
     *  \pre   <em>TRUE</em>
     *  \post   "tree" is written to the standard output in postorder.
    */
    static void write_BinTree(const BinTree<string>& tree);

    /** @brief  Add sendable problems to "user", recursively.
     *
     *  \pre   "user" must have methods: add_sendable() to add problems,
     *  and is_solved(string) to check if a problem is solved 
     *  \post  New sendable problems are add to the list of sendable problems of user.
    */
    static void iupdate_sendable(User& user, const BinTree<string>& tree);

    /** @brief  Get subtree of "tree" from "p", recursively.
     *
     *  \pre   <em>True</em>
     *  \post  If "p" exist in "tree", then "subtree" is "tree" from problem "p".
     *  Otherwise, "subtree" is not modified.
    */
   static void get_subtree(const BinTree<string>& tree, BinTree<string>& subtree, const string& p);
 
    /** @brief  Add all problems with "s" to course "crs", recursively.
     *
     *  \pre   "crs" must have methods: add_session_problema(string, string) to add problems with "s".
     *  \post  Problems with "s" are added to the crs.
    */
    static void iproblems_to_course(const BinTree<string>& tree, Course& crs, const string& s);

public:
// Constructors

    /** @brief  Default constructor.
     *
     *  \pre   <em>TRUE</em>
     *  \post  Result is an empty object of Session;
    */
    Session();

    /** @brief  Read sequence of strings of format bintree, without saving them.
     *
     *  \pre   <em>TRUE</em>
     *  \post  Sequence of string of format bintree are read from the standerd output, but nothing modified.
    */
    static void fake_read();

// Consulters

    /** @brief  Get the number of problems.
     *
     *  \pre    <em>TRUE</em>
     *  \post   Result is the number of problems.
    */
    int n_problems() const;

    /** @brief  Add all problems with "s" to the course "crs".
     *
     *  \pre   "crs" must have methods: add_session_problema(string, string) to add problems with "s".
     *  \post  Problems with "s" are added to the crs.
    */
    void problems_to_course(Course& crs, const string& s) const;

    /** @brief  Add sendable problems to "user".
     *
     *  \pre   "user" must have methods: add_sendable() to add problems,
     *  and is_solved(string) to check if a problem is solved 
     *  \post  New sendable problems are added to "u".
    */
    void update_sendable(User& u) const;

    /** @brief  This is a overload function, that requier also a string "p". 
     *  It also add sendable problems to "user", but faster then other one, 
     *  becouse it will search problems from "p", and all before "p" are ignored.
     *
     *  \pre   "user" must have methods: add_sendable() to add problems,
     *  and is_solved(string) to check if a problem is solved 
     *  \post  New sendable problems are added to "u".
    */
    void update_sendable(User& user, const string& p) const;

// Read & Write

    /** @brief  Read a name of Session and a sequence of strings in preorder, of fromat bintree, from the standard input.
     *
     *  \pre    <em>TRUE</em>
     *  \post   Name of session and a secuence of identifiers of problems are read.
    */
    void read();

    /** @brief  Write session to standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Session is written to the standard output:
     *  (id of session, total number of problems, problems in postorder of prerequisit).
    */
    void write() const;
};

#endif
