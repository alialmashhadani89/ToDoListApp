/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The shopping task hpp.
 ***************************************************************/
#ifndef ShoppingTask_hpp
#define ShoppingTask_hpp

// include the generic task class
#include "GenericTask.hpp"
#include <stdio.h>

// the class that represents shopping task
class ShoppingTask : public GenericTask{
    // this has a separate list of items to shop for
private:
    
    // the list of items
    std::string * items;
    
    // the number of items
    int numItems;
    
// the public data members
public:
    
    // the constructor
    // takes the date,description and list details
    ShoppingTask(int month,  int day,int year,const std::string &description, std::string itemList[], int numItems);
    
    // to get the list of items
    std::string * getItems(int & numItems);
    
    // the to string method
    std::string toString();
    
    // the to string details
    std::string toStringDetails();
    
    char getType() { return 'S'; }

};
#endif /* ShoppingTask_hpp */

