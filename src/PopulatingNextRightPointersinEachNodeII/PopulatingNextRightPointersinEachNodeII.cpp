
/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
Populating Next Right Pointers in Each Node II My Submissions Question

Total Accepted: 48044 Total Submissions: 149212 Difficulty: Hard
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeLinkNode 
{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution 
{
public:
  void connect(TreeLinkNode *root) 
  {
    if (NULL == root) return;

    TreeLinkNode *prev = NULL;
    queue<TreeLinkNode*> node_queue;
    node_queue.push(root);
    node_queue.push(NULL);

    while (!node_queue.empty())
    {
      TreeLinkNode *node = node_queue.front();
      node_queue.pop();
      if (NULL == node && node_queue.empty())
        break;
      if (NULL == node){
        node_queue.push(node);
        prev = NULL;
        continue;
      }
      if (NULL != node->left) node_queue.push(node->left);
      if (NULL != node->right) node_queue.push(node->right);
      if (NULL != prev ) {
        prev->next = node;
      }
      prev = node;
    }
  }
  void connectNode(TreeLinkNode *node)
  {
    if (NULL == node->left) return;
    node->left->next = node->right;

    TreeLinkNode *nleft = node->left;
    TreeLinkNode *nright = node->right;

    while (NULL != nleft && NULL != nright)
    {
      nleft->next = nright;
      nright = nright->right;
      nleft = nleft->right;
    }
    connectNode(node->left);
  }
};

int main()
{
  Solution sol;
  TreeLinkNode *root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  root->left->left = new TreeLinkNode(4);
  root->left->right = new TreeLinkNode(5);
  root->right->right = new TreeLinkNode(7);
  sol.connect(root);
  cout<<(root->left->left->next->val);
}