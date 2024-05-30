//
//  SplitString.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/9/15.
//

#ifndef SplitString_h
#define SplitString_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::string> splitString(const std::string& inputString, char delimiter) {
    std::vector<std::string> substrings;

    // Split the input string by the specified delimiter
    std::istringstream iss(inputString);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        substrings.push_back(token);
    }

    return substrings;
}


bool areStringsEqualIgnoreCase(const std::string& str1, const std::string& str2) {
    // Convert both strings to lowercase before comparison
    std::string lowercaseStr1 = str1;
    std::string lowercaseStr2 = str2;
    
    // Transform to lowercase
    std::transform(lowercaseStr1.begin(), lowercaseStr1.end(), lowercaseStr1.begin(), ::tolower);
    std::transform(lowercaseStr2.begin(), lowercaseStr2.end(), lowercaseStr2.begin(), ::tolower);

    // Compare the lowercase strings
    return lowercaseStr1 == lowercaseStr2;
}

#endif /* SplitString_h */
