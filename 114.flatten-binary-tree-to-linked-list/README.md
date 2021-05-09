<!--
 * @Author: baisichen
 * @Date: 2021-05-08 10:21:39
 * @LastEditTime: 2021-05-08 15:46:53
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210508 二叉树

# 题目描述
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？


# 思路(C++)
## 递归前序遍历
前序递归遍历，每个节点放入一个数组中，然后遍历数组，将每个元素的左子节点置为null，右节点指向下一个元素

### 复杂度
时间复杂度：O(n)，可以认为访问了多少节点，时间复杂度就为多少
空间复杂度：O(n), 借用了一个长度为n的数组

## 原地展开递归求解

- 问题分解：

要将一颗树拉平成一个链表，只需要将root节点的左右子树分别拉平成一个链表，然后将root->right指向左子树的开始节点，然后循环找到左子树的最后一个节点leftLast，将lefLast->right指向原root的右节点。

- 原子问题代码：
子问题简单的情况是只有三个节点(即一个父节点带两个子节点)的情况，设这三个节点的父节点是root， 只需要运行下面代码即可将这个最小的树拉平：
``` cpp
origin_right=root->right;
root->right=root->left; 
root->left=NULL;
tmp = root->right;
while(tmp)tmp=tmp->right; 
tmp->right = origin_right;
```

- 结束条件：
当碰到节点为NULL时，不需要进行递归拉平，则返回