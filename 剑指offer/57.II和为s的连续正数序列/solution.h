/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-11 15:57:00
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
    vector<vector<int> > findContinuousSequence_slide(int target) {
        vector<vector<int> > res; 
        if (target<=2) return res;
        int l=1, r=2, s=3;
        while(l<r && r < target && l<target) {
            if (s == target) {
                vector<int> tmp;
                for (int k=l;k<=r;k++) {
                    tmp.push_back(k);
                }
                res.push_back(tmp);
                s -= l;
                l++;
            } else if (s > target) {
                s -= l;
                l++;
            } else if (s < target){
                s += r;
                r++;
            }
        }
        return res;
    }

    vector<vector<int> > findContinuousSequence(int target) {
        vector<vector<int> > res; 
        if (target<=2) return res;
        for (long l=1; l<target; l++) {
            double r = (-1.0+sqrt(1.0+4*(2*(long)target+l*l-l)))/2;
            if (r>0 && (int)r == r && l<r) {
                vector<int> tmp;
                for (int k=l; k<=(int)r; k++) {
                    tmp.push_back(k);
                } 
                res.push_back(tmp);
            }
            if (l>r) {
                break;
            }
        }
        return res;
    }
};