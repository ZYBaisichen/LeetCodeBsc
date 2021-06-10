/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-08 11:12:32
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int>  res;
        if (len==0) return res;
        
        int tmp = 0;
        for (int i=0;i<len;i++) {
            tmp ^= nums[i];
        }
        int binary = 1;
        while (!(binary & tmp)) {
            binary <<= 1;
        }
        
        int res1=0, res2 =0;
        for (int i=0;i<len;i++) {
            if (nums[i] & binary) {
                res1 ^= nums[i];
            } else {
                res2 ^= nums[i];
            }
        }
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};