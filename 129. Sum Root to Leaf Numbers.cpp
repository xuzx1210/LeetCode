class Solution
{
public:
    void dfs(TreeNode *cur, int path, vector<int> &nums)
    {
        path = path * 10 + cur->val;
        if (!cur->left && !cur->right)
        {
            nums.push_back(path);
            return;
        }
        if (cur->left)
            dfs(cur->left, path, nums);
        if (cur->right)
            dfs(cur->right, path, nums);
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<int> nums({});
        dfs(root, 0, nums);
        int result = 0;
        for (int num : nums)
            result += num;
        return result;
    }
};
