#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int, string> longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcsLength = dp[m][n];
    string lcs;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs.push_back(text1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    return {lcsLength, lcs};
}

int main() {
    string text1 = "AGGTAB";
    string text2 = "GXTXAYB";

    pair<int, string> result = longestCommonSubsequence(text1, text2);
    int lcsLength = result.first;
    string lcs = result.second;

    cout << "Length of LCS: " << lcsLength << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}
