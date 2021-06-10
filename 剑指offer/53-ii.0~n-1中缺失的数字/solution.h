/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-08 11:12:32
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
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int mid = len/2;
        int l=0, r=len-1;
        while (l<=r) {
            cout << "val:" << nums[mid] <<endl;
            cout << "mid:" << mid << endl;
            if (nums[mid] == mid) {
                l = mid+1;
            } else {
                r = mid-1;
            }
            mid = (r-l)/2 + l;
        }
        return r+1;
    }
};