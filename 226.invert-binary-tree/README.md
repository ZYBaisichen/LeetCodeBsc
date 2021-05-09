<!--
 * @Author: baisichen
 * @Date: 2021-05-08 10:21:39
 * @LastEditTime: 2021-05-08 10:58:59
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210508 翻转二叉树

# 题目描述
翻转一颗二叉树


# 思路(C++)
递归遍历二叉树，左节点和右节点的值进行交换

伪代码框架：
``` cpp
/* 二叉树遍历框架 */
void traverse(TreeNode* root) {
    if (!root) return;
    // 前序遍历
    traverse(root->left);
    // 中序遍历
    traverse(root->right);
    // 后序遍历
}
```

### 复杂度
时间复杂度：O(n)，可以认为访问了多少节点，时间复杂度就为多少
空间复杂度：O(1), 借用两个变量