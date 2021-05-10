/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-25 11:09:20
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
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        if (len == 0) {return -1;}
        int l =0, r=len-1;
        while (l<r) {
            int mid = l + (r-l)/2;
            if (numbers[mid]<numbers[r]) {
                r = mid;
            } else if(numbers[mid]>numbers[r]){
                l = mid + 1;
            } else {
                --r;
            }
        }
        return numbers[l];
    }
};