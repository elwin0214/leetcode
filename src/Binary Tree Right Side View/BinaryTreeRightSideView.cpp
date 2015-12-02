/*

Binary Tree Right Side View My Submissions Question
Total Accepted: 27768 Total Submissions: 89916 Difficulty: Medium
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<int> result;
        if (NULL == root) return result;
        q.push(root);
        q.push(NULL);
        result.push_back(root->val);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (NULL == node) 
            {
                if (q.empty())
                    break;
                q.push(NULL);
                result.push_back(q.front()->val);
                continue;
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            if (node->left != NULL)
            {
                q.push(node->left);
            }

        }
        return result;
    }
};

void print(vector<int> &v)
{
    for_each(v.begin(), v.end(), [](int i){
        cout<<i<<" ";
    });
    cout<<endl;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    vector<int> vec=sol.rightSideView(root);
    print(vec);
}