/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-10 11:26:06
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
    int searchRight(vector<int>& nums, int target) {
        int len = nums.size();
        int r = len-1;
        int l = 0;
        int mid = (r-l)/2 + l;
        while (l<=r) {//注意这里相等时不是边界，还需要再次寻找
            if (nums[mid]>target) {
                r = mid-1;
            } else if(nums[mid]<target) {
                l = mid+1;
            } else if(nums[mid]==target) {
                l = mid+1;
            }
            mid = (r-l)/2 + l;
        }
        return r;
    }
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len==0) {
            return 0;
        }
        int l = searchRight(nums, target-1);
        int r = searchRight(nums, target);
        return r-l;
    }
};