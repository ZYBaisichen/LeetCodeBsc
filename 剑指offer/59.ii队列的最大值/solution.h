/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 14:03:03
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class MaxQueue {
private:
    deque<int> data;
    queue<int> que;
public:
    MaxQueue() {}
    
    int max_value() {
        if (data.empty()) {
            return -1;
        } else {
            return data.front();
        }
    }
    
    void push_back(int value) {
        while (!data.empty() && data.back() < value) {
            //找到第一个不小于新数字的位置插入队尾
            data.pop_back();
        }
        data.push_back(value);
        que.push(value);
    }
    
    int pop_front() {
        if (!que.empty()) {
            int lastWinNum = que.front();
            if (!data.empty() && lastWinNum == data.front()) {
                //队头最大值在窗口的最左侧，说明这个数该移除了
                data.pop_front();
            }
            que.pop();
            return lastWinNum;
        }
        return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */