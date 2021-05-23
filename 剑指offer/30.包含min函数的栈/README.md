
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-23 08:38:10
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210523 栈

注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/


# 题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 
``` cpp
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```

提示：

各函数的调用总次数不超过 20000 次
 

# 思路(C++)

## 双栈

因为栈只能先进后出，所以仅使用一个栈是无法实现每次在O(1)的时间内拿到当前栈中的最小值的。

所以使用两个栈，一个栈st1记录所有入栈的数据，另一个栈st2的栈顶元素为当前栈中的最小元素。

为了保证st2的栈顶在出栈之后栈顶也是st1的中的最小元素，所以要在入st2的时候要判断，当前元素num是否大于st2的栈顶元素top_num，因为num在top_num之后进入的的，所以在num出栈之前top_num一定不会出栈，故当num>top_num时，top_num一定会作为比num小的数字返回。当num<top_num时，则入st2

### 复杂度
时间复杂度：O(n)

空间复杂度：O(1)