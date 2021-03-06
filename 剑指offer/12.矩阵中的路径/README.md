<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-10 22:08:42
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210510 DFS，递归，减枝、回溯
和79题目相同：https://leetcode-cn.com/problems/word-search/
# 题目描述
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

``` cpp
示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

```


# 思路(C++)
## DFS+减枝
以遍历board，以每个
- 问题分解：
要在board中找到整个word="ABCCED"，就需要在board中找到"ABCCE", 以此类推，最后需要先找到第一个字母A，然后再找第二个字母B。

第一个字母可以在m*n个元素中遍历，找到第一个字母(用k=0表示)，k加1，以这一个字母当前位置(i,j)开始往上，往下，往左，往右查找第二个字母(k=1)，如果找到则继续以当前位置继续往后查找，否则返回False



- 原子问题代码：
``` cpp
如果当前字母(i,j)和第k个字母匹配，置board[i][j]为'\0'
往左找第k+1个字母
往右找第k+1个字母
往上找第k+1个字母
往下找第k+1个字母
寻找结果做或运算得到最终结果
board[i][j]为原值
```

- 结束条件：
当前所在位置不在数组的范围内，并且k小于数组长度-1，返回FALSE
当前所在位置和word[k]不匹配时，返回false
当前board[i][j]为'\0'时，表示已经判断过，此路不通，返回false
k==len-1，返回true

### 复杂度
时间复杂度:$O(3^(len)*m*n)$

字符串长度为len，每次寻找有三种选择，舍弃回头的方向，查找的复杂度为$O(3^(len))$，矩阵中公有m*n个七点，时间复杂度为O(m*n)

空间复杂度：O(len)
搜索过程中递归深度不会超过len，系统栈空间占用K个

空间复杂度 O(K)O(K) ： 搜索过程中的递归深度不超过 KK ，因此系统因函数调用累计使用的栈空间占用 O(K)O(K) （因为函数返回后，系统调用的栈空间会释放）。最坏情况下 K = MNK=MN ，递归深度为 MNMN ，此时系统栈使用 O(MN)O(MN) 的额外空间。

