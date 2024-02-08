#include <iostream>
#include <cstdlib>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

int max3(int a, int b, int c) { return max(max(a, b), c); }

struct result {
    int l;
    int r;
    int s;
};

result crosssum(int arr[], int l, int m, int h) {
    int sum = 0;
    int leftSum = INT_MIN;
    int leftEnd = m;
    for (int i = m; i >= l; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            leftEnd = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int rightStart = m + 1;
    for (int i = m + 1; i <= h; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            rightStart = i;
        }
    }

    return {leftEnd, rightStart - 1, leftSum + rightSum};
}

result subarraysum(int arr[], int l, int h) {
    if (l == h) return {l, h, arr[l]};
    int m = (l + h) / 2;

    result lr = subarraysum(arr, l, m);
    result rr = subarraysum(arr, m + 1, h);
    result cr = crosssum(arr, l, m, h);

    if (lr.s >= rr.s && lr.s >= cr.s) return lr;
    else if (rr.s >= lr.s && rr.s >= cr.s) return rr;
    else return cr;
}

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

    // cout << "Start index: " << startIndex << endl;
    // cout << "End index: " << endIndex << endl;
    // cout << "Maximum sum: " << maxSum << endl;
}

int main() {
    high_resolution_clock::time_point start, end;
    duration<double> time_taken;

    int arr[9] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
    for(int i = 0; i < 9; i++) {
        int size = arr[i];
        int *num = new int[size];
        for(int j = 0; j < size; j++) 
            num[j] = rand() % size;

        start = high_resolution_clock::now();
        findMaxSubarray(num, size);
        end = high_resolution_clock::now();
        time_taken = duration_cast<duration<double>>(end - start);

        cout << "Time taken by Naive Approach for input size " << size << " : " << time_taken.count() << " seconds" << endl;

        delete[] num;
    }

    return 0;
}
