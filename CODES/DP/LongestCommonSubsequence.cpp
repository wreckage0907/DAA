#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector< vector<int> > dp(m+1, vector<int> (n+1, 0));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
}