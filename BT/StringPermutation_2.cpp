/*
Problem:

Given a string consisting of digits from 2 to 9, develop an algorithm that generates and returns a list of all possible letter combinations, where each digit maps to a set of letters like an old-style phone keypad (e.g., 2 maps to 'a', 'b', 'c'). For example, the string "23" should return the list ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]. Provide the code in C++, explain the logic, and analyze the time complexity of your solution.
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void bt(const string& digits, int index, string current, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }
    string letters = mp[digits[index]];
    for (char letter : letters) bt(digits, index + 1, current + letter, result);
    
}
    
int main() {
    string digits = "234";
    vector<string> result;
    bt(digits, 0, "", result);
    cout << "Letter combinations for " << digits << ": " << endl;
    for (const string& c : result) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}