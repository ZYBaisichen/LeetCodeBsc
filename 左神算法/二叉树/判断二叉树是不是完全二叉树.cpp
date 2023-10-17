/*** 
 * @Author: baisichen
 * @Date: 2023-09-16 11:53:03
 * @LastEditTime: 2023-09-16 12:49:44
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream> 
#include <queue>
using namespace std;
class node {
    node* left;
    node* right;
}
bool  isCBT(node * head) {
    queue<node*> que;
    que.push(head);
    bool haveLookLeaf = false;
    if (head == NULL) {
        return true;
    }
    while (!que.empty()) {
        node* tmp = que.front();
        node* l = head->left;
        node* r = head->right;
        //如果遇到叶结点后。又发现当前节点不是叶节点; 或者遇到有右节点，没有左节点的
        if ((haveLookLeaf && !(l==NULL && r==NULL)) || (l==nullptr && r!=NULL)) {
            return false;
        }
        if (l!=NULL) {
            que.push(l);
        }
        if (r!=NULL) {
            que.push(r);
        }
        if (l==NULL && r==NULL) {
            haveLookLeaf=true;
        }
    }
    return true;
}
int main() {

}