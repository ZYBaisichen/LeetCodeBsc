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
  bool isSubStructure(TreeNode* A, TreeNode* B) {
		bool res = false;
		//空的树不可能时任何树的子树，空树不可能包含任何子树
		if (A && B) {
			if (A->val == B->val) {
				res = haveEqualTree(A, B);
			}
			//没找到看左子树
			if(!res) {
				res =  isSubStructure(A->left, B);
			}
			//没找到看右子树
			if(!res) {
				res = isSubStructure(A->right, B);
			}
		}
		return res;
    }

	bool  haveEqualTree(TreeNode * A, TreeNode* B) {
		if (!B)  return true;
		if (!A) return false;
		if (A->val != B->val) {
			return false;
		}

		return haveEqualTree(A->left, B->left) && haveEqualTree(A->right, B->right);
    }
};