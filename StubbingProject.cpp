/* 
This file displays an example of Stubbing through a switch menu option selector inside of a while loop.
The menu shall have more than 10 items, a response for invalid input, and an exit option.
The menu shall be displayed until the exit option is selected.

@file StubbingProject.cpp
@author Jackie Diep
@date 9 / 30 / 2020

*/

//Include to include text input and output
#include <iostream>

//Include namespace std to save time, but should not use in larger projects that it may cause
//    namespace issues with
using namespace std;

//Main begins here
int main()
{

    //Initialize int whileCheck to repeat and exit the menu
    int whileCheck = 1;

    //While loop using whileCheck
    while (whileCheck != 0) 
    {

        //Initialize option to select through the menu
        int option;

        //Prompt for input and list the menu options
        cout << "\nPlease select a menu option listed below." << endl;
        cout << "-----------------------------------------" << endl;

        //Unfinished menu, later fill in with product options
        cout << "1. \n2. \n3. \n4. \n5. \n6. \n7. \n8. \n9. \n10. \n";
        cout << "Select '0' to exit the menu." << endl;
        cout << "\nOption: ";

        //Obtain input
        cin >> option;

        //Switch statement using option to select through the menu
        switch (option)
        {

        //Exit case, change whileCheck to exit while loop
        case 0:
            whileCheck = 0;
            break;

        //Stubbed menu options, later fill in with product option information
        case 1:
            cout << "\n***Option 1 has not been implemented yet." << endl;
            break;
        case 2: 
            cout << "\n***Option 2 has not been implemented yet." << endl;
            break;
        case 3:
            cout << "\n***Option 3 has not been implemented yet." << endl;
            break;
        case 4:
            cout << "\n***Option 4 has not been implemented yet." << endl;
            break;
        case 5:
            cout << "\n***Option 5 has not been implemented yet." << endl;
            break;
        case 6:
            cout << "\n***Option 6 has not been implemented yet." << endl;
            break;
        case 7:
            cout << "\n***Option 7 has not been implemented yet." << endl;
            break;
        case 8:
            cout << "\n***Option 8 has not been implemented yet." << endl;
            break;
        case 9:
            cout << "\n***Option 9 has not been implemented yet." << endl;
            break;
        case 10:
            cout << "\n***Option 10 has not been implemented yet." << endl;
            break;

        //Entry for invalid input
        default:
            cout << "\nInvalid menu item entry. \nPlease try again." << endl;
        }
    }

    //Thank the customer after exiting the menu and close the program.
    cout << "\nThank you for shopping at Menu Stubmart. \nHave a nice day!" << endl;
}