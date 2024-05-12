/*
Question : 

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int norob = 0;
        for (int i = 0; i < nums.size(); i++) {
            int newRob = norob + nums[i];
            int newNoRob = max(norob, rob);
            rob = newRob;
            norob = newNoRob;
        }
        return max(rob, norob);
    }
};