#include<string>
#include<fstream>
#include <iostream>
#include "dataArray.h"
using namespace std;

int main()
{
	//Initialized variables
	int* newArray;
	int checkIntUserInput = 0;
	int modifyIntUserInput = 0;
	int addIntUserInput = 0;
	int removeIntUserInput = 0;
	const int size = 100;
	int dataArray[size];
	bool checkCorrect = false;

	//Code for checking user's input of a filename, and inputting each integer from file to a created array called dataArray
	string fileName;
	cout << "Enter filename: ";
	cin >> fileName;
	ifstream myFile(fileName);
	//Makes sure the user's input is the correct filename.
	while (myFile.fail()) {
		myFile.clear();
		cout << "Incorrect filename, please enter again" << endl;
		cin >> fileName;
		myFile.open(fileName.c_str());
	}
	//Inputs an integer at each index of dataArray as long as the file is actually open.
	if (myFile.is_open()) {
		for (int i = 0; i < size; i++) {
			myFile >> dataArray[i];
		}
	}

	//Code for checking if the user's input of an integer exists in the array
	cout << "Enter integer to see if it exists in the array: ";
	cin >> checkIntUserInput;
	checkIntInArray(dataArray, size, checkIntUserInput);

	//Code for modifying an integer at the index the user inputs.
	cout << "Enter index to be modified: ";
	cin >> modifyIntUserInput;
	//Try-catch block to make sure the user doesn't input an index that is larger or shorter than the length of the index in the array.
	try {
		if (0 <= modifyIntUserInput && modifyIntUserInput <= size + 1) {
			modifyIntInArray(dataArray, modifyIntUserInput);
		}
		else
		{
			throw(modifyIntUserInput);
		}
	}
	catch (...) {
		cout << "The index does not exist in the range of the array " << endl;
	}

	//Code for removing an integer from the array with the user's input of the index
	cout << "Enter index to remove integer: ";
	cin >> removeIntUserInput;
	//Checks to make sure user's input isn't an integer that is larger than the existing index size
	//so that code doesn't return an error.
	while (removeIntUserInput > size + 1) {
		if (removeIntUserInput > size + 1) {
			cout << "Input is larger than the size of indexes, please try again." << endl;
			cout << "Enter index to remove integer: ";
			cin >> removeIntUserInput;
		}
	}
	removeIntInArray(dataArray, removeIntUserInput);

	//Code for adding a new integer to the array. Asks for user to input an int
	cout << "Enter new integer to add to the end of the array:  ";
	cin >> addIntUserInput;
	//Try-catch block to make sure the user doesn't input a non-integer element.
	try {
		cin >> addIntUserInput;
		if (!cin >> addIntUserInput) {
			throw(addIntUserInput);
		}
	}
	catch (...) {
		addIntUserInput = NULL;
		cout << "Incorrect input, not an integer. " << endl;

	}

	newArray = addNewIntToArray(dataArray, size, addIntUserInput);
	if (addIntUserInput == NULL) {
		for (int i = 0; i < size; i++) {
			if (i % 10 == 0) {
				cout << endl << newArray[i] << " ";
			}
			else {
				cout << newArray[i] << " ";
			}
		}
	}
	else {
		for (int i = 0; i < size + 1; i++) {
			if (i % 10 == 0) {
				cout << endl << newArray[i] << " ";
			}
			else {
				cout << newArray[i] << " ";
			}
		}
	}
	/*if (checkCorrect == true) {
		for (int i = 0; i < size + 1; i++) {
			if (i % 10 == 0) {
				cout << endl << newArray[i] << " ";
			}
			else {
				cout << newArray[i] << " ";
			}
		}
	}

	if (checkCorrect == false) {
		for (int i = 0; i < size; i++) {
			if (i % 10 == 0) {
				cout << endl << dataArray[i] << " ";
			}
			else {
				cout << dataArray[i] << " ";
			}
		}
	}*/
}
