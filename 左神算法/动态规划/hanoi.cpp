/*** 
 * @Author: baisichen
 * @Date: 2023-10-12 16:54:25
 * @LastEditTime: 2023-10-12 17:12:53
 * @LastEditors: baisichen
 * @Description: 汉诺塔问题, 
 * 最优2^N-1， T(N) = T(N-1) + T(n-2) + .... + 1
 */
#include "iostream" 
#include <vector>
#include <stack>
using namespace std;
void hanoiCore(int n, string from, string to, string other) {
    if (n==1) {
        cout << from << " -> " << to << endl;
        return;
    }
    //将n-1个盘子从from挪到other
    hanoiCore(n-1, from, other, to);
    cout << from << " -> " << to << endl; //挪动最后一个盘子
    //将n-1个盘子从other挪到to
    hanoiCore(n-1, other, to, from);
}
void hanoi(int n) {
    if (n < 1) {
        return;
    }
    hanoiCore(n, "left", "right", "mid");
}

int main() {
    return 0;
}