#include "HeapMin.h"

//C'tor: convert an array which contains n persons into a heap.
//Idea: the persons in places n-1,...,n/2 are leaves.
//Build small heaps starting from leaves, and fix heaps while going towards the root.
Heap::Heap(Person A[], int n)
{
    heapSize = maxSize = n;
    int x = 0;
    data = A;                   //Assign array A to data pointer
    allocated = 0;              //Memory not allocated by heap

    for (int i = (n / 2) - 1; i >= 0; i--) //flyde
        FixHeap(i, x);
}

//D'tor: delete memory only if allocates by heap
Heap::~Heap()
{
    if (allocated)
        delete[] data;
    data = nullptr;
}

bool Heap::IsEmpty()
{
    return (this->heapSize == 0);
}

//C'tor: allocate memory for the heap and make the heap empty.
void Heap::makeEmpty(int max)
{
    data = new Person[max];
    maxSize = max;
    heapSize = 0;
    allocated = 1;
}

Person Heap::Min()
{
	return this->data[0];
}

//Delete minimum which is found in the root of heap, and fix heap.
Person Heap::DeleteMin(int& NumComp)
{
	if (heapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}

    Person min = data[0];
	heapSize--;
	data[0]=data[heapSize];
	FixHeap(0,NumComp);
	return (min);
}

//Add a new leaf for item, and swap upwards until item is in its correct position.
void Heap::Insert(Person& item)
{
    if (heapSize == maxSize)
    {
        cout << "Error: HEAP FULL\n";
        exit(1);
    }

    int i = heapSize;
    heapSize++;

    while ((i > 0) && (data[Parent(i)].getId() > item.getId()))
    {
        data[i] = data[Parent(i)];
        i = Parent(i);
    }
    data[i] = item;
}

//Private member functions of Heap class

int Heap::Parent(int node)
{
    return (node - 1) / 2;
}

int Heap::Left(int node)
{
    return (2 * node + 1);
}

int Heap::Right(int node)
{
    return (2 * node + 2);
}

void Heap::FixHeap(int node, int& NumComp)    //Fixes the heap that has node as root
{
    int min;
    int left = Left(node);
    int right = Right(node);

    //Find min among node, left and right.
    NumComp++;
    if ((left < heapSize) && (data[left].getId() < data[node].getId()))
        min = left;
    else
        min = node;
    NumComp++;
    if ((right < heapSize) && (data[right].getId() < data[min].getId()))
        min = right;

    //Swap values if neccessary, and continue fixing the heap towards the leaves.
    if (min != node)
    {
        std::swap(data[node], data[min]);
        FixHeap(min, NumComp);
    }
}