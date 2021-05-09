/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-08 10:57:55
 * @LastEditors: baisichen
 * @Description: 中序遍历
 */
#include <iostream>
#include <vector>
#include <set>
#include "../LeetCodeBsc.h"
using namespace std;
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root) {
        if (!root) return;
        // 前序遍历
        traverse(root->left);
        // 中序遍历
        traverse(root->right);

        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;
        // 后序遍历
    }
};