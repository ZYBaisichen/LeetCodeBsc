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
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* cur;
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        TreeNode * res=new TreeNode(-1);
        cur = res;
        increasingBSTCore(root);
        return res->right;
    }
    void increasingBSTCore(TreeNode* root) {
        if (root) {
            increasingBSTCore(root->left);
            cur->right = root;
            root->left = NULL;
            cur = root;
            increasingBSTCore(root->right);
        }
    }
};