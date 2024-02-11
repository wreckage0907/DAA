#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct res {
    int l;
    int r;
    int s;
};

res maxSubarray(vector<int>& nums) {
    int n = nums.size();
    int max_sum = nums[0];
    int current_sum = nums[0];
    int start_index = 0;
    int end_index = 0;
    int temp_start_index = 0;

    for (int i = 1; i < n; ++i) {
        if (current_sum + nums[i] > nums[i]) {
            current_sum += nums[i];
        } else {
            current_sum = nums[i];
            temp_start_index = i;
        }

        if (current_sum > max_sum || (current_sum == max_sum && i - temp_start_index > end_index - start_index)) {
            max_sum = current_sum;
            start_index = temp_start_index;
            end_index = i;
        }
    }

    return {start_index, end_index, max_sum};
}

int main() {
    vector<int> nums = {4, -12, 3, 10, 4, 5, -30, 6, 7, 1, 3, 1, 4};

    high_resolution_clock::time_point start = high_resolution_clock::now();
    res result = maxSubarray(nums);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    duration<double> time_taken = duration_cast<duration<double>>(end - start);

    cout << "Start index: " << result.l << endl;
    cout << "End index: " << result.r << endl;
    cout << "Maximum sum: " << result.s << endl;
    cout << "Time taken: " << time_taken.count() << " seconds" << endl;

    cout << "Elements of the subarray: ";
    for (int i = result.l; i <= result.r; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
