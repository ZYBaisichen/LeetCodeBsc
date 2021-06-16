
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-16 21:39:19
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210614 矩阵、数学

# 题目描述
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 

提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)


## 位运算

根据B数组的定义，列举出矩阵，如下图：

<div align=center>
<img src="https://github.com/ZYBaisichen/MarkdownImages/blob/main/66_%E6%9E%84%E5%BB%BA%E4%B9%98%E7%A7%AF%E6%95%B0%E7%BB%84.png" />
</div>


 可以看到对于下三角来说B[i]的值依赖B[i-1]的值乘以A[i-1], 上三角来说B[i-1]的值依赖B[i]乘以A[i], 计算上下三角时逐级相乘，可以达到O(n)的复杂度。



注意整数相乘可能会越界，需要在计算时将计算转换为long类型


### 复杂度
时间复杂度：O(n), 计算上三角和下三角各需要O(n)的复杂度

空间复杂度：O(1)

作者：jyd
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

