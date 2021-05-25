/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-25 08:56:00
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if(!root) return root;
		Node* head;
		Node* p=root;
		while(p&&p->left) {
			p=p->left;
		}
		head=p;

		treeToDoublyListCore(root);

		p=head;
		while(p&&p->right) {
			p=p->right;
		}
		p->right = head;
		head->left = p;
		return head;
    }
	Node* treeToDoublyListCore(Node* root) {
		if(!root) return NULL;

		Node* left_head = treeToDoublyListCore(root->left);
		Node* right_head = treeToDoublyListCore(root->right);
		
		Node* p=left_head;
		Node * cur_left = left_head;//记录当前树转换完之后最左边的节点
		while(p&&p->right) {
			p=p->right;
		}
		if(p) {
			p->right = root;
			root->left = p;
		} else {
			cur_left = root;
		}
		root->right = right_head;
		if(right_head) {
			right_head->left = root;
		}
		return cur_left;
	}

};

class Solution1 {
public:
	Node *pre, *head;
	Node* treeToDoublyList(Node* root) {
		if(!root) return root;
		treeToDoublyListCore(root);
		head->left = pre;
		pre->right = head;
		return head;
    }
	void treeToDoublyListCore(Node* root) {
		if(!root) return;

		treeToDoublyListCore(root->left);
		
		//建链表的过程
		if(pre) {
			pre->right = root;
		} else {
			head = root;
		}
		root->left = pre;
		pre = root;

		treeToDoublyListCore(root->right);
	}

};
