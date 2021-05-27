/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-27 11:12:28
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n==1) return 0;
        int x = 0;
        //每次计算有i个数字的情况
        for (int i=2; i<=n; i++) {
            x = (m+x)%i;
        }
        return x;
    }
};