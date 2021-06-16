/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 11:55:20
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        int len = s.length();
        int start = len-1, end = len - 1;
        while (start>=0) {
            //去除前导空格
            while (start>=0 && s[start] == ' ') {
                start--;
                end--;
            }
            
            //找单词
            while (start>=0 && s[start] != ' ') { 
                start--;
            }
            //cout << "start:" << start << endl;
            //cout << "end:" << end << endl;
            if (end>=0) {
                tmp.push_back(s.substr(start+1, end-start));
                end=start;
            }
        }
        
        string res="";
        for (int i=0;i<tmp.size();i++) {
            res+=tmp[i];
            //cout << "tmp[i]"<<i<< " "<<tmp[i]<<endl;
            if (i < tmp.size() -1) {
                res += " ";
            }
        }
        return res;
    }
};