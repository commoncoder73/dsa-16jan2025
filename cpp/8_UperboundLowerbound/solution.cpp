#include <bits/stdc++.h>

using namespace std;

int lowerBoundInSortedArray(vector<int&> arr, int k) {
  int start = 0;
  int end = arr.size() - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (k <= arr[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

int upperBoundInSortedArray(vector<int&> arr, int k) {
  int start = 0;
  int end = arr.size() - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (k < arr[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
}