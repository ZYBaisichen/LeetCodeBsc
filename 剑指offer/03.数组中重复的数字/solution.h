/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-25 11:09:20
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findRepeatNumberHash(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return -1;
        unordered_map<int, int> map;
        for (int i=0;i<len;i++) {
            if(map.find(nums[i]) != map.end()) {
                return nums[i];
            } else {
                map[nums[i]] = 1;
            }
        }
        return -1;
    }
    int findRepeatNumberO1(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return -1;
        unordered_map<int, int> map;
        for (int i=0;i<len;i++) {
            if (nums[i] <0  ||nums[i]>=len) {
                return -1;
            }
            if (nums[i] == i) continue;
            if (nums[i]==nums[nums[i]]) {
                return nums[i];
            } else {
                int tmp = nums[i];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }
};