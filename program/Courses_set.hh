/** @file  Courses_set.hh
    @brief  Contain class Courses_set.
    @author Ankush Rana
*/

#ifndef COURSES_SET_HH
#define COURSES_SET_HH

#include "Course.hh"
class Sessions_set;

/** @class  Courses_set 
    @brief  This class contains list of different objects of type Course.  
    @author Ankush Rana
*/
class Courses_set{
private:
    /* data */
    /** @brief Vector tyep Course, that contains obejcets of type Courses*/
    vector<Course> courses;  

    /** @brief  Read N ids of sessions from standard input.
     *
     *  \pre   N > 0, ids of sessions belongs to "sessions".
     *  \post  N ids of sessions are read from the standard input and added to "crs".
    */
    void read_session(const Sessions_set& sessions, Course& crs);

public:

  // Constructors

    /** @brief  Default constructor.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Result is a object of Courses_set with n_crs = 0 and courses = [](empty list);
    */
    Courses_set();


// Modifiers

    /** @brief  Increment the number of users completed the course "c".
     *          
     *  \pre    "c" exist.
     *  \post   Number of users completed of "c" is incremented
    */
    void increment_completed(unsigned int c);

    /** @brief  Increment the number of users subscribed to the course "c", currently.
     *          
     *  \pre    "c" exist.
     *  \post   Number of current users subscribed to "c" is incremented
    */
    unsigned int increment_current_user(unsigned int c);

    /** @brief  Reduce the number of users subscribed to  "c".
     *          
     *  \pre    "c" exist.
     *  \post   The number of current users subscribed to "c" is reduced.
    */
    void reduce_current_user(unsigned int c);

    /** @brief  Add a new Course with N sessions.
     *
     *  \pre    N > 0, ids of sessions must belong to "sessions".
     *  \post   If sessions read from standerd input has not any intersection between their problems, then Course with N sessions is added.
     *  If course is added, result is number of total courses after add the new one.
     *  Otherwise, the result is 0.
    */
    unsigned int new_course(const Sessions_set& sessions);

// Consultors

    /** @brief  Check if the course "c" exist.
     *          
     *  \pre   <em>TRUE</em>
     *  \post  If "s" exists, result is true.
     *  Otherwise, result is false.
    */
    bool exist(unsigned int c) const;

    /** @brief  Get number of user subscribed to the course "c".
     *          
     *  \pre    "c" exist.
     *  \post   Result is the number of users subscribed to "c".
    */
    unsigned int n_subscribed_user(unsigned int c) const;

    /** @brief  Get Course "c".
     *          
     *  \pre    c exists.
     *  \post   Result is a const reference of Course "c".
    */
    const Course& find(unsigned int c) const;


// Read & Write

    /** @brief Read a sequence of N courses from standard input.
     *  \pre   Number of courses N > 0, number of sessions Sc > 0 and Sc sessions exist and are valid and unique.
     *  And Sc sessions belongs to "sessions".
     *  \post  Read the number N of courses and read a sequence of N courses, are identified by order they were read.
     *  for each course read numbre of session Sc and read secuence of Sc sessions.
    */
    void read(const Sessions_set& sessions);

    /** @brief  Wrtie all courses to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All courses are written to the standard output in ascending order by it's id.
    */
    void write() const;

    /** @brief  Wrtie a course to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   If course "c" exists, written to the standard output.
     *  Otherwise, an error message.
    */
    void write(unsigned int c) const;
};

#endif
