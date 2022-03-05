class Solution
{
public:
    bool dfs(TreeNode *cur, int remain)
    {
        remain -= cur->val;
        if (!cur->left && !cur->right)
        {
            if (remain)
                return false;
            return true;
        }
        if (cur->left)
            if (dfs(cur->left, remain))
                return true;
        if (cur->right)
            if (dfs(cur->right, remain))
                return true;
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return dfs(root, targetSum);
    }
};
