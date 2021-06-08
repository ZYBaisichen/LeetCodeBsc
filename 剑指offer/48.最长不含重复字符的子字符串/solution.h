/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-07 17:42:38
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if (len==0) return 0;
		vector<int> dp(len+1, 0);
		dp[1] = 1;
		map<char, int> tmp_map;
		tmp_map[s[0]] = 0;
		int res = 1; //初始化结果
		for (int i=2;i<=len; i++) {
			int l = -1;
			map<char, int>::iterator iter = tmp_map.find(s[i-1]);
			if (iter!=tmp_map.end()) {
				l = iter->second;
				tmp_map[s[i-1]] = i-1;
			} else {
				tmp_map[s[i-1]] = i-1;
			}
			int tmp = (i-1) - l; //下标相减
			if (dp[i-1] < tmp) {
				dp[i] = dp[i-1] + 1;
			} else {
				dp[i] = (i-1) -l;//下标相减
			}
			if (dp[i] > res) {
				res = dp[i];
			}
		}

		return res;
	}
};