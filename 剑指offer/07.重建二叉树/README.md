# 日期/类型
20210509 二叉树、递归
# 题目描述
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

``` cpp
例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

```

# 思路(C++)

## 递归解法
- 问题分解：
我们在建立二叉树的过程中，首先需要建立当前节点root，然后建立左子树让root->left指向它；然后建立右子树让root->right指向它。

前序遍历的数组中的第一个值即为root；由于没有重复数字，所以在中序遍历中root数字前面的数字是其左子树，右边的子数组是其右子树。

要建立左子树的话，只需要以中序数组root左边的数组为左子树的中序遍历结果，假设这个子数组有n个数字，然后从前序数组中往后找n个数就为左子树的前序遍历结果，就可以用相同的方法来建立左子树了。右子树同理，其中序结果为中序数组中root右边的子数组，前序遍历结果为从n+1开始到最后的前序数组的子数组。

- 原子问题代码：
``` cpp
建立root;
找到左子树的前序和中序结果子数组
找到右子树的前序和中序结果子数组
left = 建立左子树; 
right = 建立右子树;
```

- 结束条件：
当前序结果和中序结果子数组长度为0时，返回NULL


### 复杂度
时间复杂度：O(n*n)), 按照建立root节点的次数来计算，建立n次root节点，然后每次root节点到中序数组中查找元素的复杂度为n
空间复杂度：O(n) ，最终建立的树开辟了n个节点的空间
