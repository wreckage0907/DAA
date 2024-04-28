#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int rodCut(vector<int>& prices, int n, vector<int>& memo) {
    if (n <= 0) return 0;
    if (memo[n] != -1) return memo[n];
    int maxProfit = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, prices[i] + rodCut(prices, n - i - 1, memo));
    }
    memo[n] = maxProfit;
    return maxProfit;
}

int rodCutting(vector<int>& prices, int n) {
    vector<int> memo(n + 1, -1);
    return rodCut(prices, n, memo);
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    cout << "Maximum obtainable value: " << rodCutting(prices, n) << endl;
}
