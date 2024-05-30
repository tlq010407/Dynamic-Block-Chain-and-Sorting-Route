//
//  BLOCK.hpp
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/3/19.
//

#ifndef BLOCK_hpp
#define BLOCK_hpp

#include <stdio.h>
#include <string>
#include <ctime>
#include "Diseases.h"

using namespace std;

// Define the data structure for a block
struct Block {
    int index;          // Index of the block in the chain
    time_t timestamp;   // Timestamp of when the block was created
    int ID;             // the number of employee/Patient/Transaction id
    string name = "";        // the employee name
    string disease;     // the diseases information
    string data;        // Data stored in the block (in our case, patient information)
    string previousHash;// Hash of the previous block in the chain
    string hash;        // Hash of the current block
};

#endif /* BLOCK_hpp */
