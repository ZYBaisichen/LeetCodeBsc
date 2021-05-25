/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-25 14:47:28
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int x;
		int votes=0;
		for (int i=0;i<len;i++) {
			if(votes==0) {
				x=nums[i];
				votes++;
			} else if(nums[i] == x) {
				votes++;
			} else if(nums[i] != x) {
				votes--;
			}
		}
		return x;
    }
};