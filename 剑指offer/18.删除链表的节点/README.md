<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-13 10:52:17
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210514 链表

# 题目描述
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

``` cpp
示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
```


# 思路(C++)

## 挨个遍历
两个指针，一个指向前一个节点q，一个指向当前节点p，将p挨个往后找，直到找到等于val的节点。找到后q的next指向p的next

需要考虑要删除的节点为第一个和最后一个情况

### 复杂度
时间复杂度：O(n)
空间复杂度：O(1)