/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-21 23:41:57
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
    TreeNode* mirrorTree(TreeNode* root) {
		if (!root) return root;
		mirrorTreeCore(root);
		return root;
    }
	void mirrorTreeCore(TreeNode* root) {
		if (!root) return;
		
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		mirrorTreeCore(root->left);

		mirrorTreeCore(root->right);
	}
};