/*

Partition List My Submissions Question
Total Accepted: 53342 Total Submissions: 189251 Difficulty: Medium
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Subscribe to see which companies asked this question

*/

#include <vector>
#include <iostream>

using namespace std;

struct ListNode 
{
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *node = head;

        ListNode *lessHead = NULL;
        ListNode *less = NULL;
        ListNode *greatHead = NULL;
        ListNode *great = NULL;

        while (NULL != node)
        {
            if (node->val < x)
            {
                if (less != NULL)
                    less->next = node;
                else
                    lessHead = node;
                less = node;
            }
            else
            {
                if (great != NULL)
                    great->next = node;
                else
                    greatHead = node;
                great = node;
            }

            node = node->next;
        }
        if (less != NULL)
            less->next = greatHead;
        if (NULL != great)
            great->next = NULL;

        return lessHead == NULL ? greatHead :lessHead;
    }
};

void print(ListNode *root)
{
    while(root != NULL)
    {
        cout<<(root->val)<<" ";
        root = root->next;
    }
    cout<<endl;
};
ListNode* construct(const vector<int> &vec)
{
    ListNode *node = NULL;
    ListNode *head = NULL;
    int index = -1;
    for (auto i : vec)
    {
        index++;
        if (0 == index)
        {
            node = new ListNode(i);
            head = node;
            continue;
        }
        
        node->next = new ListNode(i);
        node = node->next;
    }
    return head;
};
int main()
{
    Solution sol;
    {
        ListNode *head =  construct({2,2,3,4});
        print(sol.partition(head, 1));
    }
    {
        ListNode *head =  construct({1,2,3,4,5,2,3,9});
        print(sol.partition(head, 3 ));
    }
    {
        ListNode *head =  construct({1,2,3,4,5,2,3,9});
        print(sol.partition(head, 1 ));
    }
    {
        ListNode *head =  construct({1,2,3,4,5,2,3,9});
        print(sol.partition(head, 9 ));
    }
}