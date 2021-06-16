
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-13 12:29:32
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210613 字符串

# 题目描述
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 库函数&字符串截取
本题的难度不在于题目本身，而是在面试过程中面试官可能会做各种限制，比如不能使用库函数substr。

一、库函数截取

res = s.substr(0, k) + substr(k+1, n-k+1)


二、字符串遍历

从第k个字符开始遍历到结尾放在新的字符串中，然后遍历0-k-1放在结果字符串的末尾

### 复杂度

时间复杂度：O(n)
空间复杂度：库函数：O(1)； 字符串遍历：O(n)

