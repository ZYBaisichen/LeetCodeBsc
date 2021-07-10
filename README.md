<!--
 * @Author: baisichen
 * @Date: 2021-04-24 16:02:25
 * @LastEditTime: 2021-07-10 19:47:05
 * @LastEditors: baisichen
 * @Description: 
-->
# LeetCodeBsc
<div align=center>
<img src="https://github.com/ZYBaisichen/MarkdownImages/blob/main/leetcode_cn.jpeg" />
</div>

这个库是刷的力扣，中文版的leetcode，中国未来发展趋势肯定是方方面面国产化，所以中文还是很重要的。

LeetCode solutions in C++ 11 and Python3.

# leetcode题目目录
|NO.|Title|Solution|Note|Difficulty|Tag|相似题型汇总|
|---|-----|--------|----|----------|---|-------|
|acwing02|[01背包问题](https://www.acwing.com/problem/content/2/)|[C++](acwing02.ZeroOnePack/solution.h) |[Note](acwing02.ZeroOnePack)|简单|`背包dp`|见[题型分类汇总-背包问题](题型分类汇总.md#acwing&知乎经典背包九讲)|
|acwing03|[完全背包问题](https://www.acwing.com/problem/content/3/)|[C++](acwing03.CompletePack/solution.h) |[Note](acwing03.CompletePack)|简单|`背包dp`|见[题型分类汇总-背包问题](题型分类汇总.md#acwing&知乎经典背包九讲)|
|acwing04、05、06|[多重背包问题](https://www.acwing.com/problem/content/4/)|[C++](acwing04.MultiplePack/solution.h) |[Note](acwing04.MultiplePack)|困难|`背包dp`|见[题型分类汇总-背包问题](题型分类汇总.md#acwing&知乎经典背包九讲)|
|84|[柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)|[C++](84.largest-rectangle-in-histogram/solution.h) |[Note](84.largest-rectangle-in-histogram)|困难|`栈、单调栈`|见[题型分类汇总-栈](题型分类汇总.md#栈)|
|94|[二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)|[C++](94.binary-tree-inorder-traversal/solution.h) |[Note](94.binary-tree-inorder-traversal)|中等|`二叉树、递归`|见[题型分类汇总-二叉树](题型分类汇总.md#二叉树)|
|114|[二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)|[C++](114.flatten-binary-tree-to-linked-list/solution.h) |[Note](114.flatten-binary-tree-to-linked-list)|中等|`二叉树、递归`|见[题型分类汇总-二叉树](题型分类汇总.md#二叉树)|
|116|[填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)|[C++](116.populating-next-right-pointers-in-each-node/solution.h) |[Note](116.populating-next-right-pointers-in-each-node)|中等|`二叉树、递归`|见[题型分类汇总-二叉树](题型分类汇总.md#二叉树)|
|121|[买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)|[C++](121.best-time-to-buy-and-sell-stock/solution.h) |[Note](121.best-time-to-buy-and-sell-stock)|简单|`dfs、优化`|见[题型分类汇总-买卖股票问题](题型分类汇总.md#股票买卖系列问题)|
|122|[买卖股票的最佳时机ii](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)|[C++](122.best-time-to-buy-and-sell-stock-ii/solution.h)|[Note](122.best-time-to-buy-and-sell-stock-ii)|中等|`贪心、dp`|见[题型分类汇总-买卖股票问题](题型分类汇总.md#股票买卖系列问题)|
|123|[买卖股票的最佳时机III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)|[C++](123.best-time-to-buy-and-sell-stock-iii/solution.h)|[Note](123.best-time-to-buy-and-sell-stock-iii)|困难|`dp`|见[题型分类汇总-买卖股票问题](题型分类汇总.md#股票买卖系列问题)|
|188|[买卖股票的最佳时机IV](https://leetcode-cn.com/problems/combination-sum-iv/)|[C++](188.combination-sum-iv/solution.h)|[Note](188.combination-sum-iv)|困难|`dp`|见[题型分类汇总-买卖股票问题](题型分类汇总.md#股票买卖系列问题)|
|226|[反转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)|[C++](226.invert-binary-tree/solution.h) |[Note](226.invert-binary-tree)|简单|`二叉树、递归`|见[题型分类汇总-二叉树](题型分类汇总.md#二叉树)|
|239|[滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)|[C++](239.sliding-window-maximum/solution.h)|[Note](239.sliding-window-maximum)|困难|`数据结构、单调队列`|见[题型分类汇总-队列](题型分类汇总.md#队列)|
|309|[最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)|[C++](309.best-time-to-buy-and-sell-stock-with-cooldown/solution.h)|[Note](309.best-time-to-buy-and-sell-stock-with-cooldown)|中等|`dp`|见[题型分类汇总-买卖股票问题](题型分类汇总.md#股票买卖系列问题)|
|322|[硬币组合问题](https://leetcode-cn.com/problems/coin-change/submissions/)|[C++](322.coin-change/solution.h) |[Note](322.coin-change)|中等|`dp`|见[题型分类汇总-背包系列问题](题型分类汇总.md#leetcode背包相关变形问题)|
|363|[求矩形区域不超过K的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)|[C++](363.max-sum-of-rectangle-no-larger-than-k/solution.h) |[Note](363.max-sum-of-rectangle-no-larger-than-k)|困难|`边界遍历、贪心、dp`|见[题型分类汇总-区间最大问题](题型分类汇总.md#区间最大问题)|
|368|[最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/)|[C++](368.largest-divisible-subset/solution.h) |[Note](368.largest-divisible-subset)|中等|`排序、dp`|[300.最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)，见[题型分类汇总-集合问题](题型分类汇总.md#集合问题)|
|377|[组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)|[C++](377.combination-sum-iv/solution.h) |[Note](377.combination-sum-ivi)|中等|`dp背包`|见[题型分类汇总-leetcode背包相关变形问题](题型分类汇总.md#leetcode背包相关变形问题)|
|401|[二进制手表](https://leetcode-cn.com/problems/binary-watch/)|[C++](401.binary-watch/solution.h) |[Note](401.binary-watch)|简单|`位运算`|见[题型分类汇总-位运算](题型分类汇总.md#位运算)|
|416|[分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)|[C++](494.target-sum/solution.h) |[Note](494.target-sum)|中等|`dp背包`|见[题型分类汇总-leetcode背包相关变形问题](题型分类汇总.md#leetcode背包相关变形问题)|
|494|[ 目标和](https://leetcode-cn.com/problems/target-sum/)|[C++](416.partition-equal-subset-sum/solution.h) |[Note](416.partition-equal-subset-sum)|中等|`dp背包`|见[题型分类汇总-leetcode背包相关变形问题](题型分类汇总.md#leetcode背包相关变形问题)|
|518|[零钱兑换II](https://leetcode-cn.com/problems/coin-change-2/)|[C++](518.coin-change-2/solution.h) |[Note](518.coin-change-2)|中等|`dp、完全背包`|见[题型分类汇总-leetcode背包相关变形问题](题型分类汇总.md#leetcode背包相关变形问题)|
|714|[买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)|[C++](714.best-time-to-buy-and-sell-stock-with-transaction-fee/solution.h)|[Note](714.best-time-to-buy-and-sell-stock-with-transaction-fee)|困难|`dp`|见[题型分类汇总-买卖股票问题](题型分类汇总.md#股票买卖系列问题)|
|897|[递增顺序搜索树](https://leetcode-cn.com/problems/increasing-order-search-tree/)|[C++](897.increasing-order-search-tree/solution.h) |[Note](897.increasing-order-search-tree)|简单|`二叉树`|见[题型分类汇总-二叉树](题型分类汇总.md#二叉树)|


# 剑指offer系列
|NO.|Title|Solution|Note|Difficulty|Tag|相似题型汇总|
|---|-----|--------|----|----------|---|-------|
|剑指03|[数组中重复数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)|[C++](剑指offer/03.数组中重复的数字/solution.h) |[Note](剑指offer/03.数组中重复的数字)|简单|`哈希`| 见[题型分类汇总-哈希](题型分类汇总.md#哈希) |
|剑指04|[二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)|[C++](剑指offer/04.二维数组中的查找/solution.h) |[Note](剑指offer/04.二维数组中的查找)|中等|`数组`| 见[题型分类汇总-数组](题型分类汇总.md#数组) |
|剑指05|[替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)|[C++](剑指offer/05.替换空格/solution.h) |[Note](剑指offer/05.替换空格)|简单|`字符串`| 见[题型分类汇总-字符串](题型分类汇总.md#字符串) |
|剑指07|[重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)|[C++](剑指offer/07.重建二叉树/solution.h) |[Note](剑指offer/07.重建二叉树)|中等|`二叉树、二分递归`| 见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指09|[用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)|[C++](剑指offer/09.用两个栈实现队列/solution.h) |[Note](剑指offer/09.用两个栈实现队列)|简单|`栈、队列`| 见[题型分类汇总-栈](题型分类汇总.md#栈) |
|剑指10|[斐波那契数列I&青蛙跳台阶问题](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)|[C++](剑指offer/10.斐波那契数列I&青蛙跳台阶问题/solution.h) |[Note](剑指offer/10.斐波那契数列I&青蛙跳台阶问题)|简单|`数学、dp`| 见[题型分类汇总-斐波那契数](题型分类汇总.md#斐波那契数) |
|剑指11|[旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)|[C++](剑指offer/11.旋转数组的最小数字/solution.h) |[Note](剑指offer/11.旋转数组的最小数字)|简单|`数组、二分`| 和145相同、分类见[题型分类汇总-二分查找](题型分类汇总.md#二分查找) |
|剑指12|[矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)|[C++](剑指offer/12.矩阵中的路径/solution.h) |[Note](剑指offer/12.矩阵中的路径)|中等|`回溯、dfs`| 和145相同、分类见[题型分类汇总-回溯](题型分类汇总.md#回溯) |
|剑指13|[机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)|[C++](剑指offer/13.机器人的运动范围/solution.h) |[Note](剑指offer/13.机器人的运动范围)|中等|`回溯、dfs`|和145相同、分类见[题型分类汇总-回溯](题型分类汇总.md#回溯) |
|剑指14-i|[剪绳子i](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)|[C++](剑指offer/14.剪绳子i/solution.h) |[Note](剑指offer/14.剪绳子i)|中等|`dp、数学`|和343相同、分类见[题型分类汇总-区间最大问题](题型分类汇总.md#区间最大问题) |
|剑指14-ii|[剪绳子ii](https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/)|[C++](剑指offer/14.剪绳子ii/solution.h) |[Note](剑指offer/14.剪绳子ii)|中等|`dp、数学`|和343相同、分类见[题型分类汇总-区间最大问题](题型分类汇总.md#区间最大问题) |
|剑指15|[二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)|[C++](剑指offer/15.二进制中1的个数/solution.h) |[Note](剑指offer/15.二进制中1的个数)|中等|`dp、数学`|和191相同、分类见[题型分类汇总-位运算](题型分类汇总.md#位运算) |
|剑指16|[16.数值的整数次方](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)|[C++](剑指offer/16.数值的整数次方/solution.h) |[Note](剑指offer/16.数值的整数方)|中等|`数学、快速幂&快速幂取余`|和50相同、分类见[题型分类汇总-数学推导](题型分类汇总.md#数学推导) |
|剑指17|[17.打印从1到最大的n位数](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)|[C++](剑指offer/17.打印从1到最大的n位数/solution.h) |[Note](剑指offer/17.打印从1到最大的n位数)|简单|`dfs`|和50相同、分类见[题型分类汇总-数学推导](题型分类汇总.md#数学推导) |
|剑指18|[18.删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)|[C++](剑指offer/18.删除链表的节点/solution.h) |[Note](剑指offer/18.删除链表的节点)|简单|`链表`|和50相同、分类见[题型分类汇总-链表](题型分类汇总.md#链表) |
|剑指19|[19.正则表达式匹配](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)|[C++](剑指offer/19.正则表达式匹配/solution.h) |[Note](剑指offer/19.正则表达式匹配)|困难|`动态规划`|和10相同、分类见[题型分类汇总-字符串dp](题型分类汇总.md#字符串dp) |
|剑指20|[20.表示数值的字符串](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)|[C++](剑指offer/20.表示数值的字符串/solution.h) |[Note](剑指offer/20.表示数值的字符串)|中等|`字符串、词法分析`|分类见[题型分类汇总-字符串](题型分类汇总.md#字符串) |
|剑指21|[21.调整数组顺序使奇数位于偶数前面](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/)|[C++](剑指offer/21.调整数组顺序使奇数位于偶数前面/solution.h) |[Note](剑指offer/21.调整数组顺序使奇数位于偶数前面)|简单|`数组`|分类见[题型分类汇总-数组](题型分类汇总.md#数组) |
|剑指22|[22.链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)|[C++](剑指offer/22.链表中倒数第k个节点/solution.h) |[Note](剑指offer/22.链表中倒数第k个节点)|简单|`链表`|分类见[题型分类汇总-链表](题型分类汇总.md#链表) |
|剑指23|[23.反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)|[C++](剑指offer/23.反转链表/solution.h) |[Note](剑指offer/23.反转链表)|简单|`链表`|分类见[题型分类汇总-链表](题型分类汇总.md#链表) |
|剑指25|[25.合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)|[C++](剑指offer/25.合并两个排序的链表/solution.h) |[Note](剑指offer/25.合并两个排序的链表)|简单|`链表`|分类见[题型分类汇总-链表](题型分类汇总.md#链表) |
|剑指26|[26.树的子结构](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)|[C++](剑指offer/26.树的子结构/solution.h) |[Note](剑指offer/26.树的子结构)|中等|`二叉树、递归`|与21题相同，分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指27|[27.二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)|[C++](剑指offer/26.树的子结构/solution.h) |[Note](剑指offer/27.二叉树的镜像)|中等|`二叉树、递归`|与101题相同，分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指28|[28.对称的二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)|[C++](剑指offer/26.树的子结构/solution.h) |[Note](剑指offer/28.对称的二叉树)|简单|`二叉树、递归`|与101题相同，分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指29|[29.顺时针打印矩阵](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)|[C++](剑指offer/26.树的子结构/solution.h) |[Note](剑指offer/29.顺时针打印矩阵)|简单|`数组、方向数组`|分类见[题型分类汇总-数组](题型分类汇总.md#数组) |
|剑指30|[30.包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)|[C++](剑指offer/30.包含min函数的栈/solution.h) |[Note](剑指offer/30.包含min函数的栈)|简单|`栈`|和155相同，分类见[题型分类汇总-栈](题型分类汇总.md#栈) |
|剑指31|[31.栈的压入、弹出序列](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)|[C++](剑指offer/31.栈的压入、弹出序列/solution.h) |[Note](剑指offer/31.栈的压入、弹出序列)|中等|`栈`|和946相同，分类见[题型分类汇总-栈](题型分类汇总.md#栈) |
|剑指32|[32-I.从上到下打印二叉树](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)|[C++](剑指offer/32-I.从上到下打印二叉树/solution.h) |[Note](剑指offer/32-I.从上到下打印二叉树)|中等|`二叉树、队列`|分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指32|[32-II.从上到下打印二叉树II](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)|[C++](剑指offer/32-II.从上到下打印二叉树II/solution.h) |[Note](剑指offer/32-II.从上到下打印二叉树II)|简单|`二叉树、队列`|与102相同，分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指32|[32-III.从上到下打印二叉树III](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)|[C++](剑指offer/32-III.从上到下打印二叉树III/solution.h) |[Note](剑指offer/32-III.从上到下打印二叉树III)|中等|`二叉树`|与102相同，分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指33|[33.二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/)|[C++](剑指offer/33.二叉搜索树的后序遍历序列/solution.h) |[Note](剑指offer/33.二叉搜索树的后序遍历序列)|中等|`二叉树`|分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指34|[34.二叉树中和为某一值的路径](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)|[C++](剑指offer/34.二叉树中和为某一值的路径/solution.h) |[Note](剑指offer/34.二叉树中和为某一值的路径)|中等|`二叉树、回溯`|分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
|剑指35|[35.复杂链表的复制](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/)|[C++](剑指offer/35.复杂链表的复制/solution.h) |[Note](剑指offer/35.复杂链表的复制)|中等|`链表`|分类见[题型分类汇总-链表](题型分类汇总.md#链表) |
|剑指36|[36.二叉搜索树与双向链表](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)|[C++](剑指offer/36.二叉搜索树与双向链表/solution.h) |[Note](剑指offer/36.二叉搜索树与双向链表)|中等|`二叉树、链表`|与462相同，分类见[题型分类汇总-二叉树](题型分类汇总.md#二叉树) |
