<!--
 * @Author: baisichen
 * @Date: 2021-04-24 16:02:25
 * @LastEditTime: 2021-04-27 21:07:32
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210427 背包问题
# 题目描述
给你一个 只包含正整数的非空数组nums。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
``` cpp
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
```

# 思路(C++)
## 一、动态规划求解

类似背包问题，目的是求选取元素和为target的排列数，
1. 状态定义：用dp[i]表示数字和为i的方案个数，最终要求的就是dp[target]
2. 状态转移：对于nums中的每个数num，dp[i]如果想选取了num作为排列的最后一个元素，则一定要num<=i, 对于元素之和为i-num的每一种排列，在其后面加上num就等于i的排列，所以此时num下的dp[i]=dp[i-num]。最终dp[i]=sum(dp[i-nums[j]]), j=0,1,..,n
3. 初始边界：dp[0]=1，在所有都不选择的情况下和为0
4. 伪代码：
   dp[0] = 1;
   遍历1到target，nums，找到所有dp[i-num]加到dp[i]上
   dp[target]为答案
### 复杂度
时间复杂度：O(n*target)
空间复杂度：借用dp数组大小为target,O(target)
