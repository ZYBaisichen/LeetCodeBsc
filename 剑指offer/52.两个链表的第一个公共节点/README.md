
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-08 11:11:14
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210608 链表

本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

# 题目描述
入两个链表，找出它们的第一个公共节点。

如下面的两个链表：

在节点 c1 开始相交。


示例 1：

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

# 思路(C++)

## 链表操作

> 我换成你，你换成我，我走过你走的路，我们必定相遇

设第一个链表长度为m，第二个链表长度为n，第一个重复指针之前的节点第一个指针的个数为l1，第二个指针的个数为l2，重复的节点个数为s。用两个指针p、q初始时分别指向第一个和第二个节点，往后遍历链表，当遍历到末尾时互换指向的链表，走到第一个重复的节点时，p指针走了l1+l2+s步，q指针走的步数为l2+l1+s，两指针走的步数相同，必定会相遇

边界：当两个链表没有重复节点时，两个指针都走了m+n步，必定同时指向NULL

### 复杂度
时间复杂度：O(n）

空间复杂度：O(1)
