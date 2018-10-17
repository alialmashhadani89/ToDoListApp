/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Event hpp is the header for the cpp file.
 ***************************************************************/

#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>
#include "GenericTask.hpp"
// the clsss event class
class Event : public GenericTask{
    // the private data members
private:
    
    // this class has a time and a location
    std::string eventTime;
    
    // the location
    std::string location;
    
    // the public data members
public:
    
    // the constructor
    Event(int month, int day,int year, const std::string &description, const std::string &time,const std::string &location);
    
    // the destructor
    ~Event();
    
    // getter for the location
    std::string getLocation();
    
    // getter for the time
    std::string getEventTime();
    
    // the to string method
    std::string toString();
    
    // the to string details
    std::string toStringDetails();
    
    char getType() { return 'E'; }
    
};

#endif /* Event_hpp */


