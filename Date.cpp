/***************************************************************
 Title: Project 2
 Author: Ali Almashhadani
 Date Created: 4/11/2018
 Class: Spring 2018, CSCI 23500-04, Mon & Wed 7:00pm-8:15pm
 Professor: Aarsh Vorawmake
 Purpose: Project
 Description: The Date cpp will check for date if it vaild or not.
 ***************************************************************/
#include <iostream>
#include "Date.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;


// complete the declarations in the date class
// method to get the details of date
void Date::parseDate(const std::string &date,int &day, int &month, int &year){
    // get month
    string m = "";
    m = date.substr(0,1);
    m = m + date.substr(1,1);
    
    // get the day
    string d = "";
    d = date.substr(3,3);
    d = d + date.substr(4,4);
    
    // get year
    string y = "";
    y = date.substr(6);
  
    

    // set the dates
    day = stoi(d.c_str());
    month = stoi(m.c_str());
    year = stoi(y.c_str());
}
// leap year
bool Date::isLeapYear( const int &year){
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;
    return false;
}

bool Date::isValidDate(int & day, int & month, int & year){
    // check valid day
    if(day < 1 || day > 31)
        return false;
    
    // valid month
    if(month < 1 || month > 12)
        return false;
    
    // valid year
    if (year < 2018)
    return false;
    
    // if month has 30 days
    if(!(month == 1 || month == 2 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
        // if not valid day
        if(day > 30)
            return false;
    }
    
    // leap year
    bool leap = isLeapYear(year);
    
    // if feb
    if(month == 2){
        if(day > 29)
            return false;
        else if(leap && day == 28)
            return false;
        else if(!leap && day > 28)
            return false;
    }
    
    // final check for the to make sure the date vaild. 
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    if (year == (now->tm_year + 1900)){
        if(month == (now->tm_mon + 1)){
            if (day <= now->tm_mday)
                return false;
        }
    }
    // return true
    return true;
}
// the constructor
Date::Date(){
    // set the date to today date.
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    day = now->tm_mday;
    month = (now->tm_mon + 1);
    year = (now->tm_year + 1900);
}

// the constructor
Date::Date(int month,int day, int year){
    // set the year
    this->day = day;
    this->month = month;
    this->year = year;
}

// the to string method
string Date::toString(){
    string m = "";
    string d = "";
    string y = "";

    // get the string of the month
    if(month < 10){
        m = "0" + to_string(month);
    }
    else{
        m = to_string(month);
    }

    // get the string of the day
    if(day < 10){
        d = "0" + to_string(day);
    }
    else{
        d = to_string(day);
    }

    // get the string of the year
    if(year < 10){
        y = "0" + to_string(year);
    }
    else{
        y = to_string(year);
    }

    // return
    return m + "/" + d + "/" + y;
}

// overload operator
bool Date::operator < (const Date & rhs){
    // if the year is not same
    if(year < rhs.year)
        return true;
    
    // if the year is same but month is not
    if(year == rhs.year && month < rhs.month)
        return true;
    
    // if month and year is same, but day not
    if(year == rhs.year && month == rhs.month && day < rhs.day)
        return true;
    
    // else, return false
    return false;
}
