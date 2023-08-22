/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2023-08-17 19:39:26
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include "../../LeetCodeBsc.h"
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m==0) return false;
        int n = board[0].size();
        if (n==0) return false;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (dfs(board, word,  i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, 
        int i, int j, int k) {
            int m = board.size();
            int n = board[0].size();
            int len = word.length();
            if (i<0 
                || i>=m
                || j<0
                || j>=n
                || k >= len
                || board[i][j] == '\0'
                || board[i][j] != word[k]
            ) {
                return false;
            }
            //能走到这里说明board[i][j]==word[k]
            if (k==len-1) {return true;}
            
            //标识被访问过
            board[i][j] = '\0';

            //上下左右继续找
            bool res = dfs(board, word, i-1, j, k+1) ||
                dfs(board, word, i+1, j, k+1) ||
                dfs(board, word, i, j-1, k+1) ||
                dfs(board, word, i, j+1, k+1);
            
            //回溯被访问的节点
            board[i][j] = word[k];

            return res;
    }
    bool dfsDrection(vector<vector<char>>& board, string word, 
        int i, int j, int k) {
            int m = board.size();
            int n = board[0].size();
            int len = word.length();
            if (i<0 
                || i>=m
                || j<0
                || j>=n
                || k >= len
                || board[i][j] == '\0'
                || board[i][j] != word[k]
            ) {
                return false;
            }
            //能走到这里说明board[i][j]==word[k]
            if (k==len-1) {return true;}
            
            //标识被访问过
            board[i][j] = '\0';

            //编程小技巧，方向数组，分别表示上，下，左，右
            int map[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
            bool res = false;
            for (int kk = 0; kk <4;kk++) {
                res = res || dfs(board, word, i+map[kk][0], j+map[kk][1], k+1);
            }
            
            //这样使用vector会超时
            //vector<vector<int>> direct={{-1,0},{1,0},{0,-1},{0,1}};
            // bool res = false;
            // for (int kk=0;kk<4;kk++) {
            //     res = res || dfs(board, word, i+direct[kk][0], j+direct[kk][1], k+1);
            // }
                      
            //回溯被访问的节点
            board[i][j] = word[k];

            return res;
    }
};
