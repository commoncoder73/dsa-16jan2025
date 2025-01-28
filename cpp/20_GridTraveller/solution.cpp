
#include <bits/stdc++.h>

using namespace std;

int numOfWays(int m, int n) {
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    return numOfWays(m, n, memo);
}


int numOfWays(int m, int n, vector<vector<int>>& memo) {
    if (m <= 0 || n <= 0) {
        return 0;
    }
    if (m == 1 && n == 1) {
        return 1;
    }
    if (memo[m][n] != -1) {
        return memo[m][n];
    }
    int ans = numOfWays(m-1, n, memo) + numOfWays(m, n-1, memo);
    memo[m][n] = ans;
    return ans ; 
}