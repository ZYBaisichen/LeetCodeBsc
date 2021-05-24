/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 21:28:08
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
	vector<vector<int> > res;
	vector<vector<int> > pathSum(TreeNode* root, int target) {
		if (!root) return res;
		vector<int> path;
		int sum=0;
		pathSumCore(root, target, path, sum);
		return res;
    }
	void pathSumCore(TreeNode* root, int target, vector<int> path, int& sum){
		if (!root) return;
		path.push_back(root->val);
		sum+=root->val;

		//叶节点
		if (!root->left && !root->right && sum==target) {
			res.push_back(path);
			sum-=root->val;
			path.pop_back();
			return;
		}

		pathSumCore(root->left, target, path, sum);
		pathSumCore(root->right, target, path, sum);
		
		//回溯
		sum-=root->val;
		path.pop_back();
	}
};
