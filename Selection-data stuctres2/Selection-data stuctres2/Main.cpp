#include "Selection.h"

//Shira Ostrinsky 311119002
//Alon Ben Harush 312533698
//The program gets from user n=amount of persons, and their details-id and name and num k.
//All ids MUST be different from each other, k value MUST be from 1 to n.
//The program print the id which is the k smallest from all the persons, according to their id.
//Also print the amount of comarisons from all three selection functions.

int main()
 {
    Person* arr = nullptr;
    int size, k;

    readArr(arr, size, k);
    runSelection(arr, size, k);
    
    delete[] arr;
}