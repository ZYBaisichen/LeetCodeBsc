<!--
 * @Author: baisichen
 * @Date: 2021-05-08 10:21:39
 * @LastEditTime: 2021-05-08 10:58:34
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210508 二叉树

# 题目描述
给定一个二叉树的根节点 root ，返回它的 中序 遍历。


# 思路(C++)
二叉树中序遍历的过程是先遍历左子树，再访问当前节点，最后遍历右子树
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