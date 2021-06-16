/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 12:33:18
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    string reverseLeftWords_ku(string s, int n) {
        int len = s.length();
        string res = "";
        res += s.substr(n, len-n);
        res += s.substr(0, n);
        return res;
    }
    string reverseLeftWords(string s, int n) {
        int len = s.length();
        string res = "";
        for (int k=n; k<len;k++) {
             res += s[k];
        }
        for (int k=0; k<n; k++) {
            res += s[k];
        }
        return res;
    }
    
};