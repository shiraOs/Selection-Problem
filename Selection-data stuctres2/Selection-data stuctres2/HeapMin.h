#ifndef _HEAPMIN_H
#define _HEAPMIN_H

#include "Person.h"
#include <iostream>

using namespace std;

#pragma warning (disable:4996)

class Heap
{
private:
    Person* data;                     //Points to data array
    int maxSize;                      //Max size of heap
    int heapSize;                     //Current size of heap
    int allocated;                    //1 if heap allocated mamory
    static int Left(int node);
    static int Right(int node);
    static int Parent(int node);
    void FixHeap(int node, int& NumComp);
public:                     
    Heap(Person A[], int n);            //Turn A[] into heap
    ~Heap();
    bool IsEmpty();
    void makeEmpty(int max);            //Allocate memory
    Person Min();
    Person DeleteMin(int& NumComp);
    void Insert(Person& item);
};

#endif // !_HEAPMIN_H