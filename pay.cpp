//
//  pay.cpp
//  Assignment3
//
//  Created by Pierce Findlay on 4/16/19.
//  Copyright © 2019 Pierce Findlay. All rights reserved.
//  Pierce Findlay
//  Section 2


#include "person.cpp"

void readData(vector <Person> &employees)
{
    ifstream iFile;
    string fName;
    string lName;
    string coName;
    int id;
    float rate;
    float hours;
    iFile.open("input.txt");
    Person P;
    if (iFile.is_open())
    {
        
        while (iFile >> fName >> lName >> id >> coName >> rate >> hours)
        {
            
            cout << fName << " " << lName << " " << id << " " << coName << " " << rate
            << " " << hours << endl;
            P.setFirstName(fName);
            P.setLastName(lName);
            P.setCompanyName(coName);
            P.setEmployeeId(id);
            P.setPayRate(rate);
            P.setHoursWorked(hours);
            employees.push_back(P);
            
        }
        iFile.close();
    }
}
void getCompanies(vector <Person> &employees, vector<string> &companyNames)
{
    string name;
    name = employees.at(0).getCompanyName();
    
    
    companyNames.push_back(name);
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        bool found = false;
        for (unsigned int j = 0; j < companyNames.size(); j++)
        {
            if(employees.at(i).getCompanyName() == companyNames.at(j))
            {
                found = true;
            }
        }
        if (!found)
        {
            companyNames.push_back(employees.at(i).getCompanyName());
        }
        
    }
    for (unsigned int j = 0; j < companyNames.size(); j++)
    {
        //test
    }
}
void printHighestPaid(vector <Person> &employees)
{
    int highest = 0;
    int index = 0;
    
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        if (highest < employees.at(i).totalPay()){
            highest = employees.at(i).totalPay();
            index = i;
            
            
        }
    }
    cout << " Highest Paid: " << employees.at(index).fullName() << endl;
    cout << " Employee ID: " << employees.at(index).getEmployeeId() << endl;
    cout << " Employer: "  << employees.at(index).getCompanyName() << endl;
    cout << " Total Pay: "  << employees.at(index).totalPay() << endl;
    
}



void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
    
    float totalText = 0;
    fstream dataFile;
    for (unsigned int j = 0; j < companyNames.size(); j++)
    {
        dataFile.open(companyNames.at(j) + ".txt", fstream::out);
        for (unsigned int i = 0; i < employees.size(); i++){
            
            if (employees.at(i).getCompanyName() == companyNames.at(j))
            {
                totalText += employees.at(i).totalPay();
                
                dataFile << employees.at(i).getFirstName() << " " << employees.at(i).getLastName() << " " << employees.at(i).getEmployeeId() << " " << employees.at(i).getCompanyName() << " " << "$" << employees.at(i).totalPay() << endl;
                
            }
            
        }
        dataFile << "Total $" << totalText << endl;
        totalText = 0;
        dataFile.close();
    }
    
    
}

int main(){
    vector<Person> employees;
    vector<string> companyNames;
    
    readData(employees);
    getCompanies(employees, companyNames);
    printHighestPaid(employees);
    separateAndSave(employees, companyNames);
}

/*
 Includes:
 A main() function
 The #include "person.cpp" statement
 Any other necessary includes and/or helper functions
 All the additional details mentioned below

 
 
 */
