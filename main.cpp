#include <array>
#include <iostream>
#include <string>
#include <cstring>

int length(char arr[], int size) {
    int count = 0;
    for (int i = 0; arr[i] != '\0' && i < size; i++) {
        count++;
    }
    return count;
}

int increase(char*& array, int& size) {
    int i = 0;
    int sizeIncrease = size*2;
    char* arrayNew = new char[sizeIncrease];
    for ( ; array[i] != '\0' && i < size; i++) {
        arrayNew[i] = array[i];
    }
    arrayNew[i] = '\0';
    size = sizeIncrease;
    delete[] array;
    array = arrayNew;
    return sizeIncrease;
}

void joinStrings(char*& strFirst, char*& strSecond, int& sizeFirst, int sizeSecond) {
    //checking incoming data
    if (strSecond == nullptr) {
        std::cout << "Error! " << strSecond << " is NULL." << std::endl;
        return;
    }
    if (strFirst == nullptr && strSecond == nullptr) {
        std::cout << "Error! The arrays are NULL!";
        return;
    }
    if (strFirst == nullptr) {
        strFirst = strSecond;
        return;
    }
    //count number of contains chars
    int lengthFirst = length(strFirst, sizeFirst);
    int lengthSecond = length(strSecond, sizeSecond);
    //chek the need to add new array
    if ((lengthFirst + lengthSecond) > sizeFirst-1) {
        //increase(strFirst, sizeFirst);
        sizeFirst = increase(strFirst, sizeFirst); /* or we can use recursion instead
        joinStrings(strFirst, strSecond, sizeFirst, sizeSecond); */
    }
    //define the end of arrFirst string
    int i = lengthFirst;
    //now copy strSecond to the end of strFirst string
    for (int j = 0; strSecond[j] != '\0' && j < sizeSecond; j++) {
        strFirst[i] = strSecond[j];
        i++;
    }
    strFirst[i] = '\0';
}

bool defineIdentity(char strFirst[], char strSecond[], int sizeFirst) {
    if (strFirst == nullptr || strSecond == nullptr) {
        return false;
    }
    int i = 0;
    for ( ; strFirst[i] != '\0' && strSecond[i] != '\0' && i < sizeFirst; ) {
        if (strFirst[i] == strSecond[i]) {
            i++;
        }
    }
    if (strFirst[i] == strSecond[i]) {
        std::cout << "The strings are identical!" << std::endl;
        return true;
    } else {
        std::cout << "The strings are NOT identical!" << std::endl;
        return false;
    }
}

void output(char arr[], int size) {
    int i = 0;
    while (arr[i] != '\0' && i < size) {
        std::cout << arr[i];
        i++;
    }
    std::cout << std::endl;
}

void fullControl(char arr[], int size) {
    std::cout << "CHECKING THE ARRAY: ";
    int i = 0;
    for ( ; i < size; i++) {
        if (arr[i] == '\0') {
            std::cout << "\\0 ";
        }
        std::cout << "array{" << i << "] = " << arr[i] << " ";
    }
    //std::cout << std::endl;
    std::cout << "TOTAL: " << i << "cells" << std::endl;
    //std::cout << "\033[H\033[H";
}
int main() {
    int sizeFirst = 10;
    int sizeSecond = 10;
    char* arrFirst = new char[sizeFirst];
    char* arrSecond = new char[sizeSecond];
    strcpy(arrFirst, "Visual");
    strcpy(arrSecond, "Visual");

    //std::cout << length(arrFirst, sizeFirst);
    //std::cout << length(arrSecond, sizeSecond);
    output(arrFirst, sizeFirst);
    output(arrSecond, sizeSecond);
    defineIdentity(arrFirst, arrSecond, sizeFirst);
    //joinStrings(arrFirst, arrSecond, sizeFirst, sizeSecond);
    //std::cout << increase(arrFirst, sizeFirst) << std::endl;
    //std::cout << sizeFirst << std::endl;
    //output(arrFirst, sizeFirst);
    //fullControl(arrFirst, sizeFirst);

    return 0;

}