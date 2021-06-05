/***
 * @Author: baisichen
 * @Date: 2021-05-05 17:13:22
 * @LastEditTime: 2021-05-06 21:43:57
 * @LastEditors: baisichen
 * @Description: 完全背包问题
 */
#include<iostream>
#include<vector>
#include<deque>
#include <cstring>
using namespace std;
void CompletePack(vector<int> &F, int C, int W, int V) {//传参为dp数组，当前物品的花费、当前物品产生的价值, 总重量
	for (int v=C; v<=V; v++) {
		F[v] = max(F[v-C]+W, F[v]);
	}
}
void ZeroOnePack(vector<int> &F, int C, int W, int V) {//传参为dp数组，当前物品的花费、当前物品产生的价值, 总重量
	for (int v=V; v>=C; v--) {
		F[v] = max(F[v-C]+W, F[v]);
	}
}
void MultiplePackBinary(vector<int> &F, int C, int W, int V, int M) {
	if (C*M >= V) {//当物品件数消耗的费用超过背包总量，则为一个完全背包问题
		CompletePack(F, C, W, V);
		return;
	}
	int k=1;
	while (k < M) {
		ZeroOnePack(F, k*C, k*W , V);
		M = M - k;
		k = 2*k;
	}
	ZeroOnePack(F, M*C, M*W, V);//M减到最后即为最后一件系数为$M_i-2^(k+1)$的物品，对其进行01背包
}

void MultiplePackMonotonicQueue_STL(vector<int> &F, int C, int W, int V, int M) { //C++STL版对队列的操作可能会超时
	//每次更新F，因为是从小到大更新，所以要存储一个原来的状态值g,在这个数组上进行滑动求最大值
	vector<int> g(F);
	//枚举模的重量
	//每次循环计算出模的队列
	for (int v=0; v <= C-1; v++) {
		//计算当前模的最大价值。
		//窗口大小为size = M
		//当前位置在k处，窗口左边界在k-M*C
		//在g上滑动，队列中存储的是遍历到的背包容量, 即g的下标
		deque<int> q;
		for (int k=v;k<=V; k+=C) {
			if (!q.empty() && q.front()<k-M*C) {//队首元素的下标已经在窗口左边界的左边时，出队
				q.pop_front();
			}
			//使用队头元素更新f
			if (!q.empty()) {
				int front_v = q.front();
				F[k] = max(g[k], g[front_v]+ (k-front_v)/C * W);
			}
			//新元素入队
			//找到第一个容量然后再加上可以放的背包比当前以k为容量的背包大的数入队，否则则将末尾的元素出队
			while (!q.empty() && g[k] >= g[q.back()]+ (k-q.back())/C*W) {
				q.pop_back();
			}
			q.push_back(k);
		}
	}
}

void MultiplePackMonotonicQueue_Array(int F[], int g[], int C, int W, int V, int M, int q[]) { //用数组模拟入队出队，避免超时

	//枚举模的重量
	//每次循环计算出模的队列
	for (int v=0; v < C; v++) {
		//计算当前模的最大价值。
		//窗口大小为size = M
		//当前位置在k处，窗口左边界在k-M*C
		//在g上滑动，队列中存储的是遍历到的背包容量, 即g的下标
		int head = 0, tail=-1;
		for (int k=v;k<=V; k+=C) {
			if (head<=tail && q[head]<k-M*C) {//队首元素的下标已经在窗口左边界的左边时，出队
				++head;
			}
			//使用队头元素更新f
			if (head<=tail) {
				int front_v = q[head];
				F[k] = max(g[k], g[front_v]+ (k-front_v)/C * W);
			}
			//新元素入队
			//找到第一个容量然后再加上可以放的背包比当前以k为容量的背包大的数入队，否则则将末尾的元素出队
			while (head <= tail && g[k] >= g[q[tail]]+ (k-q[tail])/C*W) {
				--tail;
			}
			q[++tail] = k;
		}
	}
}

const int max_size = 20010;

int main(){
	int N,V;
	cin >> N >>V;
//	vector<int> c(N, 0);
//	vector<int> w(N, 0);
//	vector<int> s(N, 0);
//	for (int i=0;i<N;i++) {
//		cin >> c[i] >> w[i] >> s[i];
//	}
//
//	vector<int> F(V+1, 0);//初始一维数组表示的是0个物品放入重量为v的背包中产生的最大价值为0,F[0][v]= 0
//
//	//o(N*V*sum(log(m_i)))复杂度的方法
//	// for (int i=1;i<=N;i++) {
//	//     MultiplePackBinary(F, c[i-1], w[i-1], V, s[i-1]);
//	// }
//
//	//单调队列优化的方法用STL
//	for (int i=1;i<=N;i++) {
//		MultiplePackMonotonicQueue_STL(F, c[i-1], w[i-1], V, s[i-1]);
//	}
//	cout << F[V] << endl;

    //单调队列优化用数组模拟队列方法
    int F[max_size], g[max_size], q[max_size];
	for (int i=0;i<N;i++) {
		int c,w,m;
		cin >> c >> w >> m;
		//每次更新F，因为是从小到大更新，所以要存储一个原来的状态值g,在这个数组上进行滑动求最大值
		memcpy(g, F, sizeof(F));
		MultiplePackMonotonicQueue_Array(F, g, c, w, V, m, q);
	}
	cout << F[V] << endl;
	return 0;
}