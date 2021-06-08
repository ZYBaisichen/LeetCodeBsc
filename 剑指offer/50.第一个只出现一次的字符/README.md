
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-08 11:18:07
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210608 哈希

# 题目描述
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
 

限制：

0 <= s 的长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 哈希

两遍扫描，第一遍用哈希表记录下来每个字符出现的频次，第二遍利用哈希表找到第一个出现频次为一的字符返回，找不到则返回空格


### 复杂度
时间复杂度：O(n）

空间复杂度：O(1)
