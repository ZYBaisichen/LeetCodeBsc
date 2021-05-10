/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-25 11:09:20
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

class CQueue {
public:
    stack<int> st1, st2;
    CQueue() {
        while(!st1.empty()) {st1.pop();}
        while(!st2.empty()) {st2.pop();}
    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        int val = -1;
        if (!st2.empty()) {
            val = st2.top();
            st2.pop();
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            if (!st2.empty()) {
                val = st2.top();
                st2.pop();
            }
        }
        return val;
    }
};