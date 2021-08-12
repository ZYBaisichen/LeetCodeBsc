/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-08-12 13:34:06
 * @LastEditors: baisichen
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */
#include "LeetCodeBsc.h"
using namespace std;

class Solution {
public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		vector<vector<bool>> floyd(numCourses, vector<bool>(numCourses, false));
		// 构建图，floyd[i][j]表示从i到j是否可达
		for (auto& course : prerequisites) {
			floyd[course[0]][course[1]] = true;
		}

		//每次迭代插入一个课程
		// 转移方程floyd[i][j] = (floyd[i][k]&&floyd[k][j]) || floyd[i][j]
		for (int k=0;k< numCourses;k++) {
			//两层循环更新图，看能否通过绕一下i
			for (int i=0; i < numCourses; i++) {
				for (int j=0; j < numCourses; j++) {
					floyd[i][j] = (floyd[i][k]&&floyd[k][j]) || floyd[i][j];
				}
			}
		}
		
		vector<bool> res;
		for (auto& query:queries) {
			res.push_back(floyd[query[0]][query[1]]);
		}
		
		return res;
	}
};