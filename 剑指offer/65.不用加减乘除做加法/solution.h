/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-16 21:19:40
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int add(int a, int b) {
        // 进位为a&b<<1，当前位和为a^b
        while(b) {
            int c = (unsigned int)(a&b )<< 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};