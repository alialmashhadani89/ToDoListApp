/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Homework hpp file
 ***************************************************************/
#ifndef HomeWorkTask_hpp
#define HomeWorkTask_hpp

// include the generic taks file
#include "GenericTask.hpp"
#include <stdio.h>

// the homework task file
class HomeworkTask : public GenericTask{
    // the private data members
private:
    std::string subject;
    
    // the public data members
public:
    
    // the constructor
    HomeworkTask(int month, int day, int year, const std::string &description,const std::string &subject);
    
    // the destructor
    ~HomeworkTask();
    
    // getter for the location
    std::string getSubject();
    
    // to string
    std::string toString();
    
    // to string details
    std::string toStringDetails();
    
    // GET type
    char getType() { return 'H'; }
    
};
#endif /* HomeWorkTask_hpp */

