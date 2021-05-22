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
bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetricCore(root, root);
    }
	bool isSymmetricCore(TreeNode* rootA, TreeNode* rootB) {
		
		if (!rootA && !rootB) {
			return true;
		}

        if (!rootA || !rootB) {
			return false;
		}
		
		if (rootA->val != rootB->val) {
			return false;
		}
		return isSymmetricCore(rootA->left, rootB->right) 
			&& isSymmetricCore(rootA->right, rootB->left);
	}
};