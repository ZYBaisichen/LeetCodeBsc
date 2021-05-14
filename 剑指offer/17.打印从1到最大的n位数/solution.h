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
    vector<int> printNumbers(int n) {
        vector<int> res;
       if (n==0) return res;
       int MaxNum =10;
       int i=1;
       while (i<=n-1) {
           MaxNum =  MaxNum*10;
           i++;
       } 
       for (int i=1;i<MaxNum;i++) {
           res.push_back(i);
       }
       return res;
    }
};