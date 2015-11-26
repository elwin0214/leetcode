/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/

Sum Root to Leaf Numbers My Submissions Question
Total Accepted: 62239 Total Submissions: 199752 Difficulty: Medium
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems



*/

#include <iostream>
#include <vector>
#include <algorithm>

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
    int sumNumbers(TreeNode* root) 
    {
        if (NULL == root) return 0;
        vector<int> path;
        int sum = 0;
        sumNumbers(root, path, sum);
        return sum;
    }

    void sumNumbers(TreeNode* node, vector<int> &path, int &sum)
    {
        if (NULL == node) return;
        if (NULL == node->left && NULL == node->right)
        {
            int num = 0;
            for(auto it = path.begin(); it != path.end(); it++)
            {
                num = num * 10 + (*it);
            }
            num = num * 10 + (node->val);
            sum = sum + num;
            return;
        }
        path.push_back(node->val);
        sumNumbers(node->left, path, sum);
        sumNumbers(node->right, path, sum);
        path.erase(path.end() - 1);
    }

};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout<<sol.sumNumbers(root)<<endl;
}
 
