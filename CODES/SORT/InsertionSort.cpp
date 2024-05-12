#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void insertionsort(vector<int>& nums) {
    for(int i=1; i<nums.size(); i++) {
        int key = nums[i]; 
        int j = i-1;
        while(j >= 0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}

int main() {
    vector<int> nums = {-1, 9, 2, -34, 12, 19, 34, 0, 91, 6};
    insertionsort(nums);
    for(int i : nums) {
        cout << i << " ";
    }
}