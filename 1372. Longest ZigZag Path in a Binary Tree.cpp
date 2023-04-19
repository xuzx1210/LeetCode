class Solution
{
private:
    int dfs(const TreeNode *const node, const int length, const bool fromRight) const
    {
        if (!node)
            return 0;
        const int left = fromRight ? dfs(node->left, length + 1, false) : dfs(node->left, 1, false);
        const int right = fromRight ? dfs(node->right, 1, true) : dfs(node->right, length + 1, true);
        return max({length, left, right});
    }

public:
    int longestZigZag(TreeNode *root)
    {
        return max(dfs(root, 0, false), dfs(root, 0, true));
    }
};
