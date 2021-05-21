/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-21 20:21:09
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;


class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
		int len = nums.size();
		if (len==0) return nums;
		int i=0, j=len-1;
		while (i<j) {
            if (nums[i]%2 == 0 && nums[j]%2 == 1) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
                i++;
                j--;
			}
            
			if (nums[i]%2 == 1) {
				i++;
			}
			if (nums[j]%2 == 0) {
				j--;
			}
			 

		}
        return nums;
    }
};