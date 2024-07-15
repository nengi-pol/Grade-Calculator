#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
// Declare enum options for user
enum options{Add = '1' , Remove = '2' , Display = '3' , Search = '4' , Results ='5' , Quit = '6'};

const int test_given = 5;
// Declare Struct
struct Student {
	string name;
	string ID;
	int tests;
	int* array; 
	int average;
	int scores[5];

};

void add_Student();
void remove_Student(string studentID);
void display();
int getNumber();
void search(string studentID);
void exportResults();
int  findMinimum(int, int);

