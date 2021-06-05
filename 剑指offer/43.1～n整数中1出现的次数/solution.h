/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-31 15:14:09
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
int countDigitOne(int n) {
        if (n==0) return 0;
        int sum = 0;
        int high = n/10;
        int low = 0;
        int cur = n%10;
        long long num = 1; //位因子
        while (high != 0 || cur != 0) {
            if (cur==0) {
                sum+=high*num;
            } else if(cur==1) {
                sum+= high*num + low +1;
            } else {
                sum+= (high+1)*num;
            }
            low += cur*num;
            cur = high % 10;
            high = high / 10;
            num *= 10;
        }
        return sum;
    }
};
