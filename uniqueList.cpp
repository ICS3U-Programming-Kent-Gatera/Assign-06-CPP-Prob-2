// Copyright (c) 2022 Kent Gatera All rights reserved.
// .
// Created by: Kent Gatera
// Date: Dec 20, 2022
// This program checks a list for duplicates
// removes them and displays the new list.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> removeSimilarities
(std::vector<std::string> listSimilar) {
    std::vector<std::string> listWithNoSimilarities;
    /* This code block iterates over every element in the list, uses find() in the range ".begin() to .end()"
    and compares it to .end() since when the if finds something it returns its iterator but when it does not
    it returns .end().*/
    for (std::string elem : listSimilar) {
        if (std::find(listWithNoSimilarities.begin(),
        listWithNoSimilarities.end(), elem)
        == listWithNoSimilarities.end()) {
            listWithNoSimilarities.push_back(elem);
        }
    }
    return listWithNoSimilarities;
}

int main() {
    std::vector<std::string> cleanList;
    std::vector<std::string> badList;
    std::string tempV;
    std::string userInput;
    char commaChecker;
    std::cout << "Enter a comma-separated list of elements: ";
    std::getline(std::cin, userInput);
    // For every character in the user inputted list,
    // if it is not a comma, the program adds it to a string.
    for (const char& commaChecker : userInput) {
        if (commaChecker != ',') {
            tempV += commaChecker;
            // When the program encounters a comma,
            // meaning the end of the element, the string is added to the list.
        } else {
            badList.push_back(tempV);
            tempV.clear();
        }
    }
    cleanList = removeSimilarities(badList);
    // Printing the output.
    printf("The list after removing all duplicates is: ");
    int cleanListSize = cleanList.size();
    if (cleanListSize != 0) {
        std::cout << "[ " << cleanList[0];
        for (int displayCounter = 1;
        displayCounter < cleanListSize; displayCounter++) {
            std::cout << ", " << cleanList[displayCounter];
        }
        std::cout << " ]";
    }
}
