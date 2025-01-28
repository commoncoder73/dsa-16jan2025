#include <bits/stdc++.h>

using namespace std;

int sqrt(int n) {
  int start = 0;
  int end = n;
  while (start <= end) {
    int mid = (start + end) / 2;
    int currentSquare = mid * mid;
    if (currentSquare <= n) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  if (start * start == n) return start;
  return start - 1;
}