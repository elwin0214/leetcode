

/*
https://leetcode.com/problems/binary-tree-inorder-traversal/

Binary Tree Inorder Traversal My Submissions Question
Total Accepted: 93293 Total Submissions: 250233 Difficulty: Medium
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk;
       
        //result.push_back(root->val);
        stk.push(root);
        TreeNode* node = root->left;
        while (true) 
        {
            while (node != NULL)
            {
                //result.push_back(node->val);
                stk.push(node);
                node = node->left;
            }
            if (stk.empty())
                break;

            node = stk.top();
            stk.pop();
            result.push_back(node->val);
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
    print(sol.inorderTraversal(root)); 
    }

}