/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-21 14:25:22
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	vector<string> readBinaryWatch(int turnedOn) {
        vector<string > res;
        for (int i=0;i<12;i++) {
            for (int j=0;j<60;j++) {
                if (count(i) + count(j) == turnedOn) {
                    string min = "";
                    if (j<10) {
                        min += "0";
                    } 
                    min += to_string(j);
                    res.push_back(to_string(i) + ":" + min);                    
                }
            }
        }
        return res;
	}
	int count(int n) {
		int res =0 ;
		while (n) {
			n = n& (n-1);
			res++;
		}
		return res;
	}
};