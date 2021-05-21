/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-21 20:44:35
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(!head) return head;
		ListNode* p=head;
		ListNode* q=NULL;
		ListNode* n=head->next;
		while(n) {
			p->next = q;
			q=p;
			p=n;
			n=n->next;
		}

		//最后一个节点
		if(p) {
			p->next = q;
		}
		return p;
    }
};