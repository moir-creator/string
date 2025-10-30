#include <iostream>

int lenght(char arr[], int size) {
    int count = 0;
    for (int i = 0; arr[i] != '\0' && i < size; i++) {
        count++;
    }
    return count;
}


int main() {

    return 0;

}