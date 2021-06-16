
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-13 14:03:59
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210613 单调队列

注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/

# 题目描述
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


# 思路(C++)

## 单调队列
在新元素入队和旧元素出队的过程中，始终能够在O(1)时间内得到队列中的最大值，这个是典型的单调队列，用双向队列实现.

只不过这里，将求滑动窗口的最大值变形为了一个正常队列的出队和入队操作，额外用一个队列来实现原来数组的功能

