<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-21 20:49:57
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210521 链表
注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/

# 题目描述
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

``` cpp
示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：
```

0 <= 节点个数 <= 10000

# 思路(C++)

## 多指针一遍扫描

- 问题分解：
  要想在A中查找是否有B树，首先需要找到一个根节点rootA和B的rootB相同，然后查看以rootA为节点的树能否和B相同，如果不相同继续改变rootA，相同返回找到。
  
  判断两个树是否相同可以通过前序递归遍历来判断

- 原子问题代码：
``` cpp
如果rootA与rootB的val相同， 判断以rootA为节点能否找到与B树相同的树。

如果找到返回true

如果没找到查看rootA的左子树能否找到B树

如果还没找到查看rootA的右子树能否找到B树

如果都没找到则返回false
```

- 结束条件：
  - 遍历A树的出口是当前节点为空，时返回false
  - 判断rootA的树与B是否相等，rootB到空时说明全找到了返回true，rootA为空时返回false，rootA->val!=rootB->val时返回false

### 复杂度
时间复杂度：O(n*m)， 遍历n个A节点，每次判断相等遍历m个B树的节点

空间复杂度：O(1)