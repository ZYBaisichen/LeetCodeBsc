/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-24 16:53:54
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
		if (len == 0){
			return 0;
		}
		vector<int> dp(amount+1, -1);
		dp[0] = 0;
		for (int i=1; i<=amount; i++) {
			int min = INT_MAX;
			int flag = false;
			for (int j=0;j<len;j++) { 
				if (i>=coins[j]) {
					if(min > dp[i-coins[j]] && dp[i-coins[j]] != -1) {//注意这里，找最小值时，应该将-1这个特殊状态排除在外，-1为未找到相关组合的硬币
						min = dp[i-coins[j]];
					}
				}
			}
			if (min != INT_MAX) {
				dp[i] = min + 1;
			}
		}
		return dp[amount];
    }
};
int main(){
    Solution a;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(5);
    cout << a.coinChange(b,11) <<endl;
}