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
    string replaceSpace(string s) {
        int len = s.length();
        if (len ==0) return s;
        string tmp;
        for  (int i=0;i<len;i++) {
            if (s[i] == ' ') {
                tmp+="%20";
            } else {
                tmp+=s[i];
            }
        }
        return tmp;
    }
};