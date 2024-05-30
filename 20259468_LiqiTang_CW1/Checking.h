//
//  Start_System.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/3/20.
//

#ifndef Start_System_h
#define Start_System_h
#include <iostream>
using namespace std;

//check the validation of user input
int Cheking(){
    int userInput;      //Decleartion of userInput
    do {
        cout << "Please enter 1 or 2: "; // prompt user for input
        cin >> userInput; // read user input
        
        // check if the input failed or is not a number
        if (cin.fail()) {
            cin.clear(); // clear the input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any characters in the input buffer
            cout << "Invalid input. Please enter a number.\n"; // display an error message
        }
        // check if the input is out of range
        else if (userInput < 1 || userInput > 2) {
            cout << "Invalid input. Please enter 1 or 2.\n"; // display an error message
        }
    } while (userInput < 1 || userInput > 2); // loop until valid input is entered
    return userInput;
}

#endif /* Start_System_h */
