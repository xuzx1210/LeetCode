class Solution
{
private:
    bool result;
    void dfs(TreeNode *node, int remain)
    {
        if (!node)
            return;
        remain -= node->val;
        if (!remain && !node->left && !node->right)
            result = true;
        dfs(node->left, remain);
        if (result)
            return;
        dfs(node->right, remain);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        result = false;
        dfs(root, targetSum);
        return result;
    }
};
