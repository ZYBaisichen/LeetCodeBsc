/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-16 21:14:07
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
double myPow(double x, int n) {
        if (n==0) return 1;
        int sym = 1;
        if (x<0) {
            if (n %2==1) {
                sym=0;
            }
        }

        int isRecip = false;
        if (n<0) {
            isRecip = true;
        }

        double tmp_x = abs(x);
        long long tmp_n = abs(n);
        cout  << "x,n:" << tmp_x<<"," << tmp_n<<endl;
        double _res = quickMod(tmp_x, tmp_n);
        if (sym==0) {
            _res = -_res;
        }
        if (isRecip) {
            _res = 1/_res;
        }
        return _res;
    }
     //快速幂取余，求a^b 
    double quickMod(double a, int b) {
        double ans = 1;
        while (b) {
            if (b%2==1) {//因为b一直除以2，所以最后一定会除到1，然后1除以2才到0
                ans = (ans * a); //如果b为奇数，本次做3次方
            }
            a = a * a; //每次做平方
            b=b/2;
        }
        return ans;
    }
};