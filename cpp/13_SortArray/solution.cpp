#include <bits/stdc++.h>

using namespace std;

void swapMaxTillEnd(vector<int>& arr, int i, int n) {
    if (i >= n - 1) {
        return;
    }
    if (arr[i] > arr[i+1]){
        swap(arr[i], arr[i+1]);
    }
    swapMaxTillEnd(arr, i+1, n);
}

void sort(vector<int>& arr, int n) {
    if (n <= 1) {
        return;
    }
    swapMaxTillEnd(arr, 0, n);
    sort(arr, n-1);

}

void sort(vector<int>& arr) {
    sort(arr, arr.size());
}