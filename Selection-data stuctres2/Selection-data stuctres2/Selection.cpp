#include "Selection.h"

int Partition(Person A[], int left, int right, int& NumComp)
{
    int pivot = A[left].getId();

    while (left != right)
    {
        NumComp++;
        if (A[left].getId() > A[right].getId())
            std::swap(A[left], A[right]);
        if (pivot == A[left].getId())
            right--;
        else // Pivot == arr[right]
            left++;
    }
    return left;
}

const Person RandSelection(Person A[], int left, int right, int k, int& NumComp)
{//size = n
 //T(n) = T(n-pivot) + T(pivot-1) + teta(n)
 //T(1) = 1
    int pivot, leftpart;

    if (left != right)      //teta(1)
    {
        srand((unsigned)time(nullptr));
        int i = (((rand()) % (right -left + 1)) + left);

        std::swap(A[i], A[left]);
    }

    pivot = Partition(A, left, right, NumComp);   //teta(n)

    leftpart = pivot - left + 1;    //teta(1)

    if (k == leftpart)
        return A[pivot];            //teta(1) 
    if (k < leftpart)
        return RandSelection(A, left, pivot - 1, k, NumComp);       //T(pivot-1)
    else
        return RandSelection(A, pivot + 1, right, k - leftpart, NumComp);   //T(n-pivot)

    //Tworst(n) = Tworst(n-1) + Tworst(0) + teta(n) = teta(n^2). worst case - pivot=0.
    //Taverage(n) = teta(n). Upper bound=Tworst=omega(n^2), Lower bound=O(n), average when prob(pivot=i)=1/size
}

const Person selectHeap(Person arr[], int size, int k, int& NumComp)
{//size = n
    Heap MinHeap(arr, size); //teta(n)
    Person res;
    
    for (int i = 0; i < k; i++)                 //teta(k)
           res = MinHeap.DeleteMin(NumComp);    //teta(logn)
                     
    return (res);    
    //Tworst(n)=teta(n+klogn)=teta(nlogn). worst case k=n
    //Taverage(n)=teta(n). 
    //sigma(i=1 until n):prob(k=i) * i = sigma(i=1 until n):(1/n) * i = (1/n)*sigma(i=1 until n):i = (1/n)*(n^2) = n
}

const Person BST(Person arr[], int size, int k, int& NumComp)
{//size = n
    BSTree newtree(nullptr);        //teta(1)
    int num = k;                    //teta(1)
    
    for (int i = 0; i < size; i++)                                      //teta(n)
        newtree.Insert(arr[i].getId(), arr[i].getname(),NumComp);       //teta(h)+teta(1)+teta(1)=teta(h)

    Person res;
    newtree.getroot()->FindkNumber(num, NumComp, res);                  //teta(h)

    return (res);
    //Tworst(n)=n*n+n=teta(n^2). worst case h = n.
    //Taverage(n)=n*logn+logn=teta(nlogn). average case h=logn 
}

void runSelection(Person arr[], int size, int k)
{
    Person* arr1 = new Person[size];
    Person* arr2 = new Person[size];
    int NumCompR = 0, NumCompH = 0, NumCompBST = 0;

    for (int i = 0; i < size; i++)
    {
        arr1[i].setId(arr[i].getId());
        arr2[i].setId(arr[i].getId());
        arr1[i].setName(arr[i].getname());
        arr2[i].setName(arr[i].getname());
    }

    const Person rselect = RandSelection(arr, 0, size - 1, k, NumCompR);
    const Person hselect = selectHeap(arr1, size, k, NumCompH);
    const Person Bselect = BST(arr2, size, k, NumCompBST);

    cout << hselect.getId() << " " << hselect.getname() << endl;
    cout << "RandSelection: " << NumCompR << " comparisons" << endl << endl;
    cout << "selectHeap: " << NumCompH << " comparisons" << endl << endl;
    cout << "BST: " << NumCompBST << " comparisons";

    delete[] arr1;
    delete[] arr2;
}

void readArr(Person*& arr, int& size, int& k)
{
    int id;
    char name[MAX_SIZE];

    cout << "Enter num of persons: ";
    cin >> size;
    arr = new Person[size];
    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter person's details: first ID and then Name (max length is 20)\n";
        cin >> id;

        for (int j = 0; j < i; j++)
            if (id == arr[j].getId())
            {               
                cout << "invalid input";
                exit(1);
            }

        cin.ignore();
        cin.getline(name, MAX_SIZE);
        arr[i].setId(id);
        arr[i].setName(name);
    }

    cout << "Enter Value to search: (bewteen 1 to " << size << " )";
    cin >> k;
    cout << endl;
    if (k <= 0 || k > size)
    {
        cout << "invalid input";
        exit(1);
    }
}