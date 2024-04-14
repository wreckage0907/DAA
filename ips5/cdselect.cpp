#include <iostream>
#include <vector>

using namespace std;

int minNumberOfCDs(vector<int>& songs, int M) {
    int n = 0;
    int cc = M;
    for (int i = 0; i < songs.size(); ++i) {
        if (songs[i] > M) {
            return -1; 
        }

        if (songs[i] > cc) {
            n++;
            cc = M; 
        }

        cc -= songs[i]; 
    }

    return n + 1; 
}

int main() {
    int n;
    cout << "Enter the number of songs: ";
    cin >> n;
    vector<int> songs(n);
    cout << "Enter the length of each song (in minutes): ";
    for (int i = 0; i < n; ++i) cin >> songs[i];
    
    int M;
    cout << "Enter the capacity of each CD (in minutes): ";
    cin >> M;
    int result = minNumberOfCDs(songs, M);
    if (result == -1) cout << "Error: There is a song longer than the CD capacity." << endl;
    else cout << "Minimum number of CDs required: " << result << endl;
    

    return 0;
}
