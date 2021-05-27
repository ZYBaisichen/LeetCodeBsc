/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-27 14:38:36
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len==0) return -1;
        vector<int> dp(len+1, 0);
        dp[1] = nums[0];
        int res = dp[1];
        for (int i=2; i<=len; i++) {
            dp[i] = max(nums[i-1], dp[i-1]+nums[i-1]);
            res = max(dp[i], res);
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */