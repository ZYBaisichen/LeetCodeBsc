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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MIN;
        traverse(root, res, 0);
        return res;
    }
    void traverse(TreeNode* root, int& res, int depth) {
        if (!root) return;
        depth++;
        if (!root->left && !root->right) {
            if (depth > res) {
                res = depth;
            }
        }
        
        traverse(root->left, res, depth);

        traverse(root->right, res, depth);
        
    }
};