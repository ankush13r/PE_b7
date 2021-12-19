/** @file  Evaluator.hh
    @brief  Contain class Evaluator.
    @author Ankush Rana
*/
#ifndef EVALUATIR_HH
#define EVALUATIR_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif // NO_DIAGRAM

#include "Problems_set.hh"
#include "Sessions_set.hh"
#include "Courses_set.hh"
#include "Users_set.hh"

/** @class  Evaluator 
    @brief  This class contains objects of Problems_set, Sessions_set, Courses_set and Users_set.  
    @author Ankush Rana
*/
class Evaluator{
private:

    /** @brief Object of class Problems_set*/
    Problems_set problems_set;

    /** @brief Object of class Sessions_set */
    Sessions_set sessions_set;

    /** @brief Object of class Courses_set */
    Courses_set courses_set;

    /** @brief Object of class Users_set */
    Users_set users_set;

public:

  // Constructors

    /** @brief  Default constructor.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Result is a object of Evaluator.
    */
    Evaluator();

    /** @brief Read P problems from standard input.
     *  \pre   Number of problems P > 0 and name of each problem is unique.
     *  \post  Read the number P of problems and read a sequence of N strings(ids of problems).
    */
    void read_problems();

    /** @brief Read S session from standard input.
     *  \pre   Number of session S > 0.
     *  \post  Read the number S of sessions and read a sequence of N sessions,
     *  for each sesson read its name and secuence of ids of problems in preorder of it's structure of prerequisit.
    */
    void read_sessions();

    /** @brief Create N courses reading sequence of it's sessions from standard input.
     *  \pre   Number of courses N > 0, number of sessions Sc > 0 and Sc sessions are valid and unique.
     *  \post  Read the number N of courses and read a sequence of N courses, are identified by order they were read.
     *  for each course read numbre of session Sc and read secuence of Sc sessions.
    */
    void read_courses();

    
    /** @brief Read M user from standard input.
     *  \pre   Number of courses M > 0;
     *  \post  Read the number M of users and read a sequence of M identifiers of users.
    */
    void read_users();


    /** @brief Add new problem to the problems collection.
     *  \pre   <em>TRUE</em>
     *  \post  If "p" doesn't exist, "p" is added to the problems_set.
     *  <br> Otherwise, write an error message to the standard output.
    */
    void new_problem(const string& p); //p

    /** @brief Add new session to the repository of session.
     *  \pre   <em>TRUE</em>
     *  \post  If "p" does not exist, "s" is added to the sessions_set.
     *  <br> Otherwise, write an error message to the standard output.
    */
    void new_session(const string& s); //s

    /** @brief  Add new course to the Course set.
     *  \pre    <em>TRUE</em>
     *  \post   If a new course read from standard input is valid, 
     *          then it is added to the courses_set.<br> 
     *          Otherwise, write an error message to the standard output.
    */
    void new_course();

    /** @brief Add new user to the User set.
     *  \pre   <em>TRUE</em>
     *  \post   If "u" does not exist, "u" is added to the users_set.
     *  <br> Otherwise, write an error message to the standard output.
    */
    void register_user(const string& u); //u

    /** @brief  Remove a user from the User set.
     *  \pre    <em>TRUE</em>
     *  \post   If "u" exists, "u" is removed from the users_set.<br> 
     *          Otherwise, write an error message to the standard output.
    */
    void remove_user(const string& u); //u

    /** @brief  Subscirbe a user to a course.
     *  \pre    <em>TRUE</em>
     *  \post   "u" is subscribed to the "c" and number of users subscribed to "c" is written to the standard output,
     *  if meets all the following conditions: 
     *  > \- "u" and "c" exists.<br>
     *  > \- "u" is not subscribed to any course or has completed his course.<br>
     *  > \- "u" never has been subscribed to "c".<br>
     *  Otherwise, nothing is modified and an error message is written to the standard output.
    */
    void subscribe_curse(const string& u, int c); //u c

    /** @brief  Consult a user's course.
     *  \pre    <em>TRUE</em>
     *  \post   If user "u" exists, his course or 0 (if user has not any course) is written to the standard output.<br> 
     *          Otherwise, an error message.
    */
    void user_course(const string& u); //u

    /** @brief Consult the session of the problem "p" form course "c".
     *  \pre   <em>TRUE</em>
     *  \post  If course "c" and problem "p" esxit and "p" belongs to to "c",
     *          The name of session is written to the standard output.<br> 
     *          Othewise, an error message.
    */
    void session_problem(int c, const string& p); //c p

    /** @brief  List problems solved by user u.
     *  \pre    <em>TRUE</em>
     *  \post   if user exists, "name" and "number of times sent" of all problems solved,
     *          by user "u", are writen to the standard output, in ascending order by id(name).<br> 
     *          Othewise, an error message.
    */
    void  solved_problems(const string& u); //u

    /** @brief  List problems sendable of user u.
     *  \pre    <em>TRUE</em>
     *  \post   if user exists, "name" and "number of times sent" of all problems sendable (satisfy their prerequisit),
     *          of user "u", are writen to the standard output, in ascending order by id(name).<br>
     *          Othewise, an error message.
    */
    void problems_sendable(const string& u); //u

    /** @brief  Send a problem "p" with result "r" by user "u".
     *
     *  \pre    User "u" and problem "p" exist 
     *          - "u" is subscribed to the course that contains "p". 
     *          - "p" belongs to the sendable problems of "u".
     * 
     *  \post   Statistics of "u" and "p" are updated, depending on if r is true of false.
     *  If r is true, "p" is moved from sendable to solved problems of "u" and collection of ç
     *  sendable problems of "u" is updated with new sendable problems if exist.
    */
    void send(const string& u, const string& p, bool r); //u  p  r

    /** @brief  Write all problem from problem collecion.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All problems are written to the standard output, each problem as follows:
     *  > \- Total number of times sent "t".<br>
     *  > \- Number of times was correct "e".<br>
     *  > \- ratio(t+1)/(e+1).<br>
     *  Problem are written in ascending order by "ratio", if ratios tie, asceinding order by id(name).
    */
    void list_problems();

    /** @brief  Write the problem "p" to the standard output.
     *
     *  \pre    <em>TRUE</em>
     *  \post   If "p" exists, "p" is written to the standard output in format:
     *  > \- Total number of times sent "t".<br>
     *  > \- Number of times was correct "e".<br>
     *  > \- ratio(t+1)/(e+1).<br>
     *  Otherwise, an error message.
    */
    void write_problems(const string& p); //p

    /** @brief  Write all session from session's repository.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All problems are written to the standard output in ascending order by id, 
     *  each problem as follows:
     * > \- Number of problems.<br>
     * > \- Id of each problem, in postorder of structure of prerequisit.<br>
    */
    void list_sessions();

    /** @brief  Write a session from session's repository.
     *
     *  \pre   <em>TRUE</em>
     *  \post  If "s" exist, "s" is written to the standard output as follows:
     *  > \- Number of problems.<br>
     *  > \- Id of each problem, in postorder of structure of prerequisit.<br>
     *  Otherwise, an error message.
    */
    void write_session(const string& s); //s

    /** @brief  Write all courses from set courses.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All courses are written to the standard output in ascending order by id, 
     *          each course as follows:
     *  > \- Number of users, those currently subscribed or have completed the course.<br>
     *  > \- Number of users currently subscribed.<br>
     *  > \- Number of session of course.<br>
     *  > \- Id of these sessions, in the same order they were read when the course was created.<br>
    */
    void list_courses();

    /** @brief  Write "c" to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  If "c" exists, is written to the standard output as follows:
     *  > \- Number of users, those currently subscribed or have completed the course.<br>
     *  > \- Number of users currently subscribed.<br>
     *  > \- Number of session of course.<br>
     *  > \- Id of these sessions, in the same order they were read when the course was created.<br>
     *  Otherwise, an error message.
    */
    void write_course(int c); //c
    
    /** @brief  Write all users to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All users are written to the standard output in ascending order by name, 
     *  each user as follows:
     *  > \- Number of times sent all problems.<br>
     *  > \- Number of problems solved.<br>
     *  > \- Number of problems tried to resolve.<br>
     *  > \- Id of course subscirbed by "u". If "u" is not subscribed, then "0".<br>
    */
    void list_users();

    /** @brief  Write the user "u" to the standard ouptut.
     *
     *  \pre   <em>TRUE</em>
     *  \post   if user exists, is written to the standard output as follows:
     *  > \- Number of times sent all problems.<br>
     *  > \- Number of problems solved.<br>
     *  > \- Number of problems tried to resolve.<br>
     *  > \- Id of course subscirbed by "u". If "u" is not subscribed, then "0".<br>
     *  Otherwise, an error message.
    */
    void write_users(const string& u); //u


};



#endif
