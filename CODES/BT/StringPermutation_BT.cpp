#include <iostream>
#include <algorithm>

using namespace std;

void permutation(string& str, int l, int r) {
    if(l == r) {
        cout << str << endl;
    }
    else {
        for(int i=l; i<=r; i++) {
            swap(str[l], str[i]);
            permutation(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}

int main() {
    string s = "ABC";
    permutation(s, 0, s.length()-1);
}