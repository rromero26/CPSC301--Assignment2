#include "person.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

//-------------FUNCTIONS--------------------------------------------------------
void readData(string myString, vector<Person>  &myVect){
  fstream myFile;                         //opens file
  myFile.open(myString);

  if(!myFile) {                           //check if file open properly
    cout << "Error: input.txt could not open. Closing Program." << endl;
    exit(1);
  }

  string  fName;
  string  lName;
  int     id;
  string  coName;
  float   rate;
  float   hours;
  int     i = 0;
        //----- LOOP:Reading/Saving Data ------
  while(!myFile.eof()){
    myFile >> fName;
    myFile >> lName;
    myFile >> id;
    myFile >> coName;
    myFile >> hours;
    myFile >> rate;

    myVect[i].setFirstName(fName);
    myVect[i].setLastName(lName);
    myVect[i].setEmployeeId(id);
    myVect[i].setCompanyName(coName);
    myVect[i].setPayRate(rate);
    myVect[i].setHoursWorked(hours);
    myVect.push_back(Person());
    i++;
    }

    myFile.close();
};
//---------------------------------------------------------------
void getCompanies(vector<Person> &EmployeeVect, vector<string> &myCompanyVect){
  int counter = 0;

  while (counter < EmployeeVect.size()){
    myCompanyVect.push_back(EmployeeVect[counter].getCompanyName());
    counter++;
  }
};
//---------------------------------------------------------------
void printHighestPaid(vector<Person> &EmployeeVect){
  int    i = 0;
  int    index = 0;
  float  currentHighest = 0;

  while(i < EmployeeVect.size()){
    if(EmployeeVect[i].totalPay() > currentHighest){
      currentHighest = EmployeeVect[i].totalPay();
      index = i;
    }
    i++;
  }

  cout << "Highest paid: " << EmployeeVect[index].fullName() << endl;
  cout << "Employee ID: " << EmployeeVect[index].getEmployeeId() << endl;
  cout << "Employer: " << EmployeeVect[index].getCompanyName() << endl;
  cout << "Total Pay: $" << fixed << setprecision(2) << currentHighest;
};
//---------------------------------------------------------------
void seporateAndSave(vector<Person> &EmployeeVect){
  //CODE
};
//-----------------------END OF FUNCTIONS--------------------------------------
main(){
  vector <Person> employees;
  vector <string> companyNames;

  readData("input.txt", employees);

  getCompanies(employees, companyNames);

  printHighestPaid(employees);

  return 0;
}
