#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
	void connect(TreeLinkNode *root) 
	{
		if(NULL==root)
			return;
		TreeLinkNode *head=root;
		head->next=NULL;
		while(true)
		{
			if(NULL == head->left)
			{
				return;
			}
			TreeLinkNode *parent=head;
			TreeLinkNode *prev=NULL;
			while(true)
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