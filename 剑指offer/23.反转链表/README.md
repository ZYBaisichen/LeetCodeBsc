<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-21 20:35:37
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210521 链表
本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list

# 题目描述
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 
``` cpp
示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：

0 <= 节点个数 <= 5000

```





# 思路(C++)

## 多指针一遍扫描
用三个指针，q, p, n，分别指向前一个节点，当前节点，后一个节点.

每次做反转时执行下面操作:
``` cpp
p->next=q;
q=p;
p=n;
n=n->next;
```

### 边界
- head为空则返回空
- 初始p为head，q为NULL，n为head->next
- n挪到最后一个为NULL时，p指向最后一个节点，将p->next指向q


### 复杂度
时间复杂度：O(n)

空间复杂度：O(1)