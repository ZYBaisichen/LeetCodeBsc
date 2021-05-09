/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-08 15:18:03
 * @LastEditors: baisichen
 * @Description: 中序遍历
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    Node* connectBFS(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();//每次处理一层
            Node* pre = NULL;
            Node* cur = NULL;
            for (int i=0;i<size&&!q.empty();i++) {
                cur = q.front();
                if (!pre) { 
                    pre = cur;
                } else {
                    pre->next = cur;
                    pre = cur;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                q.pop();
            }
        }
        return root;
    }

    Node* connectRec(Node* root) {
        if(!root) return root;
        connectTwoNode(root->left,root->right);
        return root;
    }
    void connectTwoNode(Node* node1, Node* node2) {
        if (!node1 || !node2) {
            return;
        }
        node1->next = node2;

        //第一种情况，连接其两个子节点
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);

        //第二种情况，连接node1的右子节点和node2的左子节点
        connectTwoNode(node1->right, node2->left);
    }
};