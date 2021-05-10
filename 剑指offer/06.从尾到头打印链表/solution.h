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
#include <stack>
#include "../../LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (!head) return res;
        stack<ListNode*> st;
        ListNode * p =head;
        while(p) {
            st.push(p);
            p=p->next;
        }
        
        while(!st.empty()) {
            res.push_back(st.top()->val);
            st.pop();
        }

        return res;
   }
};