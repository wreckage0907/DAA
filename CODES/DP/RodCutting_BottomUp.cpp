#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        int maxProfit = INT_MIN;
        for (int j = 0; j < i; j++) {
            maxProfit = max(maxProfit, prices[j] + dp[i - j - 1]);
        }
        dp[i] = maxProfit;
    }
    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    cout << "Maximum obtainable value: " << rodCutting(prices, n) << endl;
}
