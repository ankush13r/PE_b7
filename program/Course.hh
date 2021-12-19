/** @file  Course.hh
    @brief  Contains class Course.
    @author Ankush Rana
*/

#ifndef COURSE_HH
#define COURSE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#endif // NO_DIAGRAM


/** @class  Course 
    @brief  This class contains informations of a course.  
    @author Ankush Rana
*/
class Course{
private:
    /*data*/
    /** @brief Identifier of the course*/    
    unsigned int id;                         
    
    /** @brief Number of users subscirbed to the course */     
    unsigned int current_users;             
    
    /** @brief Number of users, those completed the course */     
    unsigned int completed_users;
    
    /** @brief Vector of ids of sessions*/    
    vector<string> v_sessions;

    /** @brief map of problem, session. Id of problem as key and session as value*/
    map<string, string> problems_session;   

public:
// Constructors

    /** @brief  Default constructor.
     *  
     *  \pre   <em>TRUE</em>
     *  \post   Result is an empty object of Course 
    */
    Course();

    /** @brief  Constructor with identifier.
     *  
     *  \pre   <em>TRUE</em>
     *  \post   Result is a object of Course with ID = id; 
    */
    Course(unsigned int id);

// Modifiers

    /** @brief  Increment the number of users completed the course.
     *          
     *  \pre   <em>TRUE</em>
     *  \post   Number of users completed the course is incremented.
    */
    void increment_completed();

    /** @brief  Increment the number of current users subscribed to the course.
     *          
     *  \pre    <em>TRUE</em>
     *  \post   Number of current users subscribed to the course is incremented
    */
    unsigned int increment_current_user();

    /** @brief  Reduce the number of users subscribed to the course.
     *  
     * \pre     <em>TRUE</em>
     *  \post   The number of users subscribed to the course is reduced.
    */
    void reduce_current_user();
    
    /** @brief  Add pair of problem, session to the course.
     *  
     * \pre     <em>TRUE</em>
     *  \post   Pair of problem, session is added.
    */
    void add_session_problema(const string& p, const string& s);

    /** @brief  Add sesson "s" to the course.
     *  
     * \pre     <em>TRUE</em>
     *  \post   "s" is added to the list of sessions of the course.
    */
    void add_session(const string& s);

// Consultors

    /** @brief  Get the number of problems of course.
     *  
     * \pre     <em>TRUE</em>
     *  \post   Result is the total number of problems.
    */
    unsigned int n_problems() const;

    /** @brief  Get number of user subscribed to the course.
     *          
     *  \pre   <em>TRUE</em>
     *  \post   Result is the number of users subscribed to the course.
    */
    unsigned int n_subscribed() const;

    /** @brief  Get identifier of session "i".
     *          
     *  \pre    0 < i < numero sessiones
     *  \post   Result id of session "i".
    */
    const string& session_id(unsigned int i) const;

    /** @brief  Get size of sessions.
     *          
     *  \pre    <em>TRUE</em>
     *  \post   Result is number of sessions.
    */
    unsigned int n_sessions() const;

    /** @brief  Get the id of course.
     *  
     * \pre     <em>TRUE</em>
     *  \post   Result is the id of course.
    */
    unsigned int get_id() const;

    /** @brief  Get the session of problems "p".
     *  
     * \pre     <em>TRUE</em>
     * \post   If problems exist, the result is pair of  (true, id of session).
     * Otherwise, the result is pair of (false, "").
    */
    pair<bool, string> session_problem(const string& p) const;
 
// Read & Write

    /** @brief  Wrtie the course to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  Course is written to the standard output as follows:<br>
     *  > \- Identifier of course.<br>
     *  > \- Number of users, those completed the course.<br>
     *  > \- Number of users currently subscribed.<br>
     *  > \- Number and sequence of identifiers of sessions.
    */
    void write() const;
};

#endif

