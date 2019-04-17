//
//  person.cpp
//  Assignment3
//
//  Created by Pierce Findlay on 4/16/19.
//  Copyright © 2019 Pierce Findlay. All rights reserved.
//  Pierce Findlay
//  Section 2

#include "person.h"


using namespace std;

Person::Person()
{
    
}

void Person::setFirstName(string fName)
{
    
    firstName = fName;
    
}

void Person::setLastName(string lName)
{
    
    lastName = lName;
    
}

void Person::setEmployeeId(int id)
{
    
    employeeID = id;
    
}

void Person::setCompanyName(string coName)
{
    
    companyName = coName;
    
}

void Person::setPayRate(float rate)
{
    
    payRate = rate;
    
}

void Person::setHoursWorked(float hours)
{
    
    hoursWorked = hours;
    
}

string Person::getFirstName()
{
    return firstName;
}
string Person::getLastName()
{
    return lastName;
}
string Person::fullName()
{
    return firstName + " " + lastName;
}
int Person::getEmployeeId()
{
    return employeeID;
}
string Person::getCompanyName()
{
    return companyName;
}
float Person::getPayRate()
{
    return payRate;
}
float Person::getHoursWorked()
{
    return hoursWorked;
}
float Person::totalPay()
{
    return (payRate * hoursWorked);
}

/*
 string Person::getFirstName() { return firstName;
 }
 */
