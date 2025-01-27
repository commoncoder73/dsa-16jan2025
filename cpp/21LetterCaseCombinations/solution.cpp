#include <bits/stdc++.h>

using namespace std;


vector<string> allLetterCaseCombinations(string s) {

}

char convertCase(string& s, int i) {
    if (s[i] >= 'a' && s[i] <= 'z') {
        return s[i] - 'a' + 'A';
    }
    if (s[i] >= 'A' && s[i] <= 'Z') {
        return s[i] - 'A' + 'a';
    }
    return s[i];
}

// TC - O(N*2^N)
// SC - with considering output O(N*2^N)
// SC - without considering output O(1)
void allLetterCaseCombinations(string& s, int i, vector<string>& ans) {
    if (i >= s.size()){
        ans.push_back(s);
        return;
    }
    allLetterCaseCombinations(s, i+1, ans);
    char originalChar = s[i];
    s[i] = convertCase(s, i);
    allLetterCaseCombinations(s, i+1, ans);
    s[i] - originalChar;
}