/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-16 22:44:12
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
    //从root节点找是否含有某个节点
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //从左子树找p和q
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //从右子数找p和q
        if (!left) return right; //左子树中没有，则结果为右子树的查找结果
        if (!right) return left;//右子树中没有，则结果为左子树的查找结果
        return root;//两个都不为空，说明两个节点在root的左右子树中
    }
};
