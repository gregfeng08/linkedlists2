#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(Student*); //constructor
  ~Node(); //destructor
  
  //getters and setters

  Node* getNext();
  void  setNext(Node*);
  Student* getStudent();
  void setStudent(Student*);
 private:
  Node* next;
  Student* student; //this is the variable that connects a node to a student
};
#endif
