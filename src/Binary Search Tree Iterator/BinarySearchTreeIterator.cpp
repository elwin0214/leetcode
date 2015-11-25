

/*
Binary Search Tree Iterator My Submissions Question
Total Accepted: 33437 Total Submissions: 105935 Difficulty: Medium
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems



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
 
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *node = root;
        push(node);
    }

    void push(TreeNode *node)
    {
        while (NULL != node)
        {
            s.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = s.top();
        s.pop();
        push(node->right);
        return node->val;
    }
};
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    BSTIterator bst(root);
    while(bst.hasNext())
    {
        cout<<bst.next()<<endl;
    }
}