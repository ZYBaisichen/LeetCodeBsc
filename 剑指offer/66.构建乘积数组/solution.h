/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-16 21:39:42
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        
        int len = a.size();
        vector<int> b(len, 1);
        for (int i=1;i<len;i++) {
            b[i] = b[i-1] * a[i-1];
        }
        
        int tmp = 1;
        for (int i=len-2; i>=0; i--) {
            tmp *= a[i+1];
            b[i] *= tmp;
        }
        return b;
    }
};