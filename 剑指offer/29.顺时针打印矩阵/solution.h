/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-21 23:41:57
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (m == 0) return res;
		int n = matrix[0].size();
		if (n == 0) return res;

		int i = 0, j = 0;
		int t = 0, b = m - 1;
		int l = 0, r = n - 1;
		int num = m*n, count = 0;
		while (count<num) {

			//往右
			if (t >= 0 && t<m && t<=b) {
				for (int j = l; j <= r&&j<n; j++) {
					res.push_back(matrix[t][j]);
					count++;
				}
				t++;
			}

			//往下
			if (r >= 0 && r<n && l<=r) {
				for (int i = t; i <= b&&i<m; i++) {
					res.push_back(matrix[i][r]);
					count++;
				}
				r--;
			}

			//往左
			if (b >= 0 && b<m && t<=b) {
				for (int j = r; j >= l&&j >= 0; j--) {
					res.push_back(matrix[b][j]);
					count++;
				}
				b--;
			}

			//往上
			if (l >= 0 && l<m && l<=r) {
				for (int i = b; i >= t&&i >= 0; i--) {
					res.push_back(matrix[i][l]);
					count++;
				}
				l++;
			}
		}
		return res;
	}
};