/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-13 10:54:11
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include "../../LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) return head;
        if(head->val==val) {return head->next;}
        ListNode * p=head;
        ListNode* q = p;
        while(p) {
            if(p->val==val) {
                break;
            }
            q=p;
            p=p->next;
        }
        if(p) {
            q->next = p->next;
        }
        return head;
    }
};