/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-26 11:28:45
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	vector<string> permutation(string s) {
		set<string> set_tmp;
		vector<string> res;
		int len = s.length();
		if (len==0) return res;
		vector<bool> visited(len, false);
		string path = "";
		for (int i=0;i<len;i++) {
			path += s[i];
			visited[i] = true;
			permutationCore(s, path, set_tmp, visited);
			path = "";
			visited[i] = false;
		}

		set<string>::iterator iter=set_tmp.begin();

		while(iter != set_tmp.end()) {
			res.push_back(*iter);
			++iter;
		}

		return res;
	}
	void permutationCore(string& s, string& path, set<string>& res, vector<bool>& visited) {
		int len = s.size();
		if (path.size() == len) {
			res.insert(path);
			return;
		}

		//下一层
		for (int i=0;i<len;i++) {
			if (!visited[i]) {
				path += s[i];
				visited[i] = true;
				permutationCore(s, path, res, visited);
				path = path.substr(0, path.size()-1);
				visited[i] = false;
			}
		}
	}
};