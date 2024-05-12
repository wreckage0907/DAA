#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void print(int i, int j, vector< vector<int> > brac, int& num) {
    if(i == j) {
        cout << "A" << num++;
        return;
    }
    cout << "(";
    print(i, brac[i][j], brac, num);
    cout << "*";
    print(brac[i][j] + 1, j, brac, num);
    cout << ")";
}

void mcm(vector<int>& arr) {
    int n = arr.size();
    vector< vector<int> > cost(n, vector<int>(n, 0));
    vector< vector<int> > brac(n, vector<int>(n, 0));
    for(int l=2; l<n; l++) {
        for(int i=1; i<n-l+1; i++) {
            int j = i+l-1;
            cost[i][j] = INT_MAX;
            for(int k=i; k<j; k++) {
                int temp = cost[i][k] + cost[k+1][j] + (arr[i-1] * arr[j] * arr[k]);
                if(temp < cost[i][j]) {
                    cost[i][j] = temp;
                    brac[i][j] = k;
                }
            }
        }
    }
    cout << cost[1][n-1] << endl;
    int num = 1;
    print(1, n-1, brac, num);
    cout << endl;
}

int main() {
    vector<int> nums = {40, 20, 30, 10, 30};
    mcm(nums);
}