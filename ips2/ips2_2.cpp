#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

string toLowerCase(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> leftArr(arr.begin()+left, arr.begin()+left+n1);
    vector<string> rightArr(arr.begin()+mid+1, arr.begin()+mid+1+n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (toLowerCase(leftArr[i])<=toLowerCase(rightArr[j])) {
            arr[k++]=leftArr[i++];
        } else {
            arr[k++]=rightArr[j++];
        }
    }

    while (i<n1){
        arr[k++]=leftArr[i++];
    }

    while (j<n2){
        arr[k++]=rightArr[j++];
    }
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left<right) {
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    vector<string> words = {};
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY";
    string msg;
    srand(time(0));
    int length = rand()%12;
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        msg = ' ';
        for (int i = 0; i < length; ++i) {
                int index = std::rand() % charset.length();
                msg += charset[index];
        }
    words.push_back(msg);
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    mergeSort(words, 0, words.size()-1);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time taken for "<<n<<" words " << duration_ns.count() << " nanoseconds" << std::endl;
    return 0;
}