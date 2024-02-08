#include <iostream>
#include <chrono>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}



int InsertionSort3(int arr[], int n, int d)
{
    int x = -1;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == d)
        {
            x = i;
        }
    }
    return x;
}

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;

    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % n);
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    int temp=arr[0];
    InsertionSort3(arr, n, arr[0]);
    int position = InsertionSort3(arr, n, arr[0]);
    // quicksort(arr, 0, n - 1);
    // int position = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == temp)
    //     {
    //         position = i;
    //         break;
    //     }
    // }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    cout << "array position of " << temp << ": " << position << endl;
    cout << "Time taken: " << duration_ns.count() << " nanoseconds" << endl;

    return 0;
}
