#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort_c1(vector<char>& symbols) {
    int n = symbols.size();
    for (int i = 1; i < n; i++) {
        char key = symbols[i];
        int j = i - 1;
        while (j >= 0 && symbols[j] > key) {
            symbols[j + 1] = symbols[j];
            j = j - 1;
        }
        symbols[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<char> symbols;
    for (int i = 0; i < n; i++) {
        symbols.push_back('a' + rand() % 26); 
    }
    auto start_time_c1 = chrono::high_resolution_clock::now();
    insertionSort_c1(symbols);
    // sort(symbols.begin(), symbols.end());
    auto end_time_c1 = chrono::high_resolution_clock::now();
    auto duration_c1 = chrono::duration_cast<chrono::nanoseconds>(end_time_c1 - start_time_c1);
    cout << "Time taken by c1: " << duration_c1.count() << " nanoseconds" << endl;
    return 0;
}
