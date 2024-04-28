#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int start_ind = 0, end_ind = 0;

int mss(vector<int>& nums) {
    int sum = INT_MIN;
    for(int i=0; i<nums.size(); i++) {
        int temp = 0;
        for(int j=i+1; j<nums.size(); j++) {
            temp += nums[j];
            if(temp > sum) {
                sum = temp;
                start_ind = i + 1, end_ind = j;
            }
        }
    }
    return sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = mss(nums);
    cout << "Maximum subarray sum: " << max_sum << endl;
    cout << "Start index: " << start_ind << ", End index: " << end_ind << endl;
}