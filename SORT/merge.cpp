
#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> &arr, int l, int m, int h)
{
    int n = arr.size();
    vector<int> temp(n);
    int left = l;
    int right = m + 1;
    int k = l;
    while (left <= m && right <= h)
    {
        if (arr[left] < arr[right])
        {
            temp[k] = arr[left];
            left++;
        }
        else
        {
            temp[k] = arr[right];
            right++;
        }
        k++;
    }
    // for remaining elements left.
    while (left <= m)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }
    // for remaining elements on right.
    while (right <= h)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i];
    }
}
void mergesort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int m = (h + l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, h);
        Merge(arr, l, m, h);
    }
}
int main()
{
    vector<int> arr = {70, 0, 2, 5, 13, 1};
    mergesort(arr, 0, arr.size() - 1);
    for (int a : arr)
    {
        cout << a << " ";
    }
    return 0;
}