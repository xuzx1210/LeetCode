class Solution
{
private:
    int dfs(TreeNode *node, bool isLeft)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return isLeft ? node->val : 0;
        return dfs(node->left, true) + dfs(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return dfs(root, false);
    }
};
