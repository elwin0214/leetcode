#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
  int maxDepth(TreeNode* root) {


  }

  int recursiveMaxDepth(TreeNode* root) {
    if(NULL == root) return 0;
    return 1+max(recursiveMaxDepth(root->left),recursiveMaxDepth(root->right));
  }
};