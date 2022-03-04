class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int half = nums.size() >> 1;
        vector<int> leftTree(nums.begin(), nums.begin() + half), rightTree(nums.begin() + half + 1, nums.end());
        TreeNode *cur = new TreeNode(nums[half]);
        if (!leftTree.empty())
            cur->left = sortedArrayToBST(leftTree);
        if (!rightTree.empty())
            cur->right = sortedArrayToBST(rightTree);
        return cur;
    }
};
