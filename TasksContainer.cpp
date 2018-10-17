/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The tasks container will take tasks and store it here.
 ***************************************************************/
#include "TasksContainer.hpp"
#include <iostream>
using namespace std;

// the constructor
TasksContainer::TasksContainer(){
    // set head and tail to null
    head = NULL;
    size = 0;
}

// the constructor
TasksContainer::~TasksContainer(){
    TaskNode * curr = head;
    
    // iterate and delete node with this id
    while(curr){
        // store reference
        TaskNode *  old = curr;
            
        // move ahead
        curr = curr->next;
            
        // delete old
        delete  old;
    }
}

// to add a task
void TasksContainer::addTask(GenericTask * newTask){
    // to add this taks to the list
    if(head == NULL)
    {
        // create a new head
        head = new TaskNode;
        
        // attach the task and set next to null
        head->next = NULL;
        head->task = newTask;

    }
    // else if this task deadline is before the task dead line at head
    else if(newTask->getDeadline() < head->task->getDeadline()){
        // create new node
        TaskNode * newNode = new TaskNode;
        
        // set data and next
        newNode->next = head;
        newNode->task = newTask;
        
        // set head to this
        head = newNode;
    }
    else{
        
        // reference to current
        TaskNode * curr = head->next;
        TaskNode * prev = head;

        // create new node
        TaskNode * newNode = new TaskNode;

        // as long as there is a node
        while(curr){
            // if this task is less than current task

            if(newTask->getDeadline() < curr->task->getDeadline())
            {
                // insert new task here
                

                
                // set data and next
                newNode->next = curr;
                newNode->task = newTask;
                
                // next of previous is this
                prev->next = newNode;
                
                // increment size
                size++;
                
                // return
                return;
            }
            
            // move ahead
            prev = curr;
            curr = curr->next;
        }
        

        // set data and next
        newNode->next = NULL;
        newNode->task = newTask;
        
        // set next of tail to this
		prev->next = newNode;
    }
    // increment size
    size++;

//	resetID();
}



// is empty
bool TasksContainer::isEmpty(){
    return size == 0;
}


bool TasksContainer::removeTask(int id) {

    // if size is zero, return false
    if(isEmpty())
        return false;

    if(id == 1) {
        TaskNode *tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }
    else{
        TaskNode *tmp = head;
        int itr = 1;

        while(tmp) {
            if(itr == id - 1) {
                break;
            }
            tmp = tmp->next;
            itr++;
        }

        if(tmp == NULL) {
            return false;
        }
        if(tmp->next == NULL) {
            return false;
        }
        else {
            TaskNode *tmp2 = tmp->next;
            tmp->next = tmp->next->next;
            std::cerr << "about to delete\n";
            delete tmp2;
            size--;
        }
    }

    return true;

}

// print tasks
void TasksContainer::printTasks(bool details){
    // this takes a paramter if details have to be printed
    
    // if details has to be printed
    if(details){
        if (isEmpty()){
            cout<<"You have no outstanding tasks!"<< endl;
        }else{
        
            // iterate the list and print
            TaskNode * curr = head;
            
            
            int itr = 1;
            while(curr){
                // print with details
                cout << itr << ". " << curr->task->toStringDetails()<< endl;
                itr++;
                // move ahead
                curr = curr->next;
            }
        }
    }
    else
    {

        if (isEmpty()){
            cout<<"You have no outstanding tasks!"<< endl;
        }else{
        // iterate the list and print
            TaskNode * curr = head;
         
            
            int itr=1;
            while(curr)
            {
                // print with details
                cout << itr << ". " << curr->task->toString()<< endl;
                itr++;
                // move ahead
                curr = curr->next;
            }
        }
    }
}

// print completed tasks
void TasksContainer::printCompletedTasks(){
        // flag for the complete and completed
        bool flag = false;
    
        // iterate the list and print
        TaskNode * curr = head;
        
        // iterate and delete node with this id
        while(curr){
            if(curr->task->isCompleted()){
                // print with details
                cout<<curr->task->toString() << endl;
                flag = true;
            }
            
            // move ahead
            curr = curr->next;
        }
    // check if there is no completed tasks.
    if (!flag){
        cout<<"You have no completed tasks!" <<endl;
    }
    
}

// complete this task
bool TasksContainer::completeTask(int id){
        // iterate the list and print
    TaskNode * curr = head;
    
    // iterate and delete node with this id
    int itr=1;
    while(itr < id){
        if(curr == NULL) {
            return false;
        }
        
        // move ahead
        curr = curr->next;
    }

    curr->task->setCompleted();

    return true;
}


// print to file
void TasksContainer::printToFile(ofstream & output){
    // iterate the list and print
    TaskNode * curr = head;
    
    // iterate and delete node with this id
    while(curr){
        if(!curr->task->isCompleted()){
            // print the common details first
            output << curr->task->getType()  << "|" << curr->task->getDeadline().toString() << "|" <<
            curr->task->getDescription();
            
            // print the other details
            if(curr->task->getType() == 'H'){
                HomeworkTask * T = (HomeworkTask *)curr->task;
                // output subject
                output << "|" << T->getSubject();
            }
            else if(curr->task->getType() == 'E'){
                Event * T = (Event *)curr->task;
                output << "|" << T->getLocation() << "|" << T->getEventTime();
            }
            else if(curr->task->getType() == 'S'){
                // the shopping task
                // change c style cast to stactic cast
                ShoppingTask * T = static_cast<ShoppingTask*>(curr->task);
                
                // the list of items
                int numItems;
                string * items = T->getItems(numItems);
                
                // print all the items
                for( int i=0; i<numItems; i++){
                    output << "|" << items[i];
                }
                
            }
            output << endl;
        }
        
        // move ahead
        curr = curr->next;
    }
}

// // to reset the ids
// void TasksContainer::resetID()
// {
//     TaskNode * curr = head;

// 	// the id
// 	int id = 1;

// 	// iterate and delete node with this id
// 	while (curr)
// 	{
// 		// set this task completed
// 		curr->task->setID(id++);

// 		// move ahead
// 		curr = curr->next;
// 	}
// }




