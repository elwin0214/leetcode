
/*

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


Populating Next Right Pointers in Each Node My Submissions Question
Total Accepted: 67451 Total Submissions: 185687 Difficulty: Medium
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if (NULL == root) return;
        TreeLinkNode *head=root;
        head->next=NULL;
        while (true)
        {
            if (NULL == head->left) return;
		
			TreeLinkNode *parent=head;
			TreeLinkNode *prev=NULL;
            while (true)
			{
                parent->left->next=parent->right;
				prev=parent;
				parent=parent->next;
				if(NULL==parent)
				{
					prev->right->next=NULL;
					break;
				}
				else
				{
					prev->right->next=parent->left;
				}
			}
			head=head->left;
		}
	}
};