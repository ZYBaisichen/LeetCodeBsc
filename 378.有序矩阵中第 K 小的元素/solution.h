/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2023-06-01 14:31:05
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m==0) return -1;
        int n = matrix[0].size();
        if (n==0) return -1;
        
        int low = matrix[0][0];
        int high = matrix[m-1][n-1];
        while(low != high) {
            int mid = low + (high-low)/2;
            int count = 0;
            int i = m-1, j=0;
            while (i>=0 && j<n) {
                if (matrix[i][j]<=mid) {
                    count += i+1;
                    j++;
                } else {
                    i--;
                }
            }
            if (count < k) { 
                low = mid+1; //从左到右逼近，在mid右边
            } else {
                high = mid;
            }
        }
        return high;
    }
};
