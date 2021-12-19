/** @file   Sessions_set.hh
    @brief  Contains class Sessions_set.
    @author Ankush Rana
*/

#ifndef SESSIONS_SET_HH
#define SESSIONS_SET_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif // NO_DIAGRAM

#include "Session.hh"


/** @class  Sessions_set
    @brief  This class contains Repository of objects of type Session.
    @author Ankush Rana
*/
class Sessions_set{
private:
// Data
    /** @brief Map of tpye Session, contains as sessions as values and keys as name */
    map<string, Session> sessions_set;

public:
 //Constructer & destructor

    /** @brief  Default constructor.
     *
     *  \pre   <em>TRUE</em>
     *  \post   Result is a empty object of Sessions_set;
    */
    Sessions_set();

// Modifiers

    /** @brief  Add new session to the sessions_set.
     *
     *  \pre   <em>TRUE</em>
     *  \post   If "s" exist, is added to the list and result is true.
     *  Otherwise, result is false, and nothing modified.
    */
    bool add(const string& s);

// Consultors

  /** @brief    Get the number of total sessions.
     *
     *  \pre   <em>TRUE</em>
     *  \post  Result is the number of sessions
    */
    int n_sessions() const;

    /** @brief  Get session form set of sessions of parameter implicit.
     *
     *  \pre   s exist.
     *  \post  Result is a const reference of the session "s".
    */
    const Session& find(const string& s) const;

// Read & Write

    /** @brief  Read N Session from standard input and add to the implicit variable sessions_set.
     *
     *  \pre    number N of sessions > 0
     *  \post   Read the number N identifiers of sessions and a sequence of name of problems, in format bintree.
    */
    void read();

    /** @brief  Write all session to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post   All sesions are written to the standard output in ascending order of name(id).
    */
    void write() const;

    /** @brief  Write a session "s" to the standard output.
     *
     *  \pre   <em>TRUE</em>
     *  \post  if "s" exists, session "s" is written to the standard output.<br>
     *  Otherwise, an error message.
    */
    void write(const string& name) const;

};


#endif
