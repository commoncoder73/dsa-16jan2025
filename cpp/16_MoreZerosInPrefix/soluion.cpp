#include <bits/stdc++.h>

using namespace std;

int countFormations(int n, int zeros, int ones) {
  if (n <= 1) {
    return 1;
  }

  int sum = 0;
  if (ones + 1 < zeros) {
    sum += countFormations(n - 1, zeros, ones + 1);
  }
  sum += countFormations(n - 1, zeros + 1, ones);
  return sum;
}

int countFormations(int n) { return countFormations(n, 0, 0); }