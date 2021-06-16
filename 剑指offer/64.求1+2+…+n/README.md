
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-16 11:45:56
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210613 

# 题目描述
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45
 

限制：

1 <= n <= 10000
通过

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qiu-12n-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)


## 动态规划
详情见：[股票问题](121.best-time-to-buy-and-sell-stock)

遍历一遍记录历史最低点，和最大利润

### 复杂度
时间复杂度：使用快排排序，复杂度为O(nlog(n))

空间复杂度：遍历数组复杂度为O(n)


