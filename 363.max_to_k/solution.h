/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-22 11:39:43
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) { // 枚举上边界
            vector<int> sum(n);
            for (int ii = i; ii < m; ++ii) { // 枚举下边界
                for (int j = 0; j < n; ++j) {
                    sum[j] += matrix[ii][j]; // 更新每列的元素和
                }
                set<int> s_r_i{0};
                int s_r = 0;
                for (int v : sum) {
                    s_r += v;
                    //类似动态规划思想
                    auto s_l = s_r_i.lower_bound(s_r - k);
                    if (s_l != s_r_i.end()) {
                        res = max(res, s_r - *s_l);
                    }
                    s_r_i.insert(s_r);
                }
            }
        }
        return res;
    }
};