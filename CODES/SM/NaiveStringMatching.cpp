#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> naiveStringMatching(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        bool match = true;
        for (int j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    string text = "AABAACAADAABAABA”";
    string pattern = "AABA";
    vector<int> result = naiveStringMatching(text, pattern);
    if(result.empty()) {
        cout << "Pattern not found" << endl;
    }
    else {
        cout << "Pattern found at indices: ";
        for(int i=0; i<result.size(); i++) {
            cout << result[i] << " ";
        }
    }
}
