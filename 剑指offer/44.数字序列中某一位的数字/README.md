
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-02 12:00:16
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210527 数学

注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/


# 题目描述
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0
 

限制：

0 <= n < 2^31

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31

# 思路(C++)
> 注意这里的输入n也是从0开始计数的
## 数学规律
观察到，第n位数字是多少一定和当前这一位所在的数字位数有关，比如n=5是在个位数5里，n=11, 在两位数10中，对于整个的位数跳变过程中，满的m位数的数量是一定的，通过从小位数到大位数的递减，就可以知道第n位在哪一个位数数字里面。

即m位数的开始数字为start，数位数量为m；
|数字范围|位数(n)|满数位数量|满数位的总位数|
|------|-------|--------|------------|
|1-9|1|9|9|
|10-99|2|99-10+1=90|90*2=180|
|100-999|3|999-100+1=900|900*3=2700|
|...|...|...|...|
|start-end|m|9*start|9*start*m|

由上表即可退出各个m位数下的满数位的总位数为$count_m=9*start*m$

根据以上分析，可将求解分为三步：
1、确定n所在数字的位数，记为m：
循环执行n减去一位数、两位数、...的满数位数量$count_m$，直到n低于当前$count_m$结束
2、确定n所在的数字，记为num
从$start_m$开始计数，第n位在(n-1)/m个数字中，这里n减一是因为start是从xxx0开始的，要以0为基准
3、确定n是num中的哪一位，返回结果
所求数位设为数字num的第(n-1)%m位（数字的首个数位为第0位）



### 复杂度
时间复杂度：O(n)

空间复杂度：O(n)

