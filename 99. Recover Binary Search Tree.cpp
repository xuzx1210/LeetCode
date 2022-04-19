class Solution
{
public:
    void getNums(TreeNode *node, vector<int> &nums)
    {
        if (!node)
            return;
        getNums(node->left, nums);
        nums.push_back(node->val);
        getNums(node->right, nums);
    }
    void findDiff(TreeNode *node, vector<TreeNode *> &diff, int &index, vector<int> &nums)
    {
        if (!node)
            return;
        findDiff(node->left, diff, index, nums);
        if (node->val != nums[index])
            diff.push_back(node);
        ++index;
        findDiff(node->right, diff, index, nums);
    }
    void recoverTree(TreeNode *root)
    {
        vector<int> nums({});
        getNums(root, nums);
        sort(nums.begin(), nums.end());
        vector<TreeNode *> diff({});
        int index = 0;
        findDiff(root, diff, index, nums);
        swap(diff[0]->val, diff[1]->val);
    }
};
