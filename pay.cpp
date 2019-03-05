#include "person.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

//-------------FUNCTIONS--------------------------------------------------------
void readData(string myString = "input.txt", vector& myVect){
  fstream myFile;                         //opens file
  myFile.open(myString);

  if(!myFile) {                           //check if file open properly
    cout << "Error: data.txt could not open. Closing Program." << endl;
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
    myVect.push_back(Person);
    i++;
    }

    myFile.close();
};
//---------------------------------------------------------------
void getCompanies(vector& EmployeeVect, vector& myCompanyVect){
  int counter = 0;

  while (counter < EmployeeVect.size()){
    myCompanyVect.push_back(EmployeeVect[counter].getCompanyName());
    counter++;
  }
};
//---------------------------------------------------------------
TYPE printHighestPaid(---){
  int counter = 0;

  while(/* CONDITION */){
    //CODE
  }
};
//---------------------------------------------------------------
TYPE seporateAndSave(---){

};
//-----------------------END OF FUNCTIONS--------------------------------------
main(){
  vector <Person> employees = {};
  vector <string> companyNames;

  readData("input.txt", employees);

  getCompanies(employees, companyNames);



  return 0;
}
