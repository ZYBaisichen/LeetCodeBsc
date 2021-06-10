
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-10 10:50:30
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210610 二分查找

注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

# 题目描述
统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 二分查找左右边界
排序的数组中找满足某些数字最容易想到的是二分法，找到这个数字在数组中出现的左边界l和右边界r，该数字出现的次数即位r-l

定义start，end，mid=(end-start)/2+start分别为当前要寻找的数组的开始、结束和中间元素。

如果nums[mid]>tar, 则tar在mid左边

如果nums[mid]<tar, 则tar在mid右边

如果nums[mid]==tar, 则tar的左边界在mid的左边，右边界在mid的右边

用两次二分可以找到tar的左右边界，然后相减即可得到tar出现的次数

寻找左边界和右边界的规则不同，为了让二分的逻辑刚具一般性，可以分别计算tar的右边界r1，计算tar-1的右边界r2。然后tar的总数量为r2-r1+1，这里因为数组中都为整数，所以tar-1的右边界一定为tar。 这种变换特别像概率里面的分布函数F(x)

作者：hui-fei-de-wan-xiong-t
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/solution/xun-zhao-zuo-you-bian-jie-by-hui-fei-de-dlgz4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
### 复杂度
时间复杂度：O(log(n)）

空间复杂度：O(1)
