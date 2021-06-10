/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-08 11:12:32
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (recur(root) == -1) {
            return false;
        } else {
            return true;
        }
    }
    int recur(TreeNode* root) {
        if (!root) return 0;
        
        int left_hight = recur(root->left);
        if (left_hight == -1) {
            return -1;
        }

        int right_hight = recur(root->right);
        if (right_hight == -1) {
            return -1;
        }

        if (abs(left_hight - right_hight) <=1) {
            return max(left_hight, right_hight) + 1;
        } else {
            return -1;
        }
    }
};