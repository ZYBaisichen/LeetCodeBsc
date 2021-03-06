
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-08 11:30:36
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210606 堆，动态规划
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

# 题目描述
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

# 思路(C++)

## 堆
所有的丑数都是2、3、5做乘法的出来的，1位特殊的丑数，除了1的其他丑数都可以通过前面的丑数乘以2或3或5得到。维护一个最小堆，初始堆中只有1，每次取出一个元素x，将2x,3x,5x入堆，同时为了避免重复元素，使用哈希集合去重，避免相同元素入堆。

在排除无重复元素的情况下，第n次从堆中取出的元素即为第n个丑数

### 复杂度
时间复杂度：O(nlog(n))， 每次调整堆的复杂度为log(n)，元素个数为n

空间复杂度：O(n)，维护一个map，判断是否为重复元素

## 动态规划
一、初步分析

由于使用堆排序需要存储较多的丑数放在map中，空间复杂度较高，维护最小堆的过程也导致了时间复杂度较高，使用动态规划方法进行优化。

所有的丑数都是2、3、5做乘法的出来的，1位特殊的丑数，除了1的其他丑数都可以通过前面的丑数乘以2或3或5得到。所以下一个要遍历的丑数一定是前面还没有被使用过的丑数(没有乘以2、3、5生成过一个新的丑数)的乘数。


二、 状态定义

定义dp[i]表示第i个丑数，第一个丑数是1，即dp[1] = 1

三、状态转移

假设第n-1个丑数为dp[n-1]， 则要求的dp[n]为最接近dp[n-1]的丑数，由于每个丑数都是前面的某一个丑数乘以2或3或5得到的，所以dp[n-1]可以表示成：$dp[n-1] = min(p2*2, p3*3, p5*5)$，判断dp[n-1]与哪个乘数相等，则对应的指针加1


正确性证明**(没看太明白，先抄过来吧)**：

出处：https://leetcode-cn.com/problems/chou-shu-lcof/solution/chou-shu-by-leetcode-solution-0e5i/

对于i>1, 在计算dp[i]时，指针$p_x(x=2,3,5)$的含义是使得dp[j]*x>dp[i-1]的最小的下标j，即当$j>p_x$时，$dp[j]*x>dp[i-1]$；当$j<p_x$时，$dp[j]*x<=dp[i-1]$。

所以，对于i>1, 在计算dp[i]时，$dp[p_2]*2, dp[p_3]*3, dp[p_5]*5$都大于dp[i-1]，$dp[p_2-1], dp[p_3-1], dp[p_5-1]$都小于dp[i-1]。 令$dp[i] = min(dp[p_2]*2, dp[p_3]*3, dp[p_5]*5)$， 则dp[i]>dp[i-1]且dp[i]为大于dp[i-1]的最小丑数

注：上面证明的核心是想证明在p2,p3,p5在加一之后取最小值得到的第i个丑数是最接近第i-1个丑数的丑数，因为丑数的序列是离散的，每次作为指针的p2,p3,p5都只会往后移动1个，上述便证明了，当p2,p3,p5乘以对应因子之后必定都大于等于dp[i-1], 减一之后都必定小于等于dp[i-1]，所以他们三个乘了因子之后取到的最小值是大于dp[i-1]的数且是最接近dp[i-1]的数，即所求dp[i]


四、初始化
定义动态规划的边界条件，初始状态下是什么

五、结果输出
分析出哪个状态是最终的答案

六、空间复杂度优化
动态规划的思想本质上是用空间来换时间，那么如何在不牺牲时间的前提下降低空间复杂度，就是本阶段需要思考的问题。典型的优化如[01背包问题的优化](acwing02.ZeroOnePack)、[剑指47](剑指offer/47.礼物的最大价值)

