#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

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

int main() {
    int n;
    cin >> n;
    int arr[]={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; // Taking input for the array elements
    result res = subarraysum(arr, 0, n - 1);
    for (int i = res.l; i <= res.r; i++) cout << arr[i] << " ";
    cout << "\n" << res.l << "\n" << res.r << "\n" << res.s;

    return 0;
}
