class Solution
{
private:
    int dfs(TreeNode *node, TreeNode *parent)
    {
        if (!node)
            return 0;
        int withChildren = dfs(node->left, node) + dfs(node->right, node);
        int withParent = node->val - 1;
        if (parent)
            parent->val += withParent;
        return withChildren + (withParent > 0 ? withParent : -withParent);
    }

public:
    int distributeCoins(TreeNode *root)
    {
        return dfs(root, nullptr);
    }
};
