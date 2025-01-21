#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& arr, int start, int end, int target) {
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {  // target < arr[mid]
      end = mid - 1;
    }
  }
  return -1;
}

int infiniteBinarySearch(vector<int>& arr, int target) {
  int start = 0;
  int end = 1;
  while (true) {
    if (target <= arr[end]) {
      return binarySearch(arr, start, end, target);
    }
    start = end + 1;
    end *= 2;
  }
}