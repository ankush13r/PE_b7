/** @file   Users_set.hh
    @brief  Contain class Users_set.
    @author Ankush Rana
 */

#ifndef USERS_SET_HH
#define USERS_SET_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif // NO_DIAGRAM

#include "User.hh"
class Courses_set;
class Course;
class Sessions_set;

/** @class  Users_set
    @brief  This class contains list of different objects of type User, unique and shorted.
    @author Ankush Rana
*/
class Users_set{
private:
// Data
    
    /** @brief Dictionary of the users with key as id and value as User*/
    map<string, User> users_set;

public:
 //Constructer & destructor
 
    /** @brief  Default constructor.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Create a empty object of User_set;
    */
    Users_set();

//  Modifiers

    /** @brief  Add new user to the set.
     *
     *  \pre   <em>TRUE</em>
     *  \post   If user doesn't exist it will add to set and result is true.
     *  Otherwise, reuslt is false
    */
    bool add(const string& u);

    /** @brief  Remove user "u".
     *
     *  \pre   <em>TRUE</em>
     *  \post   If "u" exists, will be removed from the set and result is the id of course or 0 if he wasn't subscribed to any course.
     *   If user doesn't exist, result is -1.
    */
    int remove(const string& u);

    /** @brief  Subscribe "u" to the course "c".
     *
     *  \pre    "crs" exists, sesion of "crs" belogns to sessions.
     *  \post   if "u" exist and is subscribable, then "u" is subscribed to "c" and sendable problems are updated.
     *  And result is  {true, number of sendable problems} of type pair<bool, int>.
     *  Otherwise, prints an error message and result is {false, 0} of type pair<bool, int>.
     * @see    is_subscribable(const string& u, int c) const;
    */
    pair<bool, int> subscribe_course(const string& u, const Course& crs, const Sessions_set& sessions);

    /** @brief  Update User "u", when "u" sends a problem with correct answer.
     *  \pre "u" and "p" exist.
     *  > \- "u" is subscribed to a course that contains "p" and belongs to "courses".<br>
     *  > \- "sessions" is the repostitory of session where to find sessions of course subscribed by "u".<br>
     *  > \- "p" belongs to the sendable problems of "u" (satisfy prerequisit of "p").
     *
     *  \post  Statistics of "u" are updated. "p" is moved from sendable problems to solved of "u".
     *  "crs_id" is the id of course subscribed by "u".
     *  If "u" finish with all sendable problems, then "u" is subscribed from the course and result is true.
     *  Otherwise, the result is false.
    */
    void update_on_send(const string& u, const string& p);

    /** @brief  Update User "u", when "u" sends a problem with worng answer.
     *  \pre "u" and "p" exist.
     *  > \- "u" is subscribed to a course that contains "p".
     *  > \- "p" belongs to the sendable problems of "u" (satisfy prerequisit of "p").
     *  \post  Statistics of "u" are updated.
    */
    bool update_on_send(const string& u, const string& p, const Sessions_set& sessions, const Courses_set& courses, unsigned int& crs_id);


// Consulters

    /** @brief  Get number of users.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Result is the number of users.  
    */
    int n_users() const;

    /** @brief  Check if user "u" exist.
     *
     *  \pre   <em>TRUE</em>
     *  \post  If "u" exists, result is true.
     *  Otherwise, result is false.
    */
    bool exist(const string& u) const;

    /** @brief  Get user "u".
     *
     *  \pre   "u" exists.
     *  \post  Result is a const reference of user "u".  
    */
    const User& find(const string& u) const;

// Read & Write

    /** @brief Read a sequence of N user from standard input.
     *  \pre   Number of courses N > 0.
     *  \post  N users are read from the standard input.
    */
    void read();

    /** @brief  Write all users to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All users are written to the standard output, in ascending order by "name".
     *
    */
    void write() const;

    /** @brief  Write user "u" to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   if "u" exists, attributs of "u" are witten to the standard output:
     *  His name(identifier), number of problems sent, solved and tried to solve, and identifier of course subscribed by user. 
     *  <br> Otherwise, an error message.
    */
    void write(const string& u);

    /** @brief  Write sendable problems of "u" to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  If "u" exist and is subscribed to a course, sendable problems of "u" are written to the standard output,
     *  in ascending by problem's id.
     *  Otherwise, an error message is written to the standard output.
     *
    */
    void write_sendable_probs(const string& u);

    /** @brief  Write solved problems by "u" to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  If "u" exist solved problems of "u" are written to the standard output,
     *  in ascending by problem's id.
     *  Otherwise, an error message is written to the standard output.
     *
    */
    void write_solved_probs(const string& u);
};

#endif // !USERS_SET_HH
