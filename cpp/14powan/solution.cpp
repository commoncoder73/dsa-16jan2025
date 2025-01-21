#include <bits/stdc++.h>

using namespace std;

int pow(int a, int n) {
    int res = 1;
    while(n) {
        if (n&1) {
            res*=a;
        }
        n = n>>1;
        a*=a;
    }
    return res;
}