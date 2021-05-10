/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-25 11:09:20
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArrayBaoli(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        if (m==0) return false;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if(matrix[i][j]==target) {
                    return true;
                }
            }
        }
        return false;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        if (m==0) return false;
        int i=0,j=m-1;
        while(i<n && j>=0) {
            if (matrix[i][j]==target) {
                    return true;
            } else if (target<matrix[i][j]) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};