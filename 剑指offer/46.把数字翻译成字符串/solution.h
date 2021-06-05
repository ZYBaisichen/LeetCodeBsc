/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-06 00:40:15
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	int translateNum(int num) {
		if (num==0) return 1;
		string num_str = to_string(num);
		int len  = num_str.length();
		vector<int> f(len+1, 0);
		f[0] = 1;
		if (num_str[0]-'0'>=0 && num_str[0]-'0'<26) {
			f[1] = 1;
		}
		for (int  i=2;i<=len;i++) {
			if (num_str[i-1]-'0'>=0 && num_str[i-1]-'0'<26) {
				f[i] += f[i-1];
			}
			int tmp = (num_str[i-2]-'0')*10+num_str[i-1]-'0';
			if (num_str[i-2]!='0' &&tmp >= 0 && tmp<26) {
				f[i] += f[i-2];
			}
		}
		return f[len];
	}
};