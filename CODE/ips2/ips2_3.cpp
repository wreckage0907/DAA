#include <iostream>
#include <chrono>
#include <string.h>
using namespace std;

void merge(int l[],int r[],int a[],int nol,int nor){
    int i=0,j=0,k=0;
    while(i<nol && j<nor){
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<nol){
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<nor){
        a[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int n){
    if(n<2){
        return ;
    }
    int mid=n/2;
    int *left=new int[mid];
    int *right=new int[n-mid];
    for(int i=0;i<mid;i++) left[i]=arr[i];
    for(int j=mid;j<n;j++) right[j-mid]=arr[j];
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(left,right,arr,mid,n-mid);
}

#define swap(a,b) a^=b,b^=a,a^=b
int partition(int* arr, int l, int r) {
    int p = arr[l];
    l--;
    r++;
    while (1) {
        do l++; while (arr[l] < p);
        do r--; while (arr[r] > p);
        if (l >= r) return r;
        swap(arr[l], arr[r]);
    }
} 

void quicksort(int *arr,int l,int r){
    if(l<r){
        int q=partition(arr,l,r);
        quicksort(arr,l,q);
        quicksort(arr,q+1,r);
    }
}

int main(){
    int n;
    cout << "Enter size of array: "
         << "\n";
    cin >> n;
    int arr[n],arr1[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i]=(rand() % n);
    }
    memcpy(arr1, arr, sizeof(arr));
    auto start_time = std::chrono::high_resolution_clock::now();
    mergesort(arr,n);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time taken for MergeSort " << duration_ns.count() << " nanoseconds" << std::endl;

    auto start_time_1 = std::chrono::high_resolution_clock::now();
    quicksort(arr1,0,n-1);
    auto end_time_1 = std::chrono::high_resolution_clock::now();
    auto duration_ns_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_1 - start_time_1);
    std::cout << "Time taken for InsertionSort " << duration_ns_1.count() << " nanoseconds" << std::endl;
    return 0;

}