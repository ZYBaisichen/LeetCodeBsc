/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-08 11:18:17
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        int len = s.size();
        map<char, int> count_map;
        for (int i=0;i<len;i++) {
            map<char,int>::iterator iter = count_map.find(s[i]);
            if (iter == count_map.end()) {
                count_map[s[i]] = 1;
            } else {
                count_map[s[i]]++;
            }
        }
        
        for (int i=0;i<len;i++) {
            if (count_map[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};