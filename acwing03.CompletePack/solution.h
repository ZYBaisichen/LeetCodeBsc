/*** 
 * @Author: baisichen
 * @Date: 2021-05-05 17:13:22
 * @LastEditTime: 2021-05-06 10:51:16
 * @LastEditors: baisichen
 * @Description: 完全背包问题
 */
#include<iostream>
#include<vector>
using namespace std;
void CompletePack(vector<int> &F, int C, int W, int V) {//传参为dp数组，当前物品的花费、当前物品产生的价值, 总重量
   for (int v=C; v<=V; v++) {
       F[v] = max(F[v-C]+W, F[v]);
   } 
}
int main(){
    int N,V;
    cin >> N >>V;
    vector<int> c(N, 0);
    vector<int> w(N, 0);
    for (int i=0;i<N;i++) {
         cin >> c[i] >> w[i];
    }
    
    vector<int> F(V+1, 0);//初始一维数组表示的是0个物品放入重量为v的背包中产生的最大价值为0,F[0][v]= 0
    for (int i=1;i<=N;i++) {
        CompletePack(F, c[i-1], w[i-1], V);
    }
    cout << F[V] << endl;
    return 0;
}