#pragma once
#include <iostream>
using namespace std;

class StudentRecord
{
private:
	string studentFirstName;
	string studentLastName;
	string fullName;			//Calculated as: studentFirstName + " " + studentLastName
	int studentID;

	// Used to update the student full name property
	void updateFullName() {
		fullName = studentFirstName + " " + studentLastName;
	}

public:
	//Constructor
	StudentRecord(string firstName, string lastName, int ID) {

	}

	//Display details about the student in the terminal, including ID and full name
	void display() {
		
	}

	// *********************** Getters *********************** 

	//Returns copy of full name (as a string) - First name, followed by a space, followed by Last name
	string getFullName()	
	{
		
	}

	//Returns a copy of the ID (as an integer)
	int getID()			
	{
		
	}

	// *********************** Setters *********************** 

	//Update the first name
	void updateFirstName(string firstName)
	{

	}

	//Update the last name
	void updateLastName(string lastName)
	{

	}
};

