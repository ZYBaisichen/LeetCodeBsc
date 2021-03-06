<!--
 * @Author: baisichen
 * @Date: 2021-04-24 16:02:51
 * @LastEditTime: 2021-04-29 10:44:20
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210424 每日一题
# 题目描述
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

>+ 你可以认为每种硬币的数量是无限的。


# 思路(C++)

## 动态规划求解
背包问题，这里面主要的状态是凑成总金额所需硬币的数量。
1. 状态定义：用dp[i]表示凑成金额为i所需要硬币的最小数量
2. 状态转移：因为对于第j个硬币coins[j]，假设选用他刚好能够组成金额i(i>=corns[j]),则整体需要的最小硬币数dp[i]等于选用这个硬币之前的面值和需要的最小硬币数，即dp[i-coins[j]]+1
4. 初始边界：dp[0]=1，在所有都不选择的情况下和为0
5. 伪代码：
   dp[0] = 1;
   遍历1到amount，coins，找到所有dp[i-coin], 求最小值之后+1放在dp[i]上
   dp[amount]为答案
### 复杂度
时间复杂度：O(n*amount)
空间复杂度：借用dp数组大小为amount,O(amount)
