/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-08 10:33:41
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        traverse(root, res);
        return res;
    }
    void traverse(TreeNode* root, vector<int>& res) {
        if (!root) return;
        // 前序遍历
        traverse(root->left, res);
        // 中序遍历
        res.push_back(root->val);
        traverse(root->right, res);
        // 后序遍历
    }
};