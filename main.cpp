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

void output(char arr[], int size) {
    int i = 0;
    while (arr[i] != '\0' && i < size) {
        std::cout << arr[i];
        i++;
    }
    std::cout << std::endl;
}

void fullControl(char arr[], int size) {
    int i = 0;
    for ( ; i < size; i++) {
        std::cout << "array{" << i << "] = " << arr[i] << " ";
    }
    std::cout << "TOTAL: " << i << "cells";
}
int main() {
    int sizeFirst = 10;
    int sizeSecond = 10;
    char* arrFirst = new char[sizeFirst];
    char* arrSecond = new char[sizeSecond];
    strcpy(arrFirst, "Visual ");
    strcpy(arrSecond, "comfort");

    //std::cout << length(arrFirst, sizeFirst);
    //std::cout << length(arrSecond, sizeSecond);
    output(arrFirst, sizeFirst);
    output(arrSecond, sizeSecond);
    std::cout << increase(arrFirst, sizeFirst) << std::endl;
    std::cout << sizeFirst << std::endl;
    fullControl(arrFirst, sizeFirst);

    return 0;

}