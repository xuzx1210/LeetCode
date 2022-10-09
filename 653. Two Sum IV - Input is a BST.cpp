class Solution
{
private:
    void dfs(TreeNode *node, vector<int> &nums)
    {
        if (!node)
            return;
        dfs(node->left, nums);
        nums.emplace_back(node->val);
        dfs(node->right, nums);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> nums;
        dfs(root, nums);
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < k)
                ++left;
            else if (sum > k)
                --right;
            else
                return true;
        }
        return false;
    }
};
