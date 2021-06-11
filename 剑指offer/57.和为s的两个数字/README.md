
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-11 14:27:10
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210611 数组

# 题目描述
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
 

限制：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 对撞指针
数组元素为排序的，用两个指针i和j，一个指向开头，一个指向结尾。

令sum = nums[i]+num[j]， 当sum>s时，由于nums[i] < nums[i+k], nums[j]加上i之后的每个数字都会大于s, 所以j可以剔除，j--; 当sum<s时，由于nums[j]>nums[j-k], 所以nums[i]加上j之前的每个数字都会小于s，可以剔除i，i++; 当sum==s时直接返回。




### 复杂度
时间复杂度：O(log(n)）

空间复杂度：O(1)
