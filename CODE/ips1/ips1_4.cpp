#include <iostream>
#include <vector>

using namespace std;
void insertionsort(vector<int> &arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < 0 && arr[j] < temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        while (j >= 0 && arr[j] >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] =
            temp;
    }
}
int main()
{
    vector<int> sequence = {7, 3, -1, -8, -9, 20, 2, 4};
    int n = sequence.size();
    insertionsort(sequence, n);
    cout << "Sorted sequence: ";
    for (int i = 0; i < n; ++i)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
    return 0;
}