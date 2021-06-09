
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-09 15:25:33
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210608 归并排序

# 题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 归并排序
逆序对一直和归并排序息息相关，在归并排序合并两个已经有序seq1、seq2的的过程中，如果seq1[p]>seq2[q]时，则p到seq1末尾所有有元素相对于seq2[q]都构成一个逆序对，共有(r1-p+1)个。

重复上述过程，当归并排序完成后也就计算出来了逆序对的数量。

借用大神的一张图即可说明：

<div align=center>
<img src="https://github.com/ZYBaisichen/MarkdownImages/blob/main/%E9%80%86%E5%BA%8F%E5%AF%B9.png" />
</div>

### 复杂度
时间复杂度：O(n），归并排序复杂度为O(Nlog(N))

空间复杂度：O(n)，归并过程中需要占用N的额外空间
