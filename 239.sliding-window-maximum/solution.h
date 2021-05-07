/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-06 15:50:20
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;
//单调递增队列模板
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int num) {
        while (!data.empty() && data.back() < num) {
            //找到第一个不小于新数字的位置插入队尾
            data.pop_back();
        }
        data.push_back(num);
    }
    void pop(int lastWinNum) {
        if (!data.empty() && lastWinNum == data.front()) {
            //队头最大值在窗口的最左侧，说明这个数该移除了
            data.pop_front();
        }
    }
    int max_data() {
        return data.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        if (k==0 || len==0) return res;
        MonotonicQueue win;
        for (int i=0;i<len;i++) {
            if (i<k-1) {
                //填满k-1ge窗口
                win.push(nums[i]);
            } else {
                win.push(nums[i]);
                res.push_back(win.max_data());
                win.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};