/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Homework will take the homework task and store it here.
 ***************************************************************/
#include "HomeWorkTask.hpp"
using namespace std;

// the constructor
HomeworkTask::HomeworkTask(int month, int day, int year, const std::string &description,const std::string &subject) :
GenericTask(month,day,year,description)
{
    // set the subject
    this->subject = subject;
}

// the destructor
HomeworkTask::~HomeworkTask(){
    // nothing to do here
}

// getter for the location
string HomeworkTask::getSubject(){
    // return the subect
    return  subject;
}

// to string
string HomeworkTask::toString(){
    return (getDeadline().toString() + " - [Homework] " + getDescription());
}

// to string details
string HomeworkTask::toStringDetails(){
    // the to string details
    return toString() + "\n" +
    "   Subject: " + "\n" +
    "   " + subject + "\n";
}
