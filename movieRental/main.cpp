#include "customerType.h"
#include "videoType.h"

using namespace std;

char cMainMenu;

customerType customerStuff;
videoType videoStuff;

void displayMenu()
{
	while (true)
	{
		system("cls");
		cout << "Welcome to the video store!" << endl;

		cout << "- Please enter the letter of the action you would like to perform -" << endl;
		cout << "- A: Access the customer side -" << endl;
		cout << "- B: Access the video side -" << endl;
		cout << "- C: Close the program -" << endl;

		cin >> cMainMenu;
		cin.ignore(1, '\n');

		switch (cMainMenu)
		{
		case 'A':
		case 'a':
			customerStuff.customerMenu();
			break;
		case 'B':
		case 'b':
			videoStuff.movieMenu();
			break;
		case 'C':
		case 'c':
			exit(0);
		}
	}
}

int main()
{
	displayMenu();
}