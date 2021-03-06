/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: To do list App header.
 ***************************************************************/
#ifndef TODOLISTAPP_H
#define TODOLISTAPP_H

#include <iostream>
#include "ToDoListDriver.h"


// ToDoList Application Class - This class will handle the commands entered from the
// user. It is initialized with an input/output stream, which is by default cout/cin. 

// Any functions implemented should make use of out/in instead of cout/cin directly.
class ToDoListApp {
public:
	void run();
	
	ToDoListApp(std::istream& in = std::cin, 
				std::ostream& out = std::cout) : 
				in(in), out(out) {}
protected:
	
	enum TaskType { SHOPPING = 'S', EVENT = 'E', HOMEWORK = 'H', GENERIC = 'G' };

	// You will implement all of the following functions
	void executeCommandPrint(bool completed = false, bool detailed = false);

	void executeCommandAddTask();
	void executeCommandRemoveTask();
	void executeCommandCompleteTask();
	
	void executeCommandSave();
	void executeCommandLoad();

private:
	// Remember: you may add additional member variables
	std::istream& in = std::cin;
	std::ostream& out = std::cout;
	
};

#endif 
