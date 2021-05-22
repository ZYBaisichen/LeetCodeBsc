
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-21 20:49:57
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210522 二叉树

注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/

# 题目描述
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

 
``` cpp

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false
``` 

限制：

0 <= 节点个数 <= 1000



# 思路(C++)

## 递归
- 问题分解：
  
  观察到如果一颗树如果时对称序列，则它的前序遍历序列和对称前序遍历(跟节点，右节点，左节点)序列相同，包括了null

  所以对两个相同的树，一个用前序遍历一个用前序遍历，一个用对称前序遍历

- 原子问题代码：
``` cpp
rootA和rootB不同时不为空或val不相同时，返回false

对rootA->left和rootB->right做同样判断

对rootA->right和rootB->left做同样判断

结果相与得到最终结果
```

- 结束条件：
  - rootA和rootB不同时不为空或val不相同时，返回false

### 复杂度
时间复杂度：O(n)， 遍历n个树节点

空间复杂度：O(1)