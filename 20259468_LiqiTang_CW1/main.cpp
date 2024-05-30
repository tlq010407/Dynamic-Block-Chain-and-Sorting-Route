//
//  main.cpp
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/2/16.
//

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Checking.h"
#include "Blockchain_Empty_Checking.h"
#include "ReadFile.h"
#include "Diseases.h"
#include "SplitString.h"

using namespace std;

int main() {
    int continuenum, choice;     //i is the variable used to get the user input number; and continunum is used to check whether user wanna continue or not
    bool flag, empty, exists;      //Used to check whether find the information in the blockchain or not
    continuenum = 1;    //Assign continuenum as 1 to start the program at first
    /* Time function returns the time since the
     Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    Blockchain blockchain = Blockchain();  // Create a new blockchain
    Disease rootDisease;
    string key;
    /* You can call it like this : start = time(NULL);
     in both the way start contain total time in seconds
     since the Epoch. */
    time(&start);
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    Block newBlock;
    
    do {    //Use DO-WHILE loop to control the continue of the program
        
        //Main menu to let user choose what they wanna do
        cout<<"Please press the key you want:"<<endl;
        cout<<"1. Predefined and loaded the blockchian"<<endl;
        cout<<"2. Get the information by searching the Employee ID"<<endl;
        cout<<"3. Get the information by searching the Patient ID"<<endl;
        cout<<"4. Get the information by searching the Transaction ID"<<endl;
        cout<<"5. Get the information by searching the Block Index"<<endl;
        cout<<"6. Delete the block in blockchain with block ID"<<endl;
        cout<<"7. Edit the block in the blockchain by enter the block ID"<<endl;
        cout<<"8. Quick search employee's diseases information according to the name/patient ID"<<endl;
        cout<<"9. Load all diseases that are stored in the file." <<endl;
        cout<<"10. Export the blockchain information."<<endl;
        cin>>choice;
        //Switch statements to process different user's requirments
        switch (choice) {
            case 1:
                FileExists();
                blockchain = readFile();
                rootDisease.LoadDiseases("DiseaseInfo.txt");
                // Print the entire blockchain
                blockchain.printFullChain();
                break;
            case 2:
                //Find the employee information with Employee ID
                cout<<"Please enter the Employee ID"<<endl;
                flag = true;    //Set flag initial value as true
                int Employee_ID;
                cin>>Employee_ID;   //Enter the Employee_ID that user wanna check the information
                empty = isBlockchainEmpty(blockchain);   //Set the initial value as return value of isBlockchainEmpty() function
                if(empty == false){     //Check whether the blockchain is empty or not, if not then continue the process, else through the error
                    for(int i=1; i<blockchain.chain.size();){    //Use for-loop to go through ID in the blockchain
                        if(blockchain.chain[i].ID == Employee_ID){      //Use if-statement to check whether the input ID is same as blockchian ID
                            cout<< "If you want to all information about this employee press 1,or the information in this block please press 2."<<endl;
                            //External function from 'Checking.h' file, used to whether check the user input is validate or not
                            int userInput = Cheking();      // Declare an integer variable to store user input as the output of the checking function
                            // check if input if 1 then print all employee information
                            if(userInput == 1){
                                cout<< "There are all information about this Empolyee."<<endl;  //Print out all information about the user
                                cout<<"------------------------------------------------"<<endl;
                                blockchain.printChain(i);
                                blockchain.printChain(i+1);
                                blockchain.printChain(i+2);
                                flag = false;       //Set flag value to false once match the Employee_ID with blockchain ID
                                break;  //End for-loop
                            }else if(userInput == 2){   //if input is 2, print the only block information
                                cout<<"------------------------------------------------"<<endl;
                                cout<<"Employee Name: " + blockchain.chain[i].name<< endl;      //Print out the Employee Name help to check
                                blockchain.printChain(i);       //Print the block information
                                flag = false;       //Set flag value to false once match the Employee_ID with blockchain ID
                                break;  //End for-loop
                            }
                            userInput = 0;  //Resit the userInput value to continue the system
                        }
                        i=i+3;      //To make sure only check about the employee id
                    }
                    if(flag == true){   //Use if-statement to check the flag value
                        cout<<"Sorry the Employee ID cannot be found in this blockchain."<<endl;    //Failed to find the block with Employee_ID in blockchain
                    }
                }
                break;
            case 3:
                //Find the employee information with Patient ID
                cout<<"Please enter the Patient ID"<<endl;
                flag = true;    //Set flag initial value as true
                empty = isBlockchainEmpty(blockchain);   //Set the initial value as return value of isBlockchainEmpty() function
                int Patient_ID;
                cin >> Patient_ID; //Enter the Patient_ID that user wanna check the information
                if(empty == false){     //Check whether the blockchain is empty or not, if not then continue the process, else through the error
                    for(int i=2; i<blockchain.chain.size();){    //Use for-loop to go through ID in the blockchain
                        if(blockchain.chain[i].ID == Patient_ID){   //Use if-statement to check whether the input ID is same as blockchian ID
                            cout<< "If you want to all information about this employee press 1,or the information in this block please press 2."<<endl;
                            //External function from 'Checking.h' file, used to whether check the user input is validate or not
                            int userInput = Cheking();      // Declare an integer variable to store user input as the output of the checking function
                            // check if input if 1 then print all employee information
                            if(userInput == 1){
                                cout<< "There are all information about this Empolyee."<<endl;  //Print out all information about the user
                                cout<<"------------------------------------------------"<<endl;
                                blockchain.printChain(i-1);
                                blockchain.printChain(i);
                                blockchain.printChain(i+1);
                                flag = false;       //Set flag value to false once match the Patient_ID with blockchain ID
                                break;  //End for-loop
                            }else if(userInput == 2){   //if input is 2, print the only block information
                                cout<<"------------------------------------------------"<<endl;
                                cout<<"Employee Name: " + blockchain.chain[i-1].name<< endl;        //Print out the Employee Name help to check
                                blockchain.printChain(i);       //Print the block information
                                flag = false;   //Set flag value to false once match the Patient_ID with blockchain ID
                                break;  //End for-loop
                            }
                            userInput = 0;  //Resit the userInput value to continue the system
                        }
                        i=i+3;  //To make sure only check about the Patient id
                    }
                    if(flag == true){   //Use if-statement to check the flag value
                        cout<<"Sorry the Patient ID cannot be found in this blockchain."<<endl;     //Failed to find the block with Patient_ID in blockchain
                    }
                }
                break;
            case 4:
                //Find the employee information with Transaction ID
                cout<<"Please enter the Transaction ID"<<endl;
                flag = true;    //Set flag initial value as true
                empty = isBlockchainEmpty(blockchain);   //Set the initial value as return value of isBlockchainEmpty() function
                int Transaction_ID;
                cin >> Transaction_ID;  //Enter the Transaction_ID that user wanna check the information
                if(empty == false){     //Check whether the blockchain is empty or not, if not then continue the process, else through the error
                    for(int i=3; i<blockchain.chain.size();){    //Use for-loop to go through ID in the blockchain
                        if(blockchain.chain[i].ID == Transaction_ID){   //Use if-statement to check whether the input ID is same as blockchian ID
                            cout<< "If you want to all information about this employee press 1,or the information in this block please press 2."<<endl;
                            //External function from 'Checking.h' file, used to whether check the user input is validate or not
                            int userInput = Cheking();      // Declare an integer variable to store user input as the output of the checking function
                            // check if input if 1 then print all employee information
                            if(userInput == 1){
                                cout<< "There are all information about this Empolyee."<<endl;  //Print out all information about the user
                                cout<<"------------------------------------------------"<<endl;
                                blockchain.printChain(i-2);
                                blockchain.printChain(i-1);
                                blockchain.printChain(i);
                                flag = false;       //Set flag value to false once match the Employee_ID with blockchain ID
                                break;  //End for-loop
                            }else if(userInput == 2){   //if input is 2, print the only block information
                                cout<<"------------------------------------------------"<<endl;
                                cout<<"Employee Name: " + blockchain.chain[i-2].name<< endl;        //Print out the Employee Name help to check
                                blockchain.printChain(i);       //Print the block information
                                flag = false;       //Set flag value to false once match the Transaction_ID with blockchain ID
                                break;  //End for-loop
                            }
                            userInput = 0;  //Resit the userInput value to continue the system
                        }
                        i=i+3;  //To make sure only check about the patient id
                    }
                    if(flag == true){   //Use if-statement to check the flag value
                        cout<<"Sorry the Patient ID cannot be found in this blockchain."<<endl;     //Failed to find the block with Patient_ID in blockchain
                    }
                }
                break;
            case 5:
                //Find the Block information with Block Index number
                cout<< "Please enter the Block Index number:"<<endl;
                int Index;
                cin >> Index;       //get the index number that user want to search
                if(0<=Index && Index<=blockchain.chain.size()){ //check whether this block exists or not
                    blockchain.printChain(Index);       //Print the block information
                }else{
                    cout<<"Sorry the Block Index number is out of the range."<<endl;    //If the block index number is out of the range
                }
                break;
            case 6:
                //Delete the block in blockchain
                cout<<"Please enter the Block ID you want to delete"<<endl;
                int dele;
                cin>>dele;  //Get the index number which block user wanna delete
                blockchain.deleteBlock(dele);   //Delete the block in blockchain
                blockchain.printFullChain();    //Print the lastest blockchain without deleted block
                break;
            case 7:
                cout<<"Please enter the block ID that you want to edit"<<endl;
                int edit;
                cin >> edit;
                blockchain.printChain(edit);
                blockchain.editBlock(edit);
                cout << "Would you like to save the edition into the file?"<<endl;
                cout << "1. Yes"<<endl;
                cout<< "2. NO"<<endl;
                int userInput;
                userInput = Cheking();
                if (userInput == 1) {
                    blockchain.writeFile();
                }
                break;
            case 8:
                flag = true;    //Set flag initial value as true
                exists = false;
                empty = isBlockchainEmpty(blockchain);   //Set the initial value as return value of isBlockchainEmpty() function
                cout<<"Please enter the employee name or patient ID: "<<endl;
                cin.ignore();
                getline(cin, key);
                if(empty == false){     //Check whether the blockchain is empty or not, if not then continue the process, else through the error
                    for(int i=0; i<blockchain.chain.size();i++){    //Use for-loop to go through ID in the blockchain
                        if (key == to_string(blockchain.chain[i].ID) ) {
                            vector<string> substrings = splitString(blockchain.chain[i].disease, ',');
                            for (const string& substring : substrings) {
                                for (Disease& disease : rootDisease.affectedRegions) {
                                    if (areStringsEqualIgnoreCase(substring, disease.getName()) ){
                                        disease.displayDiseaseInfo();
                                        exists = true;
                                    }
                                }
                            }
                            substrings.clear();
                            flag = false;
                            break;
                        }
                        if (areStringsEqualIgnoreCase(key, blockchain.chain[i].name)) {
                            vector<string> substrings = splitString(blockchain.chain[i+1].disease, ',');
                            for (const string& substring : substrings) {
                                for (Disease& disease : rootDisease.affectedRegions) {
                                    if (areStringsEqualIgnoreCase(substring, disease.getName()) ){
                                        disease.displayDiseaseInfo();
                                        exists = true;
                                    }
                                }
                            }
                            substrings.clear();
                            flag = false;
                            break;
                        }
                    }
                    if(flag){   //Use if-statement to check the flag value
                        cout<<"Sorry the emplyee information cannot be found in this blockchain."<<endl;     //Failed to find the block with Patient_ID in blockchain
                    }
                    if (!exists && !flag) {
                        cout << "Diseases cannot be found in the file, please update the file asap."<<endl;
                    }
                }
                break;
            case 9:
                std::cout << "List of Diseases:" << std::endl;
                    for (Disease& disease : rootDisease.affectedRegions) {
                        disease.displayDiseaseInfo();
                        std::cout << "--------------------------" << std::endl;
                    }
                break;
            case 10:
                blockchain.writeFile();
                break;
            default:
                // If user presses the wrong number on the keyboard
                cout << "Please Press The Correct Number \n" << endl;
                break;
        }
        if (choice >= 1 && choice <= 10) {
                    cout << "Do you want to continue? Enter 1 to continue, or any other key to exit." << endl;
                    cin >> continuenum;
        }

    } while (continuenum == 1); //The conditional to continue the Do-While loop
    time(&end);     // Recording end time
        
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
    << time_taken<<"  sec " << endl;
    return 0;
}
