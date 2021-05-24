/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 21:33:37
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;


class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		int len = postorder.size();
		if(len==0) {
			return true;
		}

		return verifyPostorderCore(postorder, 0, len-1, len);
	}
	bool verifyPostorderCore(vector<int>& postorder, int begin, int end, int len) {
		if (begin>end
		    || end >= len || end < 0
		    || begin >= len || begin < 0) {
			return true;
		}
		if (begin==end) return true;
		int endNum = postorder[end];
		int flag=0;
		int mid=-1;
		for (int i=begin;i<=end-1 && (end-1)<len;i++){
			if(flag&&postorder[i]<endNum) {
				//找到了一个比它大的又找到一个比它小的
				return false;
			}
			//找到第一个比它大的
			if (postorder[i]>=endNum && !flag) {
				flag=1;
				mid=i;
			}
		}
		//所有值都比它小
		if (mid == -1) {
			return verifyPostorderCore(postorder, begin, end-1, len);
		}
		return verifyPostorderCore(postorder, begin, mid-1, len)
		       && verifyPostorderCore(postorder, mid, end-1, len);
	}
};