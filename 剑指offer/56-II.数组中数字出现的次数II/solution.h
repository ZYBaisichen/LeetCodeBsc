/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-11 11:32:00
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
    int singleNumber_state(vector<int>& nums) {
        int high = 0, low = 0;//初始状态为00
        int len = nums.size();
        for (int i=0;i<len;i++) {
            low = low ^ nums[i] & ~high;
            high = high ^ nums[i] & ~low;
        }
        return low;
    }
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(32, 0);
        for (int i=0;i<len;i++) {
            int num = nums[i];
            for (int j=0; j<32; j++) {
                count[j] += num & 1;//低位低地址存
                num >>= 1;
            }
        }
        int res = 0, m=3;
        for (int j=31; j>=0; --j) { //高位先算
            res <<= 1;
            res |= count[j] % m; //由于除了一个数其余数字都是m，所以最后一定是0或1
        }
        return res;
    }
};