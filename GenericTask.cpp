/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Generic task will take task and store it here.
 ***************************************************************/
#include "GenericTask.hpp"
#include <ctime>
using namespace std;

// the default constructor
GenericTask::GenericTask(){
	// set the date to todays date

	// to get todays date
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	// set the date values to current date
    date.day = now->tm_mday;
    date.month = now->tm_mon + 1;
    date.year = now->tm_year + 1900;
	

    // set description ot ""
    descrption = "";
    
    // completed is false
    completed = false;
}

// the constructor
GenericTask::GenericTask( int day,int month,int year,const std::string &descrption){
    // create new date
    date.day = day;
    date.month = month;
    date.year = year;
	
    
    // set description
    this->descrption = descrption;
    
    
    // completed is false
    completed = false;
}

// the destructor
GenericTask::~GenericTask(){
   
}

// the method to get the description
string GenericTask::getDescription(){
    return descrption;
}

// method to get the deadline
Date GenericTask::getDeadline(){
    return date;
}

string GenericTask::toStringDetails(){
    return toString();
}

string GenericTask::toString(){
    return date.toString() + " - " + descrption;
}

// setter for description and deadline
void GenericTask::setDescription(const std::string &description ){
    this->descrption = description;
}
void GenericTask::setDeadline(Date date){
    // create the new deadline date
    this->date.day = date.day;
    this->date.month = date.month;
    this->date.year = date.year;
}
