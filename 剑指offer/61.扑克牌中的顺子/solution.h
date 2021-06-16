/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 20:09:46
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return false;
		}
		sort(nums.begin(), nums.end());
        // for (int i=0; i<len; i++) {
        //     cout << nums[i] << " ";
        // }
        // cout <<endl;
		int i=0;
		int count =0;
		while (i<len && nums[i]==0) {
			count++;
			i++;
		}
		
		while (i < len-1) {
            int sub = nums[i+1] - nums[i];
            if (sub==0) return false;
            // cout << "sub" << sub << endl;
            // cout << "count" << count << endl;
			if (sub>1) {
				if (count - sub+1 < 0) { //注意这里的边界，当0的牌数不足以填补空白时，直接返回false，否则消耗大小王
					return false;
				} else {
					count = count - sub+1;
				}
			}
			i++;
		}
		return true;
    }
};