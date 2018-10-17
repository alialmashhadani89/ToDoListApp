/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Date hpp is the header for the cpp file.
 ***************************************************************/

#ifndef Date_hpp
#define Date_hpp

#include <string>

// the date class
struct Date
{
    // the private data members

    int day;
    int month;
    int year;
    
    // the public data members
public:
    // the constructor
    Date();
    
    // method to get the details of date
    void parseDate(const std::string &date,int & day, int & month, int & year);
    
    // to check if valid date
    bool isValidDate(int & day, int & month, int & year);
    
    // leap year
    bool isLeapYear(const int &year);

    
    // the constructor
    Date(int month,int day,int year);
    
    // the destructor
    ~Date() {} 
    
    
    // the to string method
    std::string toString();
    
    // overload operator
    bool operator < (const Date & rhs);

};

#endif /* Date_hpp */
