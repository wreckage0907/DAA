#include <iostream>
#include <vector>
using namespace std;
void insort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
        swap(arr[j + 1], key);
    }
}
int main()
{
    vector<int> v = {12, 11, 13, 5, 6};
    insort(v, v.size());
    for (int a : v)
    {
        cout << a << " ";
    }
    return 0;
}