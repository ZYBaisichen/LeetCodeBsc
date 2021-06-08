/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-08 14:15:24
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int nthUglyNumber_heap(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        priority_queue<long,vector<long>,greater<long> > small_heap;
        set<long> ugly_set;
        small_heap.push(1);
        ugly_set.insert(1);
        int count = 0;
        long tmp=0;
        while (count < n) {
            tmp = small_heap.top();
            small_heap.pop();
            if (ugly_set.find(tmp*2) == ugly_set.end()) {
                small_heap.push(tmp*2);
                ugly_set.insert(tmp*2);
            }
            if (ugly_set.find(tmp*3) == ugly_set.end()) {
                small_heap.push(tmp*3);
                ugly_set.insert(tmp*3);
            }
            if (ugly_set.find(tmp*5) == ugly_set.end()) {
                small_heap.push(tmp*5);
                ugly_set.insert(tmp*5);
            }
            count++;
        }
        return tmp;
    }
    int nthUglyNumber(int n) {
		if (n==1) return 1;
		vector<long> dp(n+1, 0);
		dp[1] = 1;
		int p2 = 1, p3 =1, p5 = 1;
		for (int i=2;i<=n;i++) {
			dp[i] = min(min(dp[p2]*2, dp[p3]*3), dp[p5]*5);
			if(dp[i] == dp[p2]*2) p2++;
			if(dp[i] == dp[p3]*3) p3++;
			if(dp[i] == dp[p5]*5) p5++;
		}
		return dp[n];
	}  
};