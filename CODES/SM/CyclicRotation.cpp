#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> compute_prefix(string& pattern) {
    int m = pattern.length();
    vector<int> prefix(m);
    prefix[0] = 0;
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }
    return prefix;
}

bool kmp(string& text, string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix = compute_prefix(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            return true;
        }
    }
    return false;
}

bool cyclicRotation(string& text1, string& text2) {
    if (text1.length() != text2.length()) {
        return false;
    }
    string concatenated = text1 + text1;
    return kmp(concatenated, text2);
}

int main() {
    string text1 = "butter";
    string text2 = "utterb";
    cout << "T: " << text1 << endl;
    cout << "T': " << text2 << endl;
    if (cyclicRotation(text1, text2)) {
        cout << "Cyclic rotation" << endl;
    }
    else {
        cout << "Not a cyclic rotation" << endl;
    }
}