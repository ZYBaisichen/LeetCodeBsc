/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-10 22:23:34
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include "../../LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (m==0||n==0) return 0;
        if (k==0) {
            return 1;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m,n,0,0,visited, k);
    }
    int dfs(int m, int n, int i, int j, vector<vector<bool>>& visited, int k) {
        if (
            i<0 ||
            i>=m ||
            j<0 ||
            j>=n ||
            visited[i][j]
        ) {
            return 0;
        }

        //设置已经访问过
        visited[i][j] = true;
        
        //计算是否可以进入当前节点
        
        if (getSum(i)+getSum(j) > k) {
            return 0;
        }

        int res = 1;

        //编程小技巧，方向数组，分别表示上，下，左，右
        int map[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for (int kk = 0; kk <4;kk++) {
            res += dfs(m, n, i+map[kk][0], j+map[kk][1], visited, k);
        }
        return res;
    }
    
    //这里其实是最优的，因为每个节点计算一次之后因为visited的存在，一定不会再计算一次
    int getSum(int num) {
        int sum = 0;
        while(num!=0) {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
};