/*



Linked List Cycle My Submissions Question
Total Accepted: 83218 Total Submissions: 227316 Difficulty: Medium
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


*/
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
    bool hasCycle(ListNode *head) 
    {
        ListNode* first = head;
        ListNode* second = head;
        if (NULL == first) return false;
       

        while (NULL != first && NULL != second)
        {   
            first = first->next;
            second = second->next;
            if (second == NULL) return false;
            second = second->next;
            if (first == second) return true;
        }
        return false;
    }
};

 