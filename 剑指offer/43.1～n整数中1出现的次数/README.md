
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-31 14:50:00
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210527 数学、大数

注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/


# 题目描述
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

 

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31

# 思路(C++)

## 延伸思考-数位dp
- 开始的时候看错题了，看成了要求1到最大的n位数之间的1的个数，比如1到最大两位数之间1的个数就是1-99之间的1的个数

一位数的1的个数为1个， 两位数的个数组成为:十位的1公有10个，个位1的个数为9个，即高位从1到9乘以一位数时1的个数；从而可以推广，当知道了n-1位数中1的个数为dp[n-1]，n位数为10*dp[n-1] + dp[n-1]

## 数学推导
> 这个题用到了很强的数学技巧，题解中是直接给出了数学规律的结论，即将每个数位分为0、1、2-9进行计算当前数位1的个数。背后的规律其实是往数位dp上靠
> 参考题解1：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/dong-hua-mo-ni-wo-tai-xi-huan-zhe-ge-ti-vxzwc/
> 参考题解2：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/cchao-100de-shu-xue-jie-fa-by-ffreturn-ije9/

由于要求数字中所有1出现的次数，所以枚举每一位数上出现1的次数不会出现重复计算。

记枚举到的当前位为第pos位，位因子为$num_i = 10^(pos-1)$, 记录高位为high， 低位为low。

当前数字为0时，相当于需要做退位，对于高位从0到high-1每一个数字，当前位有一种可能为1；此时低位每一位都可以选择0-9，所以总的当前位1的个数为$high*num_i$

当前数字为2-9时，对于高位0到high的high+1个数，当前位都有一种可能出现1，当为1时，低位的数量为位因子$num_i$， 汇总下来当数字为2-9时，当前pos位出现1的次数为$(high+1)*num_i$

当前数字为1时，低位不能打满整个位因子，所以分成两部分看，比如2014分成0-2004和2004-2014两部分，对于十位来说，前面一部分1的个数为$high*num_i$， 后面一部分十位为1的数量为low+1=5(因为是从0开始计数)。所以当前pos位出现1的次数为$high*num_i+low+1$


### 复杂度
时间复杂度：O(n)

空间复杂度：O(n)

