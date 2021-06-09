/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-09 15:05:27
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	// 归并排序（C++-递归版）
	int merge_sort_recursive(vector<int>& nums, vector<int>& nums_tmp, int l, int r) {
		if (l >= r)
			return 0;
		int len = r - l;
		int mid = (len >> 1) + l;
		//两个序列边界
		int l1 = l, r1 = mid;
		int l2 = mid + 1, r2 = r;
		int res = merge_sort_recursive(nums, nums_tmp, l1, r1) + merge_sort_recursive(nums, nums_tmp, l2, r2);

		//合并序列
		int k = l;
		int p = l1, q = l2;
		while (p <= r1 && q <= r2) {
			if (nums[p] > nums[q]) {
				res += r1-p+1;
				nums_tmp[k++] = nums[q++];
			} else {
				nums_tmp[k++] = nums[p++];
			}
		}

		while (p <= r1)
			nums_tmp[k++] = nums [p++];
		while (q <= r2)
			nums_tmp[k++] = nums[q++];
		for (k = l; k <= r; k++)
			nums[k] = nums_tmp[k];

		return res;
	}

	int reversePairs(vector<int>& nums) {
		int len = nums.size();
		vector<int> nums_tmp(len);
		return merge_sort_recursive(nums, nums_tmp, 0, len - 1);
	}
};