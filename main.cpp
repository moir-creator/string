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

void output(char arr[], int size) {
    int i = 0;
    while (arr[i] != '\0' && i < size) {
        std::cout << arr[i];
        i++;
    }
    std::cout << std::endl;
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
    return 0;

}