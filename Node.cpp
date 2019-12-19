#include <iostream>
#include <cstring>

#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student*) { //default class
  student = NULL;
  next = NULL;
}

Node* Node::getNext() { //function to call the next node in the link
  return next; 
}

void Node::setNext(Node* nextnode) { //sets the next node
  
  next = nextnode;
}

Student* Node::getStudent() { //gets the student information connected to a given node
  return student;
}

void Node::setStudent(Student* newstudent) { //sets the student that is to connect to a node
  student = newstudent;
}

Node::~Node() {
  delete &student;
  next = NULL;
}
