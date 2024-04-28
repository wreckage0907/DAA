#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> permute_naive(string str) {
    if (str.length() == 1) {
        return {str};
    }
    else {
        vector<string> permutations;
        for (size_t i = 0; i < str.length(); ++i) {
            string remaining_chars = str;
            remaining_chars.erase(i, 1);
            auto sub_permutations = permute_naive(remaining_chars);
            for (const auto& sub_permutation : sub_permutations) {
                permutations.push_back(str[i] + sub_permutation);
            }
        }
        return permutations;
    }
}

int main() {
    string input_string = "ABC";
    vector<string> result = permute_naive(input_string);
    cout << "Permutations:" << endl;
    for (const auto& i : result) {
        cout << i << endl;
    }
    return 0;
}
