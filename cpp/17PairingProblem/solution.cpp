#include <bits/stdc++.h>

using namespace std;


int pairs(int n) {
    if (n<=1) {
        return 1;
    }
    return pairs(n-1) + (n-1)*pairs(n-2);
}