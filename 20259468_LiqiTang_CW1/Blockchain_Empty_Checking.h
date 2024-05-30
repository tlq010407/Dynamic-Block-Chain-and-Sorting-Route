//
//  Blockchain_Empty_Checking.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/3/21.
//

#ifndef Blockchain_Empty_Checking_h
#define Blockchain_Empty_Checking_h

#include <stdexcept> // for std::runtime_error
#include <iostream>
#include "BLOCKCHAIN.hpp"


// This function takes a copy of a blockchain object as an argument
// and checks if it has less than 2 blocks, which would indicate that it's empty.

bool isBlockchainEmpty(Blockchain blockchain) {
    try {
        // If the blockchain has less than 2 blocks, it's considered empty.
        if (blockchain.chain.size() < 2) {
            // Throw a runtime error with a descriptive message.
            throw std::runtime_error("Blockchain is empty, please enter 1 to load the information");
        }
        // If the blockchain has 2 or more blocks, it's not empty.
        return false;
    }
    catch (const std::runtime_error& e) {
        // If an exception is caught, print the error message and return true to indicate that the blockchain is empty.
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return true;
    }
}


#endif /* Blockchain_Empty_Checking_h */
