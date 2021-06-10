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
    int count;
    int kthLargest(TreeNode* root, int k) {
        int res;
        traverse(root, res, k);
        return res;
    }
    void traverse(TreeNode* root, int& res, int k) {
        if (!root || count>k) return;
        traverse(root->right, res, k);
        
        count++;
        if (count == k) {
            res = root->val;
            return;
        }

        traverse(root->left, res, k);
        // 中序遍历相关操作

    }
};