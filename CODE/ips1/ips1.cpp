#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
using namespace std;

void isort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while ((j >= 0) && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> arr;
    int n;
    cout << "Enter size of array: "
         << "\n";
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % n);
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    isort(arr);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time taken: " << duration_ns.count() << " nanoseconds" << std::endl;
    return 0;
}