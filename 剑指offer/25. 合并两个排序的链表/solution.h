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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* head;

		ListNode * p1=l1, *p2=l2, *p=NULL;
		if (l1->val < l2->val) {
			head = l1;
			p1=p1->next;
		} else {
			head = l2;
			p2=p2->next;
		}
		p=head;

		while (p1&&p2) {
			if(p1->val < p2->val) {
				p->next=p1;
                p=p1;
				p1=p1->next;
			} else {
				p->next = p2;
                p=p2;
				p2 = p2->next;
			}
		}

		if(p1) {
			p->next = p1;
		} else if(p2) {
			p->next = p2;
		}
		return head;
    }
};