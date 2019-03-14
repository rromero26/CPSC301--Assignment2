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
  myFile >> fName;
  while(!myFile.eof()){
    myFile >> lName;
    myFile >> id;
    myFile >> coName;
    myFile >> hours;
    myFile >> rate;

    Person Temp;
    myVect.push_back(Temp);
    myVect[i].setFirstName(fName);
    myVect[i].setLastName(lName);
    myVect[i].setEmployeeId(id);
    myVect[i].setCompanyName(coName);
    myVect[i].setPayRate(rate);
    myVect[i].setHoursWorked(hours);

    myVect.push_back(Temp);
    myFile >> fName;                   //use to check if reach (END OF FILE) for next loop
    i++;
    }

  myFile.close();
};
//-----------------------------------------------------------------------------------------------------------
void getCompanies(vector<Person> &EmployeeVect, vector<string> &myCompanyVect){
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
        //------ VARIABLES: initalizing ---------------------
  int    i = 0;
  int    index = 0;
  float  currentHighest = 0;

        //------LOOP: saves an index of highest payed employee------
  while(i < EmployeeVect.size()){
    if(EmployeeVect[i].totalPay() > currentHighest){
      currentHighest = EmployeeVect[i].totalPay();
      index = i;
    }
    i++;
  }
        //---- COUT: highest payed employee's info ----
  cout << "Highest paid: " << EmployeeVect[index].fullName() << endl;
  cout << "Employee ID: " << EmployeeVect[index].getEmployeeId() << endl;
  cout << "Employer: " << EmployeeVect[index].getCompanyName() << endl;
  cout << "Total Pay: $" << fixed << setprecision(2) << currentHighest << endl;
};
//----------------------------------------------------------------------------------------------------------
void seporateAndSave(vector<Person> &EmployeeVect, vector<string> &myCompanyVect)
{
    for(int i = 0; i < myCompanyVect.size(); i++)
    {
        string coFilenametxt = myCompanyVect[i] + ".txt";         //create string of compnay name + .txt
        ofstream tempFile;
        tempFile.open(coFilenametxt);                             //create company file and opens
        tempFile << coFilenametxt << endl;
        tempFile << "----------------------------------------------------------------------" << endl;

        float theTotal = 0.0;
        for(int j = 0; j < EmployeeVect.size(); j++)
        {
            if(EmployeeVect[j].getCompanyName() == myCompanyVect[i])
            {
                tempFile << setw(14) << left << EmployeeVect[j].getFirstName();
                tempFile << setw(14) << left << EmployeeVect[j].getLastName();
                tempFile << setw(4) << left << EmployeeVect[j].getEmployeeId();
                tempFile << setw(12) << EmployeeVect[j].getCompanyName() << " ";
                tempFile << "$" << fixed << setprecision(2) << EmployeeVect[j].totalPay() << endl;
                theTotal = theTotal + EmployeeVect[j].totalPay();
            }
        }
        tempFile << endl << "Total: $" << theTotal;
        tempFile.close();
    }
}

//-----------------------END OF FUNCTIONS/ MAINS STARTS HERE--------------------------------------

main(){

  vector <Person> employees;
  vector <string> companyNames;

  readData("input.txt", employees);

  getCompanies(employees, companyNames);

  printHighestPaid(employees);

  seporateAndSave(employees, companyNames);

  return 0;
}
