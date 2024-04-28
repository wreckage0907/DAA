#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int hashFn(string str) {
    int hash = 0;
    for(int i=0; i<str.length(); i++) {
        hash = hash * 52 + (str[i] - 'a' + 1);
    }
    return hash;
}

vector<int> rabinKarp(string text, string pattern) {
    vector<int> result;

    int hash_pattern = hashFn(pattern);
    int len_text = text.length(), len_patt = pattern.length();

    for(int i=0; i<len_text-len_patt+1; i++) {
        string substring = text.substr(i, len_patt);
        int hash_substr = hashFn(substring);

        if(hash_substr == hash_pattern && pattern == substring) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    string text = "AABAACAADAABAABA”";
    string pattern = "AABA";
    vector<int> result = rabinKarp(text, pattern);
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