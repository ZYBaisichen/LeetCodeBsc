<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-12 10:27:52
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210510 DP、贪心
与343题目相同：https://leetcode-cn.com/problems/integer-break/

# 题目描述
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

``` cpp
示例 1：
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

提示：
2 <= n <= 58


# 思路(C++)
## 动态规划
一、初步分析
要将一个长度为n的绳子分段，分的第一段长度可以为1,2,...,n, 而每一段可以再分，比如2可以分为两个1或一个2，，长度为2的绳子得到的最大成绩即为max(2, 1*1)

二、 状态定义
定义dp[i]标识长度为i的绳子做拆分所能得到的最大乘积。

三、状态转移
dp[i] = max(i, dp[i-k]*k), k=1,2,...,i/2

三、初始化。
长度为1的绳子只能分成1段，所以dp[1] = 1

四、结果输出
dp[n]即为最终结果

五、注意
注意这里题目要求必须剪一次，所以这里还涉及到绳子从多长开始就可以不用必剪一次了。没看太明白，等哪天感冒好了清醒了再回来看：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/jian-zhi-offermian-shi-ti-14suan-fa-zhon-6bxx/

### 复杂度
时间复杂度:$O(n^2)$
循环n次，对于每个长度为i的绳子，都遍历1到i/2得到dp[i]，i最大为n。

空间复杂度：O(n)
借用长度为n的dp数组

## 自然数分解算法
这个是通过算术-集合平均值不等式来做的推导，结论是尽量拆分成3，剩下的余数如果是2则直接相乘，如果是1则需要拿出一个3出来拆分成2*2。**没太懂，感冒好了再看，链接先放上：**
https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
https://zh.wikipedia.org/wiki/%E7%AE%97%E6%9C%AF-%E5%87%A0%E4%BD%95%E5%B9%B3%E5%9D%87%E5%80%BC%E4%B8%8D%E7%AD%89%E5%BC%8F
