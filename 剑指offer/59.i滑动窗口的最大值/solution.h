/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 13:40:16
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
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
    //最终输出大小为len-k+1
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue que;
        int len = nums.size();
        vector<int> res;
        if (len==0||k>len) {
            return res;
        }
        for (int i=0;i<k;i++) {
            que.push(nums[i]);
        }
        res.push_back(que.max_data());
        que.pop(nums[0]); //右边边界右滑

        for (int r=k;r<len;r++) {
            que.push(nums[r]);
            res.push_back(que.max_data());
            que.pop(nums[r-k+1]); //右边边界右滑
        }
        return res;
    }
};