

/*
https://leetcode.com/problems/swap-nodes-in-pairs/

Swap Nodes in Pairs My Submissions Question
Total Accepted: 71903 Total Submissions: 215680 Difficulty: Medium
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {

        ListNode* first = head;
        ListNode* tail = NULL;

        while (NULL != first)
        {
            ListNode* second = first->next;
            if (NULL == second) break;
            first->next = second->next;
            second->next = first;
            if (NULL != tail)
            {
                tail->next = second;
            }
            else
            {
                head = second;
            }
            tail = first;
            first = first->next;
        }
        return head; 
    }
};