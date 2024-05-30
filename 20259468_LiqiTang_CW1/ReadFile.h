//
//  ReadFile.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/9/12.
//

#ifndef ReadFile_h
#define ReadFile_h
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "BLOCKCHAIN.hpp"
#include "convertTime.h"
using namespace std;

string mystring = "";

Blockchain readFile(){
    ifstream myfile("StoreBlock.txt");
    Blockchain Info;
    Block blocks;
    if ( myfile.is_open() ) {
        while ( myfile.good() ) {
            getline(myfile, mystring);
            if (mystring == "Timestamp:") {
                getline(myfile, mystring);
                time_t convertedTime = ConvertStringToTimeT(mystring);
                blocks.timestamp = convertedTime;
            } else if (mystring == "Employee ID:" || mystring == "Patient ID:" || mystring == "Transaction ID:"){
                if (mystring == "Patient ID:") {
                    getline(myfile, mystring);
                    blocks.ID = stoi(mystring);
                    getline(myfile, mystring);
                    if (mystring == "Sickness:") {
                        getline(myfile, mystring);
                        blocks.disease = mystring;
                    }
                    continue;
                }
                if (mystring == "Employee ID:") {
                    getline(myfile, mystring);
                    blocks.ID = stoi(mystring);
                    getline(myfile, mystring);
                    if (mystring == "Name:") {
                        getline(myfile, mystring);
                        blocks.name = mystring;
                    }
                    continue;
                }
                getline(myfile, mystring);
                blocks.ID = stoi(mystring);
            } else if (mystring == "---------------------------------------------------------"){
                Info.readBlock(blocks);
                blocks.disease = "";
                blocks.name = "";
            } else {
                blocks.data = mystring;
            }
        }
    }
    myfile.close();
    return Info;
}

void FileExists(){
    string filename = "StoreBlocks.txt";
    // Check if the file exists
    ifstream file(filename);
    if (file.good()) {
        cout << "File exists." << endl;
    } else {
        // If the file does not exist, create a new one
        ofstream newfile(filename);
        if (newfile.good()) {
            cout << "New file created." << endl;
        } else {
            cerr << "Error creating file." << endl;
        }
    }
}

#endif /* ReadFile_h */
