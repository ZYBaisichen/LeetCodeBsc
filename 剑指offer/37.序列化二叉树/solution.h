/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-25 13:10:42
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		if (!root) return res;
		serializeCore(root, res);
		return res;
	}

	void serializeCore(TreeNode* root, string& res) {
		if(root==NULL) {
			if(res=="")
				res+="$";
			else
				res+=",$";
			return;
		}
		if (res=="") {
			res += int2string(root->val);
		} else {
			res += ",";
			res += int2string(root->val);
		}
		serializeCore(root->left, res);
		serializeCore(root->right, res);
		return;
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		TreeNode* root=NULL;
		if(data=="") return root;
		int cur=0;
		deserializeCore(&root, data, cur);
		return root;
	}
	void deserializeCore(TreeNode** root, string& data, int& cur) {
		if(cur >= data.size()) {
			return;
		}
		if (data[cur] == '$') {
			cur+=2;
			return;
		}

		int i=cur;
		string tmp="";
		while (i<data.size() && data[i] != ',') {
			tmp+=data[i];
			i++;
		}
		cur = i+1;
		*root = new TreeNode(string2int(tmp));

		deserializeCore(&((*root)->left), data, cur);
		deserializeCore(&((*root)->right), data, cur);
		return;
	}

	int string2int(string str){
		stringstream ss;
		ss << str;
		int result;
		ss >> result;
		return result;
	}

	string int2string(int num){
		stringstream ss;
		ss << num; //将数字传入流中
		string result;
		ss >> result; //将流中的值写入到result中
		return result;
	}
};