#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    int i = 0, j = 0, k = low;
    int left = mid - low + 1, right = high - mid;
    vector<int> leftarr(left), rightarr(right);
    for(int l = 0; l < left; l++) {
        leftarr[l] = nums[low + l];
    }
    for(int l = 0; l < right; l++) {
        rightarr[l] = nums[mid + 1 + l];
    }
    while(i < left && j < right) {
        if(leftarr[i] <= rightarr[j]) {
            nums[k] = leftarr[i];
            i++;
        }
        else {
            nums[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i < left) {
        nums[k] = leftarr[i];
        i++;
        k++;
    }
    while(j < right) {
        nums[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
}

int main() {
    vector<int> nums = {-1, 9, 2, -34, 12, 19, 34, 0, 91, 6};
    mergesort(nums, 0, nums.size()-1);
    for(int i : nums) {
        cout << i << " ";
    }
}