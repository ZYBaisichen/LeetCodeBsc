/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-27 11:21:59
 * @LastEditors: baisichen
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */
#include "LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    
    // 朴素BFS，超时
	int ladderLength_timeout(string beginWord, string endWord, vector<string>& wordList) {
		queue<pair<string, int>> word_que;
		int len1 = beginWord.length();
		int len2 = endWord.length();
		if (beginWord == endWord) {
			return 1;
		}
		if (beginWord.length() != endWord.length()) {
			return 0;
		}
		int res=INT_MAX;
		unordered_set<string> dulp_word;
		dulp_word.insert(beginWord);
		word_que.push(make_pair(beginWord, 1));
		while (!word_que.empty()) {
			string cur_word = word_que.front().first;
			int cur_level = word_que.front().second;

			//变化
			int len = cur_word.size();
			for (int i=0;i<len;i++) {
				char letter = 'a';
				while (letter <= 'z') {
					string tmp = cur_word; //每次产生一个新的单词
					tmp[i] = letter;
					//不在字典内的不能使用
					if (find(wordList.begin(), wordList.end(), tmp) != wordList.end()) {
						//到达结束单词
						if (tmp == endWord) {
							res = min(res, cur_level + 1);
						}

						//中间单词入队和重复元素记录
						if (dulp_word.find(tmp) == dulp_word.end()) {
							dulp_word.insert(tmp);
							word_que.push(make_pair(tmp, cur_level + 1));
						}
					}
					letter++;
				}

			}

			word_que.pop();
		}
		if (res == INT_MAX) {
			res = 0;
		}
		return res;
	}
};