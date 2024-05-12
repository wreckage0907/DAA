#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int pivot(vector<int>& nums, int low, int high) {
    int pi = nums[high];
    int j = low - 1;
    for(int i=low; i<high; i++) {
        if(nums[i] <= pi) {
            j++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[j+1], nums[high]);
    return (j+1);
}

void quicksort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int pi = pivot(nums, low, high);
        quicksort(nums, low, pi-1);
        quicksort(nums, pi+1, high);
    }
}

int main() {
    vector<int> nums = {-1, 9, 2, -34, 12, 19, 34, 0, 91, 6};
    quicksort(nums, 0, nums.size()-1);
    for(int i : nums) {
        cout << i << " ";
    }
}