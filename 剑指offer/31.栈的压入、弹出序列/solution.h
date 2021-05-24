/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 13:36:26
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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      int len_push = pushed.size();
      int len_pop = popped.size();
      if (len_push != len_pop) {
        return false;
      }
      if (len_push==0) {
        return true;
      }
      stack<int> st;
      int j=0;
      for(int i=0;i<len_push;i++) {
        st.push(pushed[i]);
        while (!st.empty() && j<len_pop && st.top()==popped[j]) {
          st.pop();
          j++;
        }
      }
      if(st.empty()) {
        return true;
      } else {
        return false;
      }
    }
};
