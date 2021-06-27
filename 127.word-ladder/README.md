<!--
 * @Author: baisichen
 * @Date: 2021-04-27 14:19:05
 * @LastEditTime: 2021-06-26 16:26:57
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210626 单词接龙
https://leetcode-cn.com/problems/word-ladder/

# 题目描述
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：

序列中第一个单词是 beginWord 。
序列中最后一个单词是 endWord 。
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典 wordList 中的单词。
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。

 
示例 1：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
 

提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)
本题要求的是从一个单词到另一个单词的最短转换路径，我们将变换一个字母得到的单词和原单词视为相邻节点，这样从开始单词到终点单词就构成了一个图，图中的节点均为字典wordList中的单词。

这样就把单词变换转换为求从开始单词节点到结束单词节点的最短路径，涉及到图的最短路径问题最先想到的是BFS。(因为深度是不确定的，所以使用DFS不太好)


## 朴素BFS
用一个map记录枚举到的单词是在第几层。

从startWord开始BFS，当前节点为i，层数为level，枚举每一位，将第j位依次替换为其他字母world_tmp，并将层数置为level+1，如果为endworld，当前层数和res取最小值。

### 复杂度
时间复杂度：O(26^n)，单词的每一位都有26种字母的可能，
空间复杂度：O(26^n)，每种单词占用一种可能

## 双向BFS

由于搜索空间的爆炸导致朴素BFS的搜索空间爆炸，会超时，使用双向BFS搜索，分别从beginWord向endWord、从endWord向beginWord两个方向搜索，当其中一个方向搜索到的节点是另一个方向搜索过的，说明有一条路经可以从beginWord到endWord，路经长度为两个方向搜索的层级之和。这样可以显著的减少搜索的空间


用两个hashmap记录已经搜索过的词和其层数