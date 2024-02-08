#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
using namespace std;

int PartitionFirst(int arr[], int low, int high) {
    int i = low - 1;
    int pivot = arr[high]; // Pivot - > end
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[low]);
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
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i - 1], arr[low]);
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
        std::swap(arr[i], arr[j]);
    }
}

void QuickSortRandom(int arr[], int low, int high) {
    if (low < high) {
        int p = PartitionRandom(arr, low, high);
        QuickSortRandom(arr, low, p - 1);
        QuickSortRandom(arr, p + 1, high);
    }
}

int main() {
    int num1[] = {3,12,19,23,35,43,45,51};
    int num2[] = {3,12,19,23,35,43,45,51};
    int num3[] = {3,12,19,23,35,43,45,51};
    int size = sizeof(num1) / sizeof(num1[0]);

    clock_t startFirst, endFirst;
    cout << "Array :";
    for (int j = 0; j < size; j++) cout << num1[j] << " ";
    cout << "\n";
    startFirst = clock();
    QuickSortFirst(num1, 0, size - 1);
    endFirst = clock();
    double timeTakenFirst = double(endFirst - startFirst) / CLOCKS_PER_SEC;
    cout << "Time taken by QuickSort with first pivot: " << timeTakenFirst << " seconds\n\n";

    clock_t startLast, endLast;
    cout << "Array :";
    for (int j = 0; j < size; j++) cout << num2[j] << " ";
    cout << "\n";
    startLast = clock();
    QuickSortLast(num2, 0, size - 1);
    endLast = clock();
    double timeTakenLast = double(endLast - startLast) / CLOCKS_PER_SEC;
    cout << "Time taken by QuickSort with last pivot: " << timeTakenLast << " seconds\n\n";

    clock_t startRandom, endRandom;
    cout << "Array :";
    for (int j = 0; j < size; j++) cout << num3[j] << " ";
    cout << "\n";
    startRandom = clock();
    QuickSortRandom(num3, 0, size - 1);
    endRandom = clock();
    double timeTakenRandom = double(endRandom - startRandom) / CLOCKS_PER_SEC;
    cout << "Time taken by QuickSort with random pivot: " << timeTakenRandom << " seconds\n\n";

    return 0;
}
