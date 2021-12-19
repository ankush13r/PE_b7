/** @file   User.hh
    @brief  Contains class User.
    @author Ankush Rana
 */

#ifndef USER_HH
#define USER_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
#endif // NO_DIAGRAM


/** @class  User
    @brief  This class contains all information related to his courses.
    @author Ankush Rana
*/
class User{
private:
    /* data */

    /** @brief Id of course of user, 0 if user is not subscribed>*/
    int course_id;

    /** @brief Number of problems tried to resolve>*/
    int n_probs_tried;

    /** @brief Number of times sent all problems>*/
    int n_sent;

    /** @brief List of ids of courses, where user has been subscribed>*/
    set<int> all_courses;
    
    /** @brief Diccionary of problems solved, key as id(name) of problem and value as number of times tried to solve.>*/
    map<string, int> solved_probs;

    /** @brief Diccionary of problems sendable for user, those satisfy the prerequisit,
     * Key of diccionary as id(name) of problem and value as number of times tried to solve.>*/
    map<string, int> sendable_probs;

public:
 //Constructers

    /** @brief  Default constructor.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Result is an empty object of User.
    */
    User();


// Modifiers

    /** @brief  Subscribe user to the cource "c".
     *
     *  \pre    "c" exists in Evaluator and user is subscribeable to "c".
     *  \post   User is subscribed to "c".
     *  @see    is_subscribable(int c) const;.
    */
    void set_course_id(int c);

    /** @brief  Add "p" to the sendable problems.
     *
     *  \pre    "p" satisfy with the prerequisit to be sendable.
     *  \post   if "p" not exist in sendable problems, then it is added.
     *  Otherwise, nothing modified.  
    */
    void add_sendable(const string& p);

    /** @brief  Update user depending on the problem and it's result.
     *
     *  \pre "p" exists and belongs to the sendable problems of User.
     *  > \- User is subscribed to the course that contains "p".<br>
     *  \post Number of problems sent by user increments.
     *  > \- If problem is sent first time, number of attempts.
     *  > \- If "r" is true, then "p" is moved to solved problems.
    */
    void update_on_send(const string& p, bool r);

// Consultor.

    /** @brief  Get the identifier of course subscribed by user.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Resutl is id of course subscribed by user. 
     *  If user is not subscribed to any course, then resutl is 0.
    */
    int get_course_id() const;

   /** @brief  Get the number of problems sendable.
     *
     *  \pre    <em>TRUE</em>
     *  \post   Result is number of problems sendable.
    */
    int n_sendable() const;

   /** @brief  Check if a "p"is solved
     *
     *  \pre    <em>TRUE</em>
     *  \post   Result is true, if "p" is solved, otherwise false.
    */
    bool is_solved(const string& p) const;
   
    /** @brief  Check if user is subscribable.
     *
     *  \pre    <em>TRUE</em>
     *  \post   Result is true, user does not have any pending sendable problem.
     */
    bool is_subscribable() const;

// Read & Write

    /** @brief  Wrtie the user to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Attribuits of User is witten to the standard output:
     *  Number of times problems sent, solved, tried to solve, 
     *  and identifier of course subscribed by user or 0 if not subscribed. 
    */
    void write() const;

    /** @brief  Write all solved problems to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  All solved problems and number of attempts of each problem 
     *  are written to the standard output.
    */
    void write_solved_probs() const;

    /** @brief  Write all sendable problems to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  If user is subscribed to a course, sendable problems and
     *  number of attempts of each problem written to the standard output.
     *  Otherwise, write an error message.
    */
    void write_sendable_probs() const;

};

#endif // !USER_HH
