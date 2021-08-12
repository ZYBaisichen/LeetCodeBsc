<!--
 * @Author: baisichen
 * @Date: 2021-04-27 14:19:05
 * @LastEditTime: 2021-08-12 13:42:46
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210812 autox面试
https://leetcode-cn.com/problems/course-schedule-iv/

# 题目描述
你总共需要上 n 门课，课程编号依次为 0 到 n-1 。

有的课会有直接的先修课程，比如如果想上课程 0 ，你必须先上课程 1 ，那么会以 [1,0] 数对的形式给出先修课程数对。

给你课程总数 n 和一个直接先修课程数对列表 prerequisite 和一个查询对列表 queries 。

对于每个查询对 queries[i] ，请判断 queries[i][0] 是否是 queries[i][1] 的先修课程。

请返回一个布尔值列表，列表中每个元素依次分别对应 queries 每个查询对的判断结果。

注意：如果课程 a 是课程 b 的先修课程且课程 b 是课程 c 的先修课程，那么课程 a 也是课程 c 的先修课程。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)
floyd算法改进，只需记录i到j是否可达即可

floyd算法参考:https://www.bilibili.com/video/BV1w54y1Q79E?p=1&share_medium=iphone&share_plat=ios&share_session_id=00475C62-CDC7-48E1-BE27-35524F2D8471&share_source=WEIXIN&share_tag=s_i&timestamp=1628746502&unique_k=Dnrjhe

下图为floyd算法的计算过程：
在第四个节点插入的时候，1到3已经判断过从2到3了，也判断过了从3、从1到3，所以第四个节点加入时，判断的是能否从4到3，但实际上是在插入了三个节点的基础上判断的，是走了三步之后的判断，时第四步的判断。

<div align=center>
<img src="https://github.com/ZYBaisichen/MarkdownImages/blob/main/floyd%E7%AE%97%E6%B3%95%E6%8E%A8%E5%AF%BC.jpeg" />
</div>

### 复杂度
时间复杂度：O(n^3)，n次节点插入，每次需要更新一遍图耗时$n^2$
空间复杂度：O(n^2)，不用保存路径，只需记录是否可达即可