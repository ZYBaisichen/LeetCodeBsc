
<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-06-13 12:15:51
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210612 字符串

注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/

# 题目描述
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 思路(C++)

## 暴力枚举
用两个指针start和end，分别指向单词的开头和结尾；倒序遍历原字符串，start不停的往前遍历，直到碰到空格，start+1到end即为一个单词，将其放在中间数组中；start和end同时指向start-1，继续往前遍历，直到start碰到第一个字符串为止。最后将数组中的元素拼接起来返回。

### 复杂度

时间复杂度：$O(n)， start会从尾到头走一遍，所以复杂度是n$
空间复杂度：O(1)， 借助两个指针

