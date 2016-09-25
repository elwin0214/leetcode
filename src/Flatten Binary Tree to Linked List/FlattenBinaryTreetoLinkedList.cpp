

/*

Flatten Binary Tree to Linked List My Submissions Question
Total Accepted: 67012 Total Submissions: 226176 Difficulty: Medium
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Subscribe to see which companies asked this question

*/

//!!! wait to commit


#include <iostream>
#include <stack>

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
    void flatten(TreeNode* root) 
    {
        if (NULL == root) return;
        TreeNode *head = root;
        TreeNode *node = root;
        TreeNode *before = NULL;
        stack<TreeNode*> s;
        while(true)
        {
            while (node->left != NULL)
            {
                if (NULL != node->right) s.push(node->right);
            
                if (before != NULL)
                {
                    before->right = node;
                }
                before = node;
                node = node->left;
            }
            if (before != NULL)
            {
                before->right = node;
                before = node;
            }
            while(!s.empty())
            {
                node = s.top();
                s.pop();
                before->right = node;
                before = node;
            }
            node = node->right;
            if (NULL == node) break;
            before->right = node;
            if (node->right == NULL) break;
        }
    }
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(1);
        root->left =new TreeNode(2);
        root->right=new TreeNode(3);
        sol.flatten(root);
        while (root != NULL)
        {
            cout<<(root->val)<<" ";
            root = root->right;
        }
        cout<<endl;
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left =new TreeNode(2);
       // root->right=new TreeNode(3);
        sol.flatten(root);
        while (root != NULL)
        {
            cout<<(root->val)<<" ";
            root = root->right;
        }
        cout<<endl;
    }
     {
        TreeNode *root = new TreeNode(1);
        root->right =new TreeNode(2);
       // root->right=new TreeNode(3);
        sol.flatten(root);
        while (root != NULL)
        {
            cout<<(root->val)<<" ";
            root = root->right;
        }
        cout<<endl;
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left =new TreeNode(2);
        root->right=new TreeNode(3);
        root->left->left=new TreeNode(4);
        root->left->right=new TreeNode(5);
        root->right->left=new TreeNode(6);
        root->right->right=new TreeNode(7);
        sol.flatten(root);
        while (root != NULL)
        {
            cout<<(root->val)<<" ";
            root = root->right;
        }
        cout<<endl;
    }
}