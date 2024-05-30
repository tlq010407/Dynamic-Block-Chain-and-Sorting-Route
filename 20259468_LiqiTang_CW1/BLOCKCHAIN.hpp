//
//  BLOCKCHAIN.hpp
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/3/19.
//

#ifndef BLOCKCHAIN_hpp
#define BLOCKCHAIN_hpp

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "BLOCK.hpp"
#include "SerialBlockchain.h"

using namespace std;

// Define the blockchain data structure
class Blockchain {
public:
    vector<Block> chain;    // Vector to store the blocks in the chain
    // Define a blockchain as a vector of blocks
    using blockchain = std::vector<Block>;
    // Constructor
    Blockchain() {
        Block genesis = createGenesisBlock();   // Create the first block in the chain (genesis block)
        chain.push_back(genesis);               // Add the genesis block to the chain
    }
     
    // Function to add a new block to the blockchain
    void addBlock(int ID, string name, string disease, string data) {
        int index = int(chain.size());                       // Get the index of the new block (which is the size of the chain)
        string previousHash = getPreviousHash();        // Get the hash of the previous block in the chain
        string hash = calculateHash(index, data, previousHash);  // Calculate the hash of the new block
        Block newBlock = {index, time(NULL),ID, name, disease, data, previousHash, hash};  // Create the new block using the calculated hash
        chain.push_back(newBlock);                      // Add the new block to the chain
    }
    
    //Function to load the exits blocks from the file to the blockchain
    void readBlock(Block newBlock){
        int index = int(chain.size());  // Get the index of the new block (which is the size of the chain)
        newBlock.index = index;     //Assing the index number to the block
        string previousHash = getPreviousHash();        // Get the hash of the previous block in the chain
        string hash = calculateHash(index, newBlock.data, previousHash);  // Calculate the hash of the new block
        newBlock.hash = hash;
        newBlock.previousHash = previousHash;
        chain.push_back(newBlock);                      // Add the new block to the chain
    }
    
    //Function to edit the block content
    void editBlock(int edit){
        cout << "What would you like to edit?" << endl;
        cout << "1. ID number" << endl;
        cout << "2. Data Content" << endl;
        int userInput = Cheking();
        if (userInput == 1) {
            cout << "Please enter the corrent ID number: " << endl;
            cin >> chain[edit].ID;
            cout << "The ID is edited successfully."<<endl;
        }else if (userInput == 2){
            cout << "Please enter the corrent data: "<<endl;
            cin >> chain[edit].data;
            cout << "The content is edited successfully."<<endl;
        }else{
            cout << "It is unsuccessful to edit the block."<<endl;
        }
        chain[edit].timestamp = time(NULL);
        printChain(edit);
    }
    /**
     * Deletes a block from the blockchain at the specified index.
     *
     * @param blockIndex the index of the block to be deleted
     */
    void deleteBlock(int blockIndex) {
        // Use if statement check if the chain is empty
        if (chain.empty()) {
            cout << "The chain is empty, cannot delete a block." << endl;      //if the chain is empty, return "The chain is empty, cannot delete a block."
            return;
        }

        // Use if statement check if the block index is valid
        if (blockIndex < 0 || blockIndex > chain.size()) {
            cout << "Invalid block index, cannot delete block." << endl;    //if the index is invalid, return "Invalid block index, cannot delete block."
            return;
        }

        // Remove the block at the specified index
        chain.erase(chain.begin() + blockIndex);
        cout << "Block #" << blockIndex << " deleted." << endl;

        // Recalculate hashes for remaining blocks in the chain
        for (int i = blockIndex; i < chain.size(); i++) {
            chain[i].index = i + 1;     //increase the index by 1, since we deleted one block
            if (i == 0) {
                chain[i].previousHash = "0";       //keep the first block hash number 0
            } else {
                chain[i].previousHash = chain[i-1].hash;    //move the hash to previous one
            }
            chain[i].hash = calculateHash(chain[i].index, chain[i].data, chain[i].previousHash); //recalculate the hash for each block
        }
    }
    
    // Function to print part of blockchain
    void printChain(int i) {
        cout << "Block #" << chain[i].index << endl;     // Print the block index
        cout << "Timestamp: " << ctime(&chain[i].timestamp); // Print the block timestamp
        //use if statement to assign the name of the ID
        if(i%3 == 1){
            cout<<"Employee ID: "<<chain[i].ID<<endl;   //Print the Employee ID
            cout<<"Name: "<<chain[i].name<<endl;       //Print the name
        }else if(i%3 == 2){
            cout<<"Patient ID: "<<chain[i].ID <<endl;   //Print the Patient ID
            cout << "Diseases: " << chain[i].disease << endl;
        }else if(i%3 == 0){
            cout<<"Transaction ID: "<<chain[i].ID << endl;  //Print the Transaction ID
        }
        cout << chain[i].data << endl;      // Print the block data (patient information)
        cout << "Previous Hash: " << chain[i].previousHash << endl; // Print the hash of the previous block in the chain
        cout << "Hash: " << chain[i].hash << endl << endl; // Print the hash of the current block
        cout << "---------------------------------------------------------" <<endl;
    }
    
    // Function to print the entire blockchain
    void printFullChain() {
        for (int i = 0; i < chain.size(); i++) {         // Loop through each block in the chain
            printChain(i); // Evoke the printChian function to print full blockchian
        }
    }

    // Serialize the entire blockchain to a string
    std::string SerializeBlockchain() {
        std::string serializedBlockchain;
        for (const Block& block : chain) {
            serializedBlockchain += SerializeBlock(block);
        }
        return serializedBlockchain;
    }
    
    void writeFile () {
        std::string serializedBlockchain = SerializeBlockchain();
        
        // Write the serialized blockchain to a file
        std::ofstream outputFile("outputBlocks.txt");
        if (outputFile.is_open()) {
            outputFile << serializedBlockchain;
            outputFile.close();
            std::cout << "Blockchain written to 'outputBlocks.txt'" << std::endl;
        } else {
            std::cerr << "Failed to open the file for writing." << std::endl;
        }
        // Close the file
        outputFile.close();
    }
    
private:
    // Function to create the genesis block (the first block in the chain)
    Block createGenesisBlock() {
        Disease D1;
        D1.setName("none");
        Block genesis = {0, time(NULL), 0, "Genesis Block", D1.getName(), "0", "0"};    // Create the genesis block with default values
        return genesis;     // Return the genesis block
    }
    
    // Function to calculate the hash of a block
    string calculateHash(int index, string data, string previousHash) {
        string str = to_string(index) + data + previousHash;   // Concatenate the index, data, and previous hash into a single string
        char hash[32];      // Create a character array to store the hash (in this case, a 32-byte hash)
        for (int i = 0; i < str.length(); i++) {               // Loop through each character in the concatenated string
            hash[i % 32] ^= str[i];     // XOR the current character with the corresponding character in the hash array
        }
        return string(hash, hash+32);   // Convert the hash array back into a string and return it
    }
    // Function to get the hash of the most recent block in the chain
    string getPreviousHash() {
        return chain.back().hash;      //return previous hash block
    }
};
#endif /* BLOCKCHAIN_hpp */
