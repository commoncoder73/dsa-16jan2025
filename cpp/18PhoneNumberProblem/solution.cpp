#include <bits/stdc++.h>

using namespace std;

vector<string>* genKeypad() {
  vector<string>* keypad = new vector<string>();
  keypad->push_back("abc");
  keypad->push_back("def");
  keypad->push_back("ghi");
  keypad->push_back("jkl");
  keypad->push_back("mno");
  keypad->push_back("pqrs");
  keypad->push_back("tuv");
  keypad->push_back("wxyz");
  return keypad;
}

// TC: O(N*4^N)
// SC: O(N*4^N)
vector<string> forAllKeypadChars(string nums) {
  vector<string> ans;
  string sb = "";
  forAllKeypadChars(nums, 0, ans, sb, *genKeypad());
  return ans;
}

void forAllKeypadChars(string nums, int i, vector<string>& ans,
                       string& stringBuilder, vector<string>& keypad) {
  if (i >= nums.size()) {
    ans.push_back(stringBuilder);
    return;
  }
  int digit = nums[i] - '0';
  string keypadString = keypad[digit - 2];

  for (auto charVal : keypadString) {
    stringBuilder.push_back(charVal);
    forAllKeypadChars(nums, i + 1, ans, stringBuilder, keypad);
    stringBuilder.pop_back();
  }
}