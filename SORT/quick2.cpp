// for pivot as lower element
#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    for (int j = l + 1; j <= h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[l]);
    return i;
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