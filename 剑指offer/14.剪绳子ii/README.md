<!--
 * @Author: baisichen
 * @Date: 2021-05-10 10:20:04
 * @LastEditTime: 2021-05-13 10:54:26
 * @LastEditors: baisichen
 * @Description: 
-->
# 日期/类型
20210510 DP、贪心、数学
与343题目相同：https://leetcode-cn.com/problems/integer-break/

# 题目描述
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

``` cpp
示例 1：
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

提示：
2 <= n <= 58


# 思路(C++)
## 动态规划
一、初步分析
要将一个长度为n的绳子分段，分的第一段长度可以为1,2,...,n, 而每一段可以再分，比如2可以分为两个1或一个2，，长度为2的绳子得到的最大成绩即为max(2, 1*1)

二、 状态定义
定义dp[i]标识长度为i的绳子做拆分所能得到的最大乘积。

三、状态转移
dp[i] = max(i, dp[i-k]*k), k=1,2,...,i/2

三、初始化。
长度为1的绳子只能分成1段，所以dp[1] = 1

四、结果输出
dp[n]即为最终结果

五、注意
注意这里题目要求必须剪一次，所以这里还涉及到绳子从多长开始就可以不用必剪一次了。没看太明白，等哪天感冒好了清醒了再回来看：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/jian-zhi-offermian-shi-ti-14suan-fa-zhon-6bxx/

假设将绳子分为了$x_1, x_2, ... ,x_n$份，是要求$x_1*x_2...*x_n > x_1+x_2+...x_n$， 为了简便，假设只分成两段x和y，总长度为m。则:

$$
\left\{
\begin{aligned}
x+y=m \\
x+y<xy \\
\end{aligned}
\right.
$$

构造$(x-y)^2 = x - 2\sqrt{xy} + y >=0$ =>  $xy <= ((x+y)/2)^2$ (1)

观察xy大于x+y是要求的是从多长开始必须做剪一刀处理才能使得乘积大于和，所以如果想求绳子低于多长的时候不用再做拆分处理的话，需要使得上述等式无解，所以需要$((x+y)/2)^2 > x+y$, 综合x+y=m求得:

m < 4

即绳子小于4的时候不剪才是最优解，同时也是动态规划最优状态。

但题目要求必须剪一刀，所以当绳子长度小于4时需要做特殊处理。其他情况下做正常拆分，且不会有乘积最大值小于其本身的情况。



### 复杂度
时间复杂度:$O(n^2)$
循环n次，对于每个长度为i的绳子，都遍历1到i/2得到dp[i]，i最大为n。

空间复杂度：O(n)
借用长度为n的dp数组

## 自然数分解算法
这个是通过算术-集合平均值不等式来做的推导，结论是尽量拆分成3，剩下的余数如果是2则直接相乘，如果是1则需要拿出一个3出来拆分成2*2。

https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
https://zh.wikipedia.org/wiki/%E7%AE%97%E6%9C%AF-%E5%87%A0%E4%BD%95%E5%B9%B3%E5%9D%87%E5%80%BC%E4%B8%8D%E7%AD%89%E5%BC%8F

设将长度为 n 的绳子切为 a 段，本题即等价于求$mulres=max(n_1*n_2*...*n_a)$，由算数几何不等式，当且仅当$n_1 = n_2 = n_3 =...= n_a$的时候乘积mulres最大。

设绳子可以按照x长度均等分为a段，即n=ax，从而得到： 

$mulres=x^a=x^(n/x)=(x^(1/x))^n$ （2）

（2）式中当$x^(1/x)$最大时整体multres最大，令$y=x^(1/x)$， 取对数有

$lny=1/x*lnx$

两边对x求导得
$1/y * y' = (1 - lnx)/x^2$

整理得

$y' = {\frac{1-lnx}{x^2}}x^{\frac{1}{x}}$



令$y'=0 得 1-lnx=0 => x=e \approx 2.7$, 易知，y在e处连续，所以e即为y的极大值点。由于切分长度x必须为整数，最接近e的整数为2或3，带入y得：

$[y(3)]^6 = 9$

$[y(2)]^6 = 8$

所以将绳子尽可能的拆分成3最合理。

最后可会剩个2，2不需要拆分即为最大；剩一个时，由于3*1<2*2， 所以需要拿出一个3出来和1组成4，并做拆分成2*2

由上一节证明了当绳子长度大于4时可以拆分成3、2、1，但小于4时，由于必须剪一刀，所以需要特殊处理。

## 大数取余问题
> 参考：https://blog.csdn.net/u013174702/article/details/43761197

求解a的b次幂对n的余数时，依据的公式为：

(a*b)%n = ((a%n)*(b%n))%n

所以可以循环相乘之后取余

``` cpp
int mod(int a, int b, int n) {
    int ans=1;
    for (int i=0;i<b;i++) {
        ans = (ans*a)%n;
    }
    return ans;
}
```

这种取余方法的复杂度为n，所以需要考虑快速幂求余的方法，考虑b为奇数和偶数时的不同，有以下公式：

$$
a^b \quad mod \quad c = \left\{
\begin{aligned}
(a^{\frac{b}{2}})^2 \quad mod \quad c, \quad b为偶数 \\
a*(a^{\frac{b}{2}})^2 \quad mod \quad c, \quad b为奇数 \\
\end{aligned}
\right.
$$

``` cpp
//快速幂取余，求a^b mod n的余数
int quckMod(int a, int b, int c) {
    int ans = 1;
    long long tmp = a; //用long long做中间结果的计算，防止tmp*tmp溢出
    while (b) {
        if (b%2==1) {//因为b一直除以2，所以最后一定会除到1，然后1除以2才到0
            ans = (ans * tmp) % c; //如果b为奇数，本次做3次方
        }
        tmp = tmp * tmp % c; //每次做平方
        b=b/2;
    }
    return ans;
}
```


