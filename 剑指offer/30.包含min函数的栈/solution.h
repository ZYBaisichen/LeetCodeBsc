/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-23 08:46:12
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    stack<int> st1,st2;
    void push(int x) {
		st1.push(x);
		if(st2.empty() || st2.top()>=x) {
			st2.push(x);
		}
    }
    
    void pop() {
		int tmp = st1.top();
		if (tmp==st2.top()) {
			st2.pop();
		}
		st1.pop();
    }
    
    int top() {
		return st1.top();
    }
    
    int min() {
		return st2.top();
    }
};
