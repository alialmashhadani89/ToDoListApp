/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Shopping task will store the task and iteams.
 ***************************************************************/
#include "ShoppingTask.hpp"
using namespace std;

// the constructor
// call the super constructor
ShoppingTask::ShoppingTask(int month,  int day,int year,const std::string &description, std::string itemList[], int numItems) :
GenericTask(month,day,year,description){
    // copy the  number of items
    this->numItems = numItems;
    
    // the list of items to be created
    items = new string[ numItems ];
    
    // copy all the items
    for (int i=0; i<numItems; i++){
        this->items[i] = itemList[i];
    }
}

// to get the list of items
string * ShoppingTask::getItems(int & numItems){
    // create a list of items
    string * itemList = new std::string[this->numItems];
    
    // set the number of items
    numItems = this->numItems;
    
    // copy
    for (int i=0; i<numItems; i++){
        itemList[i] = items[i];
    }
    
    // return item list
    return itemList;
}

// to string
string ShoppingTask::toString(){
    return (getDeadline().toString() + " - [Shopping] " + getDescription());
}

// to string details
string ShoppingTask::toStringDetails(){
    // the to string details
    string str = toString() + "\n" +
    "   Items: " + "\n";
    
    // add all the items
    for(int i=0; i<numItems; i++){
        str = str + "   "+ items[i] + "\n";
    }
    // return the prepared string
    return str;
}
