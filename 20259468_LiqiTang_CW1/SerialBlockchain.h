//
//  SerialBlockchain.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/9/15.
//

#ifndef SerialBlockchain_h
#define SerialBlockchain_h

#include <iostream>
#include <string>

std::string SerializeBlockPattern1(const Block& block) {
    std::string serializedBlock =
        "Block #" + std::to_string(block.index) + "\n" +
        "Timestamp: " + std::to_string(block.timestamp) + "\n" +
        "Employee ID: " + std::to_string(block.ID) + "\n" +
        "Name: " + block.name + "\n" +
        "Data: " + block.data + "\n" +
        "Previous Hash: " + block.previousHash + "\n" +
        "Hash: " + block.hash + "\n" +
        "---------------------------------------------------------" + "\n";
    return serializedBlock;
}

std::string SerializeBlockPattern2(const Block& block) {
    std::string serializedBlock =
        "Block #" + std::to_string(block.index) + "\n" +
        "Timestamp: " + std::to_string(block.timestamp) + "\n" +
        "Patient ID: " + std::to_string(block.ID) + "\n" +
        "Disease: " + block.disease + "\n" +
        "Data: " + block.data + "\n" +
        "Previous Hash: " + block.previousHash + "\n" +
        "Hash: " + block.hash + "\n" +
        "---------------------------------------------------------" + "\n";
    return serializedBlock;
}

std::string SerializeBlockPattern3(const Block& block) {
    std::string serializedBlock =
        "Block #" + std::to_string(block.index) + "\n" +
        "Timestamp: " + std::to_string(block.timestamp) + "\n" +
        "Transaction ID: " + std::to_string(block.ID) + "\n" +
        "Data: " + block.data + "\n" +
        "Previous Hash: " + block.previousHash + "\n" +
        "Hash: " + block.hash + "\n" +
        "---------------------------------------------------------" + "\n";
    return serializedBlock;
}

// Serialize a block to a string
std::string SerializeBlock(const Block& block) {
    if (block.index % 3 == 1) {
        // Serialize using Pattern 1: Basic Block Information
        return SerializeBlockPattern1(block);
    } else if (block.index % 3 == 2) {
        // Serialize using Pattern 2: Detailed Block Information
        return SerializeBlockPattern2(block);
    } else {
        // Serialize using Pattern 3: Compact Block Information
        return SerializeBlockPattern3(block);
    }
}

#endif /* SerialBlockchain_h */
