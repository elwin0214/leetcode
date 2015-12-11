

/*

Lowest Common Ancestor of a Binary Tree My Submissions Question
Total Accepted: 25946 Total Submissions: 93758 Difficulty: Medium
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Subscribe to see which companies asked this question

Hide Tags


*/
/*

命中2个节点之间，取节点判断。
只能中序
前序不方便构造算法，比如：

   1
  / \
 2   3

如果前序 p = 2 , q = 3; 1 2 3，遍历的节点为 2，3 不包含 1。
后序也不方便，因为 顺序为 2 3 1，

*/
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int dep = 0;
        int min_dep = -1;
        int hits = 0;
        TreeNode *result = NULL; 
        search(result, root, p, q, min_dep, dep, hits);
        return result;
    }

    void search(TreeNode* &result, TreeNode *node, TreeNode* p, TreeNode* q,int &min_dep, int &dep, int &hits)
    {  
        if (NULL == node) return ;
        dep++;

        search(result, node->left, p, q, min_dep, dep, hits);
        if (node == p || node == q)
        {
            hits++;
        }
        if (hits == 1 || node == p || node == q)
        {
            if (min_dep < 0 || min_dep > dep)
            {
                min_dep = dep;
                result = node;
                //cout<<(node->val)<<endl;
            }
        }
        
        search(result, node->right, p, q, min_dep, dep, hits);
        dep--;
    }
};

int main()
{   
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);


    Solution sol ;
    TreeNode* result = sol.lowestCommonAncestor(root, root->left, root->right);
    cout<<(result->val)<<endl;
    result = sol.lowestCommonAncestor(root, root, root->right);
    cout<<(result->val)<<endl;

}