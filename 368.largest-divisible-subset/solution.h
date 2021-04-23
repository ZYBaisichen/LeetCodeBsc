/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-23 11:17:46
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n =nums.size();
        int maxSize = 1;
        int maxValue = 1;
        vector<int> dp(n, 1);
        // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
        //后面的用到了前面的状态，需要优先算前面的，所以i从1到n
        for (int i = 1 ; i < n; i++) {
            for (int j = 0; j<i; j++) {
                // 题目中说「没有重复元素」很重要
                if (nums[i] % nums[j] ==0) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
                //记录最大子集大小，和拥有的最大整数
                if(dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxValue = nums[i];
                }
            }
        }

        //倒推获得最大子集
        vector<int> res;
        if (maxSize == 1){
            res.push_back(nums[0]);
            return res;
        }
        for (int i = n-1; i>=0; i--) {
            if (dp[i] == maxSize && maxValue % nums[i] ==0) {
                maxSize--;
                res.push_back(nums[i]);
                maxValue = nums[i];
            }
        }
        return res;
    }
};