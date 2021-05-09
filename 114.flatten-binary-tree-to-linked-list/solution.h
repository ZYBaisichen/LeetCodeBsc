/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-08 16:28:03
 * @LastEditors: baisichen
 * @Description: 中序遍历
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    void flattenDFS(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> res;
        flattenDFSCore(root, res);
        int n = res.size();
        for (int i=0; i<n-1; i++) {
            res[i]->right = res[i+1];
            res[i]->left = NULL;
        }
    }
    void flattenDFSCore(TreeNode* root, vector<TreeNode*>& res) {
        if (!root) return;
        res.push_back(root);
        flattenDFSCore(root->left, res);
        flattenDFSCore(root->right, res);
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        
        //拉平左子树
        flatten(root->left);
        //拉平右子树
        flatten(root->right);
        
        //拉平的左子树放在右边
        TreeNode* ori_right = root->right;
        root->right=root->left; 
        root->left=NULL;

        //将拉平的右子树的放在左子树的最后
        TreeNode* tmp = root->right ? root->right : root;
        while(tmp && tmp->right) {
            tmp=tmp->right; 
        }
        tmp->right = ori_right;
    }
};