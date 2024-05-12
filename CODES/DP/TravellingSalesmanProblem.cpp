#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int tsp(int pos, int visited, vector< vector<int> >& dist, vector< vector<int> >& dp) {
    int n = dist.size();
    if(visited == (1 << n) - 1) {
        return dist[pos][0];
    }
    if(dp[pos][visited] != -1) {
        return dp[pos][visited];
    }
    int mindist = INT_MAX;
    for(int i=0; i<n; i++){
        if(!(visited & (1 << i))) {
            mindist = min(mindist, dist[pos][i] + tsp(i, visited | (1 << i), dist, dp));
        }
    }
    return dp[pos][visited] = mindist;
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > dist(n, vector<int>(n));
    vector< vector<int> > dp(n, vector<int>(1 << n, -1));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dist[i][j];
        }
    }
    cout << tsp(0, 1, dist, dp);
}