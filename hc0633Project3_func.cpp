#include<iostream>
#include<sstream>
#include<vector>
#include "hc0633Project3_header.h"
void add_Student()
{

	string firstName;
	string lastName;

	// open student.dat, in append mode 
	fstream output;
	output.open("student.dat", ios::app);


	// declare s of type structure
	Student s;

	cout << endl;
	// ask user for first and last name
	cout << "Enter the last name of the student: ";
        cin >> lastName;

	cout << "Enter the first name of the student: ";
	cin >> firstName;

	// store first and last in structure name
	s.name = lastName + "," + firstName;
	output << s.name;
	

	// store ID in stucture ID
	cout << "Enter student ID: ";
	cin >> s.ID;

	output <<"," << s.ID;

	// store number of tests in structure
	cout << "Enter number of test scores:";
	cin >> s.tests;
	output << "," << s.tests << ",";

	s.array  = new int[s.tests];

	for ( int i =0; i < s.tests; i++)
	{
		cout << "Enter " << i+1 << " score:";
		cin >> s.array[i];
	       output << s.array[i] << ",";	

	}
	//delete array	
	delete [] s.array;
}


void remove_Student(string studentID)
{
	ifstream inputFile("student.dat");
    string line;
    string space = " ";

 // Make sure file can be opened
        if (inputFile.fail())
        {
             cout << "File could not be opened" << endl;
        }


    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        // Read tokens separated by commas
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Assuming tokens.size() is at least 8
        Student student;
        student.name = tokens[0] + space + tokens[1];
        student.ID = tokens[2];

        // Convert the next 5 tokens to integers
        for (int i = 0; i < 5; ++i) {
            student.scores[i] = stoi(tokens[3 + i]);
        }
bool match = false;

if(studentID == student.ID){
match = true;
cout <<"Student found and information removed." <<endl;

}
else{
cout << " No student with the ID entered. "<<endl;
}
inputFile.close();
}
}



void display() {
    ifstream inputFile("student.dat");
    string line;
    string space = " ";

  // Make sure file can be opened
        if (inputFile.fail())
        {
             cout << "File could not be opened" << endl;
        }
 
 
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        // Read tokens separated by commas
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Assuming tokens.size() is at least 8
        Student student;
        student.name = tokens[0] + space + tokens[1];
        student.ID = tokens[2];

        // Convert the next 5 tokens to integers
        for (int i = 0; i < 5; ++i) {
            student.scores[i] = stoi(tokens[3 + i]);
        }

        // Display the separated components for each line
        cout << setw(30) << student.name ;
        cout << setw(15) << student.ID ;
        
        for (int i = 0; i < 5; ++i) {
            cout << setw(5) <<student.scores[i] << ' ';
        }
        cout << endl;
    }

    inputFile.close();
}


void search(string studentID){

cout << "Enter the student ID: " << endl;
cin >> studentID;

 ifstream inputFile("student.dat");
    string line;
    string space = " ";

 // Make sure file can be opened
        if (inputFile.fail())
        {
             cout << "File could not be opened" << endl;
        }
 
    
    
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        // Read tokens separated by commas
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Assuming tokens.size() is at least 8
        Student student;
        student.name = tokens[0] + space + tokens[1];
        student.ID = tokens[2];

        // Convert the next 5 tokens to integers
        for (int i = 0; i < 5; ++i) {
            student.scores[i] = stoi(tokens[3 + i]);
        }
bool match = false;

if(studentID == student.ID){
match = true;
cout <<"Student found!!" <<endl;
	
 cout << setw(30) << student.name ;
        cout << setw(15) << student.ID ;

        for (int i = 0; i < 5; ++i) {
            cout << setw(5) <<student.scores[i] << ' ';
        }
        cout << endl;

}
else{
cout << " No student with the ID entered. "<<endl;
}
inputFile.close();
}
}


int findMinimum(int scores[5], int numTests) {
    int minimum = scores[0];
        int size = getNumber();
    for (int i = 1; i < size; i++) {
        if (scores[i] < minimum) {
            minimum = scores[i];
        }
    }

    return minimum;
}

void exportResults()
{
	int sum = 0;
 	ifstream inputFile("student.dat");
 	ofstream output("averages.dat");
	string line;
	string space = " ";

 	// Make sure file can be opened   
	if (inputFile.fail() || output.fail())
	{
	     cout << "File could not be opened" << endl;
	}

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        // Read tokens separated by commas
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Assuming tokens.size() is at least 8
        Student student;
        student.name = tokens[0] + space + tokens[1];
        student.ID = tokens[2];

	output << student.ID << endl;	
        // Convert the next 5 tokens to integers
        for (int i = 0; i < 5; ++i) {
            student.scores[i] = stoi(tokens[3 + i]);
	    sum += student.scores[i];
	    //output << sum;
	}
	int min = findMinimum(student.scores, 5);
	
	//sum += student.scores[i];
         output << fixed << setprecision(1) << (sum-min)/5.0;

	output << endl;
   	sum = 0;
    
    
    
    
    
    
    
    }

    inputFile.close();
    output.close();
}


