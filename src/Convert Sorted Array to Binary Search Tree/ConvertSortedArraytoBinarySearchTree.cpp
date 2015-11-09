
/*

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Convert Sorted Array to Binary Search Tree My Submissions Question
Total Accepted: 58432 Total Submissions: 166830 Difficulty: Medium
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Subscribe to see which companies asked this question


*/
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if (nums.size() == 0) return nullptr;
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(vector<int>& nums, int start, int end)
    {
        if (start > end) 
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = construct(nums, start, mid - 1);
        node->right = construct(nums, mid + 1, end);
        return node;

    }

    void preVisit(TreeNode* node)
    {
        if( nullptr == node) return;
        cout<<(node->val)<<endl;
        preVisit(node->left);
        preVisit(node->right);
    }
};

int main()
{
    Solution sol;
    vector<int> vec ={1, 2, 3, 4, 5, 6};
    TreeNode* root = sol.sortedArrayToBST(vec);
    sol.preVisit(root);
    return 0;
}

