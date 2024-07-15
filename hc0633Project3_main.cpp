#include "hc0633Project3_header.h"


int main()
{

	//VARIABLE FOR REMOVE CHOICE (STUDENT ID)
	string studentID;
	char userchoice;

	options my_option;
do
{
	
	// USER MENU
	cout <<"1. Add" << endl;
	cout <<"2. Remove" << endl;
	cout <<"3. Display" << endl;
	cout <<"4. Search" << endl;
	cout <<"5. Results" << endl;
	cout <<"6. Quit" << endl;


	
	// ASK USER CHOICE
	cout << "Enter your choice: "<<endl;
	cin >> userchoice;

	my_option = static_cast<options>(userchoice);	
	// SWITCH CASE
	switch(my_option)
	{
		case Add:
			add_Student();
		break;

		case Remove:
			cout << "Enter ID of student to remove:";
			cin >> studentID;
			remove_Student(studentID);
		break;

		case Display:
		display();	
		break;

		case Search:
			search(studentID); 
			
		break;

		case Results:
			exportResults(); 

		break;

		case Quit:
			cout << "Bye!!!" << endl;

		break;

		default:
			cout << "Invalid choice. Please choose a valid option." << endl;
		break;
	}
	
}while (my_option != Quit);

	return 0;
}
