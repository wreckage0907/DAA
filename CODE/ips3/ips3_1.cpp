#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
using namespace std;

#define swap(a,b) a^=b,b^=a,a^=b

int PartitionFirst(int arr[], int low, int high) {
    int i = low - 1;
    int pivot = arr[high]; // Pivot - > end
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[low]);
    return i + 1;
}

void QuickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int p = PartitionFirst(arr, low, high);
        QuickSortFirst(arr, low, p - 1);
        QuickSortFirst(arr, p + 1, high);
    }
}

int PartitionLast(int arr[], int low, int high) {
    int i = high + 1;
    int pivot = arr[low]; // Pivot -> start
    for (int j = high; j > low; j--) {
        if (arr[j] > pivot) {
            i--;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i - 1], arr[low]);
    return i - 1;
}

void QuickSortLast(int arr[], int low, int high) {
    if (low < high) {
        int p = PartitionLast(arr, low, high);
        QuickSortLast(arr, low, p - 1);
        QuickSortLast(arr, p + 1, high);
    }
}



int PartitionRandom(int arr[], int low, int high) {
    int pivotIdx = low + rand() % (high - low + 1);
    int pivot = arr[pivotIdx]; // Random pivot
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void QuickSortRandom(int arr[], int low, int high) {
    if (low < high) {
        int p = PartitionRandom(arr, low, high);
        QuickSortRandom(arr, low, p - 1);
        QuickSortRandom(arr, p + 1, high);
    }
}

int main()
{
    clock_t start,end;
    int arr[9] = {10,50,100,500,1000,5000,10000,50000,100000};
    for(int i=0;i<9;i++){
        int size = arr[i];
        int *num=new int[size];
        for(int j=0;j<size;j++) num[j] = rand() % size;    
        start = clock();
        QuickSortFirst(num,0,size-1);
        end = clock();
        double Timetaken = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken by Quick Sort for input size " << size << " :" <<Timetaken << endl;}
}