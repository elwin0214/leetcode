/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Remove Duplicates from Sorted List II My Submissions Question
Total Accepted: 59753 Total Submissions: 231529 Difficulty: Medium
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Subscribe to see which companies asked this question

Hide Tags Linked List


*/
#include <iostream>
#include <vector>

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (NULL == head) return NULL;
        ListNode *prev = head;
        ListNode *node = head->next;
        if (NULL == node) return head;
        head = NULL;
        ListNode *nnode = NULL;
        int dup = 1;
         
        while(NULL != prev)
        {
            if (NULL != node && node->val == prev->val)
            { 
                dup++;
            }
            else
            {
                if (1 == dup)
                {
                    if (NULL == nnode)
                    {
                        nnode = prev;
                        head = prev;
                    }
                    else
                    {
                        nnode->next = prev;
                        nnode = prev;
                    }
                    nnode->next = NULL;
                }
                dup = 1;
            }
            prev = node;
            if (NULL != node) node = node->next;
        }
        return head;
    }
};

void print(ListNode *head)
{
    while(head != NULL)
    {
        cout<<(head->val)<<" ";
        head = head->next;
    }
    cout<<endl;
};
ListNode* construct(const vector<int> &vec)
{
    ListNode *node = NULL;
    ListNode *head =NULL;

    for( int i : vec)
    {
        if (node == NULL)
        {
            node = new ListNode(i);
            head = node;
        }
        else
        {
            node->next = new ListNode(i);
            node = node->next;
        }

    }
    
    return head;
};

int main()
{
    Solution sol;
    {
        ListNode *head = construct({1,2,2});
        print(head);
        head = sol.deleteDuplicates(head);
        print(head);
    }
    {
        ListNode *head = construct({1,2,3,4});
        print(head);
        head = sol.deleteDuplicates(head);
        print(head);
    }
    {
        ListNode *head = construct({1,1,3,4});
        print(head);
        head = sol.deleteDuplicates(head);
        print(head);
    }
    {
        ListNode *head = construct({1,1,4,4});
        print(head);
        head = sol.deleteDuplicates(head);
        print(head);
    }
    {
        ListNode *head = construct({1,1,4});
        print(head);
        head = sol.deleteDuplicates(head);
        print(head);
    }
    {
        ListNode *head = construct({1,1,4,6});
        print(head);
        head = sol.deleteDuplicates(head);
        print(head);
    }
    // ListNode *head = new ListNode(1);
    // head->next = new ListNode(2); 
    // head->next->next = new ListNode(3); 
    // head->next->next->next = new ListNode(4); 
    // head->next->next->next->next = new ListNode(5); 



}