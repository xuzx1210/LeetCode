class Solution
{
private:
    int dfs(TreeNode *node, const bool left)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right && left)
            return node->val;
        return dfs(node->left, true) + dfs(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return dfs(root, false);
    }
};
