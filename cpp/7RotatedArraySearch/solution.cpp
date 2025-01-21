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

int binarySearch(vector<int>& arr, int target) {
  return binarySearch(arr, 0, arr.size() - 1, target);
}

int rotatedSortedArraySearch(vector<int>& arr, int start, int end, int target) {
  while (start <= end) {
    int mid = (start + end) / 2;
    if (target == arr[mid]) {
      return mid;
    }

    if (arr[mid] >= arr[start] && arr[mid] >= arr[end]) {
      if (arr[start] <= target && target <= arr[mid]) {
        return binarySearch(arr, start, mid - 1, target);
      } else {
        start = mid + 1;
      }
    } else {
      if (arr[mid] <= target && target <= arr[end]) {
        return binarySearch(arr, mid + 1, end, target);
      } else {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int rotatedSortedArraySearch(vector<int>& arr, int target) {
  return rotatedSortedArraySearch(arr, 0, arr.size() - 1, target);
}