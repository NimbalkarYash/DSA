/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* helper(vector<int>& nums, int l, int r)
    {
        if(l>r)
        {
            return NULL;
        }

        int maxElement = INT_MIN;
        int maxIndex = 0;
        for(int i=l; i<=r;i++)
        {
            if(maxElement < nums[i]) 
            {
                maxElement = nums[i];
                maxIndex = i;
            } 
        }

        TreeNode* root = new TreeNode(maxElement);

        root->left = helper(nums, l, maxIndex-1);
        root->right = helper(nums, maxIndex+1, r);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};