//
//  convertTime.h
//  20259468_LiqiTang_CW1
//
//  Created by Liqi on 2023/9/12.
//

#ifndef convertTime_h
#define convertTime_h

#include <iostream>
#include <ctime>
#include <sstream>

time_t ConvertStringToTimeT(const std::string& dateTimeStr) {
    std::tm tmStruct = {};

    // Create a stringstream to parse the string
    std::istringstream ss(dateTimeStr);

    // Define a format string to match the input format
    // The format string must match the structure of the input string
    std::string format = "%a %b %d %H:%M:%S %Y";

    // Use std::get_time to parse the string into tmStruct
    ss >> std::get_time(&tmStruct, format.c_str());

    if (ss.fail()) {
        std::cerr << "Failed to parse the input string." << std::endl;
        return -1; // Return an error value
    }

    // Convert the tm struct to time_t
    time_t time = std::mktime(&tmStruct);

    if (time == -1) {
        std::cerr << "Failed to convert tm struct to time_t." << std::endl;
    }

    return time;
}

#endif /* convertTime_h */
