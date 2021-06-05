/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-02 11:59:47
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	int findNthDigit(int n) {
		long long start = 1;
		long long count = 9;
		int m = 1;

		//计算在所在数位
		while (n>count) {
			n = n - count;
			m++;
			start *= 10;
			count = 9*start*m;
		}

		//计算在哪个数上
		long long num = start + (n-1) / m;

		//计算是哪一位
		string num_str = to_string(num);
		int res = (n-1)%m;
		return num_str[res]-'0';

	}
};
