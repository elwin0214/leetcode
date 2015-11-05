/*
https://leetcode.com/problems/binary-tree-preorder-traversal/

Binary Tree Preorder Traversal My Submissions Question
Total Accepted: 92807 Total Submissions: 248251 Difficulty: Medium
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Subscribe to see which companies asked this question

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk;
       
        result.push_back(root->val);
        stk.push(root);
        TreeNode* node = root->left;
        while (true) 
        {
            while (node != NULL)
            {
                result.push_back(node->val);
                stk.push(node);
                node = node->left;
            }
            if (stk.empty())
                break;

            node = stk.top();
            stk.pop();
            node = node->right;
            
        }
        return result;
    }
};
TreeNode* constructTree(vector<char> &vec)
{
    queue<TreeNode*> q;
    TreeNode* root=new TreeNode(vec[0] + 1 - '1');
    q.push(root);
    int index = 1;
    

    for (int i=1; i<vec.size(); )
    {
        TreeNode* node = q.front();
        q.pop();
        
        
        if ('#' != vec[i])
        {
            TreeNode* child=NULL;
            child = new TreeNode(vec[i] + 1 - '1');
            node->left = child;
            q.push(child);
        }
        i++;
        if ('#' != vec[i])
        {
            TreeNode* child=NULL;
            child = new TreeNode(vec[i] + 1 - '1');
            node->right = child;
            q.push(child);
        }
        i++;

    }
    return root;
     
};

void print(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int i){
        cout<<i<<" ";
    });
    cout<<endl;
};

int main()
{
    Solution sol;

    {
    vector<char> vec={'1','2','3','#','#','4','#','#','5'};
    TreeNode* root=constructTree(vec);
    print(sol.preorderTraversal(root)); 
    }

}