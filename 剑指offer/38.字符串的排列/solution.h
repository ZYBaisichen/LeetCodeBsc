/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-25 14:29:24
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
		for (int i=0;i<len;i++) {
			string path;
			permutationCore(s, i, path, set_tmp, visited);
		}
		
		set<string>::iterator iter=set_tmp.begin();

		while(iter != set_tmp.end()) {
			res.push_back(*iter);
			++iter;
		}

		return res;
    }
	void permutationCore(string& s, int cur, string& path, set<string>& res, vector<bool>& visited) {
		int len = s.size();
		if (cur<0 || cur>=len) {
			return;
		}

		path += s[cur];
		visited[cur] = true;

		int path_len = path.size();
		if (path_len == len) {
			res.insert(path);
			path = path.substr(0, path_len-1);
			visited[cur] = false;
			return;
		}

		//下一层
		for (int i=0;i<len;i++) {
			if (!visited[i]) {
				permutationCore(s, i, path, res, visited);
			}
		}

		visited[cur] = false;
	}
};