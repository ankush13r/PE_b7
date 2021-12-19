/** @file  Problems_set.hh
    @brief  Contains class Problems_set.
    @author Ankush Rana
*/

#ifndef PROBLEMS_SET_HH
#define PROBLEMS_SET_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#endif // NO_DIAGRAM

#include "Problem.hh"

/** @class  Problems_set 
    @brief  This class contains a collection of objects type Problem.
    @author Ankush Rana
*/
class Problems_set{
private:
    /* data */
    /** @brief Map of problems, with key has id, and value as Problem*/
    map<string, Problem> probs_set;  

public:
//Constructers

    /** @brief  Default constructor.
     *  
     *  \pre   <em>TRUE</em>
     *  \post   Result is a empty object of type Col_problemes.
    */
    Problems_set();

// Modifiers

    /** @brief  Add new problem to the probs_set.
     *          
     *  \pre    <em>TRUE</em>
     *  \post   If "p" doesn't exist, p is added and result is true. 
     *          Otherwise, result is false, and nothing modified.
    */
    bool add(const string& p);

    /** @brief  Update statistics of problem "p".
     *
     *  \pre    "p" exists
     *  \post   Update statistics of "p", depending on if "r" is true or false.
    */
    void update_on_send(const string& p, bool r); 

// Consultors

    /** @brief  Check if the problem "p" exist in the collection.
     *          
     *  \pre   <em>TRUE</em>
     *  \post  If "p" exists, result is true.
     *  Otherwise, result is false.
    */
    bool exist(const string& p) const;

    /** @brief Get the number of problems.
     *          
     *  \pre   <em>TRUE</em>
     *  \post  Result is the number of problems
    */
    int n_problems() const;

// Read & Write

    /** @brief  Read N problems from standard input and add to the implicit variable problems_set.
     *          
     *  \pre   Number of problems P > 0 and each element of sequence is unique.
     *  \post  It contains N problems with ids read from standard input.
    */
    void read();

    /** @brief  Write all problems to the standard output.
     *          
     *  \pre   <em>TRUE</em>
     *  \post   All problems are written to the standard output, each problem as follows:<br>
     *  > \-  Total number of times sent "t".<br>
     *  > \-  Number of times was correct "e".<br>
     *  > \-  ratio(t+1)/(e+1).
     *  Problems are written in ascending order by "ratio", if ratios tie, asceinding order by name(identifier).
    */
    void write() const;

    /** @brief  Write the problem with NAME = name to the standard output.
     *          
     *  \pre   <em>TRUE</em>
     *  \post  If "p" exists, "p" is written to the standard output in format:
     *  > \- Total number of times sent "t". <br>
     *  > \- Number of times was correct "e". <br>
     *  > \- ratio(t+1)/(e+1). <br>
     *  Otherwise, an error message.
    */
    void write(const string& name) const;
};

#endif
