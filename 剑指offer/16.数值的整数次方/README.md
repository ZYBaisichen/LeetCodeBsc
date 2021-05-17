<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-13 13:27:27
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210513 二进制计算
与50题目相同：https://leetcode-cn.com/problems/powx-n/

# 题目描述
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。


``` cpp
示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000

```

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

# 思路(C++)

## 减一相与
快速幂求解：
$$
a^b \quad  = \left\{
\begin{aligned}
(a^{\frac{b}{2}})^2 \quad , \quad b为偶数 \\
a*(a^{\frac{b}{2}})^2 \quad , \quad b为奇数 \\
\end{aligned}
\right.
$$
计算log(n)次即可得到答案，模板为：
``` cpp
//快速幂取余，求a^b 
int quckMod(int a, int b) {
    int ans = 1;
    long long tmp = a; //用long long做中间结果的计算，防止tmp*tmp溢出
    while (b) {
        if (b%2==1) {//因为b一直除以2，所以最后一定会除到1，然后1除以2才到0
            ans = (ans * tmp); //如果b为奇数，本次做3次方
        }
        tmp = tmp * tmp; //每次做平方
        b=b/2;
    }
    return ans;
}
```


### 复杂度
时间复杂度：O(n)， 最长有32位1
空间复杂度：O(1)