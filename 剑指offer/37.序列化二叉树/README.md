
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-25 13:11:25
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210525 二叉树、数组

注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

# 题目描述
请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"


# 思路(C++)

## 前序遍历转换

前序遍历转换成字符串, 按照逗号分隔

递归建立二叉树，先建当前节点，再建立左子树和右子树

### 复杂度
时间复杂度：O(n)， 每个节点进入一次

空间复杂度：O(1)
