/*
https://leetcode.com/problems/binary-tree-postorder-traversal/

Binary Tree Postorder Traversal My Submissions Question
Total Accepted: 78984 Total Submissions: 235954 Difficulty: Hard
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

*/
/*
每次左子树退完栈，不能把根节点退栈，因为根节点最后访问，

但是右子树退完栈，无法判断当前节点的左子树，右子树是否已经访问完毕，

加多一个栈表示这种状态。左子树退完栈，用flag=1 表示。


visit(node->left);
visit(node->right);
print(node->value);



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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> s;
        stack<int> flag;
       
        //result.push_back(root->val);
        //stk.push(root);
        TreeNode* node = root;
        while (node !=NULL || !s.empty()) 
        {
            while (node != NULL)
            {
                //result.push_back(node->val);
                s.push(node);
                flag.push(0);
                node = node->left;
            }
            if (s.empty())
                break;
            node = s.top();
            if(0 == flag.top())
            {
                flag.pop();
                flag.push(1);
                node = node->right;
            }
            else
            {
                result.push_back(node->val);
                s.pop();
                flag.pop();
                node = NULL;
            }
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
    print(sol.postorderTraversal(root)); 
    }

}