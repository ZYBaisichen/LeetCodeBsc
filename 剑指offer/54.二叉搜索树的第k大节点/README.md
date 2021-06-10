
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-08 11:11:14
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210610 二叉搜索树

# 题目描述
给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 二叉搜索树

二叉搜索树的中序遍历是正序的，所以中序遍历的倒叙即为倒序的，即先遍历右子树、再访问当前节点，再遍历左子树

用一个全局计数器，拿到第k大的数返回，结束递归

### 复杂度
时间复杂度：O(n）

空间复杂度：O(1)
