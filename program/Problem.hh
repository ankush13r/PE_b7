/** @file   Problem.hh
    @brief  Contain class Problem.
    @author Ankush Rana
 */

#ifndef PROBLEM_HH
#define PROBLEM_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif // NO_DIAGRAM

/** @class  Problem 
    @brief  This class contains all the information of programming problem.
    @author Ankush Rana
*/
class Problem{
private:
    /** @brief The number of times, has been sent the problem */
    int n_sent;
        
    /** @brief The number of times, has been evaluated as correct.*/
    int n_ok;

    /** @brief ratio of the problem, rat = (n_sent+1)/(n_ok+1)*/
    double rat;

public:
// Construntors & Destructors

    /** @brief  Default constructor.
     *  
     *  \pre   <em>TRUE</em>
     *  \post   Result is an empty object of Problem; 
    */
    Problem();

    /** @brief  Compare ratio of p1 and p2.
     *  
     *  \pre   <em>TRUE</em>
     *  \post   If (ratio of p1 < ratio or p2) or 
     *  (both ratios are equel and name of p1 < name of p2), the result is true.
     *  Otherwise, the result is false;
    */
    static bool comp_ratio(const pair<string, Problem>& p1, const pair<string, Problem>& p2);

//Modifiers

    /** @brief  Update statistics of problem.
     *
     *  \pre   <em>TRUE</em>
     *  \post  Statistics of problem are updated. Number of times problem sent is incrementes,
     *  and if r is true, then number of times evaluated correct is incremented. 
    */
    void increment_values(bool r);

//Consultors

    /** @brief  Get the number of times the problem was sent. 
     *  
     *  \pre   <em>TRUE</em>
     *  \post   Result is the number of times the problem was sent.
    */
    int get_n_sent() const;

    /** @brief  Get the number of times the problem is evaluated correct.  
     *  
     *  \pre   <em>TRUE</em>
     *  \post   Result is the number of times the problem is evaluated correct. 
    */
    int get_n_ok() const;



// Read & Write
    /** @brief  Write attributes to standard output. 
     *  
     *  \pre   <em>TRUE</em>
     *  \post   "p" is written to the standard output in format:
     *  > \- Total number of times sent "t".<br>
     *  > \- Number of times was correct "e".<br>
     *  > \- ratio(t+1)/(e+1).<br>
     *  Otherwise, an error message.
    */
    void write() const;

   
};

#endif

