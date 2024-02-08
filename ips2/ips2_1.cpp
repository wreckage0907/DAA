#include <iostream>
using namespace std;

template <typename T>
void merge(T l[], T r[], T a[], int nol, int nor) {
    int i = 0, j = 0, k = 0;
    while (i < nol && j < nor) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < nol) {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < nor) {
        a[k] = r[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], int n) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    T *left = new T[mid];
    T *right = new T[n - mid];
    for (int i = 0; i < mid; i++) left[i] = arr[i];
    for (int j = mid; j < n; j++) right[j - mid] = arr[j];
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, right, arr, mid, n - mid);
}

int main() {
    int n=6;
    int arrInt[n] = {0,1,2,3,4,5};
    double arrDouble[n] = {5, 5.5, 6, 3.723, 1.23, 8.88};
    mergeSort(arrInt, n);
    mergeSort(arrDouble, n);
    cout << "Sorted integers: ";
    for (int i = 0; i < n; i++) cout << arrInt[i] << " ";
    cout << endl;
    cout << "Sorted doubles: ";
    for (int i = 0; i < n; i++) cout << arrDouble[i] << " ";
    cout << endl;
    return 0;
}
