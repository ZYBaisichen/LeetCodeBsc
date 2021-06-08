/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-07 16:44:14
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        //第一行
        for (int j=1; j<n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        //第一列
        for (int i=1; i<m; i++) {
            grid[i][0] += grid[i-1][0];
        }

        for (int j=1; j<n; j++) {
            for (int i=1; i<m; i++) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }

        return  grid[m-1][n-1];
    }
};