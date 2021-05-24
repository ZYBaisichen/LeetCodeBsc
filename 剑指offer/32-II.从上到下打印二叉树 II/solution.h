/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 15:52:53
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
      queue<TreeNode*> que;
      que.push(root);
      while(!que.empty()) {
        int len = que.size();
        vector<int> res_tmp;
        //出队len次
        for (int i=0;i<len;i++) {
          TreeNode* tmp = que.front();
          res_tmp.push_back(tmp->val);
          if (tmp->left) {
            que.push(tmp->left);
          }
          if (tmp->right) {
            que.push(tmp->right);
          }
          que.pop();
        }
        res.push_back(res_tmp);
      }
      return res;
    }
};
