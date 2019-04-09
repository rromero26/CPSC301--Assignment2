#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Person.cpp"

using namespace std;
//-----------------------------------------------------------------------------------------
int readData(vector<Person> &myVector, int size){    // WILL RETURN A INT counter OF NUM OF EMPLOYEES

    string lName;
    string fName;
    float rate;
    float hours;
    int counter = 0;                        //counter that will save
    string line;

    fstream myFile;                         //opens file
    myFile.open("data.txt");

    if(!myFile) {                           //check if file open properly
      cout << "Error: data.txt could not open. Closing Program." << endl;
      exit(1);
    }
    myFile >> fName;
    while(!myFile.eof()){
      myFile >> lName;
      myFile >> hours;
      myFile >> rate;
      myVector.emplace_back(fName, lName, rate, hours);      //Sets all values while looping
      myFile >> fName;
      counter++;
    }

    myFile.close();
    return counter;
}
//-------------------------------------------------------------------------------------------
void writeData(vector<Person> &myVector, int size){
  //NEED TO NOW USE VECTORS INSTEAD OF ARRAY HER
  //-------------------------------------------

  ofstream myFile("Output.txt");

  if(!myFile){                           //check if file open properly
    exit(1);
  }

  for(int i = 0; i < size; i++){         //Based on num of Employee, loops and print Employee's name and pay
    myFile << myVector[i].fullName() << " "<< myVector[i].totalPay() << endl;
  }
  myFile.close();
}

//-----------------------------------------------------------------------------------------------

main() {
  int EmployeeMax = 20;               //Maz size of array
  vector<Person> myVector;       //creates array

  int numOfEmployee = readData(myVector, EmployeeMax);     //Returns num of existing Employees in file

  writeData(myVector, numOfEmployee);                      //Will only print the amount of exisiting Employees

  return 0;
}
