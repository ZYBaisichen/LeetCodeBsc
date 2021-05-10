/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-25 11:09:20
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
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        return fib(n-1) + fib(n-2);
    }
    int fibDp(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i-1]+dp[i-2])% 1000000007;
        }
        
        return dp[n];
    }
    
    int fibDpOp(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        if (n==2) return 1;
        int f = 1, ff =1;
        int res = -1;
        for (int i = 3; i <= n; i++) {
            res = (f+ff)% 1000000007;
            ff = f;
            f = res;
        }
        
        return res;
    }
};