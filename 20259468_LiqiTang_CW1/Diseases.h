//
//  Diseases.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/9/14.
//

#ifndef Diseases_h
#define Diseases_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Disease {
private:
    std::string name;
    std::string symptoms;
    std::string treatment;
public:
    std::vector<Disease> affectedRegions;
    // Constructors
    Disease() {
        name = "";
        symptoms = "";
        treatment = "";
    }
    
    // Getter and Setter methods
    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }
    
    void setSymptoms(std::string symptoms) {
        this->symptoms = symptoms;
    }

    std::string getSymptoms() const {
        return symptoms;
    }

    void setTreatment(std::string treatment) {
        this->treatment = treatment;
    }

    std::string getTreatment() const {
        return treatment;
    }

    // Method to display disease information
    void displayDiseaseInfo(){
        std::cout << "Disease Name: " << name << std::endl;
        std::cout << "Symptoms: " << symptoms << std::endl;
        std::cout << "Treatment: " << treatment << std::endl;
    }

    Disease(std::string name, std::string symptoms, std::string treatment) {
        this->name = name;
        this->symptoms = symptoms;
        this->treatment = treatment;
    }

    // Getter and Setter methods (same as in your code)

    // Method to add affected regions
    void addAffectedRegion( Disease& x) {
        affectedRegions.push_back(x);
    }

    // Method to display disease information (same as in your code)

    // Method to load diseases from a file
    void LoadDiseases(const std::string& filename) {
        std::string mystring;
        std::ifstream myfile(filename);

        if (myfile.is_open()) {
            std::string name, symptoms, treatment;

            while (getline(myfile, mystring)) {
                if (mystring == "---------------------------------------------------------") {
                    Disease x(name, symptoms, treatment);
                    addAffectedRegion(x);
                    name.clear();
                    symptoms.clear();
                    treatment.clear();
                } else {
                    name = mystring;
                    getline(myfile, symptoms);
                    getline(myfile, treatment);
                }
            }
            myfile.close();
        } else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }
    }
};
#endif /* Diseases_h */
