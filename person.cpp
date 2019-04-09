#include "Person.h"
#include <fstream>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

  Person::Person(){
      lastName = " ";
      firstName = " N/A ";
      payRate = 0.0;
      hoursWorked = 0.0;
  }

  Person::Person(string fName, string lName, float Rate, float hrWorked){
      firstName = fName;
      lastName = lName;
      payRate = Rate;
      hoursWorked = hrWorked;
}


  //---------------------------------------------------------------
  void Person::setLastName(string lName){
      lastName = lName;
  }
  string Person::getLastName(){
      return lastName;
  }
  //---------------------------------------------------------------

  void Person::setFirstName(string fName){
      firstName = fName;
  }
  string Person::getFirstName(){
      return firstName;
  }
  //---------------------------------------------------------------

  void Person::setPayRate(float rate){
      payRate = rate;
  }
  float Person::getPayRate(){
      return payRate;
  }
  //---------------------------------------------------------------

  void Person::setHoursWorked(float hours){
      hoursWorked = hours;
  }
  float Person::getHoursWorked(){
      return hoursWorked;
  }
  //---------------------------------------------------------------

  float Person::totalPay(){
      float myVal = hoursWorked * payRate;
      myVal = floorf(myVal * 100) / 100;
      return myVal;
  }
  //---------------------------------------------------------------

  string Person::fullName(){
      string theFullName;
      theFullName = firstName + " " + lastName;
      return theFullName;
  }
