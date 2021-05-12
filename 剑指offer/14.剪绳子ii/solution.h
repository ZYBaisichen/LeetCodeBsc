/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-11 10:41:50
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include "../../LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n<4) return n-1;
        if (n==0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i=4;i<=n;i++){
            long long res = 0;
            for (int k=1;k<=i/2;k++) {
                if (dp[i-k]*dp[k] > res) {
                    res = dp[i-k]*dp[k];
                }
            }
            dp[i] = res;
        }
        return dp[n];
    }
};