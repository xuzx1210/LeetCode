class Solution
{
private:
    int dfs(TreeNode *node)
    {
        if (!node)
            return 10001;
        if (!node->left && !node->right)
            return 1;
        return min(dfs(node->left), dfs(node->right)) + 1;
    }

public:
    int minDepth(TreeNode *root)
    {
        return root ? dfs(root) : 0;
    }
};
