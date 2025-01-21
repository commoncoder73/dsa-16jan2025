#include <bits/stdc++.h>

using namespace std;

void insertAtSortPosition(stack<int>& s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }
    if (val <= s.top()) {
        s.push(val);
        return;
    }
    int topVal = s.top();
    s.pop();
    insertAtSortPosition(s, val);
    s.push(topVal);
}


void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int val = s.top();
    s.pop();
    sortStack(s);
    insertAtSortPosition(s, val);
}   