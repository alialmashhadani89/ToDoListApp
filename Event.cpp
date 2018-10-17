/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Event cpp will take event and store them here.
 ***************************************************************/

#include "Event.hpp"
using namespace std;

// the constructor
Event::Event(int month, int day,int year, const std::string &description, const std::string &time,const std::string &location)  : GenericTask(month,day,year,description){
    // the event time
    this->eventTime = eventTime;
    this->location = location;
}

// the destructor
Event::~Event(){
    // delete this event
}

// getter for the location
string Event::getLocation(){
    // return the location
    return location;
}

// getter for the time
string Event::getEventTime(){
    // return the event time
    return eventTime;
}

// to string
string Event::toString(){
    return (getDeadline().toString() + " - [Event] " + getDescription());
}

// to string details
string Event::toStringDetails(){
    return toString() + "\n"+
    "   Location: " + "\n"+
    "   " + location + "\n" +
    "   Time: " + "\n" +
    "   " + eventTime + "\n";
}
