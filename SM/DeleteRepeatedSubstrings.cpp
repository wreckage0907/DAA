#include <iostream> 
#include <string> 

using namespace std;

int delSubstr(string& s) {
    int deletions = 0;
    int i = 0;
    while (i < s.length() - 3) {
        if (i + 3 < s.length() && s.substr(i, 3) == s.substr(i + 3, 3)) {
            s.erase(i, 3);
            deletions++;
            i = max(0, i - 3);
        }
        else {
            i++;
        }
    }
    return deletions;
}

int main() {
    string s = "abcabcabcdabcabc";
    int numDeletions = delSubstr(s);
    cout << "Number of deletions: " << numDeletions << endl;
    cout << "Remaining String: " << s << endl; 
    return 0;
}
