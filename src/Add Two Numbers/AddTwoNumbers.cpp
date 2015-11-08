
/*
https://leetcode.com/problems/add-two-numbers/

Add Two Numbers My Submissions Question
Total Accepted: 100366 Total Submissions: 475833 Difficulty: Medium
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ;
 
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (NULL == l1 || NULL == l2) return NULL;

        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* node = NULL;
        ListNode* head = NULL;
        int value = 0;
        while (n1 != NULL || n2 != NULL || value != 0)
        {
            if (n1 != NULL) 
            {
                value = value + n1->val;
                n1 = n1->next;
            }
            if (n2 != NULL) 
            {
                value = value + n2->val;
                n2 = n2->next;
            }
            //int value = value + l1->val + l2->val;
            ListNode* next = new ListNode(value % 10);
            if (node != NULL)
            {
                node->next = next;
            }
            else
            {
                head = next;
            }
            node = next;
            value = value / 10;
        }
        return head;
    }
};



int main()
{
    Solution sol;
    ListNode n1 = new ListNode(9);
}