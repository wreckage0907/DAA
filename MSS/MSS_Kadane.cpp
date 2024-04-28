#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int start_ind = 0, end_ind = 0;

int mss(vector<int>& nums) {
    int curr = nums[0], sum = nums[0];
    int curr_start, curr_end;
    int max_len = 1, curr_len = 1;
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] > curr + nums[i]) {
            curr_start = i, curr_end = i;
            curr = nums[i];
            curr_len = 1;
        }
        else {
            curr_end = i;
            curr += nums[i];
            curr_len++;
        }
        if(curr > sum || (curr == sum && curr_len > max_len)) {
            start_ind = curr_start, end_ind = curr_end;
            sum = curr;
            max_len = curr_len;
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