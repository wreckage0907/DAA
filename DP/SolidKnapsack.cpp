#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int knapsack(int cap, vector<int>& weight, vector<int>& profit, int n) {
    vector< vector<int> > dp(n+1, vector<int> (cap));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=cap; j++) {
            if((i == 0) || (j == 0)) {
                dp[i][j] = 0;
            }
            else if(weight[i-1] <= cap){
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i-1][j - weight[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][cap];
}

int main() {
    int n, temp, cap;
    cin >> n;
    vector<int> weight(n);
    vector<int> prof(n);
    for(int i=0; i<n; i++) {
        cin >> temp;
        weight[i] = temp;
    }    
    for(int i=0; i<n; i++) {
        cin >> temp;
        prof[i] = temp;
    }
    cin >> cap;
    cout << knapsack(cap, weight, prof, n);
}