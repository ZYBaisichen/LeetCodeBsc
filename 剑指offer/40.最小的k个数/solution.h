/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-28 12:00:21
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	vector<int> getLeastNumbers_sort(vector<int>& arr, int k) {
		int len = arr.size();
		if (len<=k) return arr;
		sort(arr.begin(), arr.end());
		vector<int> res;
		for (int i=0;i<len&&i<k;i++) {
			res.push_back(arr[i]);
		}
		return res;
    }
	vector<int> getLeastNumbers_heap(vector<int>& arr, int k) {
		int len = arr.size();
		if (len<=k) return arr;
		priority_queue<int, vector<int>, less<int> > maxHeap;
		vector<int> res;
		if(k==0) {
			return res;
		}
		for (int i=0;i<len;i++) {
			if (i<k) {
				maxHeap.push(arr[i]);
			} else {
				int top = maxHeap.top();
				if (arr[i]<top) {
					maxHeap.pop();
					maxHeap.push(arr[i]);
				}
			}
		}

		while (!maxHeap.empty()) {
			res.push_back(maxHeap.top());
			maxHeap.pop();
		}
		return res;
    }
};