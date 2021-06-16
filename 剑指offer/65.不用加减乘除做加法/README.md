
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-16 21:26:04
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210614 位运算

# 题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。


示例:

输入: a = 1, b = 1
输出: 2
 

提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)


## 位运算

|a|b|当前和|进位|
|-|-|-----|---|
|0|0|0|0|
|0|1|1|0|
|1|0|1|0|
|1|1|0|1|

观察到两个二进制为相加当前保留位为a^b，进位为a&b

用两个整数分别标识进位整数和当前位整数，不停的计算当前位a^b赋值为a，不停的计算进位(a&b)<<1赋值给b(这样下一次循环就相当于加上了进位)。


### 复杂度
时间复杂度：O(1), 最差情况下进位一直为1的情况，循环32次

空间复杂度：遍历数组复杂度为O(1)

作者：jyd
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

