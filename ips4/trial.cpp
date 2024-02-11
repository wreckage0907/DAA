#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
using namespace std;
int start_ind = 0, end_ind = 0;
int mss(vector<int> &nums)
{
    int sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            temp += nums[j];
            if (temp > sum)
            {
                sum = temp;
                start_ind = i + 1, end_ind = j;
            }
        }
    }
    return sum;
}
int main()
{
    int n = 16, temp;
    vector<int> nums={4, -12, 3, 10, 4, 5, -30, 6, 7, 1, 3, 1, 4};
    clock_t tstart = clock();
    int ans = mss(nums);
    double time = (double)(clock() - tstart) /
                  CLOCKS_PER_SEC;
    cout << "Elements of the subarray whose sum is maximum : ";
    for (int i = start_ind; i <= end_ind; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Start Index: " << start_ind << endl;
    cout << "End Index: " << end_ind << endl;
    cout << "Maximum Sum: " << ans << endl;
    cout << "Time Taken: " << time << endl;
}