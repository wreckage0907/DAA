#include <iostream>
#include <vector>

using namespace std;

void subsetSum(vector<int>& nums, int target, int index, vector<int>& currentSubset, vector< vector<int> >& result) {
    if(target == 0) {
        result.push_back(currentSubset);
    }
    for(int i = index; i < nums.size(); i++) {
        if(target - nums[i] >= 0) {
            currentSubset.push_back(nums[i]);
            subsetSum(nums, target - nums[i], i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
}

int main() {
    int n, temp, target;
    vector<int> nums, currentSubset;
    vector< vector<int> > result;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> target;
    subsetSum(nums, target, 0, currentSubset, result);
    if(result.empty()) {
        cout << "Solution does not exist" << endl;
    }
    else {
        for(int i=0; i<result.size(); i++) {
            cout << "[";
            for(int j=0; j<result[i].size(); j++) {
                cout << result[i][j];
                if(j != result[i].size()-1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }
}