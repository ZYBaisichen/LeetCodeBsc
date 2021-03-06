
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-11 15:44:54
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210611 数组、数学、滑动数组

# 题目描述
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 暴力枚举

题目可以抽象为求大小为n-1的数组中和等于target的子数组。依次遍历数组，以nums[i]为开头往后找，依次求和，并保存中间元素，如果等于target则将中间子数组放入结果集；如果大于target则结束寻找，查找以nums[i+1]为开头是否有和为target的子数组

### 复杂度

时间复杂度：$O(n-2 + n-2 + n-3 + ... + 2) = O((n-1)n/2) = O(n^2)$
空间复杂度：O(n)， 最长借助n-2个元素的中间数组

## 求和公式

因为要求连续，数字之差为1，用等差数列求和；设子数组的左右边界为l和r，则其和为

$s = (l+r)*(r-l+1)/2$ (1)

当左边界l确定时，可以令数组和为target，化简(1)式，解下述一元二次方程：

$r^2+r-(2*target+l^2-l) = 0$ (2)

r的解为
$[-1 \pm \sqrt{1+4*(2*target+l^2-l})]/2$

由于r大于0，所以如果有解，则一定是
$[-1 + \sqrt{1+4*(2*target+l^2-l})]/2$

求出r之后要满足数组长度至少为2，即r>l

### 复杂度
时间复杂度：O(n）至少有两个数字，所以至多循环target/2次，时间为O(N)；循环内O(1)计算出r；考虑结果稀疏，存储结果的过程为常量级别O(1)

空间复杂度：O(1)，l和r额外空间

## 滑动窗口
> 看到这个题解，挺有趣，也实现一下。压缩滑动窗口

用一个滑动窗口，窗口中的所有元素构成了一个数组的子数组；设其边界为l和r；窗口向右滑动，每次判断窗口内元素和和target的大小关系，当大于target时需要缩小，左边界向右移动一个；当小于target时需要增大，右边界移动一个元素。

算法：

1. 初始化：左边界l=1, 右边界j=2, 元素和为s=3，结果集res
2. 循环：
   1. 循环当i>=j时跳出；
   2. 当s>target时，更新s, 向右移动左边界
   3. 当s<target时，向右移动右边界，更新s
   4. 当s==target时，将窗口内元素放入结果集， 并向右移动左边界
3. 返回值：res集合

### 复杂度
时间复杂度：O(n), 要满足i<j则至多循环target次；解稀疏，忽略将窗口元素放在结果集的时间

空间复杂度：O(1)
