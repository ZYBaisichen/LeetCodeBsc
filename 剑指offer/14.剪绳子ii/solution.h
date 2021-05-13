/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-13 10:42:15
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
    int cuttingRope(int n) {
        if (n<4) return n-1;
        if (n==0) return 0;
        int res = 1;
        int mod = n%3;
        int num_3 = n/3;
        if (mod==1) {
            num_3 -=1;
            res = 4;
        } else if(mod==2){
            res = 2;
        }
        res = (((long long)res) * quckMod(3, num_3, 1000000007))%1000000007;

        return res;
    }

    //快速幂取余，求a^b mod n的余数
	int quckMod(int a, int b, int c) {
		int ans = 1;
		long long tmp = a; //用long long做中间结果的计算，防止tmp*tmp溢出
		while (b) {
			if (b%2==1) {//因为b一直除以2，所以最后一定会除到1，然后1除以2才到0
				ans = (ans * tmp) % c; //如果b为奇数，本次做3次方
			}
			tmp = tmp * tmp % c; //每次做平方
			b=b/2;
		}
		return ans;
	}
};