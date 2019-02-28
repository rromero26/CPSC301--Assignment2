#include "person.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Person();

 //---------------------------------------------------------------
void   setFirstName(string fName);
string getFirstName();
 //---------------------------------------------------------------
void   setLastName(string lName);
string getLastName();
 //---------------------------------------------------------------
void   setEmployeeId(int id);
int    getEmployeeId();
 //---------------------------------------------------------------
void   setCompanyName(string coName);
string getCompanyName();
 //---------------------------------------------------------------
void   setPayRate(float rate);
float  getPayRate();
 //---------------------------------------------------------------
void   setHoursWorked(float hours);
float  getHoursWorked();
 //---------------------------------------------------------------
float  totalPay();
 //---------------------------------------------------------------
string fullName();
