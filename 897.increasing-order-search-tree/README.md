# 日期/类型
20210425 每日一题
# 题目描述
给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。


# 思路(C++)
因为原始树是一个二叉搜索树，所以中序遍历出来肯定是有序的。目的是将中序遍历出来的所有元素都父节点的右子树上，为了不增加额外的空间，对问题进行抽象，首先来看中序遍历的代码：
``` Cpp
void increasingBSTCore(TreeNode* root) {
    if (root) {
        increasingBSTCore(root->left);
        cout<<root<<" ";
        increasingBSTCore(root->right);
    }
}
```
本质上就是要在$cout<<root<<" ";$处做做文章，设置一个新的节点，用cur记录链表的最后一个节点，当遍历到中序时，将cur->right设置为root, root->left设置为空，cur重新指向最新的节点

### 复杂度
时间复杂度：O(n), 需要遍历所有节点
空间复杂度：O(1)，不占用额外空间
