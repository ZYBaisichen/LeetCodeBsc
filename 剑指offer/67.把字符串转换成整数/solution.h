/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-16 22:35:11
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int strToInt_str(string str) {
        int len = str.length();
        if (str =="") {
            return 0;
        }

        int start = 0;
        //去除前导空格
        while(start<len && str[start]==' ') {
            start++;
        }

        if (start == len) return 0;

        bool sign = false;
        if (str[start] == '-') {
            sign = true;
            start++;
        } else if (str[start] == '+'){
            start++;
        }

        long res=0;

        while(str[start] >= '0' && str[start] <= '9') {
            res = res*10 + str[start] - '0';
            if (res > INT_MAX) return sign ? INT_MIN: INT_MAX;
            start++;
        }

        if (sign) {
            return -res;
        } else {
            return res;
        }

    }
    
    int strToInt(string str) {
		int len =str.length();
		//3个状态。4种符号
		map<int, map<char, int> > _f;
		_f[0]['o'] = 2;
		_f[0][' '] = 0;
		_f[0]['+'] = 1;
		_f[0]['-'] = 1;
		_f[0]['d'] = 1;
		_f[1]['d'] = 1;
		_f[1]['o'] = 2;
		_f[1]['+'] = 2;
		_f[1]['-'] = 2;

		int _state = 0;
		bool sign = false;
		long res=0;
		for (int i=0; i<len; i++) {
			if (_state == 2) break;
			if (str[i] == '+' || str[i] == '-') {
				map<char, int>::iterator iter_add = _f[_state].find('+');
				map<char, int>::iterator iter_sub = _f[_state].find('+');
				if (iter_add != _f[_state].end() || iter_sub != _f[_state].end()) {
					_state = _f[_state][str[i]];
					if (str[i] == '-' && _state!=2) { //注意这里的边界如果状态为2则不应再做操作如123-
						sign = true;
					}
				} else {
					_state = 2;
				}
			} else if(str[i] >= '0' && str[i]<='9'){
				map<char, int>::iterator iter = _f[_state].find('d');
				if (iter != _f[_state].end()) {
					_state = _f[_state]['d'];
					res = res*10 + str[i] - '0';
					if (res > INT_MAX) return sign ? INT_MIN: INT_MAX;
				} else {
					_state = 2;
				}
			} else if (str[i] == ' '){
				map<char, int>::iterator iter = _f[_state].find(' ');
				if (iter != _f[_state].end()) {
					_state = _f[_state][' '];
				} else {
					_state = 2;
				}
			} else {
				map<char, int>::iterator iter = _f[_state].find('o');
				if (iter != _f[_state].end()) {
					_state = _f[_state]['o'];
				} else {
					_state = 2; //找不到状态则结束
				}
			}
		}

		if (sign) {
			return -res;
		} else {
			return res;
		}
	}
};