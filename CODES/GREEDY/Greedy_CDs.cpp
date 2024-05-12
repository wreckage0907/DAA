#include <iostream>
#include <vector>

using namespace std;

int minCdsRequired(vector<int>& songs, int n, int m) {
    int cds = 0;
    int currentCDCapacity = 0;
    for (int i = 0; i < n; ++i) {
        if (currentCDCapacity + songs[i] <= m) {
            currentCDCapacity += songs[i];
        } else {
            currentCDCapacity = songs[i];
            cds++;
        }
    }
    if (currentCDCapacity > 0) {
        cds++;
    }
    return cds;
}

int main() {
    int n = 6;
    vector<int> songs = {4, 6, 3, 2, 5, 4};
    int m = 10;
    int result = minCdsRequired(songs, n, m);
    cout << result << endl;
}
