#include <iostream>
#include <iomanip>

#include "Node.h"
#include "Student.h"

using namespace std;

Node* head = NULL; //Node creation
void print(Node* next); //Initial var definitions
void add(char* name, int id, float GPA);
void deleteID(int ID);
float average(Node* next);
int main() {
  char userInput[20];
  bool running = true;
  char name[20];
  int deletedID;
  int id;
  float calculatedAverage;
  float GPA = 0.0;
  cout << "Welcome to student list: Linked lists part 2!" << endl;
  while(running) { //Loop until quit
    cout << "What would you like to do? (ADD/PRINT/DELETE/QUIT)" << endl;
    cin >> userInput;
    if (strcmp(userInput, "ADD") == 0) {
      cout << "Name?" << endl;
      cin >> name;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "ID?" << endl;
      cin >> id;
      cout << "GPA?" << endl;
      cin >> GPA;
      add(name, id, GPA); //Uses the add function to add the name and ID
      cout << "Successfully added!" << endl; 
    }
    else if (strcmp(userInput, "DELETE") == 0) { //Deletes a student, segfaults if theres one student in the list
      cout << "ID to be deleted?" << endl;
      cin >> deletedID;
      cin.clear();
      cin.ignore(999, '\n');
      deleteID(deletedID);
    }
    /*else if (strcmp(userInput, "AVERAGE") == 0) {
      calculatedAverage = average(head);
      cout << "Class GPA Average: " << calculatedAverage << endl;
      }*/
    else if (strcmp(userInput, "PRINT") == 0) { //Prints the linked list
      print(head);
    }
    else if (strcmp(userInput, "QUIT") == 0) { //Stops the program
      running = false;
    }
  }
}

/*float average(Node* next) {
  float sum;
  int count;
  if (next == head) {
    sum = sum + next->getNext()->getStudent()->getGPA();
    count++;
  }
  while (next->getNext() != NULL) {
    sum = sum + next->getNext()->getStudent()->getGPA();
    count++;
    next = next->getNext();
  }
  return(sum/count);
  }*/

void add(char* name, int id, float gpa) { //Adds a new node at the end with inputable parameters
  Student* student = new Student(name,gpa,id);
  Node* currentNode = head;
  if (currentNode == NULL) {
    head = new Node(student); //If it is at the end... set the student info to the last node.
    head->setStudent(student);
  }
  else {
    while (currentNode->getNext() != NULL) {
      currentNode = currentNode->getNext(); //Goes through each node
    }
    currentNode->setNext(new Node(student)); 
    currentNode->getNext()->setStudent(student);
  }
}

/*void add(char* name, int id, float gpa) {
  Student* student = new Student(name,gpa,id);
  Node* currentNode = head;
  if (head == NULL) {
    head = new Node(student);
  }
  else if (student->getID() < head->getStudent()->getID()) {
    Node* holder = new Node(head->getStudent());
    holder->setNext(head->getNext());
    head->setStudent(student);
    head->setNext(holder);
  }
  else if (currentNode->getNext() == NULL) {
    Node* headNode = new Node(student);
    currentNode->setNext(headNode);
  }
  else if (student->getID() < currentNode->getNext()->getStudent()->getID()) {
    Node* newNode = new Node(student);
    newNode->setNext(currentNode->getNext());
    currentNode->setNext(newNode);
    
  }
  else {
    add(name,gpa,id);
  }

  }*/

void deleteID(int ID) {
  Node* currentNode = head;
  if (currentNode == NULL) { //If the list is empty
    cout << "List Empty" << endl;
  }
  else {
    if (currentNode->getStudent()->getID() == ID) { //If it is the head node
      Node* delet = head;
      head = head->getNext();
      delete delet;
      cout << "Node deleted" << endl;
      return; //Returns
    }
    while (currentNode->getNext() != NULL) { //If it is not hte head node
      if (currentNode->getNext()->getStudent()->getID() == ID) { //Check if the id matches
        Node* deletone = currentNode->getNext(); //If it does then delete it
	currentNode->setNext(deletone->getNext());
	delete deletone;
	cout << "Node deleted" << endl;
	return;
      }
      else { //If it doesn't, keep going through the list
	currentNode = currentNode->getNext();
      }
    }
  }
}  


void print(Node* next) { //Prints the linked list and all of the information
  if (next == head) {
    cout << "list:" << endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->getName() << ", " << next->getStudent()->getID() << ", " << fixed << setprecision(2) << next->getStudent()->getGPA() << endl;
    print(next->getNext()); //Recalls the print function so that it keeps printing until it hits a NULL node
  }
}
