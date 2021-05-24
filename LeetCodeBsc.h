/*** 
 * @Author: baisichen
 * @Date: 2021-05-08 10:26:23
 * @LastEditTime: 2021-05-24 21:41:36
 * @LastEditors: baisichen
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include<map>
#include<string>
#include<queue>
using namespace std;
//Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node* random;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL), random(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL), random(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next, Node* _random)
        : val(_val), left(_left), right(_right), next(_next), random(_random) {}
};


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 