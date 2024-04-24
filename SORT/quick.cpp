#include <iostream>
#include <vector>

// for pivot as higher element
using namespace std;
int partition(vector<int> &arr, int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}
void quicksort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr, l, h);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, h);
    }
}
int main()
{
    vector<int> arr = {70, 0, 2, 5, 13, 1};
    quicksort(arr, 0, arr.size() - 1);
    for (int a : arr)
    {
        cout << a << " ";
    }
    return 0;
}