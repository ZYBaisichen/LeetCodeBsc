/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 15:17:44
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
    vector<int> levelOrder(TreeNode* root) {
      vector<int> res;
      if(!root) return res;
      queue<TreeNode*> que;
      que.push(root); 
      while(!que.empty()) {
        TreeNode* tmp = que.front();
        res.push_back(tmp->val);
        if (tmp->left) {
          que.push(tmp->left);
        }
        if (tmp->right) {
          que.push(tmp->right);
        }
        que.pop();
      }
      return res;
    }
};
