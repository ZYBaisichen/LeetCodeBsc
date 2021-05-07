/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-07 14:11:27
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len==0) return 0;
        int res = 0;
        stack<int> sleft,sright;
        vector<int> left(len, -1),right(len, len);
        for (int i=0;i<len;i++) {
            while (!sleft.empty() && heights[sleft.top()] >= heights[i]) {
                sleft.pop();
            }
            if (sleft.empty()) {
                left[i]=-1;
            } else {
                left[i]=sleft.top();
            }
            sleft.push(i);
        }
        for (int i=len-1;i>=0;i--) {
            while (!sright.empty() && heights[sright.top()] >= heights[i]) {
                sright.pop();
            }
            if (sright.empty()) {
                right[i]=len;
            } else {
                right[i]=sright.top();
            }
            sright.push(i);
        }
        for (int i=0;i<len;i++) {
            res = max(res, (right[i]-left[i]-1)*heights[i]);
        }
        return res;
    }
};