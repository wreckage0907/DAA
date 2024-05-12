#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m, 0);
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            ++k;
        }
        pi[q] = k;
    }
    return pi;
}

vector<int> KMP(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = computePrefixFunction(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            result.push_back(i - m + 1);
            q = pi[q - 1];
        }
    }
    return result;
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";
    vector<int> result = KMP(text, pattern);
    if (result.empty()) {
        cout << "Pattern not found" << endl;
    }
    else {
        cout << "Pattern found at indices: ";
        for(int i=0; i<result.size(); i++) {
            cout << result[i] << " ";
        }
    }
}
