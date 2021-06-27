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
	void pushNew(string word, queue<string>& cur_que, queue<string>& other_que, unordered_map<string, int>& cur_level, unordered_map<string, int>& other_level, int& res, unordered_set<string>& wordSet) {
		int len = word.length();
		for (int i = 0; i<len; i++) {
			int letter = 'a';
			while (letter <= 'z') {
				//产生新的单词
				if (letter != word[i]) {
					string tmp = word;
					tmp[i] = letter;
					if (wordSet.find(tmp) != wordSet.end()) {
						if (other_level.find(tmp) != other_level.end()) {
							//因为广度优先遍历，每次试着往前走一步，所以第一个碰到的结果即为最优解
							res = other_level[tmp] + cur_level[word];
                            return;
						}
						else if (cur_level.find(tmp) == cur_level.end()) {
							cur_que.push(tmp);
							cur_level[tmp] = cur_level[word] + 1;
						}
					}
				}
				letter++;
			}
		}
	}
	// 双向BFS
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord == endWord) {
			return 1;
		}
		
		unordered_set<string> wordSet(wordList.begin(), wordList.end());

		if (beginWord.length() != endWord.length()
			|| wordSet.find(endWord) == wordSet.end()) {
			return 0;
		}


		queue<string> word_que1;//正向
		unordered_map<string, int> level1;

		queue<string> word_que2;//反向
		unordered_map<string, int> level2;

		//搜索开始节点
		word_que1.push(beginWord);
		level1[beginWord] = 1;

		word_que2.push(endWord);
		level2[endWord] = 1;

		int res = 0;
		//有一个搜索结束还没有碰到，说明没找到结果
		while (!word_que1.empty() && !word_que2.empty()) {


			string cur_word = "";
			//搜索平均分摊
			if (word_que1.size() <= word_que2.size()) {
				cur_word = word_que1.front();
				pushNew(cur_word, word_que1, word_que2, level1, level2, res, wordSet);
				word_que1.pop();
			}
			else {
				cur_word = word_que2.front();
				pushNew(cur_word, word_que2, word_que1, level2, level1, res, wordSet);
				word_que2.pop();
			}

			if (res != 0) {
				break;
			}
		}


		return res;
	}
};