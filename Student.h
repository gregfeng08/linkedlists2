  
#ifndef STUDENT_H //Header guards
#define STUDENT_H

#include <iostream> //Imports
#include <cstring>

using namespace std;

class Student {
 public:
  Student(const char*,float, int); //Pulic function and variable definitions for use in the main program
  ~Student();
  char* getName();
  int getID();
  float getGPA();
 private:
  char* nameInput; //Private variable definitions for use in Student.cpp
  int idInput;
  float GPAInput;
};

#endif
