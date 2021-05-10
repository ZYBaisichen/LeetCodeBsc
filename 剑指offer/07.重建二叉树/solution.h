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
#include <unordered_map>
#include <stack>
#include "../../LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    // TreeNode* buildTreeCore(vector<int>& preorder, int pre_s, int pre_e, vector<int>& inorder, int in_s, int in_e) { 
    //     cout << "status:" << pre_s << " " << pre_e << " "<< in_s << " "<< in_e<<endl;
        
    // }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size();
        int len2 = preorder.size();
        if (len1 != len2 || len1==0 || len2 ==0) {
            return NULL;
        }
        TreeNode* root = buildTreeCore(preorder, 0, len1-1, inorder, 0, len2-1);
        return root;
    }

    TreeNode* buildTreeCore(vector<int>& preorder, int pre_s, int pre_e, vector<int>& inorder, int in_s, int in_e) { 
        cout << "status:" << pre_s << " " << pre_e << " "<< in_s << " "<< in_e<<endl;
        //遍历数组长度为0返回NULL
        if (pre_s > pre_e 
            || in_s > in_e
            || pre_e >= preorder.size()
            || pre_s <0
            || in_e >= inorder.size()
            || in_s < 0) { 
            return NULL;
        }

        //建立root节点
        int root_val = preorder[pre_s];
        TreeNode * root = new TreeNode(root_val);
        
        //从中序遍历中找root_val
        int root_in_local = -1;
        for (int i=in_s; i<=in_e; i++) {
            if (root_val == inorder[i]) {
                root_in_local = i;
                break;
            }
        }
        if (root_in_local == -1) {
            return NULL;
        }

        //构建左子树
        int leftLen = root_in_local-in_s;
        cout << "left status:" << pre_s+1 << " " << pre_s + leftLen << " "<< in_s << " "<< root_in_local-1<<endl;
        root->left = buildTreeCore(
            preorder, pre_s+1, pre_s + leftLen,
            inorder, in_s, root_in_local-1);
        
        //构建右子树
        cout << "right status:" << pre_s + leftLen + 1 << " " << pre_e << " "<<  root_in_local+1 << " "<< in_e <<endl;
        root->right = buildTreeCore(
            preorder, pre_s + leftLen + 1, pre_e,
            inorder, root_in_local+1, in_e);
        return root;
    }

    
};