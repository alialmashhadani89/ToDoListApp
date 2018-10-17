/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The To Do list is control the full app.
 ***************************************************************/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>

#include "ToDoListApp.h"
#include "Date.hpp"

using namespace std;
TasksContainer tasks;
Date check;

void ToDoListApp::run() {

	//NOTE: we are using out/in streams from the class level, not cin/cout
	//      directly. All your functions should do this.
	out << "Welcome to your To-Do List! You may begin to enter commands.";
	out << std::endl;

	std::string command;
	do {
		out << "> ";
		getline(in, command);

		//Convert entire command to uppercase for easy compares
		transform(command.begin(), command.end(), command.begin(), ::toupper);

		if (command == "PRINT") {
			executeCommandPrint();
		} else if (command == "DETAILED") {
			executeCommandPrint(false, true);
		} else if (command == "COMPLETED") {
			executeCommandPrint(true);
		} else if (command == "ADD") {
			executeCommandAddTask();
		} else if (command == "REMOVE") {
			executeCommandRemoveTask();
		} else if (command == "COMPLETE") {
			executeCommandCompleteTask();
		} else if (command == "SAVE") {
			executeCommandSave();
		} else if (command == "LOAD") {
			executeCommandLoad();
		} else if (command == "EXIT") {
			out << "Thank you for using To-Do List!\n";
			break;
		} else {
			out << "Unknown Command (" << command << "). Try Again.\n";
		}
		out << "\n";
	} while (true);
}


void ToDoListApp::executeCommandPrint(bool completed, bool detailed){
    if(completed)
        tasks.printCompletedTasks();
    else
        tasks.printTasks(detailed);
}

void ToDoListApp::executeCommandAddTask(){
    // ask the type of task
    out << "What type of task is this? [G: Generic, S: Shopping, E: Event, H: Homework]" << endl;
    
    // get the type of the task
    string tasktype;
    out <<"> ";
    getline(in, tasktype);
    
    // according to the task type, ask info
    switch (tasktype[0]){
        
        case SHOPPING:
        {
            // case for shopping
            // ask date and description
            out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
            string deadline;
            
            // read deadline
            out<<"> ";
            getline(in, deadline);
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // until valid date
            while( !check.isValidDate(day,month,year)){
                // ask again
                out << "Invalid date."<< std::endl;
                
                // ask again
                out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
                
                // read deadline
                out<<"> ";
                getline(in, deadline);
                
                check.parseDate(deadline, day, month, year);
                
            }
            
            // now, read the description
            out << "How would you describe this task?" << endl;
            std::string description;
            out<<"> ";
            getline(in, description);
    
            // ask the other shopping details
            out << "What items do you need to buy? [Type your item and press ENTER to add another item. Type DONE to complete the list.]" << endl;
            
            std::string item;
            // read items
            
            vector<string> items;
            out<<"> ";
            while(getline(in,item)){
                out<<"> ";
                // if item is done, break
                if( item == "DONE")
                    break;
                // add to vector
                items.push_back(item);
            }
            
            // add
            string * arr = new string[items.size()];
            for(unsigned int i=0; i<items.size(); i++)
                arr[i] = items[i];
            
            // create homework task
            GenericTask * task = new ShoppingTask(month,day,year,description,arr,(int)items.size());
            
            // add this to the list of tasks
            tasks.addTask(task);
            
            // show message
            out << "Tasks saved successfully!" << endl;
            
        }
        break;
          
        case EVENT:
        {
            // ask date and description
            out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
            string deadline;
            
            // read deadline
            out<<"> ";
            getline(in, deadline);
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // until valid date
            while(!check.isValidDate(day,month,year)){
                // ask again
                out << "Invalid date." << endl;
                
                // ask again
                out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
                
                // read deadline
                out<<"> ";
                getline(in, deadline);
                
                check.parseDate(deadline, day, month, year);
                
            }
            
            // now, read the description
            out << "How would you describe this task?" << endl;
            std::string description;
            out<<"> ";
            getline(in, description);
            
            // ask other event details
            // ask location
            out << "Where is this event taking place?" << endl;
            std::string location;
            out<<"> ";
            getline(in, location);
            
            // ask time
            out << "When is this event taking place?" << endl;
            string time;
            out<<"> ";
            getline(in, time);
            
            // create new task, and add it to the list
            GenericTask * task = new Event(month,day,year,description,time,location);
            
            // add this to the list of tasks
            tasks.addTask(task);
            
            // show message
            out << "Tasks saved successfully!" << endl;
        }
        break;
        
        case HOMEWORK:
        {
            // ask date and description
            out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
            string deadline;
            
            // read deadline
            out<<"> ";
            getline(in, deadline);
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // until valid date
            while( !check.isValidDate(day,month,year)){
                // ask again
                out << "Invalid date." << endl;
                
                // ask again
                out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
                
                // read deadline
                out<<"> ";
                getline(in, deadline);
                
                check.parseDate(deadline, day, month, year);
                
            }
            
            // now, read the description
            out << "How would you describe this task?" << endl;
            string description;
            out<<"> ";
            getline(in, description);
            
            // ask other homework details
            // ask subject
            out << "What subject is this homework task for?" << endl;
            string subject;
            out<<"> ";
            getline(in, subject);
            
            // create new task, and add it to the list
            GenericTask * task = new HomeworkTask(month,day,year,description,subject);
            
            // add this to the list of tasks
            tasks.addTask(task);
            
            // show message
            out << "Tasks saved successfully!" << endl;
        }
        break;
        
        case GENERIC:
        {
            // ask date and description
            out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
            string deadline;
            
            // read deadline
            out<<"> ";
            getline(in, deadline);
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // until valid date
            while(!check.isValidDate(day,month,year)){
                // ask again
                out << "Invalid date." << endl;
                
                // ask again
                out << "What is the deadline for this task (MM/DD/YYYY format)?" << endl;
                
                // read deadline
                out<<"> ";
                getline(in, deadline);
                
                check.parseDate(deadline, day, month, year);
                
            }
            
            // now, read the description
            out << "How would you describe this task?" << endl;
            string description;
            out<<"> ";
            getline(in, description);
            
            // create new task, and add it to the list
            GenericTask * task = new GenericTask(month,day,year,description);
            
            // add this to the list of tasks
            tasks.addTask(task);
            
            // show message
            out << "Tasks saved successfully!" << endl;
            
        }
            break;
            
        default:
            // show messag wrong choice entered;
            out << "Wrong choice entered!" << endl;
    }
}

void ToDoListApp::executeCommandRemoveTask(){
    if (tasks.isEmpty() == true){
        out<<"You have no outstanding task\n";
    }else{
    
        // ask for the id
        out << "Which task would you like to remove?" << endl;
        string id;
        out<<"> ";
        getline(in,id);
        
        // if this task is removed
        if( tasks.removeTask(atoi(id.c_str()))){
            out << "Task removed successfully." << endl;
        }
        else{
            out << "You have entered an invalid task number!" << endl;
        }
    }
    
}
void ToDoListApp::executeCommandCompleteTask(){
    
    if (tasks.isEmpty() == true){
        out<<"You have no outstanding task\n";
    }else{
        
    // ask for the id
    out << "Which task would you like to complete?" << endl;
    string id;
    out<<"> ";
    getline(in, id);
    
    // if this task is removed
        if(tasks.completeTask(atoi(id.c_str()))){
            out << "Task marked complete successfully." << endl;
        }else{
            out << "You have entered an invalid task number!" << endl;
        }
    
    }
}

void ToDoListApp::executeCommandSave(){
    // execute save command
    
    // to store the file name
    string fileName;
    
    // ask file name
    out << "Where would you like to save your outstanding tasks?" << endl;
    
    // read filename
    out<<"> ";
    getline(in, fileName);
    
    // save
    // open the file
    ofstream output;
    out<<"> ";
    output.open(fileName);
    
    // if cannot open file
    if(!output){
        // show message
        cout << "Cannot open file " << fileName << endl;
        return;
    }
    
    // print
    tasks.printToFile(output);
    
    // close the file
    output.close();
    
    out << "Tasks saved successfully!" << endl;
}
void ToDoListApp::executeCommandLoad(){
    // to store the file name
    string fileName;
    
    // ask file name
    out << "What file would you like to load outstanding tasks from?" << endl;
    
    // read filename
	out <<"> ";
    getline(in, fileName);
    
    // try to open the file
    ifstream input;
    input.open(fileName);
    
    // if cannot open file
    if(!input){
        // show message
        cout << "Cannot open file " << fileName << endl;
        return;
    }
    
    // the line
    string line;
    
    // read file
    while( getline(input, line)){
        // if this is generic
        if( line[0] == 'G'){
            // parse the line
            unsigned int i=2;
            
            // read time and description
            
            // the time
            string deadline = "";
            while(line[i] != '|'){
                deadline.push_back(line[i]);
                i++;
            }
            
            i++;
            // the description
            string description = "";
            while(i<line.length()){
                description.push_back(line[i]);
                i++;
            }
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // create new task, and add it to the list
            GenericTask * task = new GenericTask(month,day,year,description);
            
            // add this to the list of tasks
            tasks.addTask(task);
            
        }
        else if( line[0] == 'H'){
            // parse the line
            unsigned int i=2;
            
            // read time and description
            
            // the time
            string deadline = "";
            while(line[i] != '|'){
                deadline.push_back(line[i]);
                i++;
            }
            
            i++;
            // the description
            string description = "";
            while(line[i] != '|'){
                description.push_back(line[i]);
                i++;
            }
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // read subject
            i++;
            string subject = "";
            while(i<line.length()){
                subject.push_back(line[i]);
                i++;
            }
            
            // create new task, and add it to the list
            GenericTask * task = new HomeworkTask(month,day,year,description,subject);
            
            // add this to the list of tasks
            tasks.addTask(task);
            
        }else if( line[0] == 'S'){
            // parse the line
            unsigned int i=2;

            // read time and description

            // the time
            string deadline = "";
            while( line[i] != '|' ){
                deadline.push_back(line[i]);
                i++;
            }

            i++;
            // the description
            string description = "";
            
            while(line[i] != '|'){
                description.push_back(line[i]);
                i++;
            }

            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);

            // get the list of items
            string item;
            // read items
            vector<string> items;

            
            i++;
            item = "";
            while(i<line.length()){
                // add to vector
                while( i<line.length() && line[i] != '|')
                {
                    item.push_back(line[i]);
                    i++;
                }
                items.push_back(item);
                item = "";
                i++;
            }
            
            // add
            string * arr = new string[ items.size() ];
            for(unsigned int i=0; i<items.size(); i++)
                arr[i] = items[i];
            
            // create homework task
            GenericTask * task = new ShoppingTask(month,day,year,description,arr,(int)items.size());
            
            // add this to the list of tasks
            tasks.addTask(task);
        }
        else if( line[0] == 'E'){
            // parse the line
            unsigned int i=2;
            
            
            // the time
            string deadline = "";
            while(line[i] != '|'){
                deadline.push_back(line[i]);
                i++;
            }
            
            i++;
            // the description
            string description = "";
            while(line[i] != '|'){
                description.push_back(line[i]);
                i++;
            }
            
            // get day month year
            int month,day,year;
            check.parseDate(deadline, day, month, year);
            
            // read subject
            i++;
            string location = "";
            while(line[i] != '|'){
                location.push_back(line[i]);
                i++;
            }
            
            // read subject
            i++;
            string time = "";
            while(i<line.length()){
                time.push_back(line[i]);
                i++;
            }
            
            GenericTask * task = new Event(month,day,year,description,time,location);
            
            // add this to the list of tasks
            tasks.addTask(task);
        }
        
    }
    
    // close the file
    input.close();
}

 
