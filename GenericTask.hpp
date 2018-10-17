/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The generic task hpp for the cpp file..
 ***************************************************************/
#ifndef GenericTask_hpp
#define GenericTask_hpp

// include the date class
#include "Date.hpp"
#include <string>

// the generic task class
class GenericTask{
    
    // the public data members
public:
    // the default constructor
    GenericTask();
    
    // the constructor
    GenericTask(int day,int month,int year, const std::string &descrption);
    
    // the destructor
    ~GenericTask();
    
    // the method to get the description
    std::string getDescription();
    
    // method to get the deadline
    Date getDeadline();
    
    // to get the id
    int getID();
    
    // to set id
    void setID(const int &n);
    
    // setter for description and deadline
    void setDescription(const std::string &description);
    void setDeadline(Date date);
    
    
    // the to string method
    virtual std::string toString();
    
    // the to string method
    virtual std::string toStringDetails();
    
    // get and set completed
    bool isCompleted() { return completed; }
    
    // set completed
    void setCompleted() { completed = true;}
    
    // GET type
    virtual char getType() { return 'G'; }
    
private:
    
    // the date
    Date date;
    
    // the descrption
    std::string descrption;
    
    // to store if completed
    bool completed;
};

#endif /* GenericTask_hpp */

