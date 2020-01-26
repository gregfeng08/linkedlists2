#include <iostream> //Imports
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(const char* name, int id) { //Creates a new student
  strcpy(nameInput, name);
  idInput = id;
}

Student::~Student() { //Destructor for the student
  delete nameInput;
}

char* Student::getName() { //GIves the name of the student
  return nameInput;
}

int Student::getID() { //Gives the id of the student
  return idInput;
}
