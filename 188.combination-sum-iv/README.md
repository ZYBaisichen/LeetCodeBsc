# 日期/类型
20210425 股票买卖问题iv
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

# 题目描述
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


# 思路(C++)
## 第一种动态规划
> 自己的思路，但没有全部ac
一、初步分析
由于在买卖过程中最多只能完成K笔交易，因此在任意一天结束后的的状态，要么手里有股票，要么手里没股票。
其中有股票有两种情况，要么是在第i天当天完成第j次的买入操作，要么在前几天完成了第j次的买入操作(j=1,2,...k)
手里没股票有两种情况，要么是在第i天当天完成第j次的卖出操作，要么在前几天已经完成了第j次的卖出操作(j=1,2,...k)

对于每次交易，共有三种状态：未操作、买入、卖出。由于未操作产生的利润为0, 所以主要考虑每次交易的买入和卖出所产生的最大利润

二、 状态定义
用buy[i][j]表示第i天结束时完成了第j次交易的买入操作所获得的最大利润
用sell[i][j]表示在第i天结束时完成了第j次交易的卖出操作所获得的最大利润，即完成第j次交易所获得的最大利润

三、状态转移
buy[i][j]：在第i天第j次交易的买入操作，可能是前几天就已经完成了第j次交易的买入，还有可能是在前几天完成第j-1次交易之后再第i天当天买入，所以状态转移方程为：
``` cpp
buy[i][j] = max(buy[i-1][j],buy[i-2][j],..,buy[0][j], sell[i-1][j-1]-prices[i],sell[i-2][j-1]-prices[i],...,sell[0][j-1]-prices[i])
```
sell[i][j]：在第i天第j次交易的卖出操作，可能是前几天已经完成了第j次交易的卖出，还有可能在前几天完成了第j次交易的买入操作后再在第i天当天卖出，所以状态转移方程为：
``` cpp
sell[i][j] = max(sell[i-1][j],sell[i-2][j],..,sell[0][j], buy[i-1][j]+prices[i],buy[i-2][j]+prices[i],...,buy[0][j]+prices[i])
```
考虑buy[i][j]>=buy[i-1][j] => buy[i-1][j]>=buy[i-2][j] && sell[i][j]>=sell[i-1][j] => sell[i-1][j]>=sell[i-2][j] （1）
所以将上述方程进行简化：
``` cpp
buy[i][j] = max(buy[i-1][j], sell[i-1][j-1]-prices[i])
sell[i][j] = max(sell[i-1][j], buy[i-1][j]+prices[i])
```

三、初始化。
- 第0次交易的买入和卖出操作都没有意义，且都为0，所以buy[i][0]=sell[i][0]=0, i=1,2,...,n
- 第1天结束后第j次交易，买入则亏损prices[0]， 买入再卖出j次利润为0：buy[1][j] = -prices[0], sell[1][j]=0, j=1,2,...k
- 第i天结束后的第1次交易，买入亏损prices[i],但卖出暂时没法计算，所以buy[i][1] = -prices[i]


四、结果输出
因为最多进行k次交易，由公式(1)可以看到sell[i][j]是 一定大于sell[i-1][j]的；再考虑假如i天中只进行了j次交易，也会因为可以再同一天买入并卖出这一宽松条件，将sell[i][j]传递给sell[i][j+1]，所以最大利润值为sell[n][k]

### 复杂度
时间复杂度：O(n*k)。遍历n天和k次交易

空间复杂度：O(2*n*k) 借用两个二维数组buy和sell

### 题解思路
> 参考：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iv-by-8xtkp/
