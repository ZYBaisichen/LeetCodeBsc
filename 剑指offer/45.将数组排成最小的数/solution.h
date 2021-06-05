/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-02 20:22:55
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
		vector<string> num_strs;
		string res="";
		int len = nums.size();
		for (int i=0;i<len;i++) {
			num_strs.push_back(to_string(nums[i]));
		}

		sort(num_strs.begin(), num_strs.end(), [](string& x, string y){return x+y < y+x;});

		for (int i=0;i<len;i++) {
			res += num_strs[i];
		}
		return res;
    }
};
