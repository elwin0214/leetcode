/*


Kth Smallest Element in a BST My Submissions Question
Total Accepted: 26078 Total Submissions: 77609 Difficulty: Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.Show More Hint 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.



*/

class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int val = -1;
        visit(root, k, val);
        return val;
    }

    void visit(TreeNode* node, int& k, int& val)
    {
        if (NULL == node) return;
        visit(node->left, k, val);
        k--;
        if (k == 0)
        {
            val = node->val;
        }
        visit(node->right, k, val);
    }
};