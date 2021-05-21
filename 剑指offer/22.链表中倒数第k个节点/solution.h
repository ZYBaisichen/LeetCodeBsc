/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-21 20:29:51
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		if (!head) return head;
		ListNode *p =head, *q=head;
		int i=1;
		while (i<=k && p!=NULL) {
			p = p->next;
			i++;
		}

		if(i!=k+1) {
			return NULL;
		}

		while(p) {
			p=p->next;
			q=q->next;
		}
        
		return q;
    }
};