#include "person.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

//-------------FUNCTIONS--------------------------------------------------------------------------------------
void readData(string myString, vector<Person>  &myVect){
  cout << "I am in readData" << endl;
      //------ VARIABLES: initalizing ---------------------
  string  fName;
  string  lName;
  int     id;
  string  coName;
  float   rate;
  float   hours;
  int     i = 0;                          //counter
        //--- File: Opening and checking -------------------
  fstream myFile;                         //opens file
  myFile.open(myString);

  if(!myFile) {                           //check if file open properly
    cout << "Error: input.txt could not open. Closing Program." << endl;
    exit(1);
  }
        //----- LOOP:Reading/Saving Data -----------------------------
  while(!myFile.eof()){

    //cout << "I am in readData: loop" << endl;

    myFile >> fName;
    myFile >> lName;
    myFile >> id;
    myFile >> coName;
    myFile >> hours;
    myFile >> rate;

    //cout << "I am in readData: loop 2" << endl; //CORE DUMPS AFTER HERE
    Person Temp;
    myVect.push_back(Temp);
    myVect[i].setFirstName(fName);
    myVect[i].setLastName(lName);
    myVect[i].setEmployeeId(id);
    myVect[i].setCompanyName(coName);
    myVect[i].setPayRate(rate);
    myVect[i].setHoursWorked(hours);

    myVect.push_back(Temp);
    i++;
    }

  myFile.close();
};
//-----------------------------------------------------------------------------------------------------------
void getCompanies(vector<Person> &EmployeeVect, vector<string> &myCompanyVect){
  //cout << "I am in getCompany"<< endl;
  int counter = 0;

    //Loops through EmployeeVect and saves company of each member into a vector
  while (counter < EmployeeVect.size()){
    myCompanyVect.push_back(EmployeeVect[counter].getCompanyName());
    counter++;
  }

    //sorts vector THEN erase duplicates to leave vector with only unique company names
  sort(myCompanyVect.begin(), myCompanyVect.end());
  myCompanyVect.erase(unique(myCompanyVect.begin(), myCompanyVect.end()), myCompanyVect.end());
};
//-----------------------------------------------------------------------------------------------------------
void printHighestPaid(vector<Person> &EmployeeVect){
  cout << "I am in highestPaid" << endl;

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
  cout << "Total Pay: $" << fixed << setprecision(2) << currentHighest << endl;
};
//----------------------------------------------------------------------------------------------------------
/*
void seporateAndSave(vector<Person> &EmployeeVect, vector<string> &myCompanyVect){
  int counter = 0;

  //Loop will create all the company.txt files needed
  while(counter < myCompanyVect.size()){
    string coName =  myCompanyVect[counter] + ".txt";

    fstream aFile;
    aFile.open(coName);
    counter++;
  }
  //CODE

  fixed << setprecision(35) <<  //fName
  fixed << setprecision(25) <<  //lName
  fixed << setprecision(2) <<   //money
};
*/

//-----------------------END OF FUNCTIONS/ MAINS STARTS HERE--------------------------------------


main(){
  cout << "I am in Main, begining" << endl;

  vector <Person> employees;
  vector <string> companyNames;

  readData("input.txt", employees);
  cout << "I am in Main, after readData" << endl;

  getCompanies(employees, companyNames);
  cout << "I am in Main, after getCompanies" << endl;

  printHighestPaid(employees);
  cout << "I am in Main, after highestPaid" << endl;

  //seporateAndSave(employees, companyNames)
  //cout << "I am in Main, after seporateAndSave" << endl;

  return 0;
}
