/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Task Container hpp for the cpp.
 ***************************************************************/
#ifndef TasksContainer_hpp
#define TasksContainer_hpp

#include <stdio.h>
#include <fstream>

// include the tasks
#include "GenericTask.hpp"
#include "HomeWorkTask.hpp"
#include "Event.hpp"
#include "ShoppingTask.hpp"


// the node class
struct TaskNode{
    // the task
    GenericTask * task;

    // the ppinter to next
    TaskNode * next;
};

// the class to store the list
class TasksContainer{
    // the private data members
private:
    // the size of the list
    int size;

    // the head pointer to the list
    TaskNode * head;

	// to reset the ids
	void resetID();

    // the public members
public:
    // the constructor
    TasksContainer();
    
    // the constructor
    ~TasksContainer();

    // to add a task
    void addTask(GenericTask * newTask);

    // remove task
    bool removeTask(int id);

    // print tasks
    void printTasks(bool details);
    
    // print completed tasks
    void printCompletedTasks();
    
    // is empty
    bool isEmpty();
    
    // complete this task
    bool completeTask(int id);
    
    // print to file
    void printToFile(std::ofstream & output);
};

#endif /* TasksContainer_hpp */

