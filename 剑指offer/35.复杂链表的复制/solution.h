/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-24 22:42:43
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
Node* copyRandomList(Node* head) {
		if(!head) return head;

		Node* p = head;
		while (p) {
			Node* tmp = new Node(p->val);
			tmp->next = p->next;
			p->next = tmp;
			p=p->next->next;
		}

        p = head;
		while(p&&p->next) {
            if (p->random) {
			    p->next->random = p->random->next;
            }
			p = p->next->next;
		}

		p=head;
		Node* res_head = NULL;
		Node* q = NULL;
		while(p&&p->next) {
            Node* origin_nn = p->next->next;
			if (res_head==NULL) {
				res_head = p->next;
				q=res_head;
                p->next = p->next->next;
			} else {
				q->next=p->next;
				q = q->next;
				p->next = p->next->next;
			}
			p = origin_nn;
		}
		return res_head;
    }
};
