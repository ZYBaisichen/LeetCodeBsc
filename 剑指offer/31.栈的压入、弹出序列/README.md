
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-24 13:31:34
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210523 栈

注意：本题与主站 946 题相同：https://leetcode-cn.com/problems/validate-stack-sequences/


# 题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

 

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。


# 思路(C++)

## 模拟栈进出

模拟栈的进出，遍历pushed数组，将pushed[i]入栈；

然后判断如果popped[j]和栈顶元素相同，直到不同或栈为空为止

循环完pushed数组之后，栈不为空则代表poped序列不是pushed的弹出序列


### 复杂度
时间复杂度：O(n)

空间复杂度：O(1)