/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-18 20:36:15
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
    bool isMatch(string s, string p) {
        int m = s.length();
		int n = p.length();
		vector< vector<bool> > dp(m+1, vector<bool>(n+1, false));
		dp[0][0] = true;
		for (int i=0;i<=m;i++) {
			for (int j=1;j<=n;j++) {
				if (p[j-1] == '.' || (i>=1 && p[j-1] == s[i-1])) {
					//如果i为0，有实际字母或为点的模式是匹配不了该空串的
					if (i>=1) {
						dp[i][j] = dp[i-1][j-1];
					}
				} else if(j>=2 && p[j-1]=='*') {
					if (s[i-1]==p[j-2] || p[j-2]=='.') {
						dp[i][j] =  dp[i][j-2];
						if (i>=1) { //如果i为0，则匹配的是一个空串，没有必要再往前看了
							dp[i][j] = dp[i][j]||dp[i-1][j];
						}
					} else {
						dp[i][j] = dp[i][j-2];
					}
				}
			}
		}

		return dp[m][n];
    }
};