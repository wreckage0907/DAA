#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int maximum(int a, int b, int c) {
    return max((max(a, b)), c);
}

int maxCrossingSum(vector<int>& nums, int low, int high, int mid, int& start_ind, int& end_ind) {
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN, temp_start, temp_end;
    for(int i=mid; i>=low; i--) {
        sum += nums[i];
        if(sum > left_sum) {
            temp_start = i;
            left_sum = sum;
        }
    }
    sum = 0;
    for(int i=mid; i<=high; i++) {
        sum += nums[i];
        if(sum > right_sum) {
            temp_end = i;
            right_sum = sum;
        }
    }
    start_ind = temp_start, end_ind = temp_end;
    return maximum(left_sum + right_sum - nums[mid], left_sum, right_sum);
}

int mss(vector<int>& nums, int low, int high, int& start_ind, int& end_ind) {
    int left_start, left_end, right_start, right_end;
    if(low > high) {
        return INT_MIN;
    }
    if(low == high) {
        start_ind = low, end_ind = high;
        return nums[low];
    }
    int mid = low + (high - low) / 2;
    int left_sum = mss(nums, low, mid - 1, left_start, left_end);
    int right_sum = mss(nums, mid + 1, high, right_start, right_end);
    int crossSum = maxCrossingSum(nums, low, high, mid, start_ind, end_ind);
    if(left_sum >= right_sum && left_sum >= crossSum) {
        start_ind = left_start, end_ind = left_end;
        return left_sum;
    }
    else if(right_sum >= left_sum && right_sum >= crossSum) {
        start_ind = right_start, end_ind = right_end;
        return right_sum;
    }
    else {
        return crossSum;
    }
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int start_ind, end_ind;
    int max_sum = mss(nums, 0, nums.size() - 1, start_ind, end_ind);
    cout << "Maximum subarray sum: " << max_sum << endl;
    cout << "Start index: " << start_ind << ", End index: " << end_ind << endl;
}
