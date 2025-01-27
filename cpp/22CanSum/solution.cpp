#include <bits/stdc++.h>

using namespace std;


// Assume that target is N and total elements in nums array is M
// TC: O(M^N) 
// SC: O(N)
// Given nums only contains positive number
bool canSum(vector<int> nums, int target) {

    if (target < 0) {
        return false;
    }
    if (target == 0) {
        return true;
    }
    for(auto num: nums) {
        if (canSum(nums, target - num)) {
            return true;
        }
    }
    return false;
}

// Assume that target is N and total elements in nums array is M
// TC: O(M*N) 
// SC: O(N)
// Given nums only contains positive number
bool canSumOptimized(vector<int>& nums, int target) {
    vector<int> memo(target+1, -1);
    return canSumOptimized(nums, target, memo);
}

bool canSumOptimized(vector<int>& nums, int target, vector<int>& memo) {
    if (target < 0) {
        return false;
    }
    if (target == 0) {
        return true;
    }
    if (memo[target] != -1) {
        return memo[target];
    }
    bool canFormTargetSum = false;
    for(auto num: nums) {
        if (canSumOptimized(nums, target - num, memo)) {
            canFormTargetSum = true;
            break;
        }
    }
    memo[target] = canFormTargetSum;
    return canFormTargetSum;
}

bool canSumOptimizedTab(vector<int>& nums, int target) {
    vector<bool> memo(target+1, false);
    memo[0] = true;
    for(int i=1; i<=target; i++) {
        bool isPossible = false;
        for(auto num: nums) {
            if (i >= num) {
                isPossible = isPossible | memo[i-num];
            }
        }
        memo[i] = isPossible;
    }
    return memo[target];
}