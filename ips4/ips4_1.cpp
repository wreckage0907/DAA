#include <iostream>
#include <climits>
using namespace std;

void findMaxSubarray(int arr[], int n) {
    int maxSum = INT_MIN;
    int startIndex, endIndex;

    for (int i = 0; i < n; ++i) {
        int currentSum = 0;
        for (int j = i; j < n; ++j) {
            currentSum += arr[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    cout << "Start index: " << startIndex << endl;
    cout << "End index: " << endIndex << endl;
    cout << "Maximum sum: " << maxSum << endl;
}

int main() {
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMaxSubarray(arr, n);

    return 0;
}
