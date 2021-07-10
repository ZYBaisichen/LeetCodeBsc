/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 15:49:19
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
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
      vector<vector<int> > res;
      if(!root) return res;
      stack<TreeNode*> st1,st2;
      st1.push(root);
      
      while(!st1.empty() || !st2.empty()) {
        if (!st1.empty()) {
          vector<int> res_tmp1;
          while(!st1.empty()) {
            TreeNode* tmp = st1.top();
            res_tmp1.push_back(tmp->val);
            if(tmp->left)
              st2.push(tmp->left);
            if(tmp->right)
              st2.push(tmp->right);
            st1.pop();
          }
          if (res_tmp1.size()>0)
            res.push_back(res_tmp1);
          vector<int> res_tmp2;
          while(!st2.empty()) {
            TreeNode* tmp = st2.top();
            res_tmp2.push_back(tmp->val);
            if(tmp->right)
              st1.push(tmp->right);
            if(tmp->left)
              st1.push(tmp->left);
            st2.pop();
          }
          if (res_tmp2.size()>0)
            res.push_back(res_tmp2);
        }
      }
      return res;
    }
};
